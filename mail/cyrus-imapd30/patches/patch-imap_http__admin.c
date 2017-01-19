$NetBSD$

* preven to support only for GLibc with its qsort_r(3)

--- imap/http_admin.c.orig	2017-01-10 23:14:21.000000000 +0000
+++ imap/http_admin.c
@@ -478,10 +478,56 @@ static int add_procinfo(pid_t pid,
     return 0;
 }
 
-static int sort_procinfo(const struct proc_info **a, const struct proc_info **b,
-                         const char *key)
+#if defined(_GNU_SOURCE) && defined (__GLIBC__) && \
+	((__GLIBC__ > 2) || ((__GLIBC__ == 2) && (__GLIBC_MINOR__ >=0)))
+#define HAVE_GLIBC_QSORT_R
+#endif
+
+#if defined(__NEWLIB__) && \
+	((__NEWLIB__ > 2) || ((__NEWLIB__ == 2) && (__NEWLIB_MINOR__ >= 2)))
+#if defined(_GNU_SOURCE)
+#define HAVE_GLIBC_QSORT_R
+#else
+#define HAVE_BSD_QSORT_R
+#endif
+#endif
+
+#if !defined(HAVE_GLIBC_QSORT_R) && \
+	(defined(__FreeBSD__) || defined(__DragonFly__) || defined(__APPLE__))
+#define HAVE_BSD_QSORT_R
+#endif
+
+#ifdef HAVE_BSD_QSORT_R
+#define QSORT_R_COMPAR_ARGS(a,b,c) (c,a,b)
+#define cyr_qsort_r(base, nmemb, size, compar, thunk) qsort_r(base, nmemb, size, thunk, compar)
+#else
+#define QSORT_R_COMPAR_ARGS(a,b,c) (a,b,c)
+#  if defined(HAVE_GLIBC_QSORT_R)
+#define cyr_qsort_r(base, nmemb, size, compar, thunk) qsort_r(base, nmemb, size, compar, thunk)
+#  elif defined(__GNUC__)
+static void cyr_qsort_r(void *base, size_t nmemb, size_t size,
+                        int (*compar)(const void *, const void *, void *),
+                        void *thunk)
+{
+    int compar_func(const void *a, const void *b)
+    {
+        return compar(a, b, thunk);
+    }
+    qsort(base, nmemb, size, compar_func);
+}
+#  else
+#    error No qsort_r support
+#  endif
+#endif
+
+static int sort_procinfo QSORT_R_COMPAR_ARGS(
+                         const void *pa, const void *pb,
+                         void *k)
 {
     int r;
+    const struct proc_info **a = (const struct proc_info**)pa;
+    const struct proc_info **b = (const struct proc_info**)pb;
+    char *key = (char*)k;
     int rev = islower((int) *key);
 
     switch (toupper((int) *key)) {
@@ -598,8 +644,8 @@ static int action_proc(struct transactio
     /* Get and sort info for running processes */
     proc_foreach(add_procinfo, &piarray);
 
-    qsort_r(piarray.data, piarray.count, sizeof(struct proc_info *),
-            (int (*)(const void *, const void *, void *)) &sort_procinfo, &key);
+    cyr_qsort_r(piarray.data, piarray.count, sizeof(struct proc_info *),
+                &sort_procinfo, &key);
 
     /* Send HTML header */
     buf_reset(body);

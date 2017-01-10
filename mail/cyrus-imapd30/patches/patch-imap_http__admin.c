$NetBSD$

* preven to support only for GLibc with its qsort_r(3)

--- imap/http_admin.c.orig	2016-06-29 02:55:04.000000000 +0000
+++ imap/http_admin.c
@@ -479,7 +479,20 @@ static int add_procinfo(pid_t pid,
     return 0;
 }
 
-static int sort_procinfo(const struct proc_info **a, const struct proc_info **b,
+#if defined __GLIBC__
+#define HAVE_GLIBC_QSORT_R
+#elif defined(__FreeBSD__) || defined(__DragonFly__) || (defined(__APPLE__) && defined(__MACH__))
+#define HAVE_BSD_QSORT_R
+#endif
+
+#ifdef HAVE_BSD_QSORT_R
+#define QSORT_COMPARE_ARGS(a,b,c) (c,a,b)
+#else
+#define QSORT_COMPARE_ARGS(a,b,c) (a,b,c)
+#endif
+
+static int sort_procinfo QSORT_COMPARE_ARGS(
+                         const struct proc_info **a, const struct proc_info **b,
                          const char *key)
 {
     int r;
@@ -527,6 +540,16 @@ static int sort_procinfo(const struct pr
     return (rev ? -r : r);
 }
 
+#if !defined(HAVE_GLIBC_QSORT_R) && !defined(HAVE_BSD_QSORT_R)
+static __thread char proc_sort_key = 0;
+
+static int sort_procinfo_with_key(const struct proc_info **a,
+                                  const struct proc_info **b)
+{
+    return sort_procinfo(a, b, &proc_sort_key);
+}
+#endif
+
 /* Perform a proc action */
 static int action_proc(struct transaction_t *txn)
 {
@@ -599,8 +622,17 @@ static int action_proc(struct transactio
     /* Get and sort info for running processes */
     proc_foreach(add_procinfo, &piarray);
 
+#if defined(HAVE_GLIBC_QSORT_R)
     qsort_r(piarray.data, piarray.count, sizeof(struct proc_info *),
             (int (*)(const void *, const void *, void *)) &sort_procinfo, &key);
+#elif defined(HAVE_BSD_QSORT_R)
+    qsort_r(piarray.data, piarray.count, sizeof(struct proc_info *),
+            &key, (int (*)(const void *, const void *, void *)) &sort_procinfo);
+#else
+    proc_sort_key = key;
+    qsort(piarray.data, piarray.count, sizeof(struct proc_info *),
+          (int (*)(const void *, const void *)) &sort_procinfo_with_key);
+#endif
 
     /* Send HTML header */
     buf_reset(body);

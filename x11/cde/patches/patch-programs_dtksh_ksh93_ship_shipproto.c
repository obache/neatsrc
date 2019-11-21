$NetBSD$

* <unistd.h> for unlink(2) and link(2)
* <utime.h> for utime(3)
* fix utime(3) argment type
* fix read/write prototype

--- programs/dtksh/ksh93/ship/shipproto.c.orig	2019-11-16 02:06:11.000000000 +0000
+++ programs/dtksh/ksh93/ship/shipproto.c
@@ -105,6 +105,8 @@
 # include <sys/types.h>
 # include <sys/stat.h>
 # include <string.h>
+# include <unistd.h>
+# include <utime.h>
 
 # undef	ctime
 
@@ -121,15 +123,15 @@
 int
 replace __PARAM__((const char* newfile, const char* oldfile, int preserve), (newfile, oldfile, preserve)) __OTORP__(const char* newfile; const char* oldfile; int preserve;){
 	struct stat	st;
-	time_t		ut[2];
+	struct utimbuf	ut;
 
 	if (preserve && stat(oldfile, &st) || remove(oldfile) || rename(newfile, oldfile))
 		return(-1);
 	if (preserve)
 	{
-		ut[0] = st.st_atime;
-		ut[1] = st.st_mtime;
-		preserve = utime(oldfile, ut);
+		ut.actime = st.st_atime;
+		ut.modtime = st.st_mtime;
+		preserve = utime(oldfile, &ut);
 	}
 	return(preserve);
 }
@@ -1338,11 +1340,11 @@ extern __MANGLE__ void		exit __PROTO__((
 extern __MANGLE__ void		free __PROTO__((__V_*));
 extern __MANGLE__ int		link __PROTO__((const char*, const char*));
 extern __MANGLE__ int		open __PROTO__((const char*, int, ...));
-extern __MANGLE__ int		read __PROTO__((int, __V_*, int));
+extern __MANGLE__ int		read __PROTO__((int, __V_*, size_t));
 extern __MANGLE__ int		strncmp __PROTO__((const char*, const char*, size_t));
 extern __MANGLE__ time_t		time __PROTO__((time_t*));
 extern __MANGLE__ int		unlink __PROTO__((const char*));
-extern __MANGLE__ int		write __PROTO__((int, const __V_*, int));
+extern __MANGLE__ int		write __PROTO__((int, const __V_*, size_t));
 
 
 

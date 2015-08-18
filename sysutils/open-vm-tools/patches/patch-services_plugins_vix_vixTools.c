$NetBSD$

--- services/plugins/vix/vixTools.c.orig	2015-06-17 16:14:30.000000000 +0000
+++ services/plugins/vix/vixTools.c
@@ -54,7 +54,7 @@
 #include <unistd.h>
 #endif
 
-#if defined(sun) || defined(__FreeBSD__) || defined(__APPLE__)
+#if defined(sun) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__NetBSD__)
 #include <sys/stat.h>
 #endif
 
@@ -1472,7 +1472,7 @@ VixToolsRunProgramImpl(char *requestName
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = (VIX_RUNPROGRAM_ACTIVATE_WINDOW & runProgramOptions)
                      ? SW_SHOWNORMAL : SW_MINIMIZE;
-#elif !defined(__FreeBSD__)
+#elif !defined(__FreeBSD__) && !defined(__NetBSD__)
    procArgs.envp = VixToolsEnvironmentTableToEnvp(userEnvironmentTable);
 #endif
 
@@ -1633,7 +1633,7 @@ VixToolsStartProgramImpl(const char *req
     * For non-Windows, we use the user's $HOME if workingDir isn't supplied.
     */
    if (NULL == workingDir) {
-#if defined(linux) || defined(sun) || defined(__FreeBSD__) || defined(__APPLE__)
+#if defined(linux) || defined(sun) || defined(__FreeBSD__) || defined(__APPLE__)|| defined(__NetBSD__)
       char *username = NULL;
 
       if (!ProcMgr_GetImpersonatedUserInfo(&username, &workingDirectory)) {
@@ -2368,7 +2368,7 @@ VixTools_GetToolsPropertiesImpl(GKeyFile
    VixPropertyListImpl propList;
    char *serializedBuffer = NULL;
    size_t serializedBufferLength = 0;
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
    char *guestName;
    int osFamily;
    char *packageList = NULL;
@@ -3957,7 +3957,7 @@ VixToolsGetMultipleEnvVarsForUser(void *
    char *resultLocal = Util_SafeStrdup("");  // makes the loop cleaner.
    VixToolsUserEnvironment *env;
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
    if (NULL == userEnvironmentTable) {
       err = VIX_E_FAIL;
       free(resultLocal);
@@ -3974,7 +3974,7 @@ VixToolsGetMultipleEnvVarsForUser(void *
    for (i = 0; i < numNames; i++) {
       char *value;
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
       /*
        * We should check the original envp for all vars except
        * a few whitelisted ones that we set/unset on impersonate
@@ -4073,7 +4073,7 @@ VixToolsGetAllEnvVarsForUser(void *userT
    char *resultLocal;
    VixToolsEnvIterator *itr;
    char *envVar;
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
    char **envp;
    if (NULL == userEnvironmentTable) {
       err = VIX_E_FAIL;
@@ -4089,7 +4089,7 @@ VixToolsGetAllEnvVarsForUser(void *userT
 
    resultLocal = Util_SafeStrdup("");  // makes the loop cleaner.
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
    err = VixToolsNewEnvIterator(userToken, envp, &itr);
 #else
    err = VixToolsNewEnvIterator(userToken, &itr);
@@ -4101,7 +4101,7 @@ VixToolsGetAllEnvVarsForUser(void *userT
    while ((envVar = VixToolsGetNextEnvVar(itr)) != NULL) {
       char *tmp = resultLocal;
       char *tmpVal;
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
       /*
        * For variables we change during Impersonatation of user,
        * we need to fetch from getenv() system call, all else
@@ -4157,7 +4157,7 @@ VixToolsGetAllEnvVarsForUser(void *userT
 
 abort:
    VixToolsDestroyEnvIterator(itr);
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
    VixToolsFreeEnvp(envp);
 #endif
    *result = resultLocal;
@@ -4367,7 +4367,7 @@ VixToolsMoveObject(VixCommandRequestHead
     * Be careful. Renaming a file to itself can cause it to be deleted.
     * This should be a no-op anyway.
     */
-#if !defined(sun) && !defined(__FreeBSD__)
+#if !defined(sun) && !defined(__FreeBSD__) && !defined(__NetBSD__)
    if (File_IsSameFile(srcFilePathName, destFilePathName)) {
       err = VIX_OK;
       goto abort;
@@ -6299,7 +6299,7 @@ VixToolsGetFileExtendedInfoLength(const 
    fileExtendedInfoBufferSize += 10 * 3;            // uid, gid, perms
 #endif
 
-#if defined(linux) || defined(sun) || defined(__FreeBSD__)
+#if defined(linux) || defined(sun) || defined(__FreeBSD__) || defined(__NetBSD__)
    if (File_IsSymLink(filePathName)) {
       char *symlinkTarget;
       symlinkTarget = Posix_ReadLink(filePathName);

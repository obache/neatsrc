$NetBSD$

* fix syntax for new array of pointers

--- programs/dtmail/dtmail/DmxMessage.C.orig	2018-07-06 18:05:20.000000000 +0000
+++ programs/dtmail/dtmail/DmxMessage.C
@@ -566,7 +566,7 @@ DmxMsg::parse (void)
 	if (handleError (env, "getContents") == DTM_TRUE)
 		exit (1);
 
-	bodyParts = new (DtMail::BodyPart *[bc]);
+	bodyParts = new DtMail::BodyPart*[bc];
 	cachedValues = DTM_TRUE;
 	
 	// cache values

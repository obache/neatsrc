$NetBSD$

* fix syntax for new array of pointers

--- programs/dtmail/dtmailpr/message.C.orig	2018-07-06 18:05:20.000000000 +0000
+++ programs/dtmail/dtmailpr/message.C
@@ -449,7 +449,7 @@ DmxMsg::parse (void)
 	if (handleError (env, "getContents") == B_TRUE)
 		exit (1);
 
-	bodyParts = new (DtMail::BodyPart *[bc]);
+	bodyParts = new DtMail::BodyPart*[bc];
 	cachedValues = B_TRUE;
 	
 	// cache values

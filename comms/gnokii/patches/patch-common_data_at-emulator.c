$NetBSD$

* fix ctype usage

--- common/data/at-emulator.c.orig	2011-12-02 14:53:04.000000000 +0000
+++ common/data/at-emulator.c
@@ -355,7 +355,7 @@ void	gn_atem_at_parse(char *cmd_buffer)
 	}
 
 	for (buf = &cmd_buffer[2]; *buf;) {
-		switch (toupper(*buf)) {
+		switch (toupper((unsigned char)*buf)) {
 
 		case 'Z':
 			/* Reset modem */
@@ -386,7 +386,7 @@ void	gn_atem_at_parse(char *cmd_buffer)
 			/* For now we'll also initialise the datapump + rlp code again */
 			dp_Initialise(PtyRDFD, PtyWRFD);
 			buf++;
-			if (toupper(*buf) == 'T' || toupper(*buf) == 'P') buf++;
+			if (toupper((unsigned char)*buf) == 'T' || toupper((unsigned char)*buf) == 'P') buf++;
 			while (*buf == ' ') buf++;
 			data.call_notification = dp_CallPassup;
 			gn_sm_functions(GN_OP_SetCallNotification, &data, sm);
@@ -566,7 +566,7 @@ void	gn_atem_at_parse(char *cmd_buffer)
 		/* + is the precursor to another set of commands */
 		case '+':
 			buf++;
-			switch (toupper(*buf)) {
+			switch (toupper((unsigned char)*buf)) {
 			case 'C':
 				buf++;
 				/* Returns true if error occured */
@@ -700,7 +700,7 @@ void	gn_atem_sms_parse(char *buff)
 /* Parser for DIR sub mode of SMS interactive mode. */
 void	gn_atem_dir_parse(char *buff)
 {
-	switch (toupper(*buff)) {
+	switch (toupper((unsigned char)*buff)) {
 		case 'P':
 			SMSNumber--;
 			gn_atem_sms_handle();

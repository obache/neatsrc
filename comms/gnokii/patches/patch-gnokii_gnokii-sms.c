$NetBSD$

* fix ctype usage

--- gnokii/gnokii-sms.c.orig	2011-12-02 14:53:04.000000000 +0000
+++ gnokii/gnokii-sms.c
@@ -128,7 +128,7 @@ gn_gsm_number_type get_number_type(const
 		type = GN_GSM_NUMBER_Unknown;
 	}
 	while (*number) {
-		if (!isdigit(*number))
+		if (!isdigit((unsigned char)*number))
 			return GN_GSM_NUMBER_Alphanumeric;
 		number++;
 	}
@@ -497,7 +497,7 @@ gn_error savesms(int argc, char *argv[],
 				return GN_ERR_WRONGDATAFORMAT;
 			}
 			for (i = 0; i < 12; i++)
-				if (!isdigit(optarg[i])) {
+				if (!isdigit((unsigned char)optarg[i])) {
 					fprintf(stderr, _("Invalid datetime format: %s (should be YYMMDDHHMISS, all digits)!\n"), optarg);
 					return GN_ERR_WRONGDATAFORMAT;
 				}

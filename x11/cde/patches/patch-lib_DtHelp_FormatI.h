$NetBSD$

--- lib/DtHelp/FormatI.h.orig	2015-05-09 23:09:11.000000000 +0000
+++ lib/DtHelp/FormatI.h
@@ -79,7 +79,7 @@ extern	int		 _DtHelpFormatToc (
 				XtPointer	  client_data,
 				_DtHelpVolumeHdl     volume,
 				char		*id_string,
-				char		*ret_id,
+				char		**ret_id,
 				XtPointer	*ret_handle);
 extern	int		 _DtHelpFormatTopic (
 				XtPointer	  client_data,

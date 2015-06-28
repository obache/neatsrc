$NetBSD$

* for the case time_t != long

--- libmate-desktop/mate-desktop-thumbnail.c.orig	2015-04-05 17:22:23.000000000 +0000
+++ libmate-desktop/mate-desktop-thumbnail.c
@@ -1380,7 +1380,7 @@ mate_desktop_thumbnail_factory_save_thum
   char *tmp_path;
   const char *width, *height;
   int tmp_fd;
-  char mtime_str[21];
+  gchar *mtime_str;
   gboolean saved_ok;
   GChecksum *checksum;
   guint8 digest[16];
@@ -1425,7 +1425,7 @@ mate_desktop_thumbnail_factory_save_thum
     }
   close (tmp_fd);
   
-  g_snprintf (mtime_str, 21, "%ld",  original_mtime);
+  mtime_str = g_strdup_printf("%" G_GINT64_FORMAT, (gint64)original_mtime);
   width = gdk_pixbuf_get_option (thumbnail, "tEXt::Thumb::Image::Width");
   height = gdk_pixbuf_get_option (thumbnail, "tEXt::Thumb::Image::Height");
 
@@ -1463,6 +1463,7 @@ mate_desktop_thumbnail_factory_save_thum
       g_clear_error (&error);
     }
 
+  g_free (mtime_str);
   g_free (path);
   g_free (tmp_path);
 }
@@ -1488,7 +1489,7 @@ mate_desktop_thumbnail_factory_create_fa
   char *path, *file;
   char *tmp_path;
   int tmp_fd;
-  char mtime_str[21];
+  gchar *mtime_str;
   gboolean saved_ok;
   GdkPixbuf *pixbuf;
   GChecksum *checksum;
@@ -1531,7 +1532,7 @@ mate_desktop_thumbnail_factory_create_fa
     }
   close (tmp_fd);
   
-  g_snprintf (mtime_str, 21, "%ld",  mtime);
+  mtime_str = g_strdup_printf("%" G_GINT64_FORMAT, (gint64)mtime);
   pixbuf = gdk_pixbuf_new (GDK_COLORSPACE_RGB, TRUE, 8, 1, 1);
   saved_ok  = gdk_pixbuf_save (pixbuf,
 			       tmp_path,
@@ -1541,6 +1542,7 @@ mate_desktop_thumbnail_factory_create_fa
 			       "tEXt::Software", "MATE::ThumbnailFactory",
 			       NULL);
   g_object_unref (pixbuf);
+  g_free(mtime_str);
   if (saved_ok)
     {
       g_chmod (tmp_path, 0600);
@@ -1659,7 +1661,7 @@ mate_desktop_thumbnail_is_valid (GdkPixb
   thumb_mtime_str = gdk_pixbuf_get_option (pixbuf, "tEXt::Thumb::MTime");
   if (!thumb_mtime_str)
     return FALSE;
-  thumb_mtime = atol (thumb_mtime_str);
+  thumb_mtime = (time_t)g_ascii_strtoll (thumb_mtime_str, (gchar**)NULL, 10);
   if (mtime != thumb_mtime)
     return FALSE;
   

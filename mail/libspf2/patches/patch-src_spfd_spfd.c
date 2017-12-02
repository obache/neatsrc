$NetBSD$

* from upstream new feature

--- src/spfd/spfd.c.orig	2012-01-28 08:24:47.000000000 +0000
+++ src/spfd/spfd.c
@@ -159,6 +159,7 @@ struct _config_t {
 	char	*localpolicy;
 	bool	 use_trusted;
 	char	*explanation;
+	bool	 onerequest;
 } config_t;
 
 typedef
@@ -435,6 +436,7 @@ static const struct option longopts[] = 
 #ifdef HAVE_GRP_H
 	{ "setgroup",	required_argument,	NULL,	'g', },
 #endif
+	{ "onerequest", no_argument,		NULL,	'o', },
 	{ "help",       no_argument,		NULL,	'h', },
 };
 
@@ -458,6 +460,7 @@ void usage (void) {
 #ifdef HAVE_GRP_H
 	fprintf(stdout,"\t-setgroup\n");
 #endif
+	fprintf(stdout,"\t-onerequest\n");
 	fprintf(stdout,"\t-help\n");
 
 }
@@ -549,6 +552,10 @@ daemon_config(int argc, char *argv[])
 				spfd_config.setgroup = daemon_get_group(optarg);
 				break;
 #endif
+			case 'o':
+				spfd_config.onerequest = 1;
+				fprintf(stdout, "One request mode\n");
+				break;
 
 			case 0:
 			case '?':
@@ -852,7 +859,10 @@ handle_stream(void *arg)
 		FREE_STRING(req->helo);
 		FREE_STRING(req->sender);
 		FREE_STRING(req->rcpt_to);
-	} while (!feof(stream));
+	} while (! (spfd_config.onerequest || feof(stream)));
+
+	shutdown(req->sock, SHUT_RDWR);
+	fclose(stream);
 
 	free(arg);
 	return NULL;

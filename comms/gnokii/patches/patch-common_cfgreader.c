$NetBSD$

* fix ctype usage

--- common/cfgreader.c.orig	2011-12-02 14:53:04.000000000 +0000
+++ common/cfgreader.c
@@ -356,10 +356,10 @@ struct gn_cfg_header *cfg_memory_read(co
 		buf = line;
 
 		/* Strip leading, trailing whitespace */
-		while (isspace((int) *line))
+		while (isspace((unsigned char) *line))
 			line++;
 
-		while ((strlen(line) > 0) && isspace((int) line[strlen(line) - 1]))
+		while ((strlen(line) > 0) && isspace((unsigned char) line[strlen(line) - 1]))
 			line[strlen(line) - 1] = '\0';
 
 		/* Ignore blank lines and comments */
@@ -423,13 +423,13 @@ struct gn_cfg_header *cfg_memory_read(co
 			*value = '\0';	/* Split string */
 			value++;
 
-			while (isspace((int) *value)) { /* Remove leading white */
+			while (isspace((unsigned char) *value)) { /* Remove leading white */
 				value++;
 			}
 
 			entry->value = strdup(value);
 
-			while ((strlen(line) > 0) && isspace((int) line[strlen(line) - 1])) {
+			while ((strlen(line) > 0) && isspace((unsigned char) line[strlen(line) - 1])) {
 				line[strlen(line) - 1] = '\0';  /* Remove trailing white */
 			}
 
@@ -563,7 +563,7 @@ struct gn_cfg_header *cfg_file_read(cons
 		tmp = line_begin;
 		nonempty = 0;
 		while (*tmp && tmp < line_end && !nonempty) {
-			if (!isspace(*tmp))
+			if (!isspace((unsigned char)*tmp))
 				nonempty = 1;
 			tmp++;
 		}
@@ -904,7 +904,7 @@ gn_phone_model *gn_cfg_get_phone_model(s
 		while (*comma && *comma != ',')
 			comma++;
 		end = comma;
-		while (end > val && (isspace(*end) || *end == ','))
+		while (end > val && (isspace((unsigned char)*end) || *end == ','))
 			end--;
 		count = end - val + 1;
 		snprintf(model, GN_MODEL_MAX_LENGTH, "%.*s", count, val);
@@ -915,7 +915,7 @@ gn_phone_model *gn_cfg_get_phone_model(s
 			while (*val && *val != ',')
 				val++;
 			/* This skips also empty fields */
-			while (*val && (*val == ',' || isspace(*val)))
+			while (*val && (*val == ',' || isspace((unsigned char)*val)))
 				val++;
 			if (!*val)
 				break;
@@ -943,7 +943,7 @@ gn_phone_model *gn_cfg_get_phone_model(s
 			while (*comma && *comma != ',')
 				comma++;
 			end = comma;
-			while (end > val && (isspace(*end) || *end == ','))
+			while (end > val && (isspace((unsigned char)*end) || *end == ','))
 				end--;
 			count = end - val + 1;
 			dprintf("Unknown flag \"%.*s\"\n", count, val);

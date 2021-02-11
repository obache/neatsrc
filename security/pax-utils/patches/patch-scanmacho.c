$NetBSD$

* prevent overflow

--- scanmacho.c.orig	2021-02-03 20:40:12.000000000 +0000
+++ scanmacho.c
@@ -283,7 +283,7 @@ static int scanmacho_fatobj(fatobj *fobj
 	for (i = 0; out_format[i]; ++i) {
 		const char *out;
 		const char *tmp;
-		static char ubuf[sizeof(unsigned long)*2];
+		static char ubuf[(sizeof(fobj->len)*CHAR_BIT+2)/3+1];
 		if (!IS_MODIFIER(out_format[i])) {
 			xchrcat(&out_buffer, out_format[i], &out_len);
 			continue;
@@ -333,7 +333,7 @@ static int scanmacho_fatobj(fatobj *fobj
 		case 'S': out = macho_file_soname(fobj, &found_soname); break;
 		case 'U': out = macho_file_uuid(fobj, &found_uuid); break;
 		case 'a': out = get_machomtype(fobj); break;
-		case 'Z': snprintf(ubuf, sizeof(ubuf), "%llu", (unsigned long long int)fobj->len); out = ubuf; break;;
+		case 'Z': snprintf(ubuf, sizeof(ubuf), "%zu", fobj->len); out = ubuf; break;;
 		default: warnf("'%c' has no scan code?", out_format[i]);
 		}
 		if (out) {

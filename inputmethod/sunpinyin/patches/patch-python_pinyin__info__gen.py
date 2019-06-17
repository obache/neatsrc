$NetBSD$

* python2to3

--- python/pinyin_info_gen.py.orig	2019-06-17 04:59:39.951076307 +0000
+++ python/pinyin_info_gen.py
@@ -38,60 +38,60 @@
 from pinyin_data import *
 
 def fmt_str_array (name, var) :
-    print 'static const char *%s[] = { %s };' % (name, ', '.join ('"%s"' % s for s in var))
+    print ('static const char *%s[] = { %s };' % (name, ', '.join ('"%s"' % s for s in var)))
 
 def fmt_array_size (name):
-    print 'static const unsigned num_%s = sizeof(%s) / sizeof(*%s);' % (name, name, name)
+    print ('static const unsigned num_%s = sizeof(%s) / sizeof(*%s);' % (name, name, name))
 
 def fmt_str_pair_array (name, var) :
-    print 'static const char *%s[] = {' % name
+    print ('static const char *%s[] = {' % name)
     for s1, s2 in var:
-        print '    %-7s %s' % ('"%s",' % s1, '"%s",' % s2)
-    print '};'
+        print ('    %-7s %s' % ('"%s",' % s1, '"%s",' % s2))
+    print ('};')
 
 def fmt_pair_array_size (name):
-    print 'static const unsigned num_%s = sizeof(%s) / sizeof(*%s) / 2;' % (name, name, name)
+    print ('static const unsigned num_%s = sizeof(%s) / sizeof(*%s) / 2;' % (name, name, name))
 
 fmt_str_array ('initials', initials)
 fmt_array_size ('initials')
-print ''
+print ('')
 
 fmt_str_array('finals', finals)
 fmt_array_size ('finals')
-print ''
+print ('')
 
 fmt_str_array('fuzzy_finals', inner_fuzzy_finals)
 fmt_array_size ('fuzzy_finals')
-print ''
+print ('')
 
 fmt_str_pair_array ('fuzzy_pairs', fuzzy_pairs)
 fmt_pair_array_size ('fuzzy_pairs')
-print ''
+print ('')
 
 fmt_str_pair_array ('auto_correction_pairs', sorted(auto_correction_pairs.items()))
 fmt_pair_array_size ('auto_correction_pairs')
-print ''
+print ('')
 
-print 'static const unsigned fuzzy_finals_map [] = {'
+print ('static const unsigned fuzzy_finals_map [] = {')
 for s in inner_fuzzy_finals:
-    print '    %-7s %-7s %-7s /* %-4s -> %-4s len %d */' % ('0x%02x,' % finals.index(s), '0x%02x,' % valid_syllables[s[1:]], '%d,' % (len(s)-1,),  s, s[1:], len(s)-1)
-print '};\n'
+    print ('    %-7s %-7s %-7s /* %-4s -> %-4s len %d */' % ('0x%02x,' % finals.index(s), '0x%02x,' % valid_syllables[s[1:]], '%d,' % (len(s)-1,),  s, s[1:], len(s)-1))
+print ('};\n')
 
-print 'static const TPyTabEntry pinyin_table[] = {'
+print ('static const TPyTabEntry pinyin_table[] = {')
 for syllable, hex_syllable in sorted(valid_syllables.items()):
-    print '    { %-9s %s },' % ('"%s",' % syllable, '0x%05x' % hex_syllable)
-print '};\n'
+    print ('    { %-9s %s },' % ('"%s",' % syllable, '0x%05x' % hex_syllable))
+print ('};\n')
 
-print 'static const unsigned fuzzy_pre_syllables [] = {'
+print ('static const unsigned fuzzy_pre_syllables [] = {')
 for s in fuzzy_pre_syllables:
-    print '    %-11s %-7s %-11s /* %s */' % ('0x%05x,' % valid_syllables[s[:-1]], "'%s'," % s[-1], '0x%05x,' % valid_syllables[s], s)
-print '    0x0,'
-print '};\n'
+    print ('    %-11s %-7s %-11s /* %s */' % ('0x%05x,' % valid_syllables[s[:-1]], "'%s'," % s[-1], '0x%05x,' % valid_syllables[s], s))
+print ('    0x0,')
+print ('};\n')
 
-print 'static const unsigned fuzzy_pro_syllables [] = {'
+print ('static const unsigned fuzzy_pro_syllables [] = {')
 for s in fuzzy_pro_syllables:
-    print '    %-11s %-7s %-11s /* %s */' % ('0x%05x,' % valid_syllables[s], "'%s'," % s[0], '0x%05x,' % valid_syllables[s[1:]], s)
-print '    0x0,'
-print '};\n'
+    print ('    %-11s %-7s %-11s /* %s */' % ('0x%05x,' % valid_syllables[s], "'%s'," % s[0], '0x%05x,' % valid_syllables[s[1:]], s))
+print ('    0x0,')
+print ('};\n')
 
 # -*- indent-tabs-mode: nil -*- vim:et:ts=4

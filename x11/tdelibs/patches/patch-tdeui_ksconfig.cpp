$NetBSD$

--- tdeui/ksconfig.cpp.orig	2020-04-10 23:08:30.000000000 +0000
+++ tdeui/ksconfig.cpp
@@ -188,11 +188,7 @@ KSpellConfig::readGlobalSettings()
   setDictionary    ( kc->readEntry("KSpell_Dictionary") );
   setDictFromList  ( kc->readNumEntry("KSpell_DictFromList", false) );
   setEncoding ( kc->readNumEntry ("KSpell_Encoding", KS_E_UTF8) );
-#if defined(__OpenBSD__) || defined(__FreeBSD__)
-  setClient ( kc->readNumEntry ("KSpell_Client", KS_CLIENT_ASPELL) );
-#else
-  setClient ( kc->readNumEntry ("KSpell_Client", KS_CLIENT_ISPELL) );
-#endif
+  setClient ( kc->readNumEntry ("KSpell_Client", DEFAULT_SPELL_CHECKER) );
 
   return true;
 }
@@ -603,6 +599,9 @@ KSpellConfig::fillDicts( TQComboBox* box
       box->insertItem( i18n("ISpell Default") );
 
       // dictionary path
+#ifdef ISPELL_LIBDIR
+      TQFileInfo dir (ISPELL_LIBDIR);
+#else
       TQFileInfo dir ("/usr/lib/ispell");
       if (!dir.exists() || !dir.isDir())
         dir.setFile ("/usr/local/lib/ispell");
@@ -617,6 +616,7 @@ KSpellConfig::fillDicts( TQComboBox* box
        if (!dir.exists() || !dir.isDir())
        dir.setFile ("/usr/local/lib");
       */
+#endif
       if (!dir.exists() || !dir.isDir()) return;
 
       kdDebug(750) << "KSpellConfig::getAvailDictsIspell "

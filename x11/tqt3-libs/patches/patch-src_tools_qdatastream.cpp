$NetBSD$

--- src/tools/qdatastream.cpp.orig	2016-09-11 06:09:05.000000000 +0000
+++ src/tools/qdatastream.cpp
@@ -489,6 +489,8 @@ void TQDataStream::setByteOrder( int bo 
 
 #if defined(Q_OS_HPUX) && !defined(__LP64__)
 extern "C" long long __strtoll( const char *, char**, int );
+#elif defined(Q_OS_INTERIX)
+extern "C" long long strtoq( const char *, char**, int );
 #endif
 
 static TQ_INT64 read_int_ascii( TQDataStream *s )
@@ -513,7 +515,7 @@ static TQ_INT64 read_int_ascii( TQDataSt
     return _atoi64( buf );
 #  elif defined(Q_OS_HPUX)
     return __strtoll( buf, (char**)0, 10 );
-#  elif defined(Q_OS_MACX) && defined(QT_MACOSX_VERSION) && QT_MACOSX_VERSION < 0x1020
+#  elif (defined(Q_OS_MACX) && defined(QT_MACOSX_VERSION) && QT_MACOSX_VERSION < 0x1020) || defined(Q_OS_INTERIX)
     return strtoq( buf, (char**)0, 10 );
 #  else
     return strtoll( buf, (char**)0, 10 );	// C99 function

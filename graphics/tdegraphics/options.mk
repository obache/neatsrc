# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.tdegraphics
PKG_SUPPORTED_OPTIONS=	t1lib libpaper tiff openexr pdf
PKG_SUGGESTED_OPTIONS=	libpaper tiff openexr pdf

PLIST_VARS+=	tiff exr pdf

.include "../../mk/bsd.options.mk"

#option( WITH_T1LIB "Enable t1lib support" OFF )
.if !empty(PKG_OPTIONS:Mt1lib)
.include "../../fonts/t1lib/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_T1LIB:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_T1LIB:BOOL=OFF
.endif

#option( WITH_PAPER "Enable libpaper support" OFF )
.if !empty(PKG_OPTIONS:Mlibpaper)
.include "../../print/libpaper/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_PAPER:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_PAPER:BOOL=OFF
.endif

#OPTION( WITH_TIFF "Enable tiff support (tdefile-plugins)" OFF )
.if !empty(PKG_OPTIONS:Mtiff)
PLIST.tiff=	yes
.include "../../graphics/tiff/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_TIFF:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_TIFF:BOOL=OFF
.endif

#OPTION( WITH_OPENEXR "Enable openexr support (tdefile-plugins)" OFF )
.if !empty(PKG_OPTIONS:Mopenexr)
PLIST.exr=	yes
.include "../../graphics/openexr/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_OPENEXR:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_OPENEXR:BOOL=OFF
.endif

#OPTION( WITH_PDF "Enable pdf support (tdefile-plugins)" OFF )
.if !empty(PKG_OPTIONS:Mpdf)
PLIST.pdf=	yes
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
USE_LANGUAGES+=	c++14
CMAKE_ARGS+=	-DWITH_PDF:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_PDF:BOOL=OFF
.endif

# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdelibs
PKG_SUPPORTED_OPTIONS=	arts alsa cups pcre ssl inotify xcomposite xrandr
PKG_SUPPORTED_OPTIONS+=	svg idn lua tiff jasper openexr avahi gamin upower
PKG_SUPPORTED_OPTIONS+=	consolekit lzma aspell
PKG_SUPPORTED_OPTIONS+=	hal
PKG_SUGGESTED_OPTIONS=	arts cups pcre ssl xcomposite xrandr
PKG_SUGGESTED_OPTIONS+=	svg idn tiff jasper openexr avahi
PKG_SUGGESTED_OPTIONS+=	lzma aspell

PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	cups xrandr svg tiff jasper exr lzma aspell

# Build with aRts
.if !empty(PKG_OPTIONS:Marts)
.include "../../audio/arts/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_ARTS:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_ARTS:BOOL=OFF
.endif

# Enable ALSA support
.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_ALSA:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_ALSA:BOOL=OFF
.endif

# Enable libart support (for SVG icons)
.if !empty(PKG_OPTIONS:Msvg)
PLIST.svg=	yes
.include "../../graphics/libart/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_LIBART:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_LIBART:BOOL=OFF
.endif

# Enable support for libidn
.if !empty(PKG_OPTIONS:Midn)
.include "../../devel/libidn/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_LIBIDN:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_LIBIDN:BOOL=OFF
.endif

# Enable support for SSL
.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_SSL:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_SSL:BOOL=OFF
.endif

# Enable CUPS support
.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups-base/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_CUPS:BOOL=ON
PLIST.cups=	yes
.else
CMAKE_ARGS+=	-DWITH_CUPS:BOOL=OFF
.endif

# Enable LUA support
.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_LUA:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_LUA:BOOL=OFF
.endif

# Enable tiff support
.if !empty(PKG_OPTIONS:Mtiff)
PLIST.tiff=	yes
.include "../../graphics/tiff/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_TIFF:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_TIFF:BOOL=OFF
.endif

# Enable jasper (jpeg2k) support
.if !empty(PKG_OPTIONS:Mjasper)
PLIST.jasper=	yes
.include "../../graphics/jasper/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_JASPER:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_JASPER:BOOL=OFF
.endif

# Enable openexr support
.if !empty(PKG_OPTIONS:Mopenexr)
PLIST.exr=	yes
.include "../../graphics/openexr/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_OPENEXR:BOOL=ON
USE_LANGUAGES+=	gnu++11
.else
CMAKE_ARGS+=	-DWITH_OPENEXR:BOOL=OFF
.endif

# Enable AVAHI support
.if !empty(PKG_OPTIONS:Mavahi)
.include "../../net/avahi-tqt/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_AVAHI:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_AVAHI:BOOL=OFF
.endif

# Enable pcre regex support for kjs
.if !empty(PKG_OPTIONS:Mpcre)
.include "../../devel/pcre/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_PCRE:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_PCRE:BOOL=OFF
.endif

# Enable inotify support for tdeio
.if !empty(PKG_OPTIONS:Minotify)
.include "../../devel/libinotify/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_INOTIFY:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_INOTIFY:BOOL=OFF
.endif

# Enable FAM/GAMIN support
.if !empty(PKG_OPTIONS:Mgamin)
.include "../../mk/fam.buildlink3.mk"
CMAKE_ARGS+=	-DWITH_GAMIN:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_GAMIN:BOOL=OFF
.endif

# Enable HAL support
.if !empty(PKG_OPTIONS:Mhal)
.include "../../sysutils/hal/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_HAL:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_HAL:BOOL=OFF
.endif

# Enable uPower support
.if !empty(PKG_OPTIONS:Mupower)
.include "../../sysutils/upower/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_UPOWER:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_UPOWER:BOOL=OFF
.endif

# Enable ConsoleKit support
.if !empty(PKG_OPTIONS:Mconsolekit)
.include "../../sysutils/consolekit/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_CONSOLEKIT:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_CONSOLEKIT:BOOL=OFF
.endif

# Enable support for LZMA/XZ"
.if !empty(PKG_OPTIONS:Mlzma)
PLIST.lzma=	yes
.include "../../archivers/xz/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_LZMA:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_LZMA:BOOL=OFF
.endif

# Enable xcomposite support
.if !empty(PKG_OPTIONS:Mxcomposite)
.include "../../x11/libXcomposite/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_XCOMPOSITE:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_XCOMPOSITE:BOOL=OFF
.endif

# Build the tderandr library
.if !empty(PKG_OPTIONS:Mxrandr)
.include "../../x11/libXrandr/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_XRANDR:BOOL=ON
PLIST.xrandr=	yes
.else
CMAKE_ARGS+=	-DWITH_XRANDR:BOOL=OFF
.endif

# Enable aspell support
.if !empty(PKG_OPTIONS:Maspell)
PLIST.aspell=	yes
.include "../../textproc/aspell/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_ASPELL:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_ASPELL:BOOL=OFF
.endif

# Enable hspell support
#.if !empty(PKG_OPTIONS:Mhspell)
#.include "../../textproc/hspell/buildlink3.mk"
#CMAKE_ARGS+=	-DWITH_HSPELL:BOOL=ON
#.else
#CMAKE_ARGS+=	-DWITH_HSPELL:BOOL=OFF
#.endif

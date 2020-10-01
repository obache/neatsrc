# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdebase
PKG_SUPPORTED_OPTIONS=	sasl ldap samba openexr xcomposite xcursor xfixes
PKG_SUPPORTED_OPTIONS+=	xrandr xrender libconfig pcre xtest opengl xscreensaver
PKG_SUPPORTED_OPTIONS+=	libart libusb libraw1394 pam xdmcp xinerama
PKG_SUPPORTED_OPTIONS+=	hal upower
PKG_SUGGESTED_OPTIONS+=	sasl ldap samba openexr xcomposite xcursor xfixes
PKG_SUGGESTED_OPTIONS+=	xrandr xrender libconfig pcre xtest opengl xscreensaver
PKG_SUGGESTED_OPTIONS+=	libart libusb libraw1394 pam xdmcp xinerama

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	cups xrandr svg tiff jasper exr lzma aspell

#option( WITH_SASL "Enable SASL support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Msasl)
.include "../../security/cyrus-sasl/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_SASL:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_SASL:BOOL=OFF
.endif

#option( WITH_LDAP "Enable LDAP support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap-client/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_LDAP:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_LDAP:BOOL=OFF
.endif

#option( WITH_SAMBA "Enable SAMBA support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Msamba)
.include "../../net/samba/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_SAMBA:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_SAMBA:BOOL=OFF
.endif

#option( WITH_OPENEXR "Enable openexr support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mopenexr)
.include "../../graphics/openexr/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_OPENXER:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_OPENXER:BOOL=OFF
.endif

#option( WITH_XCOMPOSITE "Enable xcomposite support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mxcomposite)
.include "../../x11/libXcomposite/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_XCONPOSITE:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_XCONPOSITE:BOOL=OFF
.endif

#option( WITH_XCURSOR "Enable xcursor support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mxcursor)
.include "../../x11/libXcursor/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_XCURSOR:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_XCURSOR:BOOL=OFF
.endif

#option( WITH_XFIXES "Enable xfixes support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mxfixes)
.include "../../x11/libXfixes/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_XFIXES:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_XFIXES:BOOL=OFF
.endif

#option( WITH_XRANDR "Enable xrandr support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mxrandr)
.include "../../x11/libXrandr/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_XRANDR:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_XRANDR:BOOL=OFF
.endif

#option( WITH_XRENDER "Enable xrender support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mxrender)
.include "../../x11/libXrender/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_XRENDER:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_XRENDER:BOOL=OFF
.endif

#option( WITH_LIBCONFIG "Enable libconfig support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mlibconfig)
.include "../../devel/libconfig/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_LIBCONFIG:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_LIBCONFIG:BOOL=OFF
.endif

#option( WITH_PCRE "Enable pcre regex support" ON )
.if !empty(PKG_OPTIONS:Mpcre)
.include "../../devel/pcre/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_PCRE:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_PCRE:BOOL=OFF
.endif

#option( WITH_XTEST "Enable xtest support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mxtest)
.include "../../x11/libXtst/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_XTEST:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_XTEST:BOOL=OFF
.endif

#option( WITH_OPENGL "Enable openGL support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/glu/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_OPENGL:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_OPENGL:BOOL=OFF
.endif

#option( WITH_XSCREENSAVER "Enable xscreensaver support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mxscreensaver)
.include "../../x11/libXScrnSaver/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_XSCREENSAVER:BOOL=ON
CMAKE_ARGS+=	-DXSCREENSAVER_DIR:PATH=${LOCALBASE}/libexec/xscreensaver
.else
CMAKE_ARGS+=	-DWITH_XSCREENSAVER:BOOL=OFF
.endif

#option( WITH_LIBART "Enable libart support (for SVG icons and wallpapers)" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mlibart)
.include "../../graphics/libart/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_LIBART:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_LIBART:BOOL=OFF
.endif

#option( WITH_LIBUSB "Enable control of some mouse models through libusb" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mlibusb)
.include "../../mk/libusb.buildlink3.mk"
CMAKE_ARGS+=	-DWITH_LIBUSB:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_LIBUSB:BOOL=OFF
.endif

#option( WITH_LIBRAW1394 "Enable visualization of ieee1394 devices through libraw1394" ${WITH_ALL_OPTIONS} )
CMAKE_ARGS+=	-DWITH_LIBRAW1394:BOOL=OFF

#option( WITH_SUDO_TDESU_BACKEND "Use sudo as backend for tdesu (default is su)" OFF )

#option( WITH_SUDO_KONSOLE_SUPER_USER_COMMAND "Use sudo when launching Konsole super user sessions (default is su)" OFF )

#option( WITH_PAM "tdm should use PAM" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mpam)
.include "../../mk/pam.buildlink3.mk"
CMAKE_ARGS+=	-DWITH_PAM:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_PAM:BOOL=OFF
.endif

#option( WITH_SHADOW "tdm should use shadow passwords" ${WITH_ALL_OPTIONS} )
CMAKE_ARGS+=	-DWITH_SHADOW:BOOL=OFF

#option( WITH_XDMCP "xdmcp support for tdm" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mxdmcp)
.include "../../x11/libXdmcp/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_XDMCP:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_XDMCP:BOOL=OFF
.endif

#option( WITH_XINERAMA "Enable xinerama extension support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mxinerama)
.include "../../x11/libXinerama/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_XINERAMA:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_XINERAMA:BOOL=OFF
.endif

#option( WITH_ARTS "Enable aRts support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Marts)
.include "../../audio/arts/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_ARTS:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_ARTS:BOOL=OFF
.endif
#option( WITH_I8K "Enable Dell laptop support (ksysguard)" ${WITH_ALL_OPTIONS} )
CMAKE_ARGS+=	-DWITH_I8K:BOOL=OFF

#option( WITH_SENSORS "Enable lm_sensors support (ksysguard)" ${WITH_ALL_OPTIONS} )
CMAKE_ARGS+=	-DWITH_SENSOR:BOOL=OFF

#option( WITH_HAL "Enable HAL support" OFF )
.if !empty(PKG_OPTIONS:Mhal)
.include "../../sysutils/hal/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_HAL:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_HAL:BOOL=OFF
.endif

#option( WITH_TDEHWLIB "Enable TDE hardware library support" ${WITH_ALL_OPTIONS} )
CMAKE_ARGS+=	-DWITH_TDEHWLIB:BOOL=OFF

#option( WITH_UPOWER "Enable UPOWER support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mupower)
.include "../../sysutils/upower/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_UPOWER:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_UPOWER:BOOL=OFF
.endif

#option( WITH_ELFICON "Enable ELF embedded metadata support" ${WITH_ALL_OPTIONS} )
CMAKE_ARGS+=	-DWITH_ELFICON:BOOL=OFF

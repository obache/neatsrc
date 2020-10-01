# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.tdeutils
PKG_SUPPORTED_OPTIONS=	dpms xscreensaver snmp xmms

.include "../../mk/bsd.options.mk"

#option( WITH_DPMS "Enable Display Power Management Signaling support" OFF )
.if !empty(PKG_OPTIONS:Mdpms)
.include "../../x11/libXext/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_DPMS:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_DPMS:BOOL=OFF
.endif

#option( WITH_XSCREENSAVER "Enable xscreensaver support" OFF )
.if !empty(PKG_OPTIONS:Mxscreensaver)
.include "../../x11/libXScrnSaver/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_DPMS:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_DPMS:BOOL=OFF
.endif

#option( WITH_ASUS "Enable asus laptop support" OFF )
CMAKE_ARGS+=	-DWITH_ASUS:BOOL=OFF
#option( WITH_POWERBOOK "Enable powerbook laptop support" OFF )
CMAKE_ARGS+=	-DWITH_POWERBOOK:BOOL=OFF
#option( WITH_POWERBOOK2 "Enable powerbook2 laptop support" OFF )
CMAKE_ARGS+=	-DWITH_POWERBOOK2:BOOL=OFF
#option( WITH_VAIO "Enable vaio laptop support" OFF )
CMAKE_ARGS+=	-DWITH_VAIO:BOOL=OFF
#option( WITH_THINKPAD "Enable thinkpad laptop support" OFF )
CMAKE_ARGS+=	-DWITH_THINKPAD:BOOL=OFF
#option( WITH_I8K "Enable dell laptop support" OFF )
CMAKE_ARGS+=	-DWITH_I8K:BOOL=OFF

#option( WITH_SNMP "Enable SNMP support" OFF )
.if !empty(PKG_OPTIONS:Msnmp)
.include "../../net/net-snmp/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_SNMP:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_SNMP:BOOL=OFF
.endif

#option( WITH_SENSORS "Enable lm_sensors support" OFF )
CMAKE_ARGS+=	-DWITH_SENSORS:BOOL=OFF

#option( WITH_XMMS "Enable xmms support" OFF )
.if !empty(PKG_OPTIONS:Mxmms)
.include "../../audio/xmms/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_XMMS:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_XMMS:BOOL=OFF
.endif

#option( WITH_TDENEWSTUFF "Enable tdenewstuff support" OFF )
CMAKE_ARGS+=	-DWITH_TDENEWSTUFF:BOOL=OFF

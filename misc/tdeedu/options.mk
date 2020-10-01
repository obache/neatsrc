# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.tdeedu
PKG_SUPPORTED_OPTIONS=	arts video4linux libusb python ocaml
PKG_SUGGESTED_OPTIONS=	arts libusb python ocaml

.include "../../mk/bsd.options.mk"

#CMAKE_ARGS+=	-DWITH_ALL_OPTIONS:BOOL=ON

#PLIST_VARS+=	arts libusb

#option( WITH_ARTS                 "Enable aRts support"                               ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Marts)
.include "../../audio/arts/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_ARTS:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_ARTS:BOOL=OFF
.endif

#option( WITH_LIBUSB               "Enable libusb support (kstars)"                    ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mlibusb)
.include "../../mk/libusb.buildlink3.mk"
CMAKE_ARGS+=	-DWITH_LIBUSB:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_LIBUSB:BOOL=OFF
.endif

#option( WITH_V4L                  "Enable video4linux support (kstars)"               ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mvideo4linux)
.include "../../graphics/libv4l/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_V4L:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_V4L:BOOL=OFF
.endif

#option( WITH_KIG_PYTHON_SCRIPTING "Enable python scripting in kig"                    ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mpython)
.include "../../devel/py-boost/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_KIG_PYTHON_SCRIPT:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_KIG_PYTHON_SCRIPT:BOOL=OFF
.endif

#option( WITH_OCAML_SOLVER         "Enable ocalm/facile solver (kalzium)"              ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mocaml)
.include "../../devel/facile/buildlink3.mk"
.include "../../math/ocaml-num/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_OCAML_SOLVER:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_OCAML_SOLVER:BOOL=OFF
.endif

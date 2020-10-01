# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.tdeadmin
PKG_SUPPORTED_OPTIONS=	# empty
PKG_SUGGESTED_OPTIONS=	# empty

PLIST_VARS+=	ksysv kdat lilo-config

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "Linux"
PKG_SUPPORTED_OPTIONS+=	kdat ksysv lilo-config
.endif

.include "../../mk/bsd.options.mk"


.if !empty(PKG_OPTIONS:Mksysv)
PLIST.ksysv=	yes
.else
CMAKE_ARGS+=	-DBUILD_KSYSV:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mkdat)
PLIST.kdat=	yes
.else
CMAKE_ARGS+=	-DBUILD_KDAT:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mlilo-config)
PLIST.lilo-config=	yes
.else
CMAKE_ARGS+=	-DBUILD_LILO_CONFIG:BOOL=OFF
.endif

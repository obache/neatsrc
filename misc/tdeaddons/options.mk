# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.tdeutils
PKG_SUPPORTED_OPTIONS=	arts xmms sdl bdb
PKG_SUGGESTED_OPTIONS=	${PKG_SUPPORTED_OPTIONS:Nxmms}

PLIST_VARS+=	${PKG_SUPPORTED_OPTIONS}

.include "../../mk/bsd.options.mk"

#option( WITH_ARTS        "Enable aRts support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Marts)
.include "../../audio/arts/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_ARTS:BOOL=ON
PLIST.arts=	yes
.else
CMAKE_ARGS+=	-DWITH_ARTS:BOOL=OFF
.endif

#option( WITH_SDL         "Enable SDL support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Msdl)
.include "../../devel/SDL/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_SDL:BOOL=ON
PLIST.sdl=		yes
.else
CMAKE_ARGS+=	-DWITH_SDL:BOOL=OFF
.endif

#option( WITH_BERKELEY_DB "Enable Berkeley DB support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mbdb)
BDB_INCOMPATIBLE=	db1 db2 db3
.include "../../mk/bdb.buildlink3.mk"
CMAKE_ARGS+=	-DWITH_BERKELEY_DB:BOOL=ON
CMAKE_ARGS+=	-DBERKELEY_DB_INCLUDE_DIRS:PATH=${BDBBASE}/${BUILDLINK_INCDIRS.${BDB_TYPE}}
CMAKE_ARGS+=	-DBERKELEY_DB_LIBS:FILEPATH=${BDB_TYPE}_cxx
PLIST.bdb=		yes
.else
CMAKE_ARGS+=	-DWITH_BERKELEY_DB:BOOL=OFF
.endif

#option( WITH_XMMS        "Enable xmms support" OFF )
.if !empty(PKG_OPTIONS:Mxmms)
.include "../../audio/xmms/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_XMMS:BOOL=ON
PLIST.xmms=	yes
.else
CMAKE_ARGS+=	-DWITH_XMMS:BOOL=OFF
.endif

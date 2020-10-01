# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.tdesdk
PKG_SUPPORTED_OPTIONS=	dbsearchengine kcal	
PKG_SUGGESTED_OPTIONS=	dbsearchengine kcal

PLIST_VARS+=	dbsearchengine kcal

.include "../../mk/bsd.options.mk"

#option( WITH_DBSEARCHENGINE "Enable dbsearchengine support (kbabel)" OFF )
.if !empty(PKG_OPTIONS:Mdbsearchengine)
CMAKE_ARGS+=	-DWITH_DBSEARCHENGINE:BOOL=ON
CMAKE_ARGS+=	-DUSE_DB_H_PATH:FILEPATH=${BDB_TYPE}/db.h
CMAKE_ARGS+=	-DBDB_LIBRARY:FILEPATH=${BDB_TYPE}
BDB_ACCEPTED=	db4 db5
PLIST.dbsearchengine=	yes
.include "../../mk/bdb.buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_DBSEARCHENGINE:BOOL=OFF
.endif

#option( WITH_KCAL "Enable kcal support (kbugbuster)" OFF )
.if !empty(PKG_OPTIONS:Mkcal)
CMAKE_ARGS+=	-DWITH_KCAL:BOOL=ON
PLIST.kcal=	yes
.include "../../misc/tdepim/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_KCAL:BOOL=OFF
.endif

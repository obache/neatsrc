# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.libpinyin
PKG_OPTIONS_REQUIRED_GROUPS=	dbm
PKG_OPTIONS_GROUP.dbm=	bdb kyotocabinet
PKG_SUGGESTED_OPTIONS=	bdb

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbdb)
BDB_INCOMPATIBLE+=	db1 db2 db3
.include "../../mk/bdb.buildlink3.mk"
BUILDLINK_TRANSFORM+=	l:db${BDB_LIBS:S/^-l/:/}
CONFIGURE_ARGS+=	--with-dbm=BerkeleyDB
.elif !empty(PKG_OPTIONS:Mkyotocabinet)
.include "../../databases/kyotocabinet/buildlink3.mk"
CONFIGURE_ARGS+=	--with-dbm=KyotoCabinet
.endif

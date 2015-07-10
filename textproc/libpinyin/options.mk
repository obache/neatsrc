# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.libpinyin
PKG_OPTIONS_REQUIRED_GROUPS=	dbm
PKG_OPTIONS_GROUP.dbm=	bdb kyotocabinet
PKG_SUGGESTED_OPTIONS=	bdb

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbdb)
.include "../../databases/db4/buildlink3.mk"
BUILDLINK_TRANSFORM+=	l:db:db4
CONFIGURE_ARGS+=	--with-dbm=BerkeleyDB
.elif !empty(PKG_OPTIONS:Mkyotocabinet)
.include "../../databases/kyotocabinet/buildlink3.mk"
CONFIGURE_ARGS+=	--with-dbm=KyotoCabinet
.endif

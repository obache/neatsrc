# $NetBSD: options.mk,v 1.2 2021/07/02 15:19:30 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-mysqli
PKG_SUPPORTED_OPTIONS=	mysqlnd
PKG_SUGGESTED_OPTIONS=	mysqlnd

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	mysqlnd libmysql

.if !empty(PKG_OPTIONS:Mmysqlnd)
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,mysqlnd
PLIST.mysqlnd=		yes
.else
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_PREFIX.mysql-client}/bin/mysql_config
PLIST.libmysql=		yes
.endif

# $NetBSD: options.mk,v 1.3 2016/09/11 23:31:22 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.trac
PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=	sqlite pgsql mysql
PKG_SUGGESTED_OPTIONS=	sqlite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	${PYPKGPREFIX}-sqlite3>=0:../../databases/py-sqlite3
.endif
.if !empty(PKG_OPTIONS:Mpsycopg2)
DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2:../../databases/py-psycopg2
.endif
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PYPKGPREFIX}-mysqldb>=1.2.2:../../databases/py-mysqldb
.endif

# $NetBSD$

DISTNAME=	pg_bigm-1.2-20161011
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME:C/-([0-9]*)$/.\1/}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_OSDN:=pgbigm/66565/}

HOMEPAGE=	http://pgbigm.osdn.jp/
COMMENT=	PostgreSQL extension to create bigram index for full text search
LICENSE=	postgresql-license

USE_TOOLS+=	gmake

MAKE_FLAGS+=	USE_PGXS=1 PG_CONFIG=${PGSQL_PREFIX}/bin/pg_config

.include "../../mk/pgsql.buildlink3.mk"
BUILDLINK_DEPMETHOD.${PGSQL_TYPE}=	build
DEPENDS+=	${PGSQL_TYPE:S/-client/-server/}:${PGPKGSRCDIR:S/-client/-server/}
.include "../../mk/bsd.pkg.mk"

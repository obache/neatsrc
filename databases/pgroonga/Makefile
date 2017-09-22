# $NetBSD$

DISTNAME=	pgroonga-1.2.3
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	http://packages.groonga.org/source/pgroonga/

HOMEPAGE=	http://pgroonga.github.io/
COMMENT=	PostgreSQL extension for full-text search index based on Groonga
LICENSE=	postgresql-license AND 2-clause-bsd

USE_TOOLS+=	gmake pkg-config

.include "../../textproc/groonga/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
BUILDLINK_DEPMETHOD.${PGSQL_TYPE}=	build
DEPENDS+=	${PGSQL_TYPE:S/-client/-server/}:${PGPKGSRCDIR:S/-client/-server/}
.include "../../mk/bsd.pkg.mk"

# $NetBSD$

TQT3_SQL_MODULE=	psql
.include "../../x11/tqt3-libs/sql-driver.mk"

COMMENT=	TQt3 PostgreSQL driver

QMAKE_ARGS+=	"INCLUDEPATH+=${PGSQL_PREFIX}/include/postgresql/server"
QMAKE_ARGS+=	"LIBS=-L${PGSQL_PREFIX}/lib"

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

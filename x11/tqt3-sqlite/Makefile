# $NetBSD$

TQT3_SQL_MODULE=	sqlite
.include "../../x11/tqt3-libs/sql-driver.mk"

COMMENT=	TQt3 SQLite driver

QMAKE_ARGS+=	"INCLUDEPATH+=${BUILDLINK_PREFIX.sqlite}/include"
QMAKE_ARGS+=	"LIBS=-L${BUILDLINK_PREFIX.sqlite}/lib -lsqlite"

.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

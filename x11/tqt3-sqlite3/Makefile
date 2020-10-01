# $NetBSD$

TQT3_SQL_MODULE=	sqlite3
.include "../../x11/tqt3-libs/sql-driver.mk"

COMMENT=	TQt3 SQLite3 driver

QMAKE_ARGS+=	"INCLUDEPATH+=${BUILDLINK_PREFIX.sqlite3}/include"
QMAKE_ARGS+=	"LIBS=-L${BUILDLINK_PREFIX.sqlite3}/lib"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

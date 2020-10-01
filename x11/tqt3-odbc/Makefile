# $NetBSD$

TQT3_SQL_MODULE=	odbc
.include "../../x11/tqt3-libs/sql-driver.mk"

COMMENT=	TQt3 ODBC driver

QMAKE_ARGS+=	"INCLUDEPATH+=${BUILDLINK_PREFIX.unixodbc}/include"
QMAKE_ARGS+=	"LIBS=-L${BUILDLINK_PREFIX.unixodbc}/lib -lodbc"

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

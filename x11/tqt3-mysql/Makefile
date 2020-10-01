# $NetBSD$

TQT3_SQL_MODULE=	mysql
.include "../../x11/tqt3-libs/sql-driver.mk"

COMMENT=	TQt3 MySQL driver

QMAKE_ARGS+=	"INCLUDEPATH+=${BUILDLINK_PREFIX.mysql-client}/include/mysql"
QMAKE_ARGS+=	"LIBS=-L${BUILDLINK_PREFIX.mysql-client}/lib"

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

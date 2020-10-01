# $NetBSD$

BUILD_TQT3=	no
.include "../../x11/tqt3-libs/Makefile.common"

PKGNAME=	tqt3-${TQT3_SQL_MODULE}-${TQT3_RELEASE}
COMMENT?=	TQt ${TQT3_SQL_MODULE} driver

USE_LANGUAGES+=	c c++

BUILD_DEPENDS+=	tqt3-tools>=${TQT3_RELEASE}:../../x11/tqt3-tools

CONFIGURE_DIRS=	plugins/src/sqldrivers/${TQT3_SQL_MODULE}

do-configure:
	cd ${WRKSRC}/plugins/src/sqldrivers/${TQT3_SQL_MODULE};\
	${SETENV} ${CONFIGURE_ENV} ${TQTDIR}/bin/tqmake -o Makefile ${QMAKE_ARGS} ${TQT3_SQL_MODULE}.pro

.include "../../x11/tqt3-libs/buildlink3.mk"

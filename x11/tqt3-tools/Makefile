# $NetBSD$

BUILD_TQT3=		yes

.include "../../x11/tqt3-libs/Makefile.common"

PKGNAME=	tqt3-tools-${TQT3_RELEASE}
COMMENT=	TQt3 GUI (WYSIWYG) builder and other tools

UNLIMIT_RESOURCES=	datasize
BUILD_TARGET=		sub-tools
INSTALL_TARGET=		tools-install qmake-install

post-wrapper:
	${LN} -s ${BUILDLINK_BASEDIR}/${TQTDIR}/lib/libtqt-mt.la ${WRKSRC}/lib/
	${_LIBTOOL_EXPAND} ${BUILDLINK_BASEDIR}/${TQTDIR}/lib/libtqt-mt.la | \
	while read lib; do \
		${LN} -s $${lib} ${WRKSRC}/lib/; \
	done;

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/tqt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD$

PKGNAME=	tqt3-docs-${TQT3_RELEASE}
COMMENT=	Documentation for the TQt C++ X GUI toolkit
LICENSE=	gnu-gpl-v2

BUILD_TQT3=	no
NO_BUILD=	yes

.include "../../x11/tqt3-libs/Makefile.common"

INSTALLATION_DIRS=	${TQTPREFIX}/doc ${TQTPREFIX}/${PKGMANDIR}

do-install:
	${RUN}cd ${WRKSRC}/doc/man;\
	pax -rwpp -s /\qt$$// man? ${DESTDIR}${TQTPREFIX}/${PKGMANDIR}
	${RUN}cd ${WRKSRC}/doc;\
	pax -rwpp html ${DESTDIR}${TQTPREFIX}/doc

.include "../../mk/bsd.pkg.mk"

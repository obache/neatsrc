# $NetBSD$

DISTNAME=	libstemmer_c
PKGNAME=	libstemmer-0
CATEGORIES=	textproc
MASTER_SITES=	http://snowball.tartarus.org/dist/
EXTRACT_SUFX=	.tgz

HOMEPAGE=	http://snowball.tartarus.org/
COMMENT=	Snowball language stemming algorithms library
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

INSTALLATION_DIRS=	bin include lib

do-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/stemwords ${DESTDIR}${PREFIX}/bin
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libstemmer.la ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/libstemmer.h ${DESTDIR}${PREFIX}/include/libstemmer.h

.include "../../mk/bsd.pkg.mk"

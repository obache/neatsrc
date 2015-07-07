# $NetBSD$

DISTNAME=	ncompress-4.2.4.4
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ncompress/}

HOMEPAGE=	http://ncompress.sourceforge.net/
COMMENT=	Improved version of compress
LICENSE=	public-domain

USE_LANGUAGES=	c

CPPFLAGS+=	-DNOFUNCDEF=1

INSTALLATION_DIRS+=	bin ${PKGMANDIR}

do-configure:
	${RUN}cd ${WRKSRC};	\
		${PRINTF} '1 %s %s\n4 %s\n5 %s\n6 %s\n7 %s\nq\n' \
		${DESTDIR}${PREFIX}/bin ${DESTDIR}${PREFIX}/${PKGMANDIR} \
			${CC} ${CFLAGS:Q} ${LDFLAGS:Q} ${CPPFLAGS:Q} | \
		${SETENV} ${CONFIGURE_ENV} ${SH} build

do-build:
	${RUN}cd ${WRKSRC};	\
		${PRINTF} 'c\n\nq\n' | \
		${SETENV} ${MAKE_ENV} ${SH} build

do-install:
	${RUN}cd ${WRKSRC}; 	\
		${PRINTF} 'i ${BINOWN}\n\nq\n' | \
		${SETENV} ${INSTALL_ENV} ${SH} build

.include "../../mk/bsd.pkg.mk"

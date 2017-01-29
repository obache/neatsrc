# $NetBSD$

DISTNAME=	brotli-0.5.2
CATEGORIES=	archivers
MASTER_SITES=	-https://github.com/google/brotli/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

LIB_TAG=	ccb89e138b0948d7c353bc508b0d8fc584e01ff2
DISTFILES_VARS+=	lib
DISTFILES.lib=	libbrotli-${LIB_TAG}.tar.gz
SITES.lib=	-https://github.com/bagder/lib${PKGBASE}/archive/${LIB_TAG}${EXTRACT_SUFX}

HOMEPAGE=	https://github.com/google/${PKGBASE}/
COMMENT=	generic-purpose lossless compression algorithm.
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	automake autoconf autoreconf
USE_LIBTOOL=	yes
TOOLS_NOOP=	git

PKGCONFIG_OVERRIDE+=	libbrotlienc.pc.in
PKGCONFIG_OVERRIDE+=	libbrotlidec.pc.in

WRKSRC=		${WRKDIR}/libbrotli-${LIB_TAG}

post-extract:
		${RMDIR} ${WRKSRC}/brotli || ${TRUE}
		${MV} ${WRKDIR}/brotli-${PKGVERSION_NOREV} ${WRKSRC}/brotli

pre-configure:	${WRKSRC}/configure

${WRKSRC}/configure:
	${RUN}cd ${WRKSRC};${CONFIGURE_ENV} ${SH} autogen.sh

.include "../../mk/bsd.pkg.mk"

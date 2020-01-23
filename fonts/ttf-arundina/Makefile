# $NetBSD$

DISTNAME=	ttf-arundina-0.3.0
CATEGORIES=	fonts
MASTER_SITES=	ftp://linux.thai.net/pub/thailinux/software/fonts-arundina/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://linux.thai.net/projects/fonts-arundina
COMMENT=	Bitstream Vera/Dejavu compatible Thai True Type fonts
#LICENSE=	bitstram-license

USE_LANGUAGES=	# none

NO_BUILD=	yes
NO_CONFIGURE=	yes

FONTS_DIRS.ttf=	${PREFIX}/share/fonts/X11/TTF
EGCONFDIR=	${PREFIX}/share/examples/fontconfig/conf.d
FCCONFDIR=	${PKG_SYSCONFDIR}/fontconfig/conf.d

INSTALLATION_DIRS+=	${FONTS_DIRS.ttf} ${EGCONFDIR}

REQD_DIRS+=	${FCCONFDIR}

CONF_FILES+=	${EGCONFDIR}/65-arundina.conf ${FCCONFDIR}/65-arundina.conf

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/fontconfig/conf.avail/*.conf ${DESTDIR}${EGCONFDIR}

.include "../../mk/bsd.pkg.mk"

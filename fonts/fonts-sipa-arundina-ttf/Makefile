# $NetBSD$

DISTNAME=	fonts-sipa-arundina-ttf-0.2.1
CATEGORIES=	fonts
MASTER_SITES=	http://linux.thai.net/pub/thailinux/software/fonts-sipa-arundina/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://linux.thai.net/projects/fonts-sipa-arundina
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

CONF_FILES+=	${EGCONFDIR}/65-sipa-arundina.conf ${FCCONFDIR}/65-sipa-arundina.conf

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/etc/fonts/conf.avail/*.conf ${DESTDIR}${EGCONFDIR}

.include "../../mk/bsd.pkg.mk"

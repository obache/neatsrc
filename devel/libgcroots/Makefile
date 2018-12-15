# $NetBSD: Makefile,v 1.7 2017/08/16 21:22:11 wiz Exp $
#

DISTNAME=	libgcroots-0.3.1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/uim/libgcroots/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/archive/p/sigscheme/wikis/libgcroots.wiki
COMMENT=	Garbage collector supporting library
#LICENSE=	# See ${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	gcroots.pc.in

.include "../../mk/bsd.pkg.mk"

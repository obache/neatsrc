# $NetBSD$

DISTNAME=	libpipeline-1.4.1
CATEGORIES=	devel
MASTER_SITES=	http://download.savannah.gnu.org/releases/libpipeline/

HOMEPAGE=	http://libpipeline.nongnu.org/
COMMENT=	Pipeline manipulation library
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	lib/libpipeline.pc.in

.include "../../mk/bsd.pkg.mk"

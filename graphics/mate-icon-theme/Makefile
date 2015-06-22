# $NetBSD$

DISTNAME=	mate-icon-theme-1.10.1
CATEGORIES=	graphics mate
MASTER_SITES=	http://pub.mate-desktop.org/releases/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	obache@users.sourceforge.net
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	Collection of icons used as the basis for MATE themes
LICENSE=	gnu-lgpl-v3 OR cc-by-sa-v3.0

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake intltool pkg-config
USE_LANGUAGES=	c

PKGCONFIG_OVERRIDE+=	mate-icon-theme.pc.in

.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

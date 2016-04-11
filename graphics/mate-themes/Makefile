# $NetBSD$

DISTNAME=	mate-themes-3.20.5
CATEGORIES=	graphics mate
MASTER_SITES=	http://pub.mate-desktop.org/releases/themes/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	Icons and themes for MATE desktop
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v3

DEPENDS+=	gtk2-engines-[0-9]*:../../x11/gtk2-engines
DEPENDS+=	gtk2-engines-murrine>=0.98.0:../../x11/gtk2-engines-murrine

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

ICON_THEMES=	yes

BUILDLINK_DEPMETHOD.gdk-pixbuf2+=	build
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gtk2+=	build
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

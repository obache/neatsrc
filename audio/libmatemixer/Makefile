# $NetBSD$

DISTNAME=	libmatemixer-1.12.1
CATEGORIES=	audio mate
MASTER_SITES=	http://pub.mate-desktop.org/releases/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	MATE keyboard configuration library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	data/libmatemixer.pc.in

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.36.0
.include "../../devel/glib2/buildlink3.mk"
#.include "../../x11/gtk2/buildlink3.mk"
#.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

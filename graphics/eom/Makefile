# $NetBSD$

DISTNAME=	eom-1.12.1
CATEGORIES=	graphics mate
MASTER_SITES=	http://pub.mate-desktop.org/releases/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	Eye of MATE: an image viewing and cataloging program
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool itstool msgfmt pkg-config xmllint
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	data/eom.pc.in

ICON_THEMES=		yes

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

.include "../../databases/shared-mime-info/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.36.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.gtk2:Mx11)
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"

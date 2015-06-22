# $NetBSD$

DISTNAME=	atril-1.10.0
CATEGORIES=	print mate
MASTER_SITES=	http://pub.mate-desktop.org/releases/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	obache@users.sourceforge.net
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	Simple multi-page document viewer for the MATE environment
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=	atril-document.pc.in
PKGCONFIG_OVERRIDE+=	atril-view.pc.in

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.36.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/mate-icon-theme/buildlink3.mk"
.include "../../sysutils/caja/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.gtk2:Mx11)
BUILDLINK_API_DEPENDS.libSM+=	libSM>=1.0.0
.include "../../x11/libSM/buildlink3.mk"
.endif
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"

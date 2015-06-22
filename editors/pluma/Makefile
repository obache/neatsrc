# $NetBSD$

DISTNAME=	pluma-1.10.1
CATEGORIES=	editors mate
MASTER_SITES=	http://pub.mate-desktop.org/releases/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	obache@users.sourceforge.net
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	Small and lightweight UTF-8 text editor for the MATE
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

PKGCONFIG_OVERRIDE+=	data/pluma.pc.in

CONFIGURE_ARGS+=	--disable-updater # only for OS X and Windows

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.36.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtksourceview2+=	gtksourceview2>=2.9.7
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"

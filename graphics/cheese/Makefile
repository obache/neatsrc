# $NetBSD: Makefile,v 1.96 2021/05/02 10:24:49 nia Exp $

DISTNAME=	cheese-3.34.0
PKGREVISION=	6
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/cheese/3.34/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Cheese
COMMENT=	Use your webcam to take photos and videos
LICENSE=	gnu-gpl-v2

DEPENDS+=	gst-plugins1-v4l2-[0-9]*:../../multimedia/gst-plugins1-v4l2

USE_TOOLS+=	pkg-config msgfmt xgettext itstool

MESON_ARGS+=	-Dgtk_doc=false
MESON_ARGS+=	-Dman=false

PYTHON_FOR_BUILD_ONLY=	tool

# XXX msgfmt: unknown option -- desktop
GETTEXT_TOOLS_REQD=		0.19

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/cheese.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/cheese-gtk.pc

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../audio/libcanberra/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection?=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/clutter-gtk/buildlink3.mk"
BUILDLINK_DEPMETHOD.vala?=	build
.include "../../lang/vala/buildlink3.mk"
.include "../../multimedia/clutter-gst/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../multimedia/gst-plugins1-bad/buildlink3.mk"
.include "../../multimedia/gnome-video-effects/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

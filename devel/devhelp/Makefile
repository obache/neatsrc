# $NetBSD: Makefile,v 1.142 2021/05/02 10:24:47 nia Exp $

DISTNAME=	devhelp-3.34.0
PKGREVISION=	7
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/devhelp/3.34/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Devhelp
COMMENT=	Tool for browsing and searching API documentation from GNOME
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config msgfmt xgettext itstool

PYTHON_FOR_BUILD_ONLY=	tool

# XXX msgfmt: unknown option -- xml
GETTEXT_TOOLS_REQD=		0.19.7

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/libdevhelp-3.0.pc

.include "../../devel/meson/build.mk"
.include "../../devel/amtk/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

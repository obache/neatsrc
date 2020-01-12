# $NetBSD: Makefile,v 1.30 2020/01/02 16:52:28 gutteridge Exp $

DISTNAME=	json-glib-1.4.4
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/json-glib/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/JsonGlib
COMMENT=	JSON parser for GLib-based libraries and applications
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	gmake msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	output/meson-private/json-glib-1.0.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

CONFIGURE_ARGS+=	--disable-man

.include "options.mk"

PRINT_PLIST_AWK+= \
	($$0 ~ /^lib\/girepository-1.0\//) || \
	($$0 ~ /^share\/gir-1.0\//) \
	{ $$0 = "$${PLIST.introspection}" $$0; }

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.28 2017/05/29 12:20:24 wiz Exp $

DISTNAME=	corebird-1.6
CATEGORIES=	net
MASTER_SITES=	https://github.com/baedert/${PKGBASE}/releases/download/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://corebird.baedert.org/
COMMENT=	Native Gtk+ Twitter Client
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=	yes
USE_LANGUAGES=	c
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake msgfmt xmllint

GETTEXT_TOOLS_REQD=	0.19.7

.include "options.mk"

TEST_TARGET=	check

BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.20.0
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
BUILDLINK_DEPMETHOD.vala=	build
.include "../../lang/vala/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../mk/bsd.pkg.mk"

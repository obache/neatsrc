# $NetBSD: Makefile,v 1.22 2020/03/08 16:50:13 wiz Exp $
#

DISTNAME=	ibus-hangul-1.5.4
PKGREVISION=	2
CATEGORIES=	inputmethod korean
MASTER_SITES=	${MASTER_SITE_GITHUB:=libhangul/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ibus/ibus/wiki
COMMENT=	Hangul engine for IBus input platform
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake msgfmt intltool

GETTEXT_TOOLS_REQD=	0.19.7

TEST_TARGET=		check

REPLACE_SH=	tests/runtest

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/libhangul/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.21 2019/05/15 14:33:13 leot Exp $
#

DISTNAME=	ibus-hangul-1.5.2
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

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libhangul+=	libhangul>=0.1.0
.include "../../inputmethod/libhangul/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../mk/bsd.pkg.mk"

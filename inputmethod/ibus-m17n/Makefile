# $NetBSD: Makefile,v 1.44 2019/07/21 22:25:09 wiz Exp $
#

DISTNAME=	ibus-m17n-1.4.1
PKGREVISION=	2
CATEGORIES=	inputmethod
MASTER_SITES=	https://github.com/ibus/ibus-m17n/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ibus/ibus/wiki
COMMENT=	M17N engine for IBus platform
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config msgfmt gmake

GETTEXT_TOOLS_REQD=	0.19.7

.include "../../devel/m17n-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD$

DISTNAME=	libcangjie-1.3
CATEGORIES=	inputmethod chinese
MASTER_SITES=	https://github.com/Cangjians/libcangjie/releases/download/v${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://cangjians.github.io/projects/libcangjie/
COMMENT=	Library implementing of Cangjie input method
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	data/cangjie.pc.in

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD$

DISTNAME=		smproxy-1.0.6
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X Session Manager Proxy
LICENSE=		mit

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

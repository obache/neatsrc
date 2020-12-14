# $NetBSD$

TDE_PKGNAME=	tdeaccessibility
CATEGORIES=	x11

COMMENT=	Trinity Desktop Environment [TDE] accessibility
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	tqt3-tools>=${TQT3_RELEASE}:../../x11/tqt3-tools

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config perl perl:run
EXTRACT_USING=	gtar

.include "../../meta-pkgs/tde/Makefile.tde"

CONFIGURE_ARGS+=	--with-extra-includes=${BUILDLINK_PREFIX.jpeg}/include

.include "options.mk"

.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"

.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/tqtinterface/buildlink3.mk"
.include "../../x11/tdelibs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

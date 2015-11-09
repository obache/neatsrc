# $NetBSD$

DISTNAME=	engrampa-1.12.0
CATEGORIES=	archivers mate
MASTER_SITES=	http://pub.mate-desktop.org/releases/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	Archive manager utility for the MATE Environment
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool itstool msgfmt pkg-config xmllint
USE_TOOLS+=		gtar:run gzip:run bzip2:run unzip:run zip:run xz:run
USE_PKGLOCALEDIR=	yes

ICON_THEMES=		yes

.include "../../devel/glib2/schemas.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/caja/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_DEPMETHOD.libSM=	build
.include "../../x11/libSM/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"

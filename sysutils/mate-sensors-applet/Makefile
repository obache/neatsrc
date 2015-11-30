# $NetBSD$

DISTNAME=	mate-sensors-applet-1.12.1
CATEGORIES=	sysutils mate
MASTER_SITES=	http://pub.mate-desktop.org/releases/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	MATE Sensors applets
LICENSE=	gnu-gpl-v2 AND cc-by-sa-v3.0

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool itstool msgfmt pkg-config xmllint

SUBST_CLASSES+=	dl
SUBST_STAGE.dl=	pre-configure
SUBST_SED.dl=	-e 's,-ldl,${DL_LIBS},g'
SUBST_FILES.dl=	sensors-applet/Makefile.in

.include "../../devel/glib2/schemas.mk"

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.36.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/mate-panel/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

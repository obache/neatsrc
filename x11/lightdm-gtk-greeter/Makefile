# $NetBSD$

DISTNAME=	lightdm-gtk-greeter-2.0.1
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/lightdm-gtk-greeter/${PKGVERSION_NOREV:R}/${PKGVERSION_NOREV}/+download/

HOMEPAGE=	https://launchpad.net/lightdm-gtk-greeter/
COMMENT=	LightDM GTK+ Greeter
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config intltool msgfmt
USE_PKGLOCALEDIR=	yes
ICON_THEMES=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

BUILD_DEFS+=	VARBASE

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

MAKE_DIRS+=	${PKG_SYSCONFDIR}/lightdm

CONF_FILES+=	${EGDIR}/lightdm/lightdm-gtk-greeter.conf \
		${PKG_SYSCONFDIR}/lightdm/lightdm-gtk-greeter.conf

.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/lightdm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

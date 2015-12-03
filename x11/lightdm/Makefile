# $NetBSD$

DISTNAME=	lightdm-1.17.2
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/lightdm/${PKGVERSION_NOREV:R}/${PKGVERSION_NOREV}/+download/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://www.fdeedesktop.org/wiki/Software/LightDM/
COMMENT=	Light Display Manager
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool itstool msgfmt pkg-config xmllint
USE_LANGUAGES=	c c++
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	liblightdm-gobject/liblightdm-gobject-1.pc.in
PKGCONFIG_OVERRIDE+=	liblightdm-qt/liblightdm-qt-3.pc.in
PKGCONFIG_OVERRIDE+=	liblightdm-qt/liblightdm-qt5-3.pc.in

CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

BUILD_DEFS+=	VARBASE

LIGHTDM_USER?=		lightdm
LIGHTDM_GROUP?=		daemon
PKG_GROUPS=		${LIGHTDM_GROUP}
PKG_USERS=		${LIGHTDM_USER}:${LIGHTDM_GROUP}
PKG_GROUPS_VARS=	LIGHTDM_USER
PKG_USERS_VARS=		LIGHTDM_GROUP

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

MAKE_DIRS+=	${PKG_SYSCONFDIR}/apparmor.d/abstractions
MAKE_DIRS+=	${PKG_SYSCONFDIR}/apparmor.d
MAKE_DIRS+=	${PKG_SYSCONFDIR}/dbus-1/system.d
MAKE_DIRS+=	${PKG_SYSCONFDIR}/init
OWN_DIRS+=	${PKG_SYSCONFDIR}/lightdm
OWN_DIRS+=	${VARBASE}/lib/lightdm-data

CONF_FILES+=	${EGDIR}/apparmor.d/abstractions/lightdm \
		${PKG_SYSCONFDIR}/apparmor.d/abstractions/lightdm
CONF_FILES+=	${EGDIR}/apparmor.d/abstractions/lightdm_chromium-browser \
		${PKG_SYSCONFDIR}/apparmor.d/abstractions/lightdm_chromium-browser
CONF_FILES+=	${EGDIR}/apparmor.d/lightdm-guest-session \
		${PKG_SYSCONFDIR}/apparmor.d/lightdm-guest-session
CONF_FILES+=	${EGDIR}/dbus-1/system.d/org.freedesktop.DisplayManager.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.freedesktop.DisplayManager.conf
CONF_FILES+=	${EGDIR}/init/lightdm.conf \
		${PKG_SYSCONFDIR}/init/lightdm.conf
CONF_FILES+=	${EGDIR}/lightdm/keys.conf \
		${PKG_SYSCONFDIR}/lightdm/keys.conf
CONF_FILES+=	${EGDIR}/lightdm/lightdm.conf \
		${PKG_SYSCONFDIR}/lightdm/lightdm.conf
CONF_FILES+=	${EGDIR}/lightdm/users.conf \
		${PKG_SYSCONFDIR}/lightdm/users.conf
CONF_FILES+=	${EGDIR}/pam.d/lightdm /etc/pam.d/lightdm
CONF_FILES+=	${EGDIR}/pam.d/lightdm-autologin /etc/pam.d/lightdm-autologin
CONF_FILES+=	${EGDIR}/pam.d/lightdm-greeter /etc/pam.d/lightdm-geeter

RCD_SCRIPTS=		lightdm

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD$

PKGNAME=	mate-core-1.12
CATEGORIES=	meta-pkgs mate

HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	Core packages for MATE desktop environment
LICENSE=	public-domain

META_PACKAGE=	yes

# see http://wiki.mate-desktop.org/status:1.12

DEPENDS+=	mate-common>=${PKGVERSION_NOREV}:../../devel/mate-common
DEPENDS+=	mate-desktop>=${PKGVERSION_NOREV}:../../x11/mate-desktop
DEPENDS+=	libmatekbd>=${PKGVERSION_NOREV}:../../x11/libmatekbd
DEPENDS+=	libmatemixer>=${PKGVERSION_NOREV}:../../audio/libmatemixer
DEPENDS+=	libmateweather>=${PKGVERSION_NOREV}:../../devel/libmateweather
DEPENDS+=	mate-icon-theme>=${PKGVERSION_NOREV}:../../graphics/mate-icon-theme
DEPENDS+=	caja>=${PKGVERSION_NOREV}:../../sysutils/caja
DEPENDS+=	mate-polkit>=${PKGVERSION_NOREV}:../../security/mate-polkit
DEPENDS+=	marco>=${PKGVERSION_NOREV}:../../wm/marco
DEPENDS+=	mate-settings-daemon>=${PKGVERSION_NOREV}:../../sysutils/mate-settings-daemon
DEPENDS+=	mate-session-manager>=${PKGVERSION_NOREV}:../../x11/mate-session-manager
DEPENDS+=	mate-menus>=${PKGVERSION_NOREV}:../../sysutils/mate-menus
DEPENDS+=	mate-panel>=${PKGVERSION_NOREV}:../../x11/mate-panel
DEPENDS+=	mate-backgrounds>=${PKGVERSION_NOREV}:../../graphics/mate-backgrounds
DEPENDS+=	mate-themes>=${PKGVERSION_NOREV}:../../graphics/mate-themes
DEPENDS+=	mate-notification-daemon>=${PKGVERSION_NOREV}:../../sysutils/mate-notification-daemon
DEPENDS+=	mate-control-center>=${PKGVERSION_NOREV}:../../sysutils/mate-control-center
DEPENDS+=	mate-screensaver>=${PKGVERSION_NOREV}:../../x11/mate-screensaver
DEPENDS+=	mate-media>=${PKGVERSION_NOREV}:../../multimedia/mate-media
DEPENDS+=	mate-power-manager>=${PKGVERSION_NOREV}:../../sysutils/mate-power-manager
DEPENDS+=	mate-system-monitor>=${PKGVERSION_NOREV}:../../sysutils/mate-system-monitor

.include "../../mk/bsd.pkg.mk"

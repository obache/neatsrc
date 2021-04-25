# $NetBSD: Makefile,v 1.13 2020/01/18 23:36:13 rillig Exp $

DISTNAME=		xsm-1.0.4
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X Session Manager

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.if exists(/usr/bin/ssh)
CONFIGURE_ARGS+=	--with-rsh=/usr/bin/ssh
.endif

MAKE_FLAGS+=		appdefaultdir=${PREFIX}/lib/X11/app-defaults
INSTALL_MAKE_FLAGS+=	SYSTEM_INIT_DIR=${PREFIX}/share/examples/xsm

MAKE_DIRS+=		${PKG_SYSCONFDIR}/X11/xsm
CONF_FILES+=		share/examples/xsm/system.xsm ${PKG_SYSCONFDIR}/X11/xsm/system.xsm

.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

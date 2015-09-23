# $NetBSD$

DISTNAME=	libpthread-stubs-0.3
CATEGORIES=	devel
MASTER_SITES=	http://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	http://xcb.freedesktop.org/
COMMENT=	Stubs missing from libc for standard pthread functions
LICENSE=	x11

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	pthread-stubs.pc.in

OPSYSVARS+=	CONFIGURE_ENV
CONFIGURE_ENV.NetBSD+=	ac_cv_func_pthread_self=yes
CONFIGURE_ENV.NetBSD+=	ac_cv_func_pthread_exit=yes

.include "../../mk/bsd.pkg.mk"

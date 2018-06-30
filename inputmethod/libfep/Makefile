# $NetBSD$
#

DISTNAME=	libfep-0.1.0
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_GITHUB:=ueno/}
GITHUB_PROJECT=	${PKGBASE}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

HOMEPAGE=	https://github.com/ueno/libskk/
COMMENT=	Library to implement FEP (front end processor) on ANSI terminals
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

PKGCONFIG_OVERRIDE+=	libfep/libfep.pc.in
PKGCONFIG_OVERRIDE+=	libfep-glib/libfep-glib.pc.in

.include "options.mk"

USE_NCURSES=		yes
.include "../../devel/ncurses/buildlink3.mk"
CONFIGURE_ENV+=		NCURSES_CFLAGS=${BUILDLINK_INCDIRS.ncurses:S,^,-I ${BUILDLINK_PREFIX.ncurses}/,:Q}
CONFIGURE_ENV+=		NCURSES_LIBS=${BUILDLINK_LDADD.ncurses}
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

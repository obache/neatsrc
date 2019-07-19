# $NetBSD: Makefile,v 1.72 2019/07/03 17:17:58 sevan Exp $

DISTNAME=	libgpg-error-1.36
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG:=libgpg-error/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.gnupg.org/
COMMENT=	Definitions of common error values for all GnuPG components
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
INFO_FILES=		yes
TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
CONFIGURE_ENV+=		CC_FOR_BUILD=${NATIVE_CC:Q}
.else
CONFIGURE_ENV+=		CC_FOR_BUILD=${CC:Q}\ ${CFLAGS:M*:Q}
.endif

.if !empty(MACHINE_PLATFORM:MDarwin-8.*-powerpc)
CFLAGS+= 	-D__DARWIN_UNIX03
.endif

.if !empty(MACHINE_PLATFORM:MSunOS-5.10-*)
LIBS+=	-lrt
.endif

SUBST_CLASSES+=		add-rpath
SUBST_STAGE.add-rpath=	pre-configure
SUBST_FILES.add-rpath=	configure
SUBST_SED.add-rpath=	'/GPG_ERROR_CONFIG_LIBS="/s|-L\([^ 	]*\)|${COMPILER_RPATH_FLAG}\1 -L\1|g'

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

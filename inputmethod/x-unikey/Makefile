# $NetBSD$

DISTNAME=	x-unikey-1.0.4
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=unikey/}
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	http://www.unikey.org/linux.php
COMMENT=	Unikey Input Method for X-Window
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

SUBST_CLASSES+=			kill-install
SUBST_STAGE.kill-install=	pre-configure
SUBST_FILES.kill-install=	src/xim/Makefile.in
SUBST_SED.kill-install=		-e 's,./install.sh,${TRUE},g'

.include "options.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD$

DISTNAME=	mate-icon-theme-faenza-1.12.0
CATEGORIES=	graphics mate
MASTER_SITES=	http://pub.mate-desktop.org/releases/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	Faenza and Faience icon themes for MATE desktop
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	mate-common>=${PKGVERSION_NOREV:R}:../../devel/mate-common

GNU_CONFIGURE=	yes
USE_LANGUAGES=	#empty
USE_TOOLS+=	pax autoconf automake bash
CONFIG_SHELL=	bash
CONFIGURE_SCRIPT=	autogen.sh

EXTRACT_USING=	gtar

ICON_THEMES=	yes

.include "../../mk/bsd.pkg.mk"

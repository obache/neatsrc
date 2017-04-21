# $NetBSD: Makefile,v 1.25 2015/12/29 04:54:39 dholland Exp $

DISTNAME=	xcolorsel-1.1a-src
PKGNAME=	xcolorsel-1.1a
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Browse and select named X colors from rgb.txt

WRKSRC=		${WRKDIR}/xcolorsel
USE_IMAKE=	yes

USE_X11_RGB_TXT=	yes

SUBST_CLASSES+=		xcolorsel
SUBST_STAGE.xcolorsel=		pre-configure
SUBST_MESSAGE.xcolorsel=	Fixing hard-coded paths.
SUBST_FILES.xcolorsel=		RgbText.c
SUBST_SED.xcolorsel+=	-e 's,/usr/lib/X11/rgb.txt,${PKG_RGB_TXT_PATH},'

.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

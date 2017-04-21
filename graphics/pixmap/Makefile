# $NetBSD: Makefile,v 1.35 2013/01/19 21:04:43 riastradh Exp $

DISTNAME=		pixmap2.6
PKGNAME=		pixmap-2.6.4
PKGREVISION=		8
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/pixmap/}

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		pixmap_2.6.patch1.gz \
			pixmap_2.6.patch2.gz \
			pixmap_2.6.patch3.gz \
			pixmap_2.6.patch4.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Pixmap editor based on XPM library

WRKSRC=			${WRKDIR}/pixmap
USE_IMAKE=		YES
USE_X11_RGB_TXT=	yes

MAKE_ENV+=		LOCAL_LDFLAGS=${LDFLAGS:Q}
MAKE_ENV+=		MOTIFBASE=${MOTIFBASE}

SUBST_CLASSES+=		rgb
SUBST_STAGE.rgb=	pre-configure
SUBST_FILES.rgb=	Imakefile
SUBST_SED.rgb=		-e 's,@RGBTXT@,${PKG_RGB_TXT_PATH},g'

post-extract:
	rm -rf ${WRKSRC}/X11

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

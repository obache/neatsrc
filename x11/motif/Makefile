# $NetBSD: Makefile,v 1.13 2018/03/12 11:15:54 wiz Exp $

DISTNAME=	motif-2.3.7
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=motif/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://motif.ics.com/
COMMENT=		LGPLed Motif toolkit for the X Window System
LICENSE=		gnu-lgpl-v2.1

.include "../../mk/bsd.prefs.mk"

CONFLICTS+=		lesstif-[0-9]* openmotif-[0-9]*

USE_LIBTOOL=		yes
USE_TOOLS+=		flex gmake tbl pkg-config yacc
GNU_CONFIGURE=		yes
USE_X11_RGB_TXT=	yes

CFLAGS.SunOS+=		-Dsun

CONFIGURE_ARGS+= \
		--enable-jpeg --enable-png \
		--with-libjpeg-includes=${JPEGBASE}/include \
		--with-libjpeg-lib=${JPEGBASE}/lib \
		--with-libpng-includes=${BUILDLINK_PREFIX.png}/include \
		--with-libpng-lib=${BUILDLINK_PREFIX.png}/lib \
		--x-libraries=${X11BASE}/lib

CONFIGURE_ARGS+=	--enable-xft
CFLAGS.SunOS+=		-D_POSIX_PTHREAD_SEMANTICS

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
MAKE_FLAGS+=	CROSS_COMPILING=yes CC_FOR_BUILD=${NATIVE_CC:Q} \
    CPPFLAGS_FOR_BUILD=-I${PREFIX}/include
.endif

SUBST_CLASSES+=		rgb
SUBST_STAGE.rgb=	pre-configure
SUBST_FILES.rgb=	lib/Xm/ColorS.c
SUBST_SED.rgb=		-e 's,/usr/lib/X11/rgb.txt,${PKG_RGB_TXT_PATH},'

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

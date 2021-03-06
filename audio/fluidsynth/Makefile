# $NetBSD: Makefile,v 1.50 2021/05/13 09:44:28 nia Exp $

DISTNAME=	fluidsynth-2.2.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=FluidSynth/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fluidsynth.org/
COMMENT=	Software synthesizer based on SoundFont2
LICENSE=	gnu-lgpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DMAN_INSTALL_DIR=${PREFIX}/${PKGMANDIR}/man1
CMAKE_ARGS+=	-DLIB_SUFFIX=""
CMAKE_ARGS+=	-Denable-framework=OFF
CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=TRUE

PKGCONFIG_OVERRIDE=	fluidsynth.pc.in

LDFLAGS.SunOS+=		-lsocket

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
LDFLAGS+=		${LIBOSSAUDIO}
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correcting the path to the OSS device.
SUBST_FILES.oss+=	src/drivers/fluid_oss.c
SUBST_SED.oss+=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_SED.oss+=		-e "s,/dev/midi,${DEVOSSMIDI},g"
.endif

# mlock on SunOS has a caddr_t argument rather than void *
BUILDLINK_TRANSFORM+=	rm:-Werror=incompatible-pointer-types

.include "options.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
CMAKE_ARGS+=	-DREADLINE_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.editlinereadline}/include
.if ${READLINE_TYPE} == "editline"
SUBST_CLASSES+=		readline
SUBST_STAGE.readline=	pre-configure
SUBST_MESSAGE.readline=	Adjust find_library name for readline
SUBST_FILES.readline+=	cmake_admin/FindREADLINE.cmake
SUBST_SED.readline+=	-e "s, NAMES readline , NAMES edit ,g"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

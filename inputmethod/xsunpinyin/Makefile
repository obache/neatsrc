# $NetBSD$

.include "../../inputmethod/sunpinyin/Makefile.common"

PKGNAME:=	x${PKGNAME}

COMMENT=	Standalone XIM server for SunPinyin input methord

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config scons

BUILD_DIRS+=	wrapper/xim

do-build:
	cd ${WRKSRC} && cd ${BUILD_DIRS} && \
		${SETENV} ${MAKE_ENV} \
		${SCONS} --prefix=${PREFIX}

do-install:
	cd ${WRKSRC} && cd ${BUILD_DIRS} && \
		${SETENV} ${MAKE_ENV} \
		${SCONS} install --prefix=${PREFIX} --install-sandbox=${DESTDIR}

.include "../../inputmethod/sunpinyin/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

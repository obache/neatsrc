# $NetBSD$

.include "../../inputmethod/sunpinyin/Makefile.common"

PKGNAME:=	scim-${PKGNAME}

COMMENT=	SunPinyin wrappr for SCIM

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config scons

BUILD_DIRS+=	wrapper/scim

do-build:
	cd ${WRKSRC} && cd ${BUILD_DIRS} && \
		${SETENV} ${MAKE_ENV} \
		${SCONS} --prefix=${PREFIX}

do-install:
	cd ${WRKSRC} && cd ${BUILD_DIRS} && \
		${SETENV} ${MAKE_ENV} \
		${SCONS} install --prefix=${PREFIX} --install-sandbox=${DESTDIR}

.include "../../inputmethod/scim/buildlink3.mk"
.include "../../inputmethod/sunpinyin/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

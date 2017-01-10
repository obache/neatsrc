# $NetBSD$

.include "../../inputmethod/sunpinyin/Makefile.common"

PKGNAME:=	ibus-${PKGNAME}

COMMENT=	SunPinyin wrappr for IBus

USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config scons

BUILD_DIRS+=	wrapper/ibus

do-build:
	cd ${WRKSRC} && cd ${BUILD_DIRS} && \
		${SETENV} ${MAKE_ENV} \
		${SCONS} --prefix=${PREFIX}

do-install:
	cd ${WRKSRC} && cd ${BUILD_DIRS} && \
		${SETENV} ${MAKE_ENV} \
		${SCONS} install --prefix=${PREFIX} --install-sandbox=${DESTDIR}

.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../inputmethod/sunpinyin/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

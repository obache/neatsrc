# $NetBSD$

DISTNAME=	ibus-sunpinyin-2.0.3
CATEGORIES=	inputmethod chinese
MASTER_SITES=	https://sunpinyin.googlecode.com/files/

HOMEPAGE=	http://sunpinyin.org/
COMMENT=	SunPinyin wrappr for IBus
LICENSE=	gnu-lgpl-v2.1 OR cddl-1.0

USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config scons

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

# $NetBSD$

DISTNAME=	sunpinyin-2.0.3
CATEGORIES=	inputmethod chinese
MASTER_SITES=	https://sunpinyin.googlecode.com/files/
DISTFILES_VARS+=opengram
DISTFILES.opengram=	dict.utf8-20131212.tar.bz2	\
			lm_sc.t3g.arpa-20121025.tar.bz2
SITES.opengram=	${MASTER_SITE_SOURCEFORGE:=open-gram/}

HOMEPAGE=	http://sunpinyin.org/
COMMENT=	SLM (Statistical Language Model) based input method engine
LICENSE=	gnu-lgpl-v2.1 OR cddl-1.0

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config scons

post-extract:
	${TOUCH} ${WRKSRC}/raw/lm_sc.t3g.arpa.tar.bz2
	${TOUCH} ${WRKSRC}/raw/dict.utf8.tar.bz2
	${TOUCH} ${WRKSRC}/raw/stamp-lm
	${TOUCH} ${WRKSRC}/raw/stamp-dict
	${MV} -f ${WRKDIR}/dict.utf8 ${WRKSRC}/raw/
	${TOUCH} ${WRKSRC}/raw/dict.utf8
	${MV} -f ${WRKDIR}/lm_sc.t3g.arpa ${WRKSRC}/raw/
	${TOUCH} ${WRKSRC}/raw/lm_sc.t3g.arpa

do-build:
	cd ${WRKSRC} && cd ${BUILD_DIRS} && \
		${SETENV} ${MAKE_ENV} \
		${SCONS} --prefix=${PREFIX}

do-install:
	cd ${WRKSRC} && cd ${BUILD_DIRS} && \
		${SETENV} ${MAKE_ENV} \
		${SCONS} install --prefix=${PREFIX} --install-sandbox=${DESTDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD$

.include "Makefile.common"

DISTFILES_VARS+=opengram
DISTFILES.opengram=	dict.utf8-20131214.tar.bz2	\
			lm_sc.3gm.arpa-20140820.tar.bz2
SITES.opengram=	${MASTER_SITE_SOURCEFORGE:=open-gram/}

COMMENT=	SLM (Statistical Language Model) based input method engine
LICENSE=	gnu-lgpl-v2.1 OR cddl-1.0

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake:run pkg-config scons pod2man

pre-build:
	${RUN}cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} \
		${SCONS} --prefix=${PREFIX}
	${LN} -sf ${WRKSRC}/src/slmpack ${TOOLS_DIR}/bin/slmpack
	${LN} -sf ${WRKSRC}/src/slmthread ${TOOLS_DIR}/bin/slmthread
	${LN} -sf ${WRKSRC}/src/tslmendian ${TOOLS_DIR}/bin/tslmendian
	${LN} -sf ${WRKSRC}/src/genpyt ${TOOLS_DIR}/bin/genpyt

BUILD_DIRS=	src
MAKE_FILE=	../doc/SLM-inst.mk

pre-install:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} \
		${SCONS} install --prefix=${PREFIX} --install-sandbox=${DESTDIR}

REPLACE_PYTHON=	python/*.py

post-extract:
	cd ${WRKSRC}/src && ${TOUCH} ${DISTFILES.opengram}
	${MV} -f ${WRKDIR}/dict.utf8 ${WRKSRC}/src/
	${TOUCH} ${WRKSRC}/src/dict.utf8
	${MV} -f ${WRKDIR}/lm_sc.3gm.arpa ${WRKSRC}/src/
	${TOUCH} ${WRKSRC}/src/lm_sc.3gm.arpa

REPLACE_INTERPRETER+=	gmake
REPLACE.gmake.old=	.*@MAKE@[^ ]*
REPLACE.gmake.new=	${GMAKE}
REPLACE_FILES.gmake=	src/sunpinyin-dictgen.mk.in

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_FILES.manpath=	SConstruct
SUBST_SED.manpath=	-e 's,share/man,${PKGMANDIR},'

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY=yes
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD$

PKGNAME=	today-2.12
CATEGORIES=	time games
MASTER_SITES=	ftp://ftp.vector.co.jp/pack/dos/personal/calendar/today/
DISTFILES=	td${PKGVERSION_NOREV:S/.//}s.lzh	\
		td${PKGVERSION_NOREV:S/.//}m.lzh

HOMEPAGE=	http://www.red.oit-net.jp/y-mori/soft/today.html
COMMENT=	Tells you what day today is

TOOL_DEPENDS+=	nkf>=2.0:../../converters/nkf
USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin share/examples/today share/today share/doc/today

EXTRACT_DIR=		${WRKDIR}/${PKGNAME_NOREV}
EXTRACT_OPTS_LHA=	qf
post-extract:
	${RUN}cd ${WRKSRC}; \
	for f in unix.lzh tbl.lzh utility.lzh; do \
		${EXTRACTOR} $$f; \
	done
	${RUN}cd ${WRKSRC}; ${LN} -sf makefile.uni Makefile
	${RUN}cd ${WRKSRC}; ${LN} -sf makefile.gcc src/Makefile

BUILD_DIRS=	. src

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	do-configure
SUBST_FILES.prefix=	cunix.h today.cnf
SUBST_VARS.prefix=	PREFIX PKG_SYSCONFDIR

SUBST_CLASSES+=		cconv
SUBST_STAGE.cconv=	pre-patch
SUBST_MESSAGE.cconv=	Converting kanji code
SUBST_FILES.cconv=	*.c *.h *.doc *.rc *.rh makefile.* *.tbl
SUBST_FILES.cconv+=	src/*.c src/makefile.*
SUBST_FILTER_CMD.cconv=	${LOCALBASE}/bin/nkf -Sed

SUBST_CLASSES+=		version
SUBST_STAGE.version=	post-configure
SUBST_FILES.version=	version.c
SUBST_VARS.version=	MACHINE_PLATFORM LOGNAME CC_VERSION

MAKE_FLAGS+=	BASEDIR=${PREFIX}
CFLAGS.NetBSD=	-Dunix

CONF_FILES+=	${PREFIX}/share/examples/today/today.cnf \
		${PKG_SYSCONFDIR}/today.cnf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/today ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/dayinfo ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/calendar ${DESTDIR}${PREFIX}/bin/calendar-today
	${INSTALL_DATA} ${WRKSRC}/today.cnf ${DESTDIR}${PREFIX}/share/examples/today
	${INSTALL_DATA} ${WRKSRC}/*.tbl ${DESTDIR}${PREFIX}/share/today
	${INSTALL_DATA} ${WRKSRC}/today.doc ${DESTDIR}${PREFIX}/share/doc/today

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

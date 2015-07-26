# $NetBSD$
#
DISTNAME=	cde-src-2.2.3
PKGNAME=	${DISTNAME:S/-src-/-/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cdesktopenv/}

HOMEPAGE=	http://cdesktopenv.sourceforge.net/
COMMENT=	Common Desktop Environment
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=     bison bdftopcf mkfontdir ksh awk:run sh:run xrdb:run
BUILD_TARGET=	World

MAKE_JOBS_SAFE=	no

DEPENDS+= ast-ksh-[0-9]*:../../shells/ast-ksh

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV}

PKG_SYSCONFSUBDIR=	dt

CFLAGS+=		-I${X11BASE}/include/X11

IMAKE_DEFINES+=		-DCplusplusCmd=${CXX}
IMAKE_DEFINES+=		-DLibraryCplusplusCmd=${CXX}
IMAKE_DEFINES+=		-DX11ProjectRoot=${X11BASE}
IMAKE_DEFINES+=		-DProjectRoot=${PREFIX}
IMAKE_DEFINES+=		-DTopMotifInclude=${MOTIFBASE}/include
IMAKE_DEFINES+=		-DCDEProjectRoot=${PREFIX}/dt
IMAKE_DEFINES+=		-DCdeInstallationTop=${PREFIX}/dt
IMAKE_DEFINES+=		-DCdeConfigurationTop=${PKG_SYSCONFDIR}
IMAKE_DEFINES+=		-DCdeLogfileTop=${VARBASE}/dt
#IMAKE_DEFINES+=		-DTclLibrary=${BUILDLINK_PREFIX.tcl}/lib
IMAKE_DEFINES+=		-DUseInstalledX11=YES
#IMAKE_DEFINES+=	-DKornShell=${TOOLS_PATH.ksh}
IMAKE_DEFINES+=		-DDtKornShell=${PREFIX}/dt/bin/dtksh
BUILD_MAKE_FLAGS+=	BOOTSTRAPCFLAGS=${CFLAGS:Q}
BUILD_MAKE_FLAGS+=	IMAKE_DEFINES=${IMAKE_DEFINES:Q}
#MAKE_ENV+=		MFLAGS=KORNSHELL=${TOOLS_PATH.ksh}

BUILD_DEFS+=		VARBASE
OWN_DIRS+=		${VARBASE}/dt
OWN_DIRS+=		${VARBASE}/dt/tmp
OWN_DIRS+=		${VARBASE}/dt/appconfig/appmanager
.for i in appmanager help icons types
.  for j in C de_DE.ISO8859-1 es_ES.ISO8859-1 fr_FR.ISO8859-1 it_IT.ISO8859-1
OWN_DIRS+=		${PKG_SYSCONFDIR}/appconfig/${i}/${j}
.  endfor
.endfor
OWN_DIRS+=		${PKG_SYSCONFDIR}/config
OWN_DIRS+=		${PKG_SYSCONFDIR}/config/Xsession.d
BUILDLINK_PASSTHRU_RPATHDIRS+= ${PREFIX}/dt/lib

SUBST_CLASSES+=		destdir
SUBST_STAGE.destdir=	pre-configure
SUBST_FILES.destdir=	admin/IntegTools/dbTools/installCDE.src
SUBST_SED.destdir=	-e 's,-D / ,-D $$DESTDIR ,'

SUBST_CLASSES+=		dtksh
SUBST_STAGE.dtksh=	pre-configure
SUBST_FILES.dtksh=	programs/dthelp/dthelpgen/dthelpgen.dtsh
SUBST_SED.dtksh=	-e 's,/usr/dt/bin/dtksh,${PREFIX}/dt/bin/dtksh,g'

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	databases/*.udb databases/*.src
SUBST_FILES.prefix+=	lib/DtHelp/Print.c
SUBST_FILES.prefix+=	lib/tt/slib/mp_typedb.C
SUBST_FILES.prefix+=	osf/xmbind/0040.xmbind
SUBST_FILES.prefix+=	programs/dtappbuilder/src/ab/cgen_utils.c
SUBST_FILES.prefix+=	programs/dtappbuilder/src/abmf/make_file.c
SUBST_FILES.prefix+=	programs/dtcreate/cmnrtns.c
SUBST_FILES.prefix+=	programs/dtcreate/dtcreate.h
SUBST_FILES.prefix+=	programs/dtdocbook/doc2sdl/dtdocbook
SUBST_FILES.prefix+=	programs/dthelp/dthelpgen/dthelpgen.dtsh
SUBST_FILES.prefix+=	programs/dthelp/dthelpprint/Initialize.c
SUBST_FILES.prefix+=	programs/dthelp/dthelpprint/dthelpprint.sh
SUBST_FILES.prefix+=	programs/dtimsstart/ximspath.h
SUBST_FILES.prefix+=	programs/dtinfo/dtinfo/src/Agents/AddLibraryAgentMotif.C
SUBST_FILES.prefix+=	programs/dtinfo/dtinfo/src/Managers/EnvMgr.C
SUBST_FILES.prefix+=	programs/dtimsstart/0020.dtims.src
SUBST_FILES.prefix+=	programs/dtimsstart/conf/start.conf
SUBST_FILES.prefix+=	programs/dtlogin/vg.h
SUBST_FILES.prefix+=	programs/dtprintinfo/UI/DtApp.C
SUBST_FILES.prefix+=	programs/dtprintinfo/UI/DtFindSet.C
SUBST_FILES.prefix+=	programs/dtprintinfo/UI/DtPrinterIcon.C
SUBST_FILES.prefix+=	programs/dtprintinfo/libUI/MotifUI/MotifUI.C
SUBST_FILES.prefix+=	programs/dtsearchpath/dtappg/dtappgather.C
SUBST_FILES.prefix+=	programs/dtsearchpath/dtsp/InfoLibSearchPath.C
SUBST_FILES.prefix+=	programs/dtsearchpath/libCliSrv/Environ.C
SUBST_FILES.prefix+=	programs/dtstyle/Backdrop.c
SUBST_FILES.prefix+=	programs/dtstyle/ColorFile.c
SUBST_FILES.prefix+=	programs/dtstyle/ColorMain.c
SUBST_FILES.prefix+=	programs/dtstyle/I18nEnv.c
SUBST_FILES.prefix+=	programs/dtstyle/Main.c
SUBST_FILES.prefix+=	programs/dtstyle/dtstyle.man
SUBST_FILES.prefix+=	programs/dtudcfonted/include/udccom.h
SUBST_FILES.prefix+=	programs/dtudcfonted/resource/Dtudcfonted
SUBST_FILES.prefix+=	programs/dtwm/WmInitWs.c
SUBST_FILES.prefix+=	programs/ttsnoop/ttsnoop_stubs.C.src
SUBST_FILES.prefix+=	programs/tttypes/dtinfo.ptype
SUBST_FILES.prefix+=	programs/tttypes/dtinfo_start.ptype
SUBST_FILES.prefix+=	programs/types/datatypes.dt.src
SUBST_FILES.prefix+=	programs/types/develop.dt.src
SUBST_FILES.prefix+=	programs/types/dt.dt.src
SUBST_FILES.prefix+=	programs/types/dtcm.dt
SUBST_FILES.prefix+=	programs/types/dtfile.dt.src
SUBST_FILES.prefix+=	programs/types/dthelp.dt.src
SUBST_FILES.prefix+=	programs/types/dthelptag.dt.src
SUBST_FILES.prefix+=	programs/types/dthelpprint.dt.src
SUBST_FILES.prefix+=	programs/types/dtinfo.dt.src
SUBST_FILES.prefix+=	programs/types/dtmail.dt
SUBST_FILES.prefix+=	programs/types/dtpad.dt.src
SUBST_FILES.prefix+=	programs/types/uxstd.dt.src
SUBST_FILES.prefix+=	programs/types/xclients.dt.src
SUBST_FILES.prefix+=	doc/*/help/common/DesktopIntro.hf
SUBST_FILES.prefix+=	doc/*/help/common/Desktop.hf
SUBST_SED.prefix+=	-e 's,/usr/dt,${PREFIX}/dt,g'
SUBST_SED.prefix+=	-e 's,/etc/dt/,${PKG_SYSCONFDIR}/,g'
SUBST_SED.prefix+=	-e 's,/etc/dt",${PKG_SYSCONFDIR}",g'

SUBST_CLASSES+=		awk
SUBST_STAGE.awk=	pre-configure
SUBST_FILES.awk=	programs/dtlogin/config/Xreset.src
SUBST_SED.awk=		-e 's, /bin/awk , ${AWK} ,g'

SUBST_CLASSES+=		tools
SUBST_STAGE.tools=	pre-configure
SUBST_FILES.tools=	programs/dtimsstart/ximspath.h
SUBST_SED.tools+=	-e 's,/usr/bin/sh,${SH},g'
SUBST_SED.tools+=	-e 's,/usr/bin/cat,${CAT},g'
SUBST_SED.tools+=	-e 's,/usr/bin/X11/xrdb,${TOOLS_PATH.xrdb},g'

SUBST_CLASSES+=		bitmaps
SUBST_STAGE.bitmaps=	pre-configure
SUBST_FILES.bitmaps+=	programs/dtprintinfo/libUI/MotifUI/MotifUI.C
SUBST_SED.bitmaps+=	-e 's,/usr/include/X11/bitmaps/,${X11BASE}/include/X11/bitmaps/,g'

SUBST_CLASSES+=		fontsdir
SUBST_STAGE.fontsdir=	pre-configure
SUBST_FILES.fontsdir+=	programs/dtudcfonted/libfal/Imakefile
SUBST_SED.fontsdir+=	-e 's,/lib/X11/fonts,/share/fonts/X11,g'

RCD_SCRIPTS=		dtlogin

do-install:
	${RUN}cd ${WRKSRC}/admin/IntegTools/dbTools; \
	${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ./installCDE -s ${WRKSRC} \
		-DontRunScripts

# from databases/CDE-RUN.*
SPECIAL_PERMS+=	${PREFIX}/dt/bin/dtprintinfo ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/dt/bin/dtsession ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/dt/bin/dtterm ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/dt/bin/dtapppgather ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/dt/bin/dtmail ${REAL_ROOT_USER} mail 2511
SPECIAL_PERMS+=	${PREFIX}/dt/bin/dtmailpr ${REAL_ROOT_USER} mail 2511

.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
#.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

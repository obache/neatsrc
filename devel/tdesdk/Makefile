# $NetBSD$

TDE_PKGNAME=	tdesdk
CATEGORIES=	devel

COMMENT=	Trinity Desktop Environment [TDE] SDK
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	tqt3-tools>=${TQT3_RELEASE}:../../x11/tqt3-tools

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config flex perl:run bash:run

.include "../../meta-pkgs/tde/Makefile.tde"

CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=TRUE
CMAKE_ARGS+=	-DBUILD_ALL:BOOL=ON

# glibc
CMAKE_ARGS+=	-DBUILD_KMTRACE:BOOL=OFF

.include "options.mk"

REPLACE_PERL+=	scripts/colorsvn
REPLACE_BASH+=	scripts/create_makefile
REPLACE_PERL+=	scripts/cvs-clean
REPLACE_BASH+=	scripts/cvs2dist
REPLACE_PERL+=	scripts/cvsblame
REPLACE_PERL+=	scripts/cvscheck
REPLACE_PERL+=	scripts/cvslastchange
REPLACE_PERL+=	scripts/cxxmetric
REPLACE_PERL+=	tdecachegrind/converters/dprof2calltree
REPLACE_PERL+=	scripts/extend_dmalloc
REPLACE_PERL+=	scripts/extractattr
REPLACE_PERL+=	scripts/extractrc
REPLACE_PERL+=	scripts/fixkdeincludes
REPLACE_PERL+=	scripts/fixuifiles
REPLACE_PYTHON+=tdecachegrind/converters/hotshot2calltree
REPLACE_PERL+=	scripts/includemocs
REPLACE_BASH+=	kapptemplate/kapptemplate.cmake
REPLACE_BASH+=	scripts/kde-build
REPLACE_PYTHON+=scripts/kdelnk2desktop.py
REPLACE_PERL+=	scripts/kdemangen.pl
REPLACE_PERL+=	scripts/licensecheck
REPLACE_BASH+=	scripts/makeobj
REPLACE_PERL+=	tdecachegrind/converters/memprof2calltree
REPLACE_PERL+=	scripts/noncvslist
REPLACE_PERL+=	tdecachegrind/converters/op2calltree
REPLACE_BASH+=	scripts/package_crystalsvg
REPLACE_PERL+=	scripts/png2mng.pl
REPLACE_PHP+=	tdecachegrind/converters/pprof2calltree
REPLACE_PERL+=	scripts/svn-clean
REPLACE_BASH+=	scripts/svn2dist
REPLACE_PERL+=	scripts/svnlastchange
REPLACE_BASH+=	scripts/svnversions
REPLACE_PERL+=	scripts/tdesvn-build
REPLACE_BASH+=	tdeunittest/tdeunittest
REPLACE_PERL+=	tdeunittest/tdeunittest_debughelper
REPLACE_BASH+=	tdeunittest/tdeunittestmod
REPLACE_PYTHON+=scripts/zonetab2pot.py
REPLACE_PERL+=	admin/debianrules
REPLACE_PERL+=	admin/detect-autoconf.pl
REPLACE_PERL+=	admin/nmcheck
REPLACE_PERL+=	cervisia/cervisia-change_repos_list.pl
REPLACE_PERL+=	cervisia/cervisia-normalize_cvsroot.pl
REPLACE_PERL+=	cervisia/change_colors.pl
REPLACE_PERL+=	cervisia/move_repositories.pl

CHECK_INTERPRETER_SKIP+=	bin/pprof2calltree

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/flex/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/tdelibs/buildlink3.mk"
.include "../../x11/tqt3-tools/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

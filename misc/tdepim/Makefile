# $NetBSD$

TDE_PKGNAME=	tdepim
CATEGORIES=	x11

COMMENT=	Trinity Desktop Environment [TDE] pim
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config perl perl:run bash:run

.include "../../meta-pkgs/tde/Makefile.tde"

CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=TRUE
CMAKE_ARGS+=	-DBUILD_ALL:BOOL=TRUE
# used in installed script
CMAKE_ARGS+=	-DPERL:FILEPATH=${PERL5:Q}

.include "options.mk"

REPLACE_PERL+=	kmail/*.pl
REPLACE_PERL+=	tderesources/kolab/upgrade-resourcetype.pl
REPLACE_PERL+=	libkpgp/kpgp-3.1-upgrade-address-data.pl
REPLACE_BASH+=	kmail/*.sh

.include "../../security/gpgme/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../x11/tqt3-tools/buildlink3.mk"
.include "../../x11/tqtinterface/buildlink3.mk"
.include "../../x11/tdelibs/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"

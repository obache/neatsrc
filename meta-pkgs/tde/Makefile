META_PACKAGE=YES

.include "Makefile.tde"

PKGNAME=	trinity-${_TDE_RELEASE}
COMMENT=	Trinity Desktop Environment (CDE) Core Modules

DEPENDS+=	tdelibs-${_TDE_RELEASE}{,nb[0-9]*}:../../x11/tdelibs
DEPENDS+=	tdebase-${_TDE_RELEASE}{,nb[0-9]*}:../../x11/tdebase
DEPENDS+=	tdeaccessibility-${_TDE_RELEASE}{,nb[0-9]*}:../../misc/tdeaccessibility
DEPENDS+=	tdeutils-${_TDE_RELEASE}{,nb[0-9]*}:../../misc/tdeutils
DEPENDS+=	tdemultimedia-${_TDE_RELEASE}{,nb[0-9]*}:../../multimedia/tdemultimedia
DEPENDS+=	tdenetwork-${_TDE_RELEASE}{,nb[0-9]*}:../../net/tdenetwork
DEPENDS+=	tdeadmin-${_TDE_RELEASE}{,nb[0-9]*}:../../misc/tdeadmin
DEPENDS+=	tdeartwork-${_TDE_RELEASE}{,nb[0-9]*}:../../misc/tdeartwork
DEPENDS+=	tdegames-${_TDE_RELEASE}{,nb[0-9]*}:../../games/tdegames
DEPENDS+=	tdetoys-${_TDE_RELEASE}{,nb[0-9]*}:../../games/tdetoys
DEPENDS+=	tdeedu-${_TDE_RELEASE}{,nb[0-9]*}:../../misc/tdeedu
DEPENDS+=	tdegraphics-${_TDE_RELEASE}{,nb[0-9]*}:../../graphics/tdegraphics
DEPENDS+=	tdepim-${_TDE_RELEASE}{,nb[0-9]*}:../../misc/tdepim
DEPENDS+=	tdesdk-${_TDE_RELEASE}{,nb[0-9]*}:../../devel/tdesdk
DEPENDS+=	tdevelop-${_TDE_RELEASE}{,nb[0-9]*}:../../devel/tdevelop
DEPENDS+=	tdeaddons-${_TDE_RELEASE}{,nb[0-9]*}:../../misc/tdeaddons

.include "../../mk/bsd.pkg.mk"

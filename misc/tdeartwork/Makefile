# $NetBSD$

TDE_PKGNAME=	tdeartwork
CATEGORIES=	misc

COMMENT=	Trinity Desktop Environment [TDE] artwork tools
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	tqt3-tools>=${TQT3_RELEASE}:../../x11/tqt3-tools

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
EXTRACT_USING=	gtar

.include "options.mk"

.include "../../meta-pkgs/tde/Makefile.tde"

CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=TRUE
CMAKE_ARGS+=	-DXSCREENSAVER_DIR:PATH=${LOCALBASE}/libexec/xscreensaver
CMAKE_ARGS+=	-DXSCREENSAVER_CONFIG_DIR:PATH=${LOCALBASE}/libexec/xscreensaver/config
CMAKE_ARGS+=	-DBUILD_ALL:BOOL=ON

post-extract:
.for d in 16 32
.  for a in kbabel ktimemon
	${RM} -f ${WRKSRC}/IconThemes/locolor/${d}x${d}/apps/${a}.png
.  endfor
.endfor

.include "../../graphics/libart/buildlink3.mk"

.include "../../x11/tdelibs/buildlink3.mk"
.include "../../x11/tdebase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

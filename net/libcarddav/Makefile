# $NetBSD$

TDE_PKGNAME=		libcarddav
TDE_SUBDIR=		dependencies
CATEGORIES=		net

HOMEPAGE=		https://www.trinitydesktop.org/relatedprojects.php
COMMENT=		CardDAV access library
LICENSE=		gnu-gpl-v3

USE_CMAKE=		YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE=	src/libcarddav.pc.cmake

CMAKE_ARGS+=		-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=TRUE

.include "../../meta-pkgs/tde/Makefile.tde"

.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

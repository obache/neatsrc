# $NetBSD$

TDE_PKGNAME=		libcaldav
TDE_SUBDIR=		dependencies
CATEGORIES=		net

HOMEPAGE=		https://www.trinitydesktop.org/relatedprojects.php
COMMENT=		CalDAV access library
LICENSE=		gnu-gpl-v3

USE_CMAKE=		YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE=	src/libcaldav.pc.cmake

CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=ON

.include "../../meta-pkgs/tde/Makefile.tde"

.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.9 2020/06/12 14:31:12 ryoon Exp $

TDE_PKGNAME=		libart-lgpl
TDE_SUBDIR=		dependencies
PKGNAME=		libart-${_TDE_RELEASE}
CATEGORIES=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.levien.com/libart/
COMMENT=		High-performance 2D graphics library
LICENSE=		gnu-lgpl-v2

USE_CMAKE=		YES
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE=	libart-2.0.pc.in

.include "../../meta-pkgs/tde/Makefile.tde"

.include "../../mk/bsd.pkg.mk"

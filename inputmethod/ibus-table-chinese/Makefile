# $NetBSD: Makefile,v 1.14 2017/08/16 21:22:13 wiz Exp $
#

DISTNAME=	ibus-table-chinese-1.8.3
CATEGORIES=	inputmethod chinese
MASTER_SITES=	-https://github.com/definite/ibus-table-chinese/archive/${PKGVERSION_NOREV}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ibus/ibus/wiki
COMMENT=	Chinese tables for IBus-Table
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DCMAKE_FEDORA_ENABLE_FEDORA_BUILD=0

.include "../../devel/cmake-fedora/buildlink3.mk"
.include "../../inputmethod/ibus-table/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

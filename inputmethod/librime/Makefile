# $NetBSD: Makefile,v 1.23 2021/01/01 08:24:49 ryoon Exp $

DISTNAME=	librime-1.7.0
CATEGORIES=	inputmethod chinese
MASTER_SITES=	-https://github.com/rime/librime/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rime.im/
COMMENT=	Rime input method engine
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	rime.pc.in

.include "options.mk"

CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=TRUE

.include "../../converters/opencc/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/leveldb/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/capnproto/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/yaml-cpp/buildlink3.mk"
.include "../../textproc/marisa/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.14 2018/03/07 11:57:31 wiz Exp $

DISTNAME=	rime-1.2.9
PKGNAME=	lib${DISTNAME}
CATEGORIES=	inputmethod chinese
MASTER_SITES=	https://github.com/rime/librime/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rime.im/
COMMENT=	Rime input method engine
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/librime-${DISTNAME}
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	rime.pc.in

.include "options.mk"

.include "../../converters/opencc/buildlink3.mk"
.include "../../databases/leveldb/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/google-glog/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/yaml-cpp/buildlink3.mk"
.include "../../textproc/marisa/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

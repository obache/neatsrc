# $NetBSD$

DISTNAME=	libgooglepinyin-0.1.2
CATEGORIES=	inputmethod chinese
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/libgooglepinyin/
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	https://code.google.com/archive/p/libgooglepinyin/
COMMENT=	Fork from google pinyin on android
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	data/googlepinyin.pc.in

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

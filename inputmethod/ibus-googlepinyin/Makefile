# $NetBSD$

DISTNAME=	ibus-googlepinyin-0.1.2
CATEGORIES=	inputmethod chinese
MASTER_SITES=	https://libgooglepinyin.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	https://code.googlecode.com/p/libgooglepinyin/
COMMENT=	libgooglepinyin wrapper for ibus
LICENSE=	gnu-gpl-v2

DEPENDS+=	ibus-[0-9]*:../../inputmethod/ibus
DEPENDS+=	libgooglepinyin-[0-9]*:../../inputmethod/libgooglepinyin
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

WRKSRC=		${WRKDIR}/ibus-googlepinyin
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	CMakeLists.txt
SUBST_SED.prefix=	-e 's,IBUS_PREFIX /usr,IBUS_PREFIX ${LOCALBASE},'

SUBST_CLASSES+=		pinyindir
SUBST_STAGE.pinyindir=	pre-configure
SUBST_FILES.pinyindir=	googlepinyin.py
SUBST_SED.pinyindir=	-e 's,/usr/share,${LOCALBASE}/share,'
SUBST_SED.pinyindir+=	-e 's,/usr/lib,${LOCALBASE}/lib,'

REPLACE_PYTHON+=	googlepinyin.py opencc.py main.py

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"

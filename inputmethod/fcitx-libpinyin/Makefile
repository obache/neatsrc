# $NetBSD$

PKGNAME=	fcitx-libpinyin-0.3.3
DISTNAME=	${PKGNAME_NOREV}_dict
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://download.fcitx-im.org/fcitx-libpinyin/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://fcitx-im.org/
COMMENT=	Libpinyin Wrapper for Fcitx
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

ICON_THEMES=	yes

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libpinyin/buildlink3.mk"
.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

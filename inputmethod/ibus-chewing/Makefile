# $NetBSD: Makefile,v 1.62 2019/07/21 22:25:09 wiz Exp $
#

DISTNAME=	ibus-chewing-1.6.1
PKGREVISION=	9
CATEGORIES=	inputmethod chinese
MASTER_SITES=	-https://github.com/definite/ibus-chewing/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ibus/ibus/wiki
COMMENT=	Chewing engine for IBus input platform
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=		gob2>=2.0.16:../../devel/gob2

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt pkg-config
TOOLS_NOOP+=		msgmerge xgettext

#BUILD_TARGET=	all translations

TEST_TARGET=	test

.include "../../devel/glib2/schemas.mk"

.include "../../devel/cmake-fedora/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../inputmethod/libchewing/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

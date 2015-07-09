# $NetBSD$

DISTNAME=	fcitx-handwriting-0.1.1
CATEGORIES=	inputmethod
MASTER_SITES=	https://fcitx-handwriting.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	https://code.googlecode.com/p/fcitx-handwriting/
COMMENT=	Handwrite recognizer for Fcitx
LICENSE=	gnu-gpl-v3

DEPENDS+=	zinnia-tomoe-[0-9]*:../../inputmethod/zinnia-tomoe

FIND_PREFIX:=	ZINNIA_TOMOE_DIR=zinnia-tomoe
.include "../../mk/find-prefix.mk"

WRKSRC=		${WRKDIR}/fcitx-handwriting
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		model_dir
SUBST_STAGE.model_dir=	pre-configure
SUBST_FILES.model_dir=	src/stroke.h
SUBST_SED.model_dir=	-e 's,/usr/lib/zinnia,${ZINNIA_TOMOE_DIR}/lib/zinnia,'

.include "../../inputmethod/zinnia/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD$

DISTNAME=	ibus-libzhuyin-1.9.1
CATEGORIES=	inputmethod chinese
#MASTER_SITES=	https://github.com/libzhuyin/ibus-libzhuyin/releases/download/${PKGVERSION_NOREV}/
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libzhuyin/}

HOMEPAGE=	https://github.com/libzhuyin/ibus-libzhuyin/
COMMENT=	New Zhuyin engine based on libzhuyin for IBus
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake msgfmt pkg-config intltool
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

.include "options.mk"

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

.if (!empty(PKGSRC_COMPILER:Mgcc) && (empty(CC_VERSION:Mgcc-[0-3].*) && empty(CC_VERSION:Mgcc-4.[0-3].*))) || !empty(PKGSRC_COMPILER:Mclang)
CONFIGURE_ARGS+=	--disable-boost
.else
CONFIGURE_ARGS+=	--enable-boost
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-headers}
.include "../../devel/boost-headers/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../textproc/libpinyin/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../mk/bsd.pkg.mk"

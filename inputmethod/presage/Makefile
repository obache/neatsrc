# $NetBSD$

DISTNAME=	presage-0.9.1
CATEGORIES=	inputmethod textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=presage/}

HOMEPAGE=	https://presage.sourceforge.io/
COMMENT=	Intelligent predicative text entry system
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--disable-gpresagemate
CONFIGURE_ARGS+=	--disable-gprompter
CONFIGURE_ARGS+=	--disable-python-binding
CONFIGURE_ENV+=		PYTHON=:
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/${PKGBASE}

CONF_FILES+=	share/examples/${PKGBASE}/presage.xml ${PKG_SYSCONFDIR}/presage.xml

.include "options.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

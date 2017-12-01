# $NetBSD: Makefile,v 1.23 2017/11/30 16:45:27 adam Exp $

DISTNAME=	ibus-array-release-0.1.2
PKGNAME=	${DISTNAME:S/-release-/-/}
PKGREVISION=	1
CATEGORIES=	inputmethod chinese
MASTER_SITES=	-https://github.com/lexical/ibus-array/archive/release-${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lexical/ibus-array/
COMMENT=	Array 30 Input Method for iBus
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=	gmake pkg-config automake autoconf autopoint msgfmt msgmerge

pre-configure:
	${RUN}cd ${WRKSRC};${PKGSRC_SETENV} ${CONFIGURE_ENV} ./autogen.sh

SUBST_CLASSES+=		epython
SUBST_STAGE.epython=	pre-configure
SUBST_FILES.epython=	setup/ibus-setup-array.in
SUBST_SED.epython=	-e 's;exec python;exec ${PYTHONBIN};g'

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"

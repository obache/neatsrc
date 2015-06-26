# $NetBSD: Makefile,v 1.7 2014/04/21 15:35:27 wiz Exp $

DISTNAME=	xdg-utils-1.1.0-rc3
PKGNAME=	${DISTNAME:S/-rc/rc/}
CATEGORIES=	sysutils
MASTER_SITES=	http://people.freedesktop.org/~rdieter/xdg-utils/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://portland.freedesktop.org/
COMMENT=	Tools to assist applications with various desktop integration tasks
LICENSE=	mit

TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
TOOL_DEPENDS+=	{lynx-[0-9]*,w3m-[0-9]*,links-[0-9]*}:../../www/lynx

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake bash:run gsed:run

SUBST_CLASSES+=		gsed
SUBST_FILES.gsed=	scripts/xdg-*
SUBST_STAGE.gsed=	post-build
SUBST_MESSAGE.gsed=	Use GNU sed instead of sed.
SUBST_SED.gsed+=	-e "s,sed ,${TOOLS_PATH.gsed} ,g"

SUBST_CLASSES+=		xdgdir
SUBST_FILES.xdgdir=	scripts/xdg-*
SUBST_STAGE.xdgdir=	pre-configure
SUBST_MESSAGE.xdgdir=	Insert our XDG_*_DIR to the default path.
SUBST_SED.xdgdir+=	-e 's,/usr/local/share/:,${PREFIX}/share/:&,g'
SUBST_SED.xdgdir+=	-e 's,/usr/local/share:,${PREFIX}/share:&,g'
SUBST_SED.xdgdir+=	-e 's,/etc/xdg,${PKG_SYSCONFDIR}/xdg,g'

# "foo > /dev/null 2> /dev/null" gives "foo: not found" with NetBSD's sh
REPLACE_BASH+=	scripts/xdg-*.in
REPLACE_BASH+=	tests/testrun

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"

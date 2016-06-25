# $NetBSD: Makefile,v 1.9 2016/06/13 21:40:22 youri Exp $

DISTNAME=	xdg-utils-1.1.1
PKGNAME=	${DISTNAME:S/-rc/rc/}
CATEGORIES=	misc
MASTER_SITES=	http://portland.freedesktop.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://portland.freedesktop.org/
COMMENT=	Tools to assist applications with various desktop integration tasks
LICENSE=	mit

TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
TOOL_DEPENDS+=	{lynx-[0-9]*,w3m-[0-9]*,links-[0-9]*}:../../www/lynx

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	bash:run gmake gsed:run

SUBST_CLASSES+=		gsed
SUBST_FILES.gsed=	scripts/xdg-*.in
SUBST_STAGE.gsed=	pre-configure
SUBST_MESSAGE.gsed=	Use GNU sed instead of sed.
SUBST_SED.gsed+=	-e "s, sed , ${TOOLS_PATH.gsed} ,g"
SUBST_SED.gsed+=	-e "s,|sed ,|${TOOLS_PATH.gsed} ,g"

SUBST_CLASSES+=		xdgdir
SUBST_FILES.xdgdir=	scripts/xdg-*.in
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

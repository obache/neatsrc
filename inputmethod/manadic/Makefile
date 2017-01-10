# $NetBSD$
#

DISTNAME=	manadic-0.1.4
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_OSDN:=shinji/15963/}
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	http://osdn.jp/projects/shinji/
COMMENT=	Dictionary for Mana

BUILD_DEPENDS+=	mana-[0-9]*:../../inputmethod/mana

GNU_CONFIGURE=	yes
USE_LANGUAGES=	#empty

CONFIGURE_ARGS+=	--with-chasenrc-path=${DESTDIR}${PREFIX}/share/examples/manadic

CONF_FILES+=	${PREFIX}/share/examples/manadic/manarc	\
		${PKG_SYSCONFDIR}/manarc

INSTALLATION_DIRS+=	${PREFIX}/share/examples/manadic

MAKE_JOBS_SAFE=no

.include "../../mk/bsd.pkg.mk"

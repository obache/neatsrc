# $NetBSD$
#

DISTNAME=	mana-0.2.1
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_OSDN:=shinji/20514/}
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	http://osdn.jp/projects/shinji/
COMMENT=	Japanese Kana-Kanji conversion engine with Hidden Markov Model
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

MAKE_FLAGS+=	CFLAGS="" LDFLAGS=""

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	mana/config.ml
SUBST_SED.path=		-e 's;/usr/local/src/misc/mana/trunk;${PREFIX}/share;'

INSTALLATION_DIRS+=	${PREFIX}/share/mana

post-install:
	${INSTALL_DATA}	${WRKSRC}/mana/mana-prelude.scm ${DESTDIR}${PREFIX}/share/mana

MAKE_JOBS_SAFE=no

.include "../../databases/gdbm/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocaml-findlib+=	build
.include "../../devel/ocaml-findlib/buildlink3.mk"
BUILDLINK_DEPMETHOD.camlp4+=	build
.include "../../lang/camlp4/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocaml+=	build
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

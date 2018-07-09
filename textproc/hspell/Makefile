# $NetBSD$

DISTNAME=	hspell-1.4
CATEGORIES=	textproc
MASTER_SITES=	http://hspell.ivrix.org.il/

HOMEPAGE=	http://hspell.ivrix.org.il/
COMMENT=	Free Hebrew spellchecker and morphology engine
LICENSE=	gnu-agpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl gzip
USE_TOOLS+=	perl:run # multispell

CONFIGURE_ARGS+=	--enable-shared

REPLACE_PERL+=	multispell pmerge

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

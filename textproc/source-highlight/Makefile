# $NetBSD: Makefile,v 1.64 2020/05/18 11:31:51 nia Exp $

DISTNAME=	source-highlight-3.1.9
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=src-highlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/src-highlite/
COMMENT=	Highlight syntax of various languages source into HTML document
LICENSE=	gnu-gpl-v3

DEPENDS+=	exctags-[0-9]*:../../devel/exctags

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-libs}
CONFIGURE_ARGS+=	--with-boost-regex=boost_regex
CONFIGURE_ARGS+=	--without-bash-completion
CONFIGURE_ENV+=		CTAGS=${PREFIX}/bin/exctags
CONFIGURE_ENV+=		ac_cv_header_stdbool_h=yes
CONFIGURE_ENV+=		ac_cv_ctags_flags=yes

PKGCONFIG_OVERRIDE=	source-highlight.pc.in

INFO_FILES=	YES

# gmake and gsed are necessary for testing only,
# but the tools handling is somewhat broken in that regard
USE_TOOLS+=	gsed gmake bash:test
TEST_TARGET=	check

SUBST_CLASSES+=			boost_rpath
SUBST_STAGE.boost_rpath=	post-configure
SUBST_SED.boost_rpath=		-e "s|-lboost_regex|${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.boost-libs}/lib &|g"
SUBST_FILES.boost_rpath=	src/Makefile lib/srchilite/Makefile

# bash scripts
CHECK_PORTABILITY_SKIP+= \
	lib/tests/valgrind_test.sh.in \
	tests/valgrind_suppressions.sh.in \
	tests/valgrind_test.sh.in \
	tests/valgrind_tests.sh.in

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.21 2019/06/22 11:52:32 nia Exp $
#

DISTNAME=	paexec-1.1.1
CATEGORIES=	parallel sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=paexec/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/paexec
COMMENT=	Distributes tasks over network or CPUs
LICENSE=	mit

BUILD_DEPENDS+=		mk-configure>=0.27.0:../../devel/mk-configure
DEPENDS+=		runawk>=1.4.3:../../lang/runawk

REPLACE_INTERPRETER+=	runawk
REPLACE.runawk.old=	/usr/bin/env runawk
REPLACE.runawk.new=	${PREFIX}/bin/runawk
REPLACE_FILES.runawk=	paexec/paexec_reorder

TEST_TARGET=		test

EGDIR=			${PREFIX}/share/examples/${PKGBASE}

MAKE_ENV+=		AWK=${AWK:Q}
MAKE_ENV+=		EGDIR=${EGDIR}

BUILD_TARGET=		all doc examples
INSTALL_TARGET=		install install-doc install-examples

REPLACE_SH+=		examples/all_substr/run_all_substr \
			examples/cc_wrapper/cmd_cc_wrapper \
			examples/cc_wrapper/run_cc_wrapper \
			examples/cc_wrapper2/run_cc_wrapper2 \
			examples/dirtest/run_dirtest \
			examples/divide/run_divide \
			examples/divide/run_divide2 \
			examples/make_package/run_cycle_make_package \
			examples/make_package/run_make_package \
			examples/toupper/run_toupper \
			examples/wav2flac/run_wav2flac \
			tests/fakeflac/flac \
			tests/scripts/paexec_notransport \
			tests/scripts/transport_broken_echo2 \
			tests/test.sh

post-install:
	set -e; cd ${WRKSRC}; \
	${INSTALL_DATA} presentation/paexec.pdf ${DESTDIR}${PREFIX}/share/doc/paexec/

.include "../../devel/mk-configure/mk-c.mk"
.include "../../mk/bsd.pkg.mk"

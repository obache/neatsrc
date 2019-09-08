# $NetBSD: Makefile,v 1.36 2019/08/02 21:28:12 schmonz Exp $

.include "../../textproc/xapian/Makefile.common"

DISTNAME=		xapian-core-${VERSION}
PKGNAME=		${DISTNAME:S/-core-/-/}

HOMEPAGE=		https://xapian.org/
COMMENT=		Probabilistic Information Retrieval search engine

TEST_TARGET=		check

LDFLAGS.SunOS+=		-lsocket -lnsl

SUBST_CLASSES+=		rpath
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Include rpath to xapian-config
SUBST_FILES.rpath=	xapian-config.in
SUBST_VARS.rpath=	COMPILER_RPATH_FLAG

.include "../../mk/bsd.prefs.mk"

SUPPORTED_BUILTIN_UUID_OPSYS=	AIX FreeBSD NetBSD
.if empty(SUPPORTED_BUILTIN_UUID_OPSYS:M${OPSYS})
.include "../../devel/libuuid/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"

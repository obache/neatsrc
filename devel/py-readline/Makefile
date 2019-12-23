# $NetBSD: Makefile,v 1.34 2019/12/15 14:42:26 adam Exp $

PKGNAME=	${PYPKGPREFIX}-readline-${PY_DISTVERSION}
CATEGORIES=	devel misc python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.python.org/3/library/readline.html
COMMENT=	Line editing support for Python

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/readline.c

USE_GCC_RUNTIME=	yes

PYDISTUTILSPKG=		yes
PY_SETUP_SUBST+=	RLPREFIX=${BUILDLINK_PREFIX.readline}
PY_SETUP_SUBST+=	RLRTPREFIX=${BUILDLINK_PREFIX.readline}

.include "../../devel/readline/buildlink3.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"

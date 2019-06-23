# $NetBSD: Makefile,v 1.61 2019/06/14 14:33:07 adam Exp $

DISTNAME=	numpy-1.16.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/numpy/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.numpy.org/
COMMENT=	Array processing for numbers, strings, records, and objects
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-cython>=0.19:../../devel/py-cython
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=		c fortran
MAKE_ENV+=		ATLAS=None

REPLACE_PYTHON+=	*.py */*.py */*/*.py */*/*/*.py

# XXX Avoid picking up other compilers when installed
.include "../../mk/compiler.mk"

.if defined(PKGSRC_FORTRAN) && ${PKGSRC_FORTRAN} == "g95"
PYSETUPBUILDARGS+=	--fcompiler=g95
.elif defined(PKGSRC_FORTRAN) && ${PKGSRC_FORTRAN} == "gfortran"
PYSETUPBUILDARGS+=	--fcompiler=gnu95
.elif !empty(PKGSRC_COMPILER:Mgcc)
PYSETUPBUILDARGS+=	--fcompiler=gnu
.endif

# This package bypasses the wrappers and calls the compilers directly when
# linking, so ensure that we pass through requisite options.
LDFLAGS+=		${_COMPILER_ABI_FLAG.${ABI}}

.include "../../mk/bsd.prefs.mk"

# numpy fails using the gold linker with:
# fatal error: --sysroot=: must take a non-empty argument
# Work around it on DragonFly by specifying the classic gnu linker
MAKE_ENV.DragonFly+=	LDVER=ld.bfd

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${RM} f2py || ${TRUE}

do-test:
	${RUN}cd ${WRKSRC};${PYTHONBIN} runtests.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.if ${OPSYS} != "Darwin"
# blas and lapack are not needed; numpy will use Accelerate.framework
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"

post-patch:
	${CP} ${FILESDIR}/site.cfg ${FAKEHOMEDIR}/numpy-site.cfg

SUBST_CLASSES+=		site_cfg
SUBST_STAGE.site_cfg=	pre-configure
SUBST_VARS.site_cfg=	LOCALBASE BUILDLINK_PREFIX.blas BUILDLINK_PREFIX.lapack
SUBST_VARS.site_cfg+=	X11BASE
SUBST_FILES.site_cfg=	${FAKEHOMEDIR}/numpy-site.cfg

.endif
.include "../../mk/bsd.pkg.mk"

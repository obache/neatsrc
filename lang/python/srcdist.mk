# $NetBSD: srcdist.mk,v 1.39 2019/12/15 14:42:26 adam Exp $

.include "../../lang/python/pyversion.mk"

.sinclude "${.CURDIR}/${PYPKGSRCDIR}/dist.mk"

PYSUBDIR=	${DISTNAME}
WRKSRC=		${WRKDIR}/${PYSUBDIR}

.if defined(PYDISTUTILSPKG)
# This is used for standard modules shipped with Python but build as
# separate packages.

.  if ${_PYTHON_VERSION} != 27
EXTRACT_ELEMENTS+=	${PYSUBDIR}/Modules/clinic
.  endif

# Standard modules depend on their own version
BUILDLINK_API_DEPENDS.${PYPACKAGE}+=	${PYPACKAGE}>=${PY_DISTVERSION}
BUILDLINK_ABI_DEPENDS.${PYPACKAGE}+=	${PYPACKAGE}>=${PY_DISTVERSION}

python-std-patchsetup:
	${SED} ${PY_SETUP_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/} \
		<${FILESDIR}/setup.py >${WRKSRC}/setup.py

post-extract: python-std-patchsetup

PYSETUPINSTALLARGS+=	--install-lib ${PREFIX}/${PYLIB}/lib-dynload
PY_NO_EGG?=	yes
.include "../../lang/python/distutils.mk"

.endif

.if !empty(EXTRACT_ELEMENTS)
USE_TOOLS+=	patch
# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-*;do \
	${PATCH} --batch <$$f || ${TRUE}; \
	done)
.endif

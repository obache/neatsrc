# $NetBSD: srcdist.mk,v 1.37 2018/07/03 03:55:40 adam Exp $

.include "../../lang/python/pyversion.mk"

.sinclude "${.CURDIR}/${PYPKGSRCDIR}/dist.mk"

PYSUBDIR=	${DISTNAME}
WRKSRC=		${WRKDIR}/${PYSUBDIR}

.if defined(PYDISTUTILSPKG)
# This is used for standard modules shipped with Python but build as
# separate packages.

.  if ${PYVERSSUFFIX} == "3.5" || ${PYVERSSUFFIX} == "3.6" || ${PYVERSSUFFIX} == "3.7"
EXTRACT_ELEMENTS+=	${PYSUBDIR}/Modules/clinic
.  endif

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

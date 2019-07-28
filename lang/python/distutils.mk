# $NetBSD: distutils.mk,v 1.8 2016/08/28 09:40:35 richard Exp $
#
# Common logic for python distributions that use distutils.
#
.include "../../mk/bsd.fast.prefs.mk"

.include "../../lang/python/pyversion.mk"

# This file should be included to package python "distributions" which
# use distutils.  See egg.mk for distributions that use setuptools and
# extensions.mk for ad hoc cases.

PYSETUP?=		setup.py
PYSETUPBUILDTARGET?=	build
PYSETUPBUILDARGS?=	#empty
# Python 3.5+ supports parallel building
.if defined(MAKE_JOBS) && ${_PYTHON_VERSION} != 27
.  if !defined(MAKE_JOBS_SAFE) || empty(MAKE_JOBS_SAFE:M[nN][oO])
PYSETUPBUILDARGS+=	-j${MAKE_JOBS}
.  endif
.endif
PYSETUPARGS?=		#empty
PYSETUPINSTALLTARGET?=	install
PYSETUPINSTALLARGS?=	#empty
PYSETUPOPTARGS?=	-c -O1
_PYSETUPINSTALLARGS=	${PYSETUPINSTALLARGS} ${PYSETUPOPTARGS} ${_PYSETUPTOOLSINSTALLARGS}
_PYSETUPINSTALLARGS+=	--root=${DESTDIR:Q}
PY_PATCHPLIST?=		yes
PYSETUPTESTTARGET?=	test
PYSETUPTESTARGS?=	#empty
PYSETUPSUBDIR?=		#empty

do-build:
	(cd ${WRKSRC}/${PYSETUPSUBDIR} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} \
	 ${PYSETUP} ${PYSETUPARGS} ${PYSETUPBUILDTARGET} ${PYSETUPBUILDARGS})

do-install:
	(cd ${WRKSRC}/${PYSETUPSUBDIR} && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	 ${PYTHONBIN} ${PYSETUP} ${PYSETUPARGS} ${PYSETUPINSTALLTARGET} ${_PYSETUPINSTALLARGS})
.if !target(do-test) && !(defined(TEST_TARGET) && !empty(TEST_TARGET))
do-test:
	(cd ${WRKSRC}/${PYSETUPSUBDIR} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} \
	 ${PYSETUP} ${PYSETUPARGS} ${PYSETUPTESTTARGET} ${PYSETUPTESTARGS})
.endif

# We expect distutils to create an egg-info file if Python distutils
# can do so, and provide support for a PLIST entry that represents
# this norm and will work with all python versions.

# Set the egg file basename.
EGG_NAME?=	${DISTNAME:C/-([^0-9])/_\1/g}

# PY_NO_EGG suppress the installation of the egg info file (and
# therefore its inclusion in the package).  Python practice is be to
# use these files to let 'require' verify that python distributions
# are present, and therefore the default value of PY_NO_EGG=yes causes
# pkgsrc not to conform to python norms.  The reason for this behavior
# appears to be that creating egg info files was new in Python 2.5.
PY_NO_EGG?=	no
.if !empty(PY_NO_EGG:M[yY][eE][sS])
# see python*/patches/patch-av
INSTALL_ENV+=		PKGSRC_PYTHON_NO_EGG=defined
.endif

.include "../../lang/python/extension.mk"

# Egg files have the version encoded, so generalize in PLIST.
PLIST_SUBST+=	EGG_FILE=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info
PRINT_PLIST_AWK+=	{ gsub("${EGG_NAME}-py${PYVERSSUFFIX}.egg-info", \
				"$${EGG_FILE}") }
PRINT_PLIST_AWK+=	{ gsub(/${PYVERSSUFFIX}/, \
				"$${PYVERSSUFFIX}") }

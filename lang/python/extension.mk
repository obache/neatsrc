# $NetBSD: extension.mk,v 1.55 2018/12/14 13:09:10 adam Exp $

.include "../../lang/python/pyversion.mk"

# This mk fragment is included to handle packages that create
# extensions to python, which by definition are those that place files
# in ${PYSITELIB}.  Extensions can be implemented via setuptools as
# eggs (see egg.mk), via distutils (confusing, with an egg-info file,
# even though they are not eggs, see distuilts.mk), or via more ad hocs methods.


.if !empty(PY_PATCHPLIST:M[Yy][Ee][Ss])
PLIST_SUBST+=	PYINC=${PYINC} PYLIB=${PYLIB} PYSITELIB=${PYSITELIB}

PRINT_PLIST_AWK+=	/^${PYINC:S|/|\\/|g}/ \
			{ gsub(/${PYINC:S|/|\\/|g}/, "$${PYINC}") }
PRINT_PLIST_AWK+=	/^${PYSITELIB:S|/|\\/|g}/ \
			{ gsub(/${PYSITELIB:S|/|\\/|g}/, "$${PYSITELIB}") }
PRINT_PLIST_AWK+=	/^${PYLIB:S|/|\\/|g}/ \
			{ gsub(/${PYLIB:S|/|\\/|g}/, "$${PYLIB}") }
.endif

.include "../../lang/python/pep-3147.mk"

DISTUTILS_BUILDDIR_IN_TEST_ENV?=	no

.if ${DISTUTILS_BUILDDIR_IN_TEST_ENV} == "yes"
DISTUTILS_BUILDDIR_CMD=	cd ${WRKSRC} && ${PYTHONBIN} ${.CURDIR}/../../lang/python/distutils-builddir.py
TEST_ENV+=	PYTHONPATH=${DISTUTILS_BUILDDIR_CMD:sh}
.endif

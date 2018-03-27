# $NetBSD: extension.mk,v 1.52 2018/03/25 07:32:19 adam Exp $

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

# prepare Python>=3.2 bytecode file location change
# http://www.python.org/dev/peps/pep-3147/
.if empty(_PYTHON_VERSION:M2?)
PY_PEP3147?=		yes
.endif
.if defined(PY_PEP3147) && !empty(PY_PEP3147:M[yY][eE][sS])
PLIST_AWK+=		-f ${PKGSRCDIR}/lang/python/plist-python.awk
PLIST_AWK_ENV+=		PYVERS="${PYVERSSUFFIX:S/.//}"
PRINT_PLIST_AWK+=	/^[^@]/ && /[^\/]+\.py[co]$$/ {
PRINT_PLIST_AWK+=	gsub(/__pycache__\//, "")
PRINT_PLIST_AWK+=	gsub(/opt-1\.pyc$$/, "pyo")
PRINT_PLIST_AWK+=	gsub(/\.cpython-${_PYTHON_VERSION}/, "")}
.endif

DISTUTILS_BUILDDIR_IN_TEST_ENV?=	no

.if ${DISTUTILS_BUILDDIR_IN_TEST_ENV} == "yes"
DISTUTILS_BUILDDIR_CMD=	cd ${WRKSRC} && ${PYTHONBIN} ${.CURDIR}/../../lang/python/distutils-builddir.py
TEST_ENV+=	PYTHONPATH=${DISTUTILS_BUILDDIR_CMD:sh}
.endif

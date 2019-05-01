.if !defined(PEP_3147_MK)
PEP_3147_MK=	defined

.if !defined(_PYTHON_VERSION)
.  include "../../lang/python/pyversion.mk"
.endif

# prepare Python>=3.2 bytecode file location change
# http://www.python.org/dev/peps/pep-3147/
.if empty(_PYTHON_VERSION:M2?)
PLIST_AWK+=		-f ${PKGSRCDIR}/lang/python/plist-python.awk
PLIST_AWK_ENV+=		PYVERS="${PYVERSSUFFIX:S/.//}"
PRINT_PLIST_AWK+=	/^[^@]/ && /[^\/]+\.py[co]$$/ {
PRINT_PLIST_AWK+=	gsub(/__pycache__\//, "")
PRINT_PLIST_AWK+=	gsub(/opt-1\.pyc$$/, "pyo")
PRINT_PLIST_AWK+=	gsub(/\.cpython-${_PYTHON_VERSION}/, "")}
.endif

.endif

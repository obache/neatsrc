# $NetBSD: pyversion.mk,v 1.129 2019/04/26 09:44:59 roy Exp $

# This file determines which Python version is used as a dependency for
# a package.
#
# === User-settable variables ===
#
# PYTHON_VERSIONS_PREFERRED
#	The preferred Python versions to use. The order of the
#	entries matters, since earlier entries are preferred over
#	later ones.
#
#	Possible values: 27 36 37
#	Default: 37 36 27
#
# PYTHON_VERSION_DEFAULT
#	The default Python version to use.
#
#	Possible values: 27 36 37
#	Default: ${PYTHON_VERSIONS_PREFERRED:[1]}
#
# === Infrastructure variables ===
#
# PYTHON_VERSION_REQD
#	Python version to use. This variable should not be set in
#	packages.  Normally it is used by bulk build tools.
#
#	Possible: ${PYTHON_VERSIONS_ACCEPTED}
#	Default:  ${PYTHON_VERSION_DEFAULT}
#
# === Package-settable variables ===
#
# PYTHON_VERSIONS_ACCEPTED
#	The Python versions that are acceptable for the package. The
#	order of the entries matters, since earlier entries are
#	preferred over later ones.
#
#	Possible values: 37 36 27
#	Default: 37 36 27
#
# PYTHON_VERSIONS_INCOMPATIBLE
#	The Python versions that are NOT acceptable for the package.
#
#	Possible values: 27 36 37
#	Default: (empty)
#
# PYTHON_FOR_BUILD_ONLY
#	Whether Python is needed only at build time or at run time.
#
#	Possible values: yes no test tool
#	Default: no
#
# PYTHON_SELF_CONFLICT
#	If set to "yes", additional CONFLICTS entries are added for
#	registering a conflict between pyNN-<modulename> packages.
#
#	Possible values: yes no
#	Default: no
#
# === Defined variables ===
#
# PYPKGPREFIX
#	The prefix to use in PKGNAME for extensions which are meant
#	to be installed for multiple Python versions.
#
#	Example: py27
#
# PYVERSSUFFIX
#	The suffix to executables and in the library path, equal to
#	sys.version[0:3].
#
#	Example: 2.7
#
# Keywords: python
#

.if !defined(PYTHON_PYVERSION_MK)
PYTHON_PYVERSION_MK=	defined

# derive a python version from the package name if possible
# optionally handled quoted package names
.if defined(PKGNAME_REQD) && !empty(PKGNAME_REQD:Mpy[0-9][0-9]-*) || \
    defined(PKGNAME_REQD) && !empty(PKGNAME_REQD:M*-py[0-9][0-9]-*)
PYTHON_VERSION_REQD?=	${PKGNAME_REQD:C/(^.*-|^)py([0-9][0-9])-.*/\2/}
.elif defined(PKGNAME_OLD) && !empty(PKGNAME_OLD:Mpy[0-9][0-9]-*) || \
      defined(PKGNAME_OLD) && !empty(PKGNAME_OLD:M*-py[0-9][0-9]-*)
PYTHON_VERSION_REQD?=	${PKGNAME_OLD:C/(^.*-|^)py([0-9][0-9])-.*/\2/}
.endif

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		PYTHON_VERSION_DEFAULT
BUILD_DEFS+=		PYTHON_VERSIONS_PREFERRED
BUILD_DEFS_EFFECTS+=	PYPACKAGE

PYTHON_VERSIONS_PREFERRED?=		37 36 27
PYTHON_VERSION_DEFAULT?=		${PYTHON_VERSIONS_PREFERRED:[1]}
PYTHON_VERSIONS_ACCEPTED?=		37 36 27
PYTHON_VERSIONS_INCOMPATIBLE?=		# empty by default

# transform the list into individual variables
.for pv in ${PYTHON_VERSIONS_ACCEPTED}
.  if empty(PYTHON_VERSIONS_INCOMPATIBLE:M${pv})
_PYTHON_VERSION_${pv}_OK=	yes
_PYTHON_VERSIONS_ACCEPTED+=	${pv}
.  endif
.endfor

#
# choose a python version where to add,
# try to be intelligent
#
# if a version is explicitely required, take it
.if defined(PYTHON_VERSION_REQD)
# but check if it is acceptable first, error out otherwise
.  if defined(_PYTHON_VERSION_${PYTHON_VERSION_REQD}_OK)
_PYTHON_VERSION=	${PYTHON_VERSION_REQD}
.  endif
.else
# if the default is accepted, it is first choice
.  if !defined(_PYTHON_VERSION)
.    if defined(_PYTHON_VERSION_${PYTHON_VERSION_DEFAULT}_OK)
_PYTHON_VERSION=	${PYTHON_VERSION_DEFAULT}
.    endif
.  endif
# preferred versions, in order of "preferred"
.  if !defined(_PYTHON_VERSION)
.    for pv in ${PYTHON_VERSIONS_PREFERRED:U${PYTHON_VERSION_DEFAULT}}
.      if defined(_PYTHON_VERSION_${pv}_OK)
_PYTHON_VERSION?=	${pv}
.      endif
.    endfor
.  endif
# prefer an already installed version, in order of "accepted"
.  if !defined(_PYTHON_VERSION)
.    for pv in ${PYTHON_VERSIONS_ACCEPTED}
.      if defined(_PYTHON_VERSION_${pv}_OK)
_PYTHON_VERSION?=	${pv}
.      endif
.    endfor
.  endif
.endif

#
# Variable assignment for multi-python packages
MULTI+=	PYTHON_VERSION_REQD=${_PYTHON_VERSION}

# No supported version found, annotate to simplify statements below.
.if !defined(_PYTHON_VERSION)
_PYTHON_VERSION=	none
PKG_FAIL_REASON+=	"No valid Python version"
.endif

# Additional CONFLICTS
.if ${PYTHON_SELF_CONFLICT:U:tl} == "yes"
.  for i in ${PYTHON_VERSIONS_ACCEPTED:N${_PYTHON_VERSION}}
CONFLICTS+=	${PKGNAME:S/py${_PYTHON_VERSION}/py${i}/:C/-[0-9].*$/-[0-9]*/}
.  endfor
.endif # PYCONFLICTS

#
PLIST_VARS+=	py2x py3x

.if empty(_PYTHON_VERSION:Mnone)
PYPACKAGE=				python${_PYTHON_VERSION}
PYVERSSUFFIX=				${_PYTHON_VERSION:C/^([0-9])/\1./1}
BUILDLINK_API_DEPENDS.${PYPACKAGE}?=	${PYPACKAGE}>=${PYVERSSUFFIX}
PYPKGSRCDIR=				../../lang/${PYPACKAGE}
PYDEPENDENCY=				${BUILDLINK_API_DEPENDS.${PYPACKAGE}}:${PYPKGSRCDIR}
PYPKGPREFIX=				py${_PYTHON_VERSION}
.endif
.if !empty(_PYTHON_VERSION:M3*)
PLIST.py3x=				yes
.endif
.if !empty(_PYTHON_VERSION:M2*)
PLIST.py2x=				yes
.endif

PTHREAD_OPTS+=	require
.include "../../mk/pthread.buildlink3.mk"

PYTHON_FOR_BUILD_ONLY?=		no
.if defined(PYPKGSRCDIR)
.  if !empty(PYTHON_FOR_BUILD_ONLY:M[tT][oO][oO][lL])
TOOL_DEPENDS+=			${PYDEPENDENCY}
.  elif !empty(PYTHON_FOR_BUILD_ONLY:M[tT][eE][sS][tT])
TEST_DEPENDS+=			${PYDEPENDENCY}
.  else
.    if !empty(PYTHON_FOR_BUILD_ONLY:M[yY][eE][sS])
BUILDLINK_DEPMETHOD.python?=	build
.    endif
.    include "${PYPKGSRCDIR}/buildlink3.mk"
.  endif
.endif

PYTHONBIN=	${LOCALBASE}/bin/python${PYVERSSUFFIX}
.if exists(${PYTHONBIN}m)
PYTHONCONFIG=	${LOCALBASE}/bin/python${PYVERSSUFFIX}m-config
.else
PYTHONCONFIG=	${LOCALBASE}/bin/python${PYVERSSUFFIX}-config
.endif
PY_COMPILE_ALL= \
	${PYTHONBIN} ${PREFIX}/lib/python${PYVERSSUFFIX}/compileall.py -q
PY_COMPILE_O_ALL= \
	${PYTHONBIN} -O ${PREFIX}/lib/python${PYVERSSUFFIX}/compileall.py -q

.if exists(${PYTHONBIN})
PYINC!=	${PYTHONBIN} -c "import distutils.sysconfig; \
	print (distutils.sysconfig.get_python_inc(0, \"\"))" \
	|| ${ECHO} include/python${PYVERSSUFFIX}
PYLIB!=	${PYTHONBIN} -c "import distutils.sysconfig; \
	print (distutils.sysconfig.get_python_lib(0, 1, \"\"))" \
	|| ${ECHO} lib/python${PYVERSSUFFIX}
PYSITELIB!=	${PYTHONBIN} -c "import distutils.sysconfig; \
	print (distutils.sysconfig.get_python_lib(0, 0, \"\"))" \
	|| ${ECHO} lib/python${PYVERSSUFFIX}/site-packages
.endif

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

# mostly for ALTERNATIVES files
FILES_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
FILES_SUBST+=	PYVERS_MAJOR=${PYVERSSUFFIX:S/./ /:[1]}

ALL_ENV+=		PYTHON=${PYTHONBIN}
.if defined(USE_CMAKE)
# used by FindPythonInterp.cmake and FindPythonLibs.cmake
CMAKE_ARGS+=		-DPYVERSSUFFIX:STRING=${PYVERSSUFFIX}
# set this explicitly, as by default it will prefer the built in framework
# on Darwin
CMAKE_ARGS+=		-DPYTHON_INCLUDE_DIR:PATH=${BUILDLINK_DIR}/${PYINC}
CMAKE_ARGS+=		-DPYTHON_INCLUDE_PATH:PATH=${BUILDLINK_DIR}/${PYINC}
CMAKE_ARGS+=		-DPYTHON_EXECUTABLE:FILEPATH=${PYTHONBIN}
.endif

.endif	# PYTHON_PYVERSION_MK

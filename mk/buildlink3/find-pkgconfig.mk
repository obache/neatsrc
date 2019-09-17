# $NetBSD$
#

#
# This is a "subroutine" that can be included to detect the presence of
# pkg-config *.pc files in the base system.
#
# The input variable is BUILDLINK_FIND_PKGCONFIGS, which is a list of package
# names, e.g. zlib, expat, etc., that will be sought in the base
# system.  BUILTIN_PKGCONFIG_FOUND.<pkg> is set to "yes" or "no" depending
# on the result of the search.
#
# An example use is:
#
# BUILDLINK_FIND_PKGCONFIGS:=	zlib expat
# .include "../../mk/buildlink3/find-pkgconfig.mk"
# # ${BUILTIN_PKGCONFIG_FOUND.zlib} and ${BUILTIN_PKGCONFIG_FOUND.expat} are now
# # either "yes" or "no".
#

.if empty(USE_TOOLS:Mecho)
USE_TOOLS+=	echo
.endif
.if empty(USE_TOOLS:Mtest)
USE_TOOLS+=	test
.endif

.for _pkg_ in ${BUILTIN_FIND_PKGCONFIGS}
.  if !defined(BUILTIN_PKGCONFIG_FOUND.${_pkg_})
BUILTIN_PKGCONFIG_FOUND.${_pkg_}=	no
.    for _path_ in ${COMPILER_LIB_DIRS}
.      if ${BUILTIN_PKGCONFIG_FOUND.${_pkg_}} == "no"
BUILTIN_PKGCONFIG_FOUND.${_pkg_}!=    \
	if ${TEST} -e "${_path_}/pkgconfig/${_pkg_}.pc"; then		\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        if ${BUILTIN_PKGCONFIG_FOUND.${_pkg_}} == "yes"
BUILTIN_PKGCONFIG_FILE.${_pkg_}=	${_path_}/pkgconfig/${_pkg_}.pc
BUILTIN_PKGCONFIG_PREFIX.${_pkg_}!=	\
		prefix=`${SED} -n -e 's/^prefix=//p' ${BUILTIN_PKGCONFIG_FILE.${_pkg_}}`; \
		[ -n "$${prefix}" ] || prefix=`dirname ${_path_}`; \
		echo $${prefix}
BUILTIN_PKGCONFIG_VERSION.${_pkg_}!=	\
		${SED} -n -e 's/^Version: //p' ${BUILTIN_PKGCONFIG_FILE.${_pkg_}}
.        endif
.      endif
.    endfor
.  endif
MAKEVARS+=	BUILTIN_PKGCONFIG_FOUND.${_pkg_}
MAKEVARS+=	BUILTIN_PKGCONFIG_FILE.${_pkg_}
MAKEVARS+=	BUILTIN_PKGCONFIG_PREFIX.${_pkg_}
MAKEVARS+=	BUILTIN_PKGCONFIG_VERSION.${_pkg_}
.endfor
.undef BUILDLINK_FIND_PKGCONFIGS

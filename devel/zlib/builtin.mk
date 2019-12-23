# $NetBSD: builtin.mk,v 1.15 2019/11/03 10:39:32 rillig Exp $

BUILTIN_PKG:=	zlib

BUILTIN_FIND_HEADERS_VAR:=	H_ZLIB
BUILTIN_FIND_HEADERS.H_ZLIB=	zlib.h
BUILTIN_FIND_LIBS:=		z
BUILTIN_FIND_PKGCONFIGS:=	zlib

.include "../../mk/buildlink3/bsd.builtin.mk"

.if ! empty(MACHINE_PLATFORM:MDarwin-[0-8].*-*)
USE_BUILTIN.zlib=	no
.endif

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.zlib)
IS_BUILTIN.zlib=	no
.  if empty(H_ZLIB:M__nonexistent__) && empty(H_ZLIB:M${LOCALBASE}/*)
IS_BUILTIN.zlib=	yes
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.zlib

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.zlib) && \
    !empty(IS_BUILTIN.zlib:M[yY][eE][sS])
.  if ${BUILTIN_PKGCONFIG_FOUND.zlib} == "yes"
BUILTIN_VERSION.zlib=	${BUILTIN_PKGCONFIG_VERSION.zlib}
.  elif    empty(H_ZLIB:M__nonexistent__)
BUILTIN_VERSION.zlib!=							\
	${AWK} '/\#define[ 	]*ZLIB_VERSION/ {			\
			vers = $$3;					\
			gsub("\"", "", vers);				\
			print vers;					\
		}							\
	' ${H_ZLIB:Q}
.  endif
BUILTIN_PKG.zlib=	zlib-${BUILTIN_VERSION.zlib:C/-[A-Za-z]*//}

.endif
MAKEVARS+=	BUILTIN_PKG.zlib

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.zlib)
.  if ${PREFER.zlib} == "pkgsrc"
USE_BUILTIN.zlib=	no
.  else
USE_BUILTIN.zlib=	${IS_BUILTIN.zlib}
.    if defined(BUILTIN_PKG.zlib) && \
        !empty(IS_BUILTIN.zlib:M[yY][eE][sS])
USE_BUILTIN.zlib=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.zlib}
.        if !empty(USE_BUILTIN.zlib:M[yY][eE][sS])
USE_BUILTIN.zlib!=	\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.zlib:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.zlib
.endif
MAKEVARS+=		USE_BUILTIN.zlib

# If USE_ZLIB is defined, then force the use of a true zlib
# implementation.
#
.if defined(USE_ZLIB)
.  if !empty(IS_BUILTIN.zlib:M[nN][oO])
USE_BUILTIN.zlib=	no
.  endif
.endif

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.zlib?=	no
.if !empty(CHECK_BUILTIN.zlib:M[nN][oO])
.  if !empty(USE_BUILTIN.zlib:M[yY][eE][sS])
.    if ${BUILTIN_PKGCONFIG_FOUND.zlib} == "yes"
BUIDLINK_PREFIX.zlib?=	${BUILTIN_PKGCONFIG_PREFIX.zlib}
.    endif
BUILTIN_FAKE_PC_FILES.zlib=	zlib
FAKE_PC_SRC.zlib=		../../devel/zlib/files/zlib.pc.in
FAKE_PC_SUBST_SED.zlib+=	-e s,@VERSION@,${BUILTIN_VERSION.zlib},g
FAKE_PC_SUBST_SED.zlib+=	-e s,@prefix@,${BUILDLINK_PREFIX.zlib},g
FAKE_PC_SUBST_SED.zlib+=	-e s,@exec_prefix@,${BUILDLINK_PREFIX.zlib},g
FAKE_PC_SUBST_SED.zlib+=	-e s,@includedir@,${BUILTIN_HEADER_FOUND_DIR.H_ZLIB},g
FAKE_PC_SUBST_SED.zlib+=	-e s,@libdir@,${BUILTIN_LIB_FOUND_DIR.z},g
FAKE_PC_SUBST_SED.zlib+=	-e s,@sharedlibdir@,${BUILTIN_LIB_FOUND_DIR.z},g
.  endif
.endif # CHECK_BUILTIN.zlib

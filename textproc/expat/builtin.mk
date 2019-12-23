# $NetBSD: builtin.mk,v 1.20 2019/11/04 21:43:35 rillig Exp $

BUILTIN_PKG:=	expat

BUILTIN_FIND_HEADERS_VAR:=	H_EXPAT
BUILTIN_FIND_HEADERS.H_EXPAT=	expat.h
BUILTIN_FIND_LIBS:=		expat
BUILTIN_FIND_PKGCONFIGS:=	expat

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.expat)
.  if empty(H_EXPAT:M__nonexistent__)
IS_BUILTIN.expat=	yes
.  else
IS_BUILTIN.expat=	no
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.expat

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.expat) && \
    !empty(IS_BUILTIN.expat:M[yY][eE][sS])
.  if ${BUILTIN_PKGCONFIG_FOUND.expat} == "yes"
BUILTIN_VERSION.expat=	${BUILTIN_PKGCONFIG_VERSION.expat}
.  elif empty(H_EXPAT:M__nonexistent__)
BUILTIN_VERSION.expat!=							\
	${AWK} '/\#define[ 	]*XML_MAJOR_VERSION/ { M = $$3 }	\
		/\#define[ 	]*XML_MINOR_VERSION/ { m = "."$$3 }	\
		/\#define[ 	]*XML_MICRO_VERSION/ { u = "."$$3 }	\
		END { printf "%s%s%s\n", M, m, u }'			\
		${H_EXPAT}
.  endif
BUILTIN_PKG.expat=	expat-${BUILTIN_VERSION.expat}
.endif
MAKEVARS+=		BUILTIN_PKG.expat

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.expat)
.  if ${PREFER.expat} == "pkgsrc"
USE_BUILTIN.expat=	no
.  else
USE_BUILTIN.expat=	${IS_BUILTIN.expat}
.    if defined(BUILTIN_PKG.expat) && \
        !empty(IS_BUILTIN.expat:M[yY][eE][sS])
USE_BUILTIN.expat=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.expat}
.        if !empty(USE_BUILTIN.expat:M[yY][eE][sS])
USE_BUILTIN.expat!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.expat:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.expat
.endif
MAKEVARS+=		USE_BUILTIN.expat

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.expat?=	no
.if !empty(CHECK_BUILTIN.expat:M[nN][oO])

.  if !empty(USE_BUILTIN.expat:M[nN][oO])
BUILDLINK_API_DEPENDS.expat+=	expat>=1.95.4
.  else
.    if ${BUILTIN_PKGCONFIG_FOUND.expat} == "yes"
BUIDLINK_PREFIX.expat?=	${BUILTIN_PKGCONFIG_PREFIX.expat}
.    endif
.    if !empty(H_EXPAT:M${X11BASE}/*)
.      include "../../mk/x11.builtin.mk"
.    elif !empty(H_EXPAT:M/usr/*)
BUILDLINK_PREFIX.expat?=	/usr
.    endif
BUILTIN_FAKE_PC_FILES.expat=	expat
FAKE_PC_SRC.expat=	../../textproc/expat/files/expat.pc.in
FAKE_PC_SUBST_SED.expat+=	-e s,@PACKAGE_VERSION@,${BUILTIN_VERSION.expat},g
FAKE_PC_SUBST_SED.expat+=	-e s,@prefix@,${BUILDLINK_PREFIX.expat},g
FAKE_PC_SUBST_SED.expat+=	-e s,@exec_prefix@,${BUILDLINK_PREFIX.expat},g
FAKE_PC_SUBST_SED.expat+=	-e s,@includedir@,${BUILTIN_HEADER_FOUND_DIR.H_EXPAT},g
FAKE_PC_SUBST_SED.expat+=	-e s,@libdir@,${BUILTIN_LIB_FOUND_DIR.expat},g
.  endif

.endif	# CHECK_BUILTIN.expat

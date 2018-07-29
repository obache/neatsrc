# $NetBSD$

BUILTIN_PKG:=	flex

BUILTIN_FIND_LIBS:=		fl
BUILTIN_FIND_HEADERS_VAR:=	H_FLEX_XX
BUILTIN_FIND_HEADERS.H_FLEX_XX=	FlexLexer.h g++/FlexLexer.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.flex)
IS_BUILTIN.flex=	yes
.  if empty(BUILTIN_LIB_FOUND.fl:M[Yy][Ee][Ss]) \
   || !empty(USE_LANGUAGES:Mc++*) && \
	(!empty(H_FLEX_XX:M__nonexistent__) || !empty(H_FLEX_XX:M${LOCALBASE}/*)) \
    || (empty(TOOLS_PLATFORM.flex) || !exists(${TOOLS_PLATFORM.flex}))
IS_BUILTIN.flex=	no
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.flex

.if !defined(BUILTIN_PKG.flex) && !empty(IS_BUILTIN.flex:M[yY][eE][sS])
BUILTIN_VERSION.flex!=	\
	${TOOLS_PLATFORM.flex} --version |				\
	${SED} -e 's/^[[:blank:]]*\([^[:blank:]]\{1,\}\)[[:blank:]]\{1,\}\([^[:blank:]]\{1,\}\).*$$/\2/'
BUILTIN_PKG.flex=	flex-${BUILTIN_VERSION.flex}
.endif
MAKEVARS+=	BUILTIN_PKG.flex

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.flex)
.  if ${PREFER.flex} == "pkgsrc"
USE_BUILTIN.flex=	no
.  else
USE_BUILTIN.flex=	${IS_BUILTIN.flex}
.    if defined(BUILTIN_PKG.flex) && \
        !empty(IS_BUILTIN.flex:M[yY][eE][sS])
USE_BUILTIN.flex=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.flex} ${FLEX_REQD:Dflex>=${FLEX_REQD}}
.        if !empty(USE_BUILTIN.flex:M[yY][eE][sS])
USE_BUILTIN.flex!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.flex:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.flex
.endif
MAKEVARS+=	USE_BUILTIN.flex

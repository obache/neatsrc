# $NetBSD: builtin.mk,v 1.8 2015/04/09 09:55:58 tron Exp $

BUILTIN_PKG:=	editline

BUILTIN_FIND_LIBS:=		edit
BUILTIN_FIND_HEADERS_VAR:=	H_EDITLINE
BUILTIN_FIND_HEADERS.H_EDITLINE=editline/readline.h \
				readline/readline.h
BUILTIN_FIND_PKGCONFIGS:=	libedit

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.editline)
IS_BUILTIN.editline=	no
.  if empty(H_EDITLINE:M__nonexistent__) && \
      !empty(BUILTIN_LIB_FOUND.edit:M[yY][eE][sS])
IS_BUILTIN.editline=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.editline

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.editline)
.  if ${PREFER.editline} == "pkgsrc"
USE_BUILTIN.editline=	no
.  else
USE_BUILTIN.editline=	${IS_BUILTIN.editline}
.    if defined(BUILTIN_PKG.editline) && \
        !empty(IS_BUILTIN.editline:M[yY][eE][sS])
USE_BUILTIN.editline=	yes
.    endif
MAKEVARS+=	USE_BUILTIN.editline
.  endif
.endif

CHECK_BUILTIN.editline?=	no
.if !empty(CHECK_BUILTIN.editline:M[nN][oO])

.  if !empty(_PKG_USE_READLINE:U:M[yY][eE][sS])
BUILDLINK_TRANSFORM+=	l:history:edit:${BUILTIN_LIBNAME.termcap}
BUILDLINK_TRANSFORM+=	l:readline:edit:${BUILTIN_LIBNAME.termcap}
.  endif

###
### create readline compat headers for the case not using builtin editline and
###  buitin editline with readline style header files
###  using readline compat interfaces
###
.  if ( !empty(USE_BUILTIN.editline:M[nO][oO]) && \
	(!empty(H_EDITLINE:M*/readline/readline.h) || \
	 !empty(_PKG_USE_READLINE:U:M[yY][eE][sS])))
BUILDLINK_FNAME_ALIASES.editline+=	include/editline/history.h include/readline/history.h
BUILDLINK_FNAME_ALIASES.editline+=	include/editline/readline.h include/readline/readline.h
.  endif

###
### create readline compat headers for the case using builtin editline and
###  buitin editline with editline style header files and
###  using readline compat interfaces
###
.  if !empty(USE_BUILTIN.editline:M[yY][eE][sS])
.    if !empty(H_EDITLINE:M*/editline/readline.h) && \
	!empty(_PKG_USE_READLINE:U:M[yY][eE][sS])
BUILDLINK_TARGETS+=	buildlink-readline-readline-h
BUILDLINK_TARGETS+=	buildlink-readline-history-h
.    endif

.    if !target(buildlink-readline-readline-h)
.PHONY: buildlink-readline-readline-h
buildlink-readline-readline-h:
	${RUN}								\
	src=${H_EDITLINE:Q};						\
	dest=${BUILDLINK_DIR}"/include/readline/readline.h";		\
	if ${TEST} ! -f "$$dest" -a -f "$$src"; then			\
		fname=`${BASENAME} $$src`;				\
		${ECHO_BUILDLINK_MSG} "Linking $$fname -> readline.h.";	\
		${MKDIR} `${DIRNAME} "$$dest"`;				\
		${LN} -s "$$src" "$$dest";				\
	fi
.    endif

.    if !target(buildlink-readline-history-h)
.PHONY: buildlink-readline-history-h
buildlink-readline-history-h:
	${RUN}								\
	src=${H_EDITLINE:Q};						\
	dest=${BUILDLINK_DIR}"/include/readline/history.h";		\
	if ${TEST} ! -f "$$dest" -a -f "$$src"; then			\
		fname=`${BASENAME} $$src`;				\
		${ECHO_BUILDLINK_MSG} "Linking $$fname -> history.h.";	\
		${MKDIR} `${DIRNAME} "$$dest"`;				\
		${LN} -s "$$src" "$$dest";				\
	fi
.    endif

###
### create missing pkg editline compat headers for buitin editline
### with readline style header files
###
.    if !empty(H_EDITLINE:M*/readline/readline.h)
BUILDLINK_TARGETS+=	buildlink-editline-readline-h
BUILDLINK_TARGETS+=	buildlink-editline-history-h
.    endif

.    if !target(buildlink-editline-readline-h)
.PHONY: buildlink-editline-readline-h
buildlink-editline-readline-h:
	${RUN}								\
	src=${H_EDITLINE:Q};						\
	dest=${BUILDLINK_DIR}"/include/editline/readline.h";		\
	if ${TEST} ! -f "$$dest" -a -f "$$src"; then			\
		fname=`${BASENAME} $$src`;				\
		${ECHO_BUILDLINK_MSG} "Linking $$fname -> readline.h.";	\
		${MKDIR} `${DIRNAME} "$$dest"`;				\
		${LN} -s "$$src" "$$dest";				\
	fi
.    endif

.    if !target(buildlink-editline-history-h)
.PHONY: buildlink-editline-history-h
buildlink-editline-history-h:
	${RUN}								\
	src=${H_EDITLINE:Q};						\
	dest=${BUILDLINK_DIR}"/include/editline/history.h";		\
	if ${TEST} ! -f "$$dest" -a -f "$$src"; then			\
		fname=`${BASENAME} $$src`;				\
		${ECHO_BUILDLINK_MSG} "Linking $$fname -> history.h.";	\
		${MKDIR} `${DIRNAME} "$$dest"`;				\
		${LN} -s "$$src" "$$dest";				\
	fi
.    endif
.    if ${BUILTIN_PKGCONFIG_FOUND.libedit} == "yes"
BUIDLINK_PREFIX.editline?=	${BUILTIN_PKGCONFIG_PREFIX.libedit}
BUILTIN_VERSION.editline?=	${BUILTIN_PKGCONFIG_VERSION.libedit}
.    endif
BUILTIN_VERSION.editline?=	3.0
BUILTIN_PKG.editline?=		editline-${BUILTIN_VERSION.editline}
BUILTIN_FAKE_PC_FILES.editline=	libedit
FAKE_PC_SRC.libedit=	../../devel/editline/files/libedit.pc.in
FAKE_PC_SUBST_SED.libedit+=	-e s,@VERSION@,${BUILTIN_VERSION.editline},g
FAKE_PC_SUBST_SED.libedit+=	-e s,@prefix@,${BUILDLINK_PREFIX.editline},g
FAKE_PC_SUBST_SED.libedit+=	-e s,@exec_prefix@,${BUILDLINK_PREFIX.editline},g
FAKE_PC_SUBST_SED.libedit+=	-e s,@libdir@,${BUILTIN_LIB_FOUND_DIR.edit},g
FAKE_PC_SUBST_SED.libedit+=	-e s,@includedir@,${BUILTIN_HEADER_FOUND_DIR.H_EDITLINE},g
FAKE_PC_SUBST_SED.libedit+=	-e s,@LIBS@,${BUILDLINK_LDADD.termcap},g
.  endif

.endif	# CHECK_BUILTIN.editline

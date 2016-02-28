# $NetBSD$
#

.if !empty(USE_TOOLS:Mpkg-config)
BUILDLINK_TARGETS+=	create-fake-pc

.for _pkg_ in ${_BUILTIN_PKGS}
.  for _pc_ in ${BUILTIN_FAKE_PC_FILES.${_pkg_}}
FAKE_PC_SUBST_VARS.${_pc_}?=	#empty
FAKE_PC_SUBST_SED.${_pc_}?=	#empty
.        for _var_ in ${FAKE_PC_SUBST_VARS.${_pc_}}
FAKE_PC_SUBST_SED.${_pc_}+=	-e s,@${_var_}@,${${_var_}},g
.        endfor
.  endfor
.endfor

create-fake-pc:
.for _pkg_ in ${_BUILTIN_PKGS}
.  for _pc_ in ${BUILTIN_FAKE_PC_FILES.${_pkg_}}
.    if !exists(${BUILDLINK_DIR}/lib/pkgconfig/${_pc_}.pc) && \
	!exists(${BUILDLINK_X11_DIR}/lib/pkgconfig/${_pc_}.pc)
	${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig
.      if empty(BUILTIN_PKGCONFIG_FOUND.${_pc_}:M[Yy][Ee][Ss])
.        if empty(FAKE_PC_SUBST_SED.${_pc_})
	${CP} ${FAKE_PC_SRC.${_pc_}} ${BUILDLINK_DIR}/lib/pkgconfig/${_pc_}.pc
.        else
	${SED} ${FAKE_PC_SUBST_SED.${_pc_}} \
		< ${FAKE_PC_SRC.${_pc_}} \
		> ${BUILDLINK_DIR}/lib/pkgconfig/${_pc_}.pc
.        endif
.      else
	${LN} -s ${BUILTIN_PKGCONFIG_FILE.${_pc_}} \
		${BUILDLINK_DIR}/lib/pkgconfig/${_pc_}.pc
.      endif
.    endif
.  endfor
.endfor

.endif

# This file checks that the package is not using required maitainance tasks,
# or register redundant tasks as a part of INSTALL/DFINSTALL scripts.
#
# User-settable variables:
#
# CHECK_MAINTAINANCE_TASKS
#	Specifies whether the check should be run at all.
#
#	Possible values: yes, no.
#
#	Default value: yes for PKG_DEVELOPER, no otherwise.
#
# Package-settable variables:
#

.if ${PKG_DEVELOPER:Uno} != "no"
CHECK_MAINTAINANCE_TASKS?=	yes
.else
CHECK_MAINTAINANCE_TASKS?=	no
.endif

_CHECK_MAINTAINANCE_TASKS+=	mimedb
_CHECK_MAINTAINANCE_TASKS_FILES_FILTER.mimedb=	${AWK} '/^${PREFIX:S/\//\\\//g}\/share\/mime\/packages\/.+\.xml$$/'
_CHECK_MAINTAINANCE_TASKS_MAKEFILE.mimedb=	databases/shared-mime-info/mimedb.mk
_CHECK_MAINTAINANCE_TASKS_SELFPKGPATH.mimedb=	databases/shared-mime-info
_CHECK_MAINTAINANCE_TASKS_VARNAME.mimedb=	SHARED_MIME_INFO_MIMEDB_MK


_CHECK_MAINTAINANCE_TASKS+=	desktopdb
_CHECK_MAINTAINANCE_TASKS_FILES_FILTER.desktopdb=	${AWK} '/^${PREFIX:S/\//\\\//g}\/share\/applications\/.+\.desktop$$/'	\
			| while read fname; do	\
				${GREP} -q -e '^MimeType=.' ${DESTDIR}$$fname && ${ECHO} $$fname || ${TRUE}; \
			done
_CHECK_MAINTAINANCE_TASKS_MAKEFILE.desktopdb=	sysutils/desktop-file-utils/desktopdb.mk
_CHECK_MAINTAINANCE_TASKS_SELFPKGPATH.desktopdb=	sysutils/desktop-file-utils
_CHECK_MAINTAINANCE_TASKS_VARNAME.desktopdb=	DESKTOP_FILE_UTILS_MIMEDB_MK

_CHECK_MAINTAINANCE_TASKS+=	gschema
_CHECK_MAINTAINANCE_TASKS_FILES_FILTER.gschema=	${AWK} '/^${PREFIX:S/\//\\\//g}\/share\/glib-2.0\/schemas\/.+\.gschema\.xml$$/'
_CHECK_MAINTAINANCE_TASKS_MAKEFILE.gschema=	devel/glib2/schemas.mk
_CHECK_MAINTAINANCE_TASKS_SELFPKGPATH.gschema=	devel/glib2
_CHECK_MAINTAINANCE_TASKS_VARNAME.gschema=	GLIB_SCHEMAS_MK

.if !empty(CHECK_MAINTAINANCE_TASKS:M[Yy][Ee][Ss])
privileged-install-hook: _check-maintainance-tasks
.endif

_check-maintainance-tasks: .PHONY error-check
	@${STEP_MSG} "Checking for maintainance tasks in ${PKGNAME}"
	${RUN}${RM} -f ${ERROR_DIR}/${.TARGET}
.for d in ${_CHECK_MAINTAINANCE_TASKS}
	${RUN}${RM} -f ${WRKDIR}/${.TARGET}-${d}
	${RUN}${PKG_FILELIST_CMD} | ${_CHECK_MAINTAINANCE_TASKS_FILES_FILTER.${d}} > ${WRKDIR}/${.TARGET}-${d}
. if	defined(${_CHECK_MAINTAINANCE_TASKS_VARNAME.${d}})
	${RUN}		\
	if ${_ZERO_FILESIZE_P} ${WRKDIR}/${.TARGET}-${d}; then		\
		${ECHO} "************************************************************"; \
		${ECHO} "${_CHECK_MAINTAINANCE_TASKS_MAKEFILE.${d}} is included, but any relevant files are not installed."; \
	fi
. elif empty(_CHECK_MAINTAINANCE_TASKS_SELFPKGPATH.${d}:U:M${PKGPATH})
	${RUN}		\
	if ${_NONZERO_FILESIZE_P} ${WRKDIR}/${.TARGET}-${d}; then	\
		${ECHO} "************************************************************"; \
		${ECHO} "Following files are installed but ${_CHECK_MAINTAINANCE_TASKS_MAKEFILE.${d}} is not included"; \
		${CAT} ${WRKDIR}/${.TARGET}-${d} >> ${ERROR_DIR}/${.TARGET}; \
	fi
. endif
.endfor

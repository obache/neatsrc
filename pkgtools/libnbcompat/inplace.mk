# $NetBSD: inplace.mk,v 1.14 2018/08/07 12:04:36 jperkin Exp $
#
# This file should not be included directly. Use USE_FEATURES instead.
#
# This Makefile fragment builds a working copy of libnbcompat inside
# ${WRKDIR}.
#

.include "../../mk/bsd.prefs.mk"

OVERRIDE_GNU_CONFIG_SCRIPTS=	yes

LIBNBCOMPAT_USE_PIC?=	no

LIBNBCOMPAT_FILESDIR=	${.CURDIR}/../../pkgtools/libnbcompat/files
LIBNBCOMPAT_SRCDIR=	${WRKDIR}/libnbcompat

CPPFLAGS.nbcompat=	-DHAVE_NBCOMPAT_H=1 -I${LIBNBCOMPAT_SRCDIR}
LDFLAGS.nbcompat=	-L${LIBNBCOMPAT_SRCDIR}
LDADD.nbcompat=		-lnbcompat
CONFIG_EXTRA_OVERRIDE_DIRS+=	${LIBNBCOMPAT_SRCDIR}

.if !empty(LIBNBCOMPAT_USE_PIC:M[Yy][Ee][Ss])
LIBNBCOMPAT_PICDIR=	${WRKDIR}/libnbcompat_pic
CPPFLAGS.nbcompat_pic=	-DHAVE_NBCOMPAT_H=1 -I${LIBNBCOMPAT_PICDIR}
LDFLAGS.nbcompat_pic=	-L${LIBNBCOMPAT_PICDIR}
LDADD.nbcompat_pic=	-lnbcompat
CONFIG_EXTRA_OVERRIDE_DIRS+=	${LIBNBCOMPAT_PICDIR}
.endif

post-extract: libnbcompat-extract
.PHONY: libnbcompat-extract
libnbcompat-extract:
	${RUN} ${CP} -R ${LIBNBCOMPAT_FILESDIR} ${LIBNBCOMPAT_SRCDIR}
.if !empty(LIBNBCOMPAT_USE_PIC:M[Yy][Ee][Ss])
	${RUN} ${CP} -R ${LIBNBCOMPAT_FILESDIR} ${LIBNBCOMPAT_PICDIR}
.endif

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
NBCOMPAT_CONFIGURE_ARGS+=	--build=${NATIVE_MACHINE_GNU_PLATFORM:Q}
.endif
NBCOMPAT_CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM:Q}

_DO_CONFIGURE_TARGETS:=	libnbcompat-build ${_DO_CONFIGURE_TARGETS:Nlibnbcompat-build}

# The illumos fts(3) implementation is not (as of August 2018) largefile aware
.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	ac_cv_func_fts_open=no
.endif

.PHONY: libnbcompat-build
libnbcompat-build:
	@${STEP_MSG} "Configuring and building libnbcompat"
	${RUN} ${_ULIMIT_CMD}						\
	cd ${LIBNBCOMPAT_SRCDIR} && ${SETENV}				\
		AWK=${AWK:Q} CC=${CC:Q} CFLAGS=${CFLAGS:M*:Q}		\
		CPPFLAGS=${CPPFLAGS:M*:Q}				\
		${CONFIGURE_ENV:NLIBS=*} ${CONFIG_SHELL}		\
		${CONFIGURE_SCRIPT} ${NBCOMPAT_CONFIGURE_ARGS} &&	\
		${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS}
.if !empty(LIBNBCOMPAT_USE_PIC:M[Yy][Ee][Ss])
	@${STEP_MSG} "Configuring and building libnbcompat (PIC version)"
	${RUN} ${_ULIMIT_CMD}						\
	cd ${LIBNBCOMPAT_PICDIR} && ${SETENV}				\
		${CONFIGURE_ENV:NLIBS=*} CFLAGS=${CFLAGS:Q}" -fPIC"	\
		${CONFIG_SHELL}						\
		${CONFIGURE_SCRIPT} ${NBCOMPAT_CONFIGURE_ARGS} &&	\
		${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS}
.endif

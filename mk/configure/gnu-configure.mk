# $NetBSD: gnu-configure.mk,v 1.19 2019/04/20 16:32:42 rillig Exp $
#
# Package-settable variables:
#
# GNU_CONFIGURE
#	Whether the package has a GNU-style configure script as the
#	primary means of configuring itself to the platform.
#
#	Possible: yes no
#	Default: undefined
#
# GNU_CONFIGURE_STRICT
#	Whether unknown --enable/--disable/--with/--without options make
#	the package fail immediately.
#
#	Possible: yes no
#	Default: no

_VARGROUPS+=			gnu-configure
_USER_VARS.gnu-configure=	# none
_PKG_VARS.gnu-configure=	\
	GNU_CONFIGURE GNU_CONFIGURE_STRICT GNU_CONFIGURE_PREFIX \
	SET_LIBDIR GNU_CONFIGURE_LIBSUBDIR \
	GNU_CONFIGURE_LIBDIR GNU_CONFIGURE_INFODIR GNU_CONFIGURE_MANDIR \
	CONFIGURE_HAS_LIBDIR CONFIGURE_HAS_MANDIR CONFIGURE_HAS_INFODIR \
	OVERRIDE_DIRDEPTH.configure \
	USE_GNU_CONFIGURE_HOST

HAS_CONFIGURE=			defined
OVERRIDE_GNU_CONFIG_SCRIPTS=	defined
INSTALL_SH_OVERRIDE?=		# empty

CONFIGURE_ENV+=	CONFIG_SHELL=${CONFIG_SHELL:Q}
CONFIGURE_ENV+=	LIBS=${LIBS:M*:Q}
CONFIGURE_ENV+=	ac_given_INSTALL=${INSTALL:Q}\ -c\ -o\ ${BINOWN}\ -g\ ${BINGRP}

.if (defined(USE_LIBTOOL) || !empty(PKGPATH:Mdevel/libtool-base)) && \
    defined(_OPSYS_MAX_CMDLEN_CMD)
CONFIGURE_ENV+=	lt_cv_sys_max_cmd_len=${_OPSYS_MAX_CMDLEN_CMD:sh}
.endif

.if ${OPSYS} == "MirBSD"
CONFIGURE_ENV+=	lt_cv_deplibs_check_method='match_pattern /lib[^/]+(\.so\.[0-9]+\.[0-9]+|\.so|_pic\.a)$$'
.endif

GNU_CONFIGURE_PREFIX?=	${PREFIX}
CONFIGURE_ARGS+=	--prefix=${GNU_CONFIGURE_PREFIX:Q}

.if (defined(SET_LIBDIR) && !empty(SET_LIBDIR)) || \
	(defined(GNU_CONFIGURE_LIBDIR) && !empty(GNU_CONFIGURE_LIBDIR)) || \
	(defined(GNU_CONFIGURE_LIBSUBDIR) && !empty(GNU_CONFIGURE_LIBSUBDIR))
CONFIGURE_HAS_LIBDIR=	yes
.else
CONFIGURE_HAS_LIBDIR?=	no
.endif
.if defined(GNU_CONFIGURE_LIBSUBDIR) && !empty(GNU_CONFIGURE_LIBSUBDIR)
GNU_CONFIGURE_LIBDIR?=	${GNU_CONFIGURE_PREFIX}/lib/${GNU_CONFIGURE_LIBSUBDIR}
.else
GNU_CONFIGURE_LIBDIR?=	${GNU_CONFIGURE_PREFIX}/lib
.endif
.if !empty(CONFIGURE_HAS_LIBDIR:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--libdir=${GNU_CONFIGURE_LIBDIR}
.endif

USE_GNU_CONFIGURE_HOST?=	yes
.if !empty(USE_GNU_CONFIGURE_HOST:M[yY][eE][sS])
.  if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
CONFIGURE_ARGS+=	--build=${NATIVE_MACHINE_GNU_PLATFORM:Q}
.  else
CONFIGURE_ARGS+=	--build=${MACHINE_GNU_PLATFORM:Q}
.  endif
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM:Q}
.endif

# PKGINFODIR is the subdirectory of ${PREFIX} into which the info
# files are installed unless the software was configured with an
# installation prefix other than ${PREFIX}.
#
CONFIGURE_HAS_INFODIR?=	yes
.if ${GNU_CONFIGURE_PREFIX} == ${PREFIX}
GNU_CONFIGURE_INFODIR?=	${GNU_CONFIGURE_PREFIX}/${PKGINFODIR}
.else
GNU_CONFIGURE_INFODIR?=	${GNU_CONFIGURE_PREFIX}/info
.endif
.if defined(INFO_FILES) && !empty(CONFIGURE_HAS_INFODIR:M[yY][eE][sS])
CONFIGURE_ARGS+=	--infodir=${GNU_CONFIGURE_INFODIR:Q}
.endif

# PKGMANDIR is the subdirectory of ${PREFIX} into which the man and
# catman pages are installed unless the software was configured with
# an installation prefix other than ${PREFIX}.
#
CONFIGURE_HAS_MANDIR?=	 yes
.if ${GNU_CONFIGURE_PREFIX} == ${PREFIX}
GNU_CONFIGURE_MANDIR?=	${GNU_CONFIGURE_PREFIX}/${PKGMANDIR}
.else
GNU_CONFIGURE_MANDIR?=	${GNU_CONFIGURE_PREFIX}/man
.endif
.if !empty(CONFIGURE_HAS_MANDIR:M[yY][eE][sS])
CONFIGURE_ARGS+=	--mandir=${GNU_CONFIGURE_MANDIR:Q}
.endif

# prevent to invoke unwanted autoheader with patched configure.ac
.if empty(USE_TOOLS:Mautoheader*)
MAKE_FLAGS+=	am__configure_deps=
.endif

GNU_CONFIGURE_STRICT?=	no
CONFIGURE_ARGS+=	${"${GNU_CONFIGURE_STRICT:M[yY][eE][sS]}":?--enable-option-checking=fatal:}

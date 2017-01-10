# $NetBSD: ext.mk,v 1.44 2016/12/10 07:08:39 taca Exp $
#
# PHP extension package framework, for both PECL and bundled PHP extensions.
#
# Just include this file, define MODNAME, define PKGREVISION if necessary,
# add dependencies, and add the appropriate --with-configure-arg, then include
# bsd.pkg.mk.
#
# === User-settable variables ===
#
# PHP_AUTO_REGISTER_EXT
#	Indicates whether to automatically install php extension config
#	file into ${PKG_SYSCONFDIR}/php.d.
#
#	Possible: YES or NO
#	Default: YES
#
# === Infrastructure variables ===
#
# PHP_EXTENSION_DIRECTIVE
#	PHP extension directive used for configuration file.
#
#	Possible: extension zend_extension
#	Default:  extension
#
# === Package-settable variables ===
#
# PHP_ZEND_EXTENSION 
#	Set for Zend extension

.if !defined(PHPEXT_MK)
PHPEXT_MK=	defined

_VARGROUPS+=		phpext
_USER_VARS.phpext=	PHP_AUTO_REGISTER_EXT
_PKG_VARS.phpext=	MODNAME PECL_VERSION PKGMODNAME MODULESDIR \
			USE_PHP_EXT_PATCHES
_SYS_VARS.phpext=	DISTINFO_FILE PATCHDIR

.if defined(PECL_VERSION)
HOMEPAGE?=		http://pecl.php.net/package/${MODNAME}
.endif

.include "../../lang/php/phpversion.mk"

.if defined(PHPPKGSRCDIR)
.include "${PHPPKGSRCDIR}/Makefile.common"
.endif

PKGMODNAME?=		${MODNAME:S/-/_/}
PHPSETUPSUBDIR?=	#empty
MODULESDIR?=		${WRKSRC}/modules

.if !defined(PECL_VERSION)
# bundled extension
PKGNAME?=		${PHP_PKG_PREFIX}-${MODNAME}-${PHP_VERSION}
EXTRACT_ELEMENTS?=	${DISTNAME}/ext/${PKGMODNAME}
WRKSRC?=		${WRKDIR}/${EXTRACT_ELEMENTS}
DISTINFO_FILE=		${.CURDIR}/${PHPPKGSRCDIR}/distinfo
.else
# PECL extension
PKGNAME?=		${PHP_PKG_PREFIX}-${MODNAME}-${PECL_VERSION}
MASTER_SITES?=		http://pecl.php.net/get/
PECL_DISTNAME?=		${MODNAME}-${PECL_VERSION}
DISTNAME=		${PECL_DISTNAME}
DIST_SUBDIR?=		php-${MODNAME}
EXTRACT_SUFX?=		.tgz
.endif

PHP_CONF_EGDIR=		${PREFIX}/share/examples/php.d

PHP_EXT_CONF_DIR?=	${PKG_SYSCONFDIR}/php.d

PHPIZE?=		${BUILDLINK_PREFIX.php}/bin/phpize
PHP_CONFIG?=		${BUILDLINK_PREFIX.php}/bin/php-config

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-php-config=${PHP_CONFIG}

USE_CONFIG_WRAPPER=	YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	YES
USE_TOOLS+=		automake

PHP_AUTO_REGISTER_EXT?=	YES

.if !empty(PHP_ZEND_EXTENSION:U:M[Yy][Ye][Ss])
PHP_EXTENSION_DIRECTIVE=zend_extension
.else
PHP_EXTENSION_DIRECTIVE=extension
.endif

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}
MAKE_ENV+=		EXPORT_SYMBOLS_LDFLAGS="${EXPORT_SYMBOLS_LDFLAGS}"

DESTDIR_VARNAME?=	INSTALL_ROOT
GENERATE_PLIST+=	${ECHO} ${PHP_EXTENSION_DIR}/${PKGMODNAME}.${SHLIB_SUFFIX};
PRINT_PLIST_AWK+=	/^${PHP_EXTENSION_DIR:S/\//\\\//g}\/${PKGMODNAME}/ { next; }
.if empty(PHP_AUTO_REGISTER_EXT:M[Yy][Ee][Ss])
MESSAGE_SRC=		${.CURDIR}/../../lang/php/MESSAGE.module
.endif
MESSAGE_SUBST+=		MODNAME=${PKGMODNAME}
MESSAGE_SUBST+=		PHP_EXTENSION_DIR=${PHP_EXTENSION_DIR}
MESSAGE_SUBST+=		PHP_EXTENSION_DIRECTIVE=${PHP_EXTENSION_DIRECTIVE}

# Also include extension-specific message
.if exists(${.CURDIR}/MESSAGE)
MESSAGE_SRC+=		${.CURDIR}/MESSAGE
.endif

SHLIB_SUFFIX.SOM=	sl
SHLIB_SUFFIX.PE=	dll
SHLIB_SUFFIX=		${SHLIB_SUFFIX.${OBJECT_FMT}:Uso}

pre-configure:	phpize-module

phpize-module:
	@cookie=${WRKDIR}/.phpize_module_done;				\
	if [ ! -f $${cookie} ]; then					\
		cd ${WRKSRC}/${PHPSETUPSUBDIR} &&			\
		${SETENV}						\
			AUTOCONF=${TOOLS_DIR:Q}/bin/autoconf		\
			AUTOHEADER=${TOOLS_DIR:Q}/bin/autoheader	\
			ACLOCAL=${TOOLS_DIR:Q}/bin/aclocal		\
			LIBTOOLIZE=${LOCALBASE:Q}/bin/libtoolize	\
			${PHPIZE} &&					\
		${TOUCH} ${TOUCH_FLAGS} $${cookie};			\
	fi

.if defined(USE_PHP_EXT_PATCHES)
PATCHDIR=		${.CURDIR}/${PHPPKGSRCDIR}/patches
do-patch:
	${_PKG_SILENT}${_PKG_DEBUG}	\
	cd ${WRKSRC};			\
	for p in `${EGREP} -l '^\+\+\+ ext/${MODNAME}/' ${PATCHDIR}/patch-*`;do\
		${SED} -e 's,^+++ ext/${MODNAME}/,+++ ,' $$p | ${PATCH} ${PATCH_ARGS}; \
	done || ${TRUE}
.endif

.if !empty(PHP_AUTO_REGISTER_EXT:M[Yy][Ee][Ss])
_PHP_EXT_INI_NAME=	10-pkg-${MODNAME}.ini

post-build:	${WRKDIR}/${_PHP_EXT_INI_NAME}

${WRKDIR}/${_PHP_EXT_INI_NAME}:
	@${ECHO} ${PHP_EXTENSION_DIRECTIVE}=${PREFIX}/${PHP_EXTENSION_DIR}/${PKGMODNAME}.${SHLIB_SUFFIX} > ${.TARGET}

post-install: install-php-ext-ini

.PHONY: install-php-ext-ini
install-php-ext-ini: ${WRKDIR}/${_PHP_EXT_INI_NAME}
	${INSTALL_DATA_DIR} ${DESTDIR}${PHP_CONF_EGDIR}
	${INSTALL_DATA} ${WRKDIR}/${_PHP_EXT_INI_NAME} ${DESTDIR}${PHP_CONF_EGDIR}/

MAKE_DIRS+=	${PHP_EXT_CONF_DIR}
CONF_FILES+=	${PHP_CONF_EGDIR}/${_PHP_EXT_INI_NAME} ${PHP_EXT_CONF_DIR}/${_PHP_EXT_INI_NAME}

GENERATE_PLIST+=	${ECHO} ${PHP_CONF_EGDIR:S/^${PREFIX}\///}/${_PHP_EXT_INI_NAME};
PRINT_PLIST_AWK+=	/^${PHP_CONF_EGDIR:S/^${PREFIX}\///:S/\//\\\//g}\/${_PHP_EXT_INI_NAME}/ { next; }

.endif

.if defined(PHPPKGSRCDIR)
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.endif

.endif	# PHPEXT_MK

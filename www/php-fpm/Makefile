# $NetBSD: Makefile,v 1.23 2018/04/14 07:34:44 adam Exp $

PKGNAME=	${PHP_PKG_PREFIX}-fpm-${PHP_VERSION}
PKGREVISION=	1
CATEGORIES=	www

HOMEPAGE=	https://php-fpm.org/
MAINTAINER=	filip@joyent.com
COMMENT=	FPM interface for ${PKG_PHP}
LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config

USE_PHP_EXT_PATCHES=	yes
LIBTOOL_OVERRIDE=	# empty

.include "../../mk/bsd.prefs.mk"

FPM_USER?=		${APACHE_USER}
FPM_GROUP?=		${APACHE_GROUP}

BUILD_DEFS+=		VARBASE FPM_USER FPM_GROUP

BUILD_TARGET=		fpm
INSTALL_TARGET=		install-fpm
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}
DESTDIR_VARNAME=	INSTALL_ROOT

PKG_USERS_VARS=		FPM_USER
PKG_GROUPS_VARS=	FPM_GROUP
PKG_GROUPS=		${FPM_GROUP}
PKG_USERS=		${FPM_USER}:${FPM_GROUP}

PKG_GECOS.${FPM_USER}=	PHP FPM daemon user
PKG_SHELL.${FPM_USER}=	${NOLOGIN}

EGDIR=			${PREFIX}/share/examples/php
CONF_FILES=		${EGDIR}/php-fpm.conf.default ${PKG_SYSCONFDIR}/php-fpm.conf

.include "../../lang/php/phpversion.mk"

PLIST_VARS+=		fpmdotd

.if ${PKG_PHP_VERSION} >= 70
CONF_FILES+=		${EGDIR}/php-fpm.d/www.conf.default ${PKG_SYSCONFDIR}/php-fpm.d/www.conf
OWN_DIRS+=		${PKG_SYSCONFDIR}/php-fpm.d
PLIST.fpmdotd=		yes
.endif

CONFIGURE_ARGS+=	--enable-fpm
CONFIGURE_ARGS+=	--with-fpm-user=${FPM_USER}
CONFIGURE_ARGS+=	--with-fpm-group=${FPM_GROUP}

SMF_NAME=		php-fpm
RCD_SCRIPTS=		php_fpm
MESSAGE_SUBST+=		CGIDIR=${CGIDIR}
MESSAGE_SUBST+=		VARBASE=${VARBASE}

.include "${PHPPKGSRCDIR}/Makefile.php"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

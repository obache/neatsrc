# $NetBSD: plugins.mk,v 1.1 2016/09/13 15:56:01 taca Exp $
#

# plugin's PKGNAME
PKGNAME=	${PHP_PKG_PREFIX}-roundcube-plugin-${PLUGIN}-${RC_VERS}

DEPENDS+=	${PHP_PKG_PREFIX}-roundcube>=${RC_VERS}:../../mail/roundcube

#
# a few parameters
EXTRACT_ELEMENTS?=	${DISTNAME}/${PLUGIN_DIR}
PLUGIN_DIR?=		plugins/${PLUGIN}
CONF_PLUGINS?=		${PLUGIN}

#
# plugin directory
INSTALLATION_DIRS=	${RCDIR}/${PLUGIN_DIR}

.if !empty(CONF_PLUGINS)
ROUNDCUBE_BUILD_DEF_CMD= \
	${PKG_INFO} -Q @BUILD_DEF@ ${PHP_PKG_PREFIX}-roundcube 2>/dev/null \
	|| {	cd ${.CURDIR}/../../mail/roundcube \
		&& ${MAKE} ${MAKEFLAGS} show-var VARNAME=@BUILD_DEF@;}
WWW_USER?=	${ROUNDCUBE_BUILD_DEF_CMD:S/@BUILD_DEF@/WWW_USER/:sh}
WWW_GROUP?=	${ROUNDCUBE_BUILD_DEF_CMD:S/@BUILD_DEF@/WWW_GROUP/:sh}
.endif

.for f in ${CONF_PLUGINS}
CONF_FILES_PERMS+=	${EGDIR}/plugins/${f}/config.inc.php \
			${RCDIR}/plugins/${f}/config.inc.php \
			${WWW_USER} ${WWW_GROUP} 0640
.endfor

plugin-install:
.for i in ${PLUGIN_DIR}
	cd ${WRKSRC}/${i} && ${FIND} . -type f \! -name "*.orig" -print | \
		${PAX} -rw ${DESTDIR}${PREFIX}/${RCDIR}/${i}
	${FIND} ${DESTDIR}${PREFIX}/${RCDIR}/${i} -type f | \
		${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${DESTDIR}${PREFIX}/${RCDIR}/${i} -type d | \
		${XARGS} ${CHMOD} ${PKGDIRMODE}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/${RCDIR}/${i}
.endfor

.include "../../mail/roundcube/Makefile.common"

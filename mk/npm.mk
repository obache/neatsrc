# package installation framework for NPM
#
# === Package-settable variables ===
#
# NPM_PKGNAME
#	Package name on NPM
#
# NPM_PKGVERSION
#	Package Version on NPM

.if !defined(NPM_MK)
NPM_MK=	defined

_VARGROUPS+=		npm
_PKG_VARS.npm=		NPM_PKGNAME NPM_PKGVERSION

_NPM_PKG_PREFIX=	npm
_NPM=			${LOCALBASE}/bin/npm
TOOL_DEPENDS+=		nodejs-[0-9]*:../../lang/nodejs

WRKSRC?=			${WRKDIR}/package
USE_LANGUAGES?=	# none

NO_BUILD?=	yes

HOMEPAGE?=		http://www.npnjs.com/package/${NPM_PKGNAME}

PKGNAME?=		${_NPM_PKG_PREFIX}-${NPM_PKGNAME}-${NPM_PKGVERSION}
DISTFILES_VARS+=	npm
SITES.npm?=		https://registry.npmjs.org/${NPM_PKGNAME}/-/
DISTFILES.npm+=		${NPM_PKGNAME}-${NPM_PKGVERSION}.tgz

do-install: npm-install

.PHONY: npm-install
npm-install:
	${RUN}cd ${WRKSRC}; \
	${SETENV} ${INSTALL_ENV} ${MAKE_ENV} ${_NPM} -g \
		--prefix ${DESTDIR}${PREFIX} install

.endif	# NPM_MK

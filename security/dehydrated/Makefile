# $NetBSD$

DISTNAME=	dehydrated-0.4.0
CATEGORIES=	security
MASTER_SITES=	-https://github.com/lukas2511/${PKGBASE}/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

HOMEPAGE=	https://dehydrated.de/
COMMENT=	letsencrpyt/acme client implementad as a shell-script
LICENSE=	mit

USE_LANGUAGES=	# none
USE_TOOLS+=	bash:run curl:run sed:run grep:run mktemp:run openssl:run
USE_TOOLS+=	diff:run readlink:run awk:run pax

REPLACE_BASH+=	dehydrated test.sh docs/examples/hook.sh

NO_BUILD=	yes

PKG_SYSCONFSUBDIR=	${PKGBASE}

SUBST_CLASSES+=		sysconfdir
SUBST_STAGE.sysconfdir=	pre-configure
SUBST_FILES.sysconfdir=	dehydrated
SUBST_SED.sysconfdir=	-e s,/usr/local/etc/${PKGBASE},${PKG_SYSCONFDIR},g

.for c in config domains.txt hook.sh
CONF_FILES+=	${PREFIX}/share/doc/${PKGBASE}/examples/$c ${PKG_SYSCONFDIR}/$c
.endfor

INSTALLATION_DIRS+=	bin share/doc/${PKGBASE}

do-install:
	${RUN}cd ${WRKSRC};	\
	${INSTALL_SCRIPT} dehydrated ${DESTDIR}${PREFIX}/bin/dehydrated; \
	cd docs; ${PAX} -rwpp . ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"

# $NetBSD$
#

DISTNAME=	portmaster-3.19
CATEGORIES=	pkgtools
MASTER_SITES=	-https://github.com/freebsd/${PKGBASE}/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

HOMEPAGE=	http://portmaster.github.com/
COMMENT=	FreeBSD port management script
LICENSE=	2-clause-bsd

USE_TOOLS+=	sh:run install:run nice:run mktemp:run find:run unlink:run

NO_BUILD=	yes

REPLACE_SH+=	portmaster

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	portmaster files/portmaster.rc.sample files/portmaster.8
SUBST_SED.paths+=	-e 's,/usr/local/etc,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.paths+=	-e 's,/usr/X11R6,${X11BASE},g'
SUBST_SED.paths+=	-e 's,/usr/ports,${PKGSRCDIR},g'
SUBST_SED.paths+=	-e 's,PORTSDIR,PKGSRCDIR,g'
SUBST_SED.paths+=	-e 's,/usr/bin/make,${MAKE},g'
SUBST_SED.paths+=	-e 's,/usr/bin/install,${INSTALL},g'
SUBST_SED.paths+=	-e 's,/usr/bin/nice,${ITOOLS_PATH.nice},g'
SUBST_SED.paths+=	-e 's,/usr/bin/mktemp,${ITOOLS_PATH.mktemp},g'
SUBST_SED.paths+=	-e 's,/usr/bin/find,${FIND},g'
SUBST_SED.paths+=	-e 's,/bin/mkdir -p,${MKDIR},g'
SUBST_SED.paths+=	-e 's,/bin/unlink,${ITOOLS_PATH.unlink},g'
SUBST_SED.paths+=	-e 's,/usr/sbin/pkg_delete,${PKG_DELETE_CMD},g'
SUBST_SED.paths+=	-e 's,/var/db/pkg,${PKG_DBDIR},g'

INSTALLATION_DIRS+=	sbin ${PKGMANDIR}/man8 share/examples/${PKGBASE}
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/zsh/site-functions

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/portmaster ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/files/portmaster.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA} ${WRKSRC}/files/portmaster.rc.sample ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/
	${INSTALL_DATA} ${WRKSRC}/files/bash-completions ${DESTDIR}${PREFIX}/share/bash-completion/completions/${PKGBASE}.sh
	${INSTALL_DATA} ${WRKSRC}/files/zsh-completions ${DESTDIR}${PREFIX}/share/zsh/site-functions/_${PKGBASE}

.include "../../mk/bsd.pkg.mk"

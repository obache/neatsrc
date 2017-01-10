# $NetBSD$
#

DISTNAME=	cli_freebsd_10-2
PKGNAME=	tw_cli-10.2
CATEGORIES=	sysutils
MASTER_SITES=	http://docs.avagotech.com/docs-and-downloads/raid-controllers/raid-controllers-common-files/
EXTRACT_SUFX=	.zip

HOMEPAGE=	http://www.avagotech.com/support/
COMMENT=	3ware Strage Controller Management Command Line Interface

RESTRICTED=	Redistribution is not permitted
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

NO_BUILD=		yes

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

INSTALL_UNSTRIPPED=	yes

EMUL_PLATFORMS=	freebsd-i386 freebsd-x86_64

DIST_ARCH.i386=		x86
DIST_ARCH.x86_64=	x86_64
DIST_ARCH=		${DIST_ARCH.${EMUL_ARCH}}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DIST_ARCH}/tw_cli ${DESTDIR}${PREFIX}/sbin/tw_cli
	${INSTALL_MAN} ${WRKDIR}/tw_cli.8.nroff ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/tw_cli.8

.include "../../mk/bsd.pkg.mk"

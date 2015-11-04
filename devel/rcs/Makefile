# $NetBSD: Makefile,v 1.41 2015/11/01 14:24:45 tnn Exp $

DISTNAME=		rcs-5.9.4
CATEGORIES=		devel scm
MASTER_SITES=		${MASTER_SITE_GNU:=rcs/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cs.purdue.edu/homes/trinkle/RCS/
COMMENT=		GNU Revision Control System - version control software
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake diff:run diff3:run

TOOLS_INCOMPAT_PLATFORMS.diff=	SunOS-*-* OSF1-*-* AIX-*-* Minix-*-*
TOOLS_INCOMPAT_PLATFORMS.diff3=	SunOS-*-* OSF1-*-* AIX-*-* Minix-*-*

CONFIGURE_ENV+=		DIFF3=${TOOLS_PATH.diff3}

REPLACE_SH=		build-aux/extract-help

INFO_FILES=	yes

post-install:
	${LN} -s ${DESTDIR}${PREFIX}/bin/rlog ${DESTDIR}${PREFIX}/bin/rcslog
	${LN} -s ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/rlog.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/rcslog.1

.include "../../mk/bsd.pkg.mk"

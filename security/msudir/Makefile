# $NetBSD: Makefile,v 1.8 2009/02/11 23:19:01 abs Exp $

DISTNAME=	msudir-0.15
CATEGORIES=	security
MASTER_SITES=	http://msudir.googlecode.com/files/
EXTRACT_SUFX=	.tbz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://code.google.com/p/msudir/
COMMENT=	Easy setuid script management
LICENSE=	modified-bsd

MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR:Q}

SPECIAL_PERMS+=	bin/msudir ${SETUID_ROOT_PERMS}

.include "../../mk/bsd.pkg.mk"

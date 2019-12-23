# $NetBSD: Makefile,v 1.10 2019/11/04 21:12:55 rillig Exp $

DISTNAME=	msudir-0.15
CATEGORIES=	security
MASTER_SITES=	http://msudir.googlecode.com/files/
EXTRACT_SUFX=	.tbz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://code.google.com/archive/p/msudir/
COMMENT=	Easy setuid script management
LICENSE=	modified-bsd

MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR:Q}

SPECIAL_PERMS+=	bin/msudir ${SETUID_ROOT_PERMS}

.include "../../mk/bsd.pkg.mk"

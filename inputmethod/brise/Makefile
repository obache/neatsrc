# $NetBSD: Makefile,v 1.3 2017/08/01 16:52:55 wiz Exp $

DISTNAME=	brise-0.35
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://dl.bintray.com/lotem/rime/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rime.im/
COMMENT=	Official Rime Schema repository
LICENSE=	gnu-gpl-v3

DEPENDS+=	librime>=1.2:../../inputmethod/librime

WRKSRC=		${WRKDIR}/brise
USE_LANGUAGES=	# none

USE_TOOLS+=	gmake

.include "../../mk/bsd.pkg.mk"

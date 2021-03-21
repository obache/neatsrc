# $NetBSD: Makefile,v 1.34 2020/01/26 17:31:18 rillig Exp $

DISTNAME=	xfrisk-1.2
PKGREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://www.tuxick.net/xfrisk/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tuxick.net/xfrisk/
COMMENT=	X11 version of the classic Risk board game
# LICENSE pending investigation; absence of LICENSE violates
# "RESTRICTED implies LICENSE" pkgsrc rule.
#LICENSE=	gnu-gpl-v2
LICENSE=	generic-nonlicense

WRKSRC=		${WRKDIR}/XFrisk
USE_TOOLS+=	gmake

RESTRICTED=		Possible trademark infringement
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

.include "../../mk/bsd.prefs.mk"

LIBS.SunOS=	-lsocket -lnsl
MAKE_ENV+=	LIBS=${LIBS:Q}

.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

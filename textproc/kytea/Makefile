# $NetBSD$

DISTNAME=	kytea-0.4.7
CATEGORIES=	textproc
MASTER_SITES=	http://www.phontron.com/kytea/download/

HOMEPAGE=	http://www.phontron.com/kytea/
COMMENT=	Kyoto Text Analysis Toolkit
LICENSE=	apache-2.0

RESTRICTED=		Redistribution of included model is not permitted.
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	kytea.pc.in

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"

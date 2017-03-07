# $NetBSD$
#

DISTNAME=	cldr-emoji-annotation-30.0.3_2
PKGNAME=	${DISTNAME:S/_/pl/}
CATEGORIES=	misc
MASTER_SITES=	https://github.com/fujiwarat/cldr-emoji-annotation/releases/download/${PKGVERSION_NOREV:S/pl/_/}/

HOMEPAGE=	https://github.com/fujiwarat/cldr-emoji-annotation
COMMENT=	Emoji annotation files in CLDR
LICENSE=	gnu-lgpl-v2 AND unicode

GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	cldr-emoji-annotation.pc.in

.include "../../mk/bsd.pkg.mk"

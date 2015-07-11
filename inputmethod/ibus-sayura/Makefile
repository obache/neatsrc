# $NetBSD$

DISTNAME=	ibus-sayura-1.3.2
CATEGORIES=	inputmethod
MASTER_SITES=	https://fedorahosted.org/releases/i/b/ibus-sayura/

HOMEPAGE=	https://fedorahosted.org/ibus-sayura/
COMMENT=	Sinhala Trans IME engine for IBus
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

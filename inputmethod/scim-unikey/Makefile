# $NetBSD: Makefile,v 1.35 2019/07/21 22:25:13 wiz Exp $
#

DISTNAME=	scim-unikey-0.3.2
PKGREVISION=	7
CATEGORIES=	inputmethod
MASTER_SITES=	-https://github.com/scim-im/${PKGBASE}/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/archive/p/scim-unikey/
COMMENT=	Vietnamese Input Method Engine for SCIM using Unikey IME
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++03
USE_TOOLS+=		pkg-config msgfmt
USE_TOOLS+=		autopoint aclocal autoheader automake autoconf

USE_SCIM_GTKUTILS=	yes

CONFIGURE_SCRIPT=	autogen.sh

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

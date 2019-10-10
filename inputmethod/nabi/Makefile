# $NetBSD: Makefile,v 1.59 2019/07/21 22:25:11 wiz Exp $
#

DISTNAME=		nabi-1.0.0
CATEGORIES=		korean inputmethod
MASTER_SITES=		https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/nabi/

MAINTAINER=		minskim@NetBSD.org
HOMEPAGE=		https://code.google.com/archive/p/nabi/
COMMENT=		X Input Method for Korean
LICENSE=		gnu-gpl-v2 # or later

USE_TOOLS+=		pkg-config msgfmt
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libhangul+=	libhangul>=0.1.0
.include "../../inputmethod/libhangul/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

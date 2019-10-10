# $NetBSD$

PKGNAME=	imhangul3-3.1.1
DISTNAME=	${PKGBASE:S/3//}-${PKGVERSION_NOREV}
CATEGORIES=	inputmethod korean
MASTER_SITES=	${MASTER_SITE_GOOGLECODE:=imhangul/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://code.google.com/archive/p/imhangul/
COMMENT=	GTK+-3.0 Hangul Input Module
LICENSE=	gnu-gpl-v2 # or later

USE_TOOLS+=		pkg-config msgfmt
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
GTK3_IMMODULES=		YES
.include "../../x11/gtk3/modules.mk"

.include "../../inputmethod/libhangul/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

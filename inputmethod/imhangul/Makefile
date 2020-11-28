# $NetBSD: Makefile,v 1.50 2020/08/17 20:19:16 leot Exp $

DISTNAME=	imhangul-2.1.1
PKGREVISION=	25
CATEGORIES=	inputmethod korean
MASTER_SITES=	${MASTER_SITE_GOOGLECODE:=imhangul/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://code.google.com/archive/p/imhangul/
COMMENT=	GTK+-2.0 Hangul Input Module
LICENSE=	gnu-gpl-v2 # or later

USE_TOOLS+=		pkg-config msgfmt
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
GTK2_IMMODULES=		YES
.include "../../x11/gtk2/modules.mk"

.include "../../inputmethod/libhangul/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

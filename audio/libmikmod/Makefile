# $NetBSD: Makefile,v 1.62 2017/07/23 16:11:31 adam Exp $

DISTNAME=	libmikmod-3.3.11.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mikmod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mikmod.sourceforge.net/
COMMENT=	MikMod Sound Library
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-threads

INFO_FILES=		yes
PKGCONFIG_OVERRIDE=	libmikmod.pc.in

SUBST_CLASSES+=		addrpath
SUBST_STAGE.addrpath=	pre-configure
SUBST_FILES.addrpath=	libmikmod-config.in
SUBST_SED.addrpath=	-e '/^[ 	]*echo[ 	]/s|-L\([ 	]*[^ 	]*\)|${COMPILER_RPATH_FLAG}\1 -L\1|g'

.include "options.mk"
.include "../../mk/bsd.pkg.mk"

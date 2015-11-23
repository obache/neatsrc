# $NetBSD: Makefile,v 1.8 2015/03/15 16:47:19 hiramatsu Exp $
#

DISTNAME=	msgpack-1.3.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/msgpack/msgpack-c/releases/download/cpp-${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://msgpack.org/
COMMENT=	Binary-based efficient object serialization library
LICENSE=	boost-license

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE=	msgpack.pc.in

.include "options.mk"

.include "../../mk/bsd.pkg.mk"

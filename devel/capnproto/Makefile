# $NetBSD$

DISTNAME=	capnproto-c++-0.8.0
PKGNAME=	${DISTNAME:S/-c++-/-/}
CATEGORIES=	devel
MASTER_SITES=	https://capnproto.org/

HOMEPAGE=	https://capnproto.org/
COMMENT=	Insanely Fast Data Serialization Format
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	pkgconfig/capnp-json.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/capnp-rpc.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/capnp.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/kj-async.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/kj-gzip.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/kj-http.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/kj-test.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/kj-tls.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/kj.pc.in

TEST_TARGET=	check

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.13 2021/05/24 19:49:14 wiz Exp $

DISTNAME=	libgadu-1.12.2
PKGREVISION=	10
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=wojtekka/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://libgadu.net/
COMMENT=	Library for handling the protocol of Gadu-Gadu
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl:test pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-bind
# XXX: https://github.com/wojtekka/libgadu/issues/25
CONFIGURE_ARGS+=	--without-pthread
PKGCONFIG_OVERRIDE+=	pkgconfig/libgadu.pc.in
TEST_TARGET=		check

CONFIGURE_ENV.NetBSD+=	ac_cv_func_gethostbyname_r=no

.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
BUILDLINK_DEPMETHOD.libxml2=	test
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_DEPMETHOD.curl=	test
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

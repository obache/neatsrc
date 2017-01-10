# $NetBSD$

DISTNAME=	apr-iconv-1.2.1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_APACHE:=apr/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://apr.apache.org/
COMMENT=	Character set conversion library based on APR
LICENSE=	apache-2.0

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apr=${BUILDLINK_PREFIX.apr}/bin/apr-1-config

# override rules.mk from apr
MAKE_FLAGS+=	LIBTOOL=${LIBTOOL:Q}

BUILDLINK_API_DEPENDS.apr+=	apr>=1.5.1
.include "../../devel/apr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

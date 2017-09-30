# $NetBSD: Makefile,v 1.2 2017/09/16 19:26:47 wiz Exp $

MODNAME=	raphf
PECL_VERSION=	2.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pecl.php.net/package/raphf
COMMENT=	Resource and persistent handles factory
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	re2c>=0.13.0.4:../../devel/re2c

PHP_VERSIONS_ACCEPTED=	70

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

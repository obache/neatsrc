# $NetBSD: Makefile,v 1.6 2016/09/11 17:03:26 taca Exp $

MODNAME=	raphf
PECL_VERSION=	1.1.2
CATEGORIES=	devel

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://pecl.php.net/package/raphf
COMMENT=	Resource and persistent handles factory
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	re2c>=0.13.0.4:../../devel/re2c

PHP_VERSIONS_ACCEPTED=	56

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.6 2021/01/03 06:48:05 taca Exp $

MODNAME=	propro
PECL_VERSION=	2.1.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pecl.php.net/package/propro
COMMENT=	Reusable split-off of pecl_http's property proxy API
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	re2c>=0.13.0.4:../../devel/re2c

PHP_VERSIONS_INCOMPATIBLE=	56

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

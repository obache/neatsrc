# $NetBSD: Makefile,v 1.3 2017/12/09 02:39:19 taca Exp $

MODNAME=	propro
PECL_VERSION=	2.0.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pecl.php.net/package/propro
COMMENT=	Reusable split-off of pecl_http's property proxy API
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	re2c>=0.13.0.4:../../devel/re2c

PHP_VERSIONS_ACCEPTED=	70 71 72

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

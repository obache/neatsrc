# $NetBSD: Makefile,v 1.3 2017/12/09 02:28:19 taca Exp $

MODNAME=	raphf
PECL_VERSION=	2.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pecl.php.net/package/raphf
COMMENT=	Resource and persistent handles factory
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	re2c>=0.13.0.4:../../devel/re2c

PHP_VERSIONS_ACCEPTED=	70 71 72

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"

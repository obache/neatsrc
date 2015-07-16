# $NetBSD$

DISTNAME=	mod_wsgi-4.4.13
PKGNAME=	${APACHE_PKG_PREFIX}-${PYPKGPREFIX}-${DISTNAME:S/mod_//}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/m/mod_wsgi/

HOMEPAGE=	https://www.modwsgi.org/
COMMENT=	WSGI module for apache
LICENSE=	apache-2.0

APACHE_MODULE=		yes

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN:Q}

.include "../../lang/python/extension.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"

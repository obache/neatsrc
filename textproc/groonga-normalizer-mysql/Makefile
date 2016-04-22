# $NetBSD$

DISTNAME=	groonga-normalizer-mysql-1.1.0
CATEGORIES=	textproc databases
MASTER_SITES=	http://packages.groonga.org/source/groonga-normalizer-mysql/

HOMEPAGE=	https://github.com/groonga/groonga-normalizer-mysql
COMMENT=	MySQL compatible normalizer plugin for groonga
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
EXTRACT_USING=	gtar

PKGCONFIG_OVERRIDE+=	groonga-normalizer-mysql.pc.in

.include "options.mk"

.include "../../textproc/groonga/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD$

DISTNAME=	MathJax-2.5.3
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	www math
MASTER_SITES=	-https://github.com/mathjax/MathJax/archive/${PKGVERSION_NOREV}.tar.gz

HOMEPAGE=	https://www.mathjax.org/
COMMENT=	Beautiful math in all browser
LICENSE=	apache-2.0 AND ofl-v1.1 AND gfsl

USE_LANGUAGES=	# none
USE_TOOLS+=	pax

NO_BUILD=	yes

INSTALLATION_DIRS=	share/javascript/mathjax

do-install:
	${RUN}cd ${WRKSRC};${PAX} -rwpp . ${DESTDIR}${PREFIX}/share/javascript/mathjax

.include "../../mk/bsd.pkg.mk"

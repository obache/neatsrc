# $NetBSD$

DISTNAME=	groonga-command-parser-1.0.5
CATEGORIES=	textproc

HOMEPAGE=	https://github.com/groonga/groonga-command-parser
COMMENT=	Ruby library that parses Groonga commands
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${RUBY_PKGPREFIX}-ffi-[0-9]*:../../devel/ruby-ffi
DEPENDS+=	${RUBY_PKGPREFIX}-ffi-yajl-[0-9]*:../../devel/ruby-ffi-yajl
DEPENDS+=	${RUBY_PKGPREFIX}-groonga-command>=1.0.9:../../textproc/ruby-groonga-command

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

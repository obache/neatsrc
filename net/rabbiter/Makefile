# $NetBSD: Makefile,v 1.9 2015/12/30 14:39:12 taca Exp $
#

DISTNAME=	rabbiter-2.0.1
PKGREVISION=	1
CATEGORIES=	net ruby
MASTER_SITES=	${MASTER_SITE_RUBYGEMS}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rabbit-shocker.org/en/rabbiter/
COMMENT=	Twitter client for Rabbit
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	${RUBY_PKGPREFIX}-rabbit>=2.0.0:../../graphics/rabbit
DEPENDS+=	${RUBY_PKGPREFIX}-twitter_oauth-[0-9]*:../../security/ruby-twitter_oauth
DEPENDS+=	${RUBY_PKGPREFIX}-twitter-stream>=0.1.16:../../net/ruby-twitter-stream

CONFLICTS+=	${RUBY_PKGPREFIX}-rabbit<2.0.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

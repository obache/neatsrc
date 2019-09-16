# $NetBSD: Makefile,v 1.1 2019/09/14 18:11:37 tsutsui Exp $
#

DISTNAME=		atk-${VERSION}
COMMENT=		Ruby binding of ATK-1.0.x or later
CATEGORIES=		devel

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		${RUBY_PKGPREFIX}-gnome2-atk>=3.0.7nb1
SUPERSEDES+=		${RUBY_PKGPREFIX}-gnome2-atk>=3.0.7nb1

DEPENDS+=		${RUBY_PKGPREFIX}-glib2>=${VERSION}:../../devel/ruby-glib2

.include "../../devel/atk/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1 2019/09/14 18:11:37 tsutsui Exp $
#

DISTNAME=		gio2-${VERSION}
COMMENT=		Ruby binding of gio-2.0.x
CATEGORIES=		devel

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		${RUBY_PKGPREFIX}-gnome2-gio>=3.0.7nb1
SUPERSEDES+=		${RUBY_PKGPREFIX}-gnome2-gio>=3.0.7nb1

DEPENDS+=		${RUBY_PKGPREFIX}-gobject-introspection>=${VERSION}:../../devel/ruby-gobject-introspection

.include "../../devel/ruby-gobject-introspection/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

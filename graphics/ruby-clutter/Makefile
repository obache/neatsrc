# $NetBSD: Makefile,v 1.4 2019/09/14 18:11:38 tsutsui Exp $
#

DISTNAME=		clutter-${VERSION}
COMMENT=		Ruby binding of Clutter
CATEGORIES=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS+=		${RUBY_PKGPREFIX}-gnome2-clutter>=3.0.7nb1
SUPERSEDES+=		${RUBY_PKGPREFIX}-gnome2-clutter>=3.0.7nb1

DEPENDS+=	${RUBY_PKGPREFIX}-gobject-introspection>=${VERSION}:../../devel/ruby-gobject-introspection
DEPENDS+=	${RUBY_PKGPREFIX}-pango>=${VERSION}:../../devel/ruby-pango
DEPENDS+=	${RUBY_PKGPREFIX}-cairo-gobject>=${VERSION}:../../graphics/ruby-cairo-gobject
DEPENDS+=	clutter>=1.0:../../graphics/clutter

.include "../../graphics/clutter/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

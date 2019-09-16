# $NetBSD: Makefile,v 1.1 2019/09/14 18:11:38 tsutsui Exp $
#

DISTNAME=		clutter-gdk-${VERSION}
COMMENT=		Ruby binding of GDK specific API of Clutter
CATEGORIES=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS+=		${RUBY_PKGPREFIX}-gnome2-clutter-gdk>=3.0.7nb1
SUPERSEDES+=		${RUBY_PKGPREFIX}-gnome2-clutter-gdk>=3.0.7nb1

DEPENDS+=	${RUBY_PKGPREFIX}-clutter>=${VERSION}:../../graphics/ruby-clutter
DEPENDS+=	${RUBY_PKGPREFIX}-gdk3>=${VERSION}:../../graphics/ruby-gdk3

.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

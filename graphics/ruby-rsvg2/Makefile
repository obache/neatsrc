# $NetBSD: Makefile,v 1.1 2019/09/14 18:11:38 tsutsui Exp $
#

DISTNAME=		rsvg2-${VERSION}
COMMENT=		Ruby binding of librsvg
CATEGORIES=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS+=		${RUBY_PKGPREFIX}-gnome2-rsvg>=3.0.7nb1
SUPERSEDES+=		${RUBY_PKGPREFIX}-gnome2-rsvg>=3.0.7nb1

DEPENDS+=		${RUBY_PKGPREFIX}-gdk_pixbuf2>=${VERSION}:../../graphics/ruby-gdk_pixbuf2
DEPENDS+=		${RUBY_PKGPREFIX}-cairo>=1.14.3:../../graphics/ruby-cairo
DEPENDS+=		${RUBY_PKGPREFIX}-cairo-gobject>=${VERSION}:../../graphics/ruby-cairo-gobject

.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/ruby-cairo/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

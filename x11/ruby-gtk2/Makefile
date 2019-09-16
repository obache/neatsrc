# $NetBSD: Makefile,v 1.1 2019/09/14 18:11:39 tsutsui Exp $
#

DISTNAME=		gtk2-${VERSION}
COMMENT=		Ruby binding of GTK+-2.x
CATEGORIES=		x11

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		${RUBY_PKGPREFIX}-gnome2-gtk>=3.0.7nb1
SUPERSEDES+=		${RUBY_PKGPREFIX}-gnome2-gtk>=3.0.7nb1

DEPENDS+=		${RUBY_PKGPREFIX}-atk>=${VERSION}:../../devel/ruby-atk
DEPENDS+=		${RUBY_PKGPREFIX}-pango>=${VERSION}:../../devel/ruby-pango
DEPENDS+=		${RUBY_PKGPREFIX}-gdk_pixbuf2>=${VERSION}:../../graphics/ruby-gdk_pixbuf2

.include "../../devel/ruby-pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

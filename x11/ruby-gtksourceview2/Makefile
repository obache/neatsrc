# $NetBSD: Makefile,v 1.7 2020/11/05 09:09:28 ryoon Exp $
#

DISTNAME=		gtksourceview2-${VERSION}
COMMENT=		Ruby binding of gtksourceview2
PKGREVISION=		3
CATEGORIES=		x11

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS+=		${RUBY_PKGPREFIX}-gnome2-gtksourceview2>=3.0.7nb1
SUPERSEDES+=		${RUBY_PKGPREFIX}-gnome2-gtksourceview2>=3.0.7nb1

DEPENDS+=		${RUBY_PKGPREFIX}-gtk2>=${VERSION}:../../x11/ruby-gtk2

.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../x11/ruby-gtk2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

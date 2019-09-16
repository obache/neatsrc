# $NetBSD: Makefile,v 1.1 2019/09/14 18:11:37 tsutsui Exp $
#

DISTNAME=		glib2-${VERSION}
COMMENT=		Ruby binding of GLib-2.x
CATEGORIES=		devel

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		${RUBY_PKGPREFIX}-gnome2-glib>=3.0.7nb1
SUPERSEDES+=		${RUBY_PKGPREFIX}-gnome2-glib>=3.0.7nb1

DEPENDS+=		${RUBY_PKGPREFIX}-native-package-installer>=1.0.3:../../devel/ruby-native-package-installer
DEPENDS+=		${RUBY_PKGPREFIX}-pkg-config>=1.3.5:../../devel/ruby-pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

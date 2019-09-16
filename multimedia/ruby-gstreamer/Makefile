# $NetBSD: Makefile,v 1.1 2019/09/14 18:11:39 tsutsui Exp $
#

DISTNAME=		gstreamer-${VERSION}
COMMENT=		Ruby binding of GStreamer 1.0.x or later
CATEGORIES=		multimedia

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS+=		${RUBY_PKGPREFIX}-gnome2-gstreamer>=3.0.7nb1
SUPERSEDES+=		${RUBY_PKGPREFIX}-gnome2-gstreamer>=3.0.7nb1

DEPENDS+=		${RUBY_PKGPREFIX}-gobject-introspection>=${VERSION}:../../devel/ruby-gobject-introspection
DEPENDS+=		gst-plugins1-base-[0-9]*:../../multimedia/gst-plugins1-base

.include "../../devel/ruby-gobject-introspection/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

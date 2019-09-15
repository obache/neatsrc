# $NetBSD: Makefile,v 1.59 2019/09/14 18:37:04 tsutsui Exp $
#

DISTNAME=	rabbit-2.2.1
PKGREVISION=	1
CATEGORIES=	graphics ruby

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rabbit-shocker.org/
COMMENT=	RD-document-based presentation application
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	${RUBY_PKGPREFIX}-gtk2>=0.90.3:../../x11/ruby-gtk2
DEPENDS+=	${RUBY_PKGPREFIX}-gio2>=1.1.4:../../devel/ruby-gio2
#DEPENDS+=	${RUBY_PKGPREFIX}-gdk_pixbuf2>=3.0.9:../../graphics/ruby-gdk_pixbuf2
DEPENDS+=	${RUBY_PKGPREFIX}-rsvg2-[0-9]*:../../graphics/ruby-rsvg2
DEPENDS+=	${RUBY_PKGPREFIX}-poppler-[0-9]*:../../print/ruby-poppler
DEPENDS+=	${RUBY_PKGPREFIX}-hikidoc-[0-9]*:../../textproc/ruby-hikidoc
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri-[0-9]*:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-rdtool>=0.6.20:../../textproc/ruby-rdtool
DEPENDS+=	${RUBY_PKGPREFIX}-rttool-[0-9]*:../../textproc/ruby-rttool
DEPENDS+=	${RUBY_PKGPREFIX}-coderay>=1.0.0:../../textproc/ruby-coderay
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown-[0-9]*:../../textproc/ruby-kramdown
DEPENDS+=	${RUBY_PKGPREFIX}-gettext>=3.0.1:../../devel/ruby-gettext
DEPENDS+=	${RUBY_PKGPREFIX}-faraday-[0-9]*:../../www/ruby-faraday

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"

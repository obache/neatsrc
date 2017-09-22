# $NetBSD$
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.groonga-normalizer-mysql
PKG_SUPPORTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
USE_TOOLS+=	bash ruby
CONFIGURE_ARGS+=	--with-ruby=${RUBY}
TEST_TARGET=		check
REPLACE_BASH+=		test/run-test.sh
.include "../../lang/ruby/rubyversion.mk"
TOOL_DEPENDS+=	${RUBY_PKGPREFIX}-groonga-command-parser-[0-9]*:../../textproc/ruby-groonga-command-parser
TOOL_DEPENDS+=	${RUBY_PKGPREFIX}-msgpack-[0-9]*:../../devel/ruby-msgpack
.else
CONFIGURE_ARGS+=	--without-ruby
.endif

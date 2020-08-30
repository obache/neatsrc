# $NetBSD$
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.ibus-hangul
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS=	tests

PLIST_VARS+=	tests

.include "../../mk/bsd.options.mk"

#
# tests
#
.if !empty(PKG_OPTIONS:Mtests)
CONFIGURE_ARGS+=	--enable-installed-tests
PLIST.tests=		yes
.else
CONFIGURE_ARGS+=	--disable-installed-tests
BUILDLINK_DEPMETHOD.gtk3+=	build
.endif
.include "../../x11/gtk3/buildlink3.mk"
TEST_MAKE_FLAGS+=	DISABLE_GUI_TESTS=ibus-hangul

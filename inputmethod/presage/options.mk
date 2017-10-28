# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.presage
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
CONFIGURE_ARGS+=	--without-cppunit-prefix
CONFIGURE_ARGS+=	--without-cppunit-exec-prefix
CONFIGURE_ENV+=		CPPUNIT_CONFIG=${TOOLS_DIR:Q}/bin/cppunit-config
BUILDLINK_DEPMETHOD.cppunit?=	build
USE_TOOLS+=	pkg-config
.include "../../devel/cppunit/buildlink3.mk"
.include "../../devel/cppunit/cppunit-config.mk"
TEST_TARGET=		check
.else
CONFIGURE_ARGS+=	--without-cppunit-prefix
CONFIGURE_ARGS+=	--without-cppunit-exec-prefix
CONFIGURE_ENV+=		CPPUNIT_CONFIG=no
.endif

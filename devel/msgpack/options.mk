# $NetBSD: options.mk,v 1.1.1.1 2011/04/06 13:01:30 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.msgpack
PKG_SUPPORTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
BUILDLINK_DEPMETHOD.boost-libs+=	build
.include "../../devel/boost-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.googletest+=	build
.include "../../devel/googletest/buildlink3.mk"
BUILDLINK_DEPMETHOD.zlib+=	build
.include "../../devel/zlib/buildlink3.mk"
TEST_TARGET=	test
CMAKE_ARGS+=	-DMSGPACK_BUILD_TESTS:BOOL=ON
CMAKE_ARGS+=	-DMSGPACK_BOOST:BOOL=ON
TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}:${BUILDLINK_PREFIX.googletest}/lib
CXXFLAGS+=	${"${CC_VERSION:Mgcc*}" != "":?-Wno-conversion-null:}
.else
CMAKE_ARGS+=	-DMSGPACK_BUILD_TESTS:BOOL=OFF
.endif

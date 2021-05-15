# $NetBSD: options.mk,v 1.2 2021/02/20 20:53:01 ryoon Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.librime
PKG_SUPPORTED_OPTIONS=		logging tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlogging)
.include "../../devel/google-glog/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_LOGGING:BOOL=ON
TEST_TARGET=	test
.else
CMAKE_ARGS+=	-DENABLE_LOGGING:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mtests)
.include "../../devel/googletest/buildlink3.mk"
CMAKE_ARGS+=	-DBUILD_TEST:BOOL=ON
TEST_TARGET=	test
.else
CMAKE_ARGS+=	-DBUILD_TEST:BOOL=OFF
.endif

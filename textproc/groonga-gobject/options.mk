# $NetBSD$
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.groonga-gobject
PKG_SUPPORTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
CONFIGURE_ARGS+=	--with-cutter
BUILDLINK_API_DEPENDS.cutter+=		cutter>=1.1.6
.include "../../devel/cutter/buildlink3.mk"
do-test:
	${RUN}cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${BUILDLINK_PREFIX.cutter}/bin/cutter test/
.else
CONFIGURE_ARGS+=	--without-cutter
.endif

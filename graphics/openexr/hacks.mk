.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-[0-4].*)
CONFIGURE_ARGS+=	--enable-cxxstd=11
.endif

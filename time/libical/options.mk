# $NetBSD$
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.libical
PKG_SUPPORTED_OPTIONS=	icu introspection
PKG_SUGGESTED_OPTIONS=	icu

PLIST_VARS+=	introspection

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Micu)
.  include "../../textproc/icu/buildlink3.mk"
CMAKE_ARGS+=	-DICU_BASE:PATH=${BUILDLINK_PREFIX.icu}
.else
CMAKE_ARGS+=	-DICU_INCLUDE_DIR:PATH=
CMAKE_ARGS+=	-DICU_LIBRARY:FILEPATH=
.endif

.if !empty(PKG_OPTIONS:Mintrospection)
BUILDLINK_DEPMETHOD.gobject-introsepction=	build
.  include "../../devel/gobject-introspection/buildlink3.mk"
CMAKE_ARGS+=	-DGOBJECT_INTROSPECTION:BOOL=True
USE_TOOLS+=	gmake pkg-config
PLIST.introspection=	yes
.else
CMAKE_ARGS+=	-DGOBJECT_INTROSPECTION:BOOL=False
.endif

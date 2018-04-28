# $NetBSD$
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.libical
PKG_SUPPORTED_OPTIONS=	introspection
PKG_SUGGESTED_OPTIONS=	#empty

PLIST_VARS+=	introspection

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mintrospection)
BUILDLINK_DEPMETHOD.gobject-introsepction=	build
.  include "../../devel/gobject-introspection/buildlink3.mk"
CMAKE_ARGS+=	-DGOBJECT_INTROSPECTION:BOOL=True
USE_TOOLS+=	gmake
PLIST.introspection=	yes
.else
CMAKE_ARGS+=	-DGOBJECT_INTROSPECTION:BOOL=False
.endif

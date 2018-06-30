# $NetBSD$
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.libfep
PKG_SUPPORTED_OPTIONS=	glib introspection vala
PKG_SUGGESTED_OPTIONS=	glib introspection vala

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	glib introspection vala

.if !empty(PKG_OPTIONS:Mglib)
PLIST.glib=		yes
.include "../../devel/glib2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-glib
.else
CONFIGURE_ARGS+=	--disable-glib
.endif

.if !empty(PKG_OPTIONS:Mintrospection)
PLIST.introspection=		yes
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.9.0
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-introspection=yes
.else
CONFIGURE_ARGS+=	--enable-introspection=no
.endif

.if !empty(PKG_OPTIONS:Mvala)
PLIST.vala=		yes
.include "../../lang/vala/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-vala=yes
.else
CONFIGURE_ARGS+=	--enable-vala=no
.endif

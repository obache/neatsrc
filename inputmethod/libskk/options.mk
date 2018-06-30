# $NetBSD: options.mk,v 1.1 2014/09/10 09:34:45 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.libskk
PKG_SUPPORTED_OPTIONS=	fep introspection
PKG_SUGGESTED_OPTIONS=	introspection

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	fep introspection

.if !empty(PKG_OPTIONS:Mfep)
PLIST.fep=		yes
.include "../../inputmethod/libfep/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-fep
.else
CONFIGURE_ARGS+=	--disable-fep
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

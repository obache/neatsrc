# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.fcitx
PKG_SUPPORTED_OPTIONS=	gtk2 gtk3 qt4 introspection enchant opencc
PKG_SUGGESTED_OPTIONS=	gtk2 gtk3 qt4 introspection enchant opencc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk2 gtk3 qt4 introspection

.if !empty(PKG_OPTIONS:Mgtk2)
PLIST.gtk2=		yes
.include "../../x11/gtk2/buildlink3.mk"
GTK2_IMMODULES=	YES
.include "../../x11/gtk2/modules.mk"
CMAKE_ARGS+=	-DENABLE_GTK2_IM_MODULE:BOOL=ON
.else
CMAKE_ARGS+=	-DENABLE_GTK2_IM_MODULE:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
PLIST.gtk3=		yes
.include "../../x11/gtk3/buildlink3.mk"
GTK3_IMMODULES=	YES
.include "../../x11/gtk3/modules.mk"
CMAKE_ARGS+=	-DENABLE_GTK3_IM_MODULE:BOOL=ON
.else
CMAKE_ARGS+=	-DENABLE_GTK3_IM_MODULE:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mqt4)
PLIST.qt4=		yes
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_QT:BOOL=ON
CMAKE_ARGS+=	-DENABLE_QT_GUI:BOOL=ON
CMAKE_ARGS+=	-DENABLE_QT_IM_MODULE:BOOL=ON
.else
CMAKE_ARGS+=	-DENABLE_QT:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_QT_GUI:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_QT_IM_MODULE:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Menchant)
.include "../../textproc/enchant/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_ENCHANT:BOOL=ON
.else
CMAKE_ARGS+=	-DENABLE_ENCHANT:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mopencc)
.include "../../converters/opencc/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_OPENCC:BOOL=ON
.else
CMAKE_ARGS+=	-DENABLE_OPENCC:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mintrospection)
PLIST.introspection=		yes
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_GIR:BOOL=ON
.else
CMAKE_ARGS+=	-DENABLE_GIR:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mbacktrace)
PLIST.backtrace=		yes
.include "../../devel/libexecinfo/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_BACKTRACE:BOOL=ON
.else
CMAKE_ARGS+=	-DENABLE_BACKTRACE:BOOL=OFF
.endif

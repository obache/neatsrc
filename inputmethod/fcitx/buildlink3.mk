# $NetBSD$
#

BUILDLINK_TREE+=	fcitx

.if !defined(FCITX_BUILDLINK3_MK)
FCITX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fcitx+=	fcitx>=4.2.9
BUILDLINK_PKGSRCDIR.fcitx?=	../../inputmethod/fcitx

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"

.if defined(USE_FCITX_QT_GUI) && !empty(USE_FCITX_QT_GUI:M[Yy][Ee][Ss])
pkgbase := fcitx
.include "../../mk/pkg-build-options.mk"
.  if !empty(PKG_BUILD_OPTIONS.fcitx:Mqt4)
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.  else
FAIL_REASON+=	Fcitx Qt GUI is required, but not enabled with option.
.  endif
.endif

.endif	# FCITX_BUILDLINK3_MK

BUILDLINK_TREE+=	-fcitx

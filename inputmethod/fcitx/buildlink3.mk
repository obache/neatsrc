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
.endif	# FCITX_BUILDLINK3_MK

BUILDLINK_TREE+=	-fcitx

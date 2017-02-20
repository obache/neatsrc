# $NetBSD$
#

BUILDLINK_TREE+=	fcitx-qt5

.if !defined(FCITX_QT5_BUILDLINK3_MK)
FCITX_QT5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fcitx-qt5+=	fcitx-qt5>=1.1.0
BUILDLINK_PKGSRCDIR.fcitx-qt5?=	../../inputmethod/fcitx-qt5

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# FCITX_QT5_BUILDLINK3_MK

BUILDLINK_TREE+=	-fcitx-qt5

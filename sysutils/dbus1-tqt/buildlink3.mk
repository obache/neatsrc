# $NetBSD$

BUILDLINK_TREE+=	dbus1-tqt

.if !defined(DBUS1_TQT_BUILDLINK3_MK)
DBUS1_TQT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dbus1-tqt+=	dbus1-tqt>=14.0.4
BUILDLINK_PKGSRCDIR.dbus1-tqt?=	../../sysutils/dbus1-tqt

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/tqtinterface/buildlink3.mk"
.endif	# DBUS1_TQT_BUILDLINK3_MK

BUILDLINK_TREE+=	-dbus1-tqt

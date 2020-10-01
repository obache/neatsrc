# $NetBSD$

BUILDLINK_TREE+=	dbus-tqt

.if !defined(DBUS_TQT_BUILDLINK3_MK)
DBUS_TQT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dbus-tqt+=	dbus-tqt>=14.0.4
BUILDLINK_PKGSRCDIR.dbus-tqt?=	../../sysutils/dbus-tqt

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/tqtinterface/buildlink3.mk"
.endif	# DBUS_TQT_BUILDLINK3_MK

BUILDLINK_TREE+=	-dbus-tqt

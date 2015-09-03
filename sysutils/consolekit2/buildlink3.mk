# $NetBSD$

BUILDLINK_TREE+=	consolekit2

.if !defined(CONSOLEKIT2_BUILDLINK3_MK)
CONSOLEKIT2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.consolekit2+=	consolekit2>=1.0.0
BUILDLINK_PKGSRCDIR.consolekit2?=	../../sysutils/consolekit2

.include "../../sysutils/dbus/buildlink3.mk"
.endif # CONSOLEKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-consolekit2

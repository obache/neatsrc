# $NetBSD$

BUILDLINK_TREE+=	tdebase

.if !defined(TDEBASE_BUILDLINK3_MK)
TDEBASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tdebase+=	tdebase>=14.0.4
BUILDLINK_PKGSRCDIR.tdebase?=	../../x11/tdebase

#.include "../../devel/glib2/buildlink3.mk"
#.include "../../sysutils/dbus/buildlink3.mk"
#.include "../../sysutils/dbus-tqt/buildlink3.mk"
#.include "../../sysutils/dbus1-tqt/buildlink3.mk"
#.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/tqtinterface/buildlink3.mk"
.include "../../x11/tdelibs/buildlink3.mk"
.endif	# TDEBASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-tdebase

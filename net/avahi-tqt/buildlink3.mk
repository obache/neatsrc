# $NetBSD$

BUILDLINK_TREE+=	avahi-tqt

.if !defined(AVAHI_TQT_BUILDLINK3_MK)
AVAHI_TQT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.avahi-tqt+=	avahi-tqt>=14.0.0
BUILDLINK_PKGSRCDIR.avahi-tqt?=	../../net/avahi-tqt

.include "../../net/avahi/buildlink3.mk"
.include "../../x11/tqtinterface/buildlink3.mk"
.endif	# AVAHI_TQT_BUILDLINK3_MK

BUILDLINK_TREE+=	-avahi-tqt

# $NetBSD$

BUILDLINK_TREE+=	tdemultimedia

.if !defined(TDEMULTIMEDIA_BUILDLINK3_MK)
TDEMULTIMEDIA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tdemultimedia+=	tdemultimedia>=14.0.4
BUILDLINK_PKGSRCDIR.tdemultimedia?=	../../multimedia/tdemultimedia

.include "../../x11/tqtinterface/buildlink3.mk"
.include "../../x11/tdelibs/buildlink3.mk"
.endif	# TDEMULTIMEDIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-tdemultimedia

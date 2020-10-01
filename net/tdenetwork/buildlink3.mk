# $NetBSD$

BUILDLINK_TREE+=	tdenetwork

.if !defined(TDENETWORK_BUILDLINK3_MK)
TDENETWORK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tdenetwork+=	tdenetwork>=14.0.4
BUILDLINK_PKGSRCDIR.tdenetwork?=	../../net/tdenetwork

#.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/tdelibs/buildlink3.mk"
.endif	# TDENETWORK_BUILDLINK3_MK

BUILDLINK_TREE+=	-tdenetwork

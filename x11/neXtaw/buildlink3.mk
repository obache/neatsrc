# $NetBSD: buildlink3.mk,v 1.17 2015/12/29 04:54:39 dholland Exp $

BUILDLINK_TREE+=	neXtaw

.if !defined(NEXTAW_BUILDLINK3_MK)
NEXTAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.neXtaw+=	neXtaw>=0.15.1
BUILDLINK_ABI_DEPENDS.neXtaw+=	neXtaw>=0.15.1nb2
BUILDLINK_PKGSRCDIR.neXtaw?=	../../x11/neXtaw

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif # NEXTAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-neXtaw

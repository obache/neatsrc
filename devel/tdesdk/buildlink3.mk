# $NetBSD$

BUILDLINK_TREE+=	tdesdk

.if !defined(TDESDK_BUILDLINK3_MK)
TDESDK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tdesdk+=	tdesdk>=14.0.4
BUILDLINK_PKGSRCDIR.tdesdk?=	../../devel/tdesdk

.include "../../x11/tdelibs/buildlink3.mk"
.include "../../x11/tqt3-tools/buildlink3.mk"
.endif	# TDESDK_BUILDLINK3_MK

BUILDLINK_TREE+=	-tdesdk

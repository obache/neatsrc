# $NetBSD: buildlink3.mk,v 1.30 2018/11/14 22:21:19 kleink Exp $

BUILDLINK_TREE+=	pangomm

.if !defined(PANGOMM_BUILDLINK3_MK)
PANGOMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pangomm+=	pangomm>=2.26.2
BUILDLINK_ABI_DEPENDS.pangomm+=	pangomm>=2.40.1nb7
BUILDLINK_PKGSRCDIR.pangomm?=	../../devel/pangomm

BUILDLINK_INCDIRS.pangomm=	include/pangomm-1.4 lib/pangomm-1.4/include

.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairomm/buildlink3.mk"
.endif # PANGOMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-pangomm

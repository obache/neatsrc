# $NetBSD$

BUILDLINK_TREE+=	tdeaccessibility

.if !defined(TDEACCESSIBILITY_BUILDLINK3_MK)
TDEACCESSIBILITY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tdeaccessibility+=	tdeaccessibility>=14.0.4
BUILDLINK_PKGSRCDIR.tdeaccessibility?=	../../misc/tdeaccessibility

.include "../../x11/tqtinterface/buildlink3.mk"
.include "../../x11/tdelibs/buildlink3.mk"
.endif	# TDEACCESSIBILITY_BUILDLINK3_MK

BUILDLINK_TREE+=	-tdeaccessibility

# $NetBSD$

BUILDLINK_TREE+=	presage

.if !defined(PRESAGE_BUILDLINK3_MK)
PRESAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.presage+=	presage>=0.9.1
BUILDLINK_PKGSRCDIR.presage?=	../../inputmethod/presage

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.endif	# PRESAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-presage

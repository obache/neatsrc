# $NetBSD$

BUILDLINK_TREE+=	tqca

.if !defined(TQCA_BUILDLINK3_MK)
TQCA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tqca+=	tqca>=14.0.10
BUILDLINK_PKGSRCDIR.tqca?=	../../security/tqca
BUILDLINK_INCDIRS.tqca=		tqt3/include

.include "../../x11/tqtinterface/buildlink3.mk"
.endif	# TQCA_BUILDLINK3_MK

BUILDLINK_TREE+=	-tqca

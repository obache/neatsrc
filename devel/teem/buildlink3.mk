# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:30 joerg Exp $

BUILDLINK_TREE+=	teem

.if !defined(TEEM_BUILDLINK3_MK)
TEEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.teem+=		teem>=1.8.0
BUILDLINK_ABI_DEPENDS.teem+=		teem>=1.8.0nb1
BUILDLINK_PKGSRCDIR.teem?=		../../devel/teem

.endif # TEEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-teem

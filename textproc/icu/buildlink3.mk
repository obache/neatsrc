# $NetBSD: buildlink3.mk,v 1.36 2018/04/14 07:05:08 adam Exp $

BUILDLINK_TREE+=	icu

.if !defined(ICU_BUILDLINK3_MK)
ICU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.icu+=	icu>=3.4
BUILDLINK_ABI_DEPENDS.icu+=	icu>=61.1
BUILDLINK_PKGSRCDIR.icu?=	../../textproc/icu

.if !empty(USE_LANGUAGES:Mc++)
USE_LANGUAGES+=	c++11
.endif

.endif # ICU_BUILDLINK3_MK

BUILDLINK_TREE+=	-icu

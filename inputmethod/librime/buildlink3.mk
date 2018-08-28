# $NetBSD: buildlink3.mk,v 1.9 2018/08/16 18:54:30 adam Exp $
#

BUILDLINK_TREE+=	librime

.if !defined(LIBRIME_BUILDLINK3_MK)
LIBRIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librime+=	librime>=1.0
BUILDLINK_ABI_DEPENDS.librime?=	librime>=1.0nb11
BUILDLINK_PKGSRCDIR.librime?=	../../inputmethod/librime

.endif	# LIBRIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-librime

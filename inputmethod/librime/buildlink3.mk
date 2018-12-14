# $NetBSD: buildlink3.mk,v 1.10 2018/12/13 19:51:35 adam Exp $
#

BUILDLINK_TREE+=	librime

.if !defined(LIBRIME_BUILDLINK3_MK)
LIBRIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librime+=	librime>=1.0
BUILDLINK_ABI_DEPENDS.librime?=	librime>=1.3.2nb1
BUILDLINK_PKGSRCDIR.librime?=	../../inputmethod/librime

.endif	# LIBRIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-librime

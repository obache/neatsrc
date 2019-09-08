# $NetBSD: buildlink3.mk,v 1.12 2019/08/22 12:23:24 ryoon Exp $
#

BUILDLINK_TREE+=	librime

.if !defined(LIBRIME_BUILDLINK3_MK)
LIBRIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librime+=	librime>=1.0
BUILDLINK_ABI_DEPENDS.librime?=	librime>=1.5.3nb2
BUILDLINK_PKGSRCDIR.librime?=	../../inputmethod/librime

.endif	# LIBRIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-librime

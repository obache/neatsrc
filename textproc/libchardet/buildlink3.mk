# $NetBSD$

BUILDLINK_TREE+=	libchardet

.if !defined(LIBCHARDET_BUILDLINK3_MK)
LIBCHARDET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libchardet+=	libchardet>=1.0.5
BUILDLINK_PKGSRCDIR.libchardet?=	../../textproc/libchardet
.endif	# LIBCHARDET_BUILDLINK3_MK

BUILDLINK_TREE+=	-libchardet

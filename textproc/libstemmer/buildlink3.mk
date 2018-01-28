# $NetBSD$

BUILDLINK_TREE+=	libstemmer

.if !defined(LIBSTEMMER_BUILDLINK3_MK)
LIBSTEMMER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libstemmer+=	libstemmer>=0
BUILDLINK_PKGSRCDIR.libstemmer?=	../../textproc/libstemmer
.endif	# LIBSTEMMER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libstemmer

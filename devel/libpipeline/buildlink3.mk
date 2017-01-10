# $NetBSD$
#

BUILDLINK_TREE+=	libpipeline

.if !defined(LIBPIPELINE_BUILDLINK3_MK)
LIBPIPELINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpipeline+=	libpipeline>=1.4.0
BUILDLINK_PKGSRCDIR.libpipeline?=	../../devel/libpipeline
.endif	# LIBPIPELINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpipeline

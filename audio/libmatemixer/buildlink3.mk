# $NetBSD$
#

BUILDLINK_TREE+=	libmatemixer

.if !defined(LIBMATEMIXER_BUILDLINK3_MK)
LIBMATEMIXER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmatemixer+=	libmatemixer>=1.12.0
BUILDLINK_PKGSRCDIR.libmatemixer?=	../../audio/libmatemixer

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBMATEMIXER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmatemixer

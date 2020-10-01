# $NetBSD$

BUILDLINK_TREE+=	libcarddav

.if !defined(LIBCARDDAV_BUILDLINK3_MK)
LIBCARDDAV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcarddav+=	libcarddav>=14.0.4
BUILDLINK_PKGSRCDIR.libcarddav?=	../../net/libcarddav

.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif	# LIBCARDDAV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcarddav

# $NetBSD$

BUILDLINK_TREE+=	libfep

.if !defined(LIBFEP_BUILDLINK3_MK)
LIBFEP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfep+=	libfep>=0.1.0
BUILDLINK_PKGSRCDIR.libfep?=	../../inputmethod/libfep

#.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBFEP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfep

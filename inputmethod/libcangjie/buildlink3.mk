# $NetBSD$
#

BUILDLINK_TREE+=	libcangjie

.if !defined(LIBCANGJIE_BUILDLINK3_MK)
LIBCANGJIE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcangjie+=	libcangjie>=1.3
BUILDLINK_PKGSRCDIR.libcangjie?=	../../inputmethod/libcangjie

.include "../../databases/sqlite3/buildlink3.mk"
.endif	# LIBCANGJIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcangjie

# $NetBSD: buildlink3.mk,v 1.15 2017/11/30 16:45:04 adam Exp $

BUILDLINK_TREE+=	libchewing

.if !defined(LIBCHEWING_BUILDLINK3_MK)
LIBCHEWING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libchewing+=	libchewing>=0.5.0
BUILDLINK_ABI_DEPENDS.libchewing+=	libchewing>=0.5.1nb4
BUILDLINK_PKGSRCDIR.libchewing?=	../../inputmethod/libchewing

.include "../../databases/sqlite3/buildlink3.mk"
.endif # LIBCHEWING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libchewing

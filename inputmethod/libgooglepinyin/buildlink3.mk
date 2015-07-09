# $NetBSD$
#

BUILDLINK_TREE+=	libgooglepinyin

.if !defined(LIBGOOGLEPINYIN_BUILDLINK3_MK)
LIBGOOGLEPINYIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgooglepinyin+=	libgooglepinyin>=0.1.2
BUILDLINK_PKGSRCDIR.libgooglepinyin?=	../../inputmethod/libgooglepinyin
.endif	# LIBGOOGLEPINYIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgooglepinyin

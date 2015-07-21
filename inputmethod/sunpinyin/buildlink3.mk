# $NetBSD$
#

BUILDLINK_TREE+=	sunpinyin

.if !defined(SUNPINYIN_BUILDLINK3_MK)
SUNPINYIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sunpinyin+=	sunpinyin>=2.0.4beta0
BUILDLINK_PKGSRCDIR.sunpinyin?=	../../inputmethod/sunpinyin

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.endif	# SUNPINYIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-sunpinyin

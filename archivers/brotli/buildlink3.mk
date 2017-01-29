# $NetBSD$
#

BUILDLINK_TREE+=	brotli

.if !defined(BROTLI_BUILDLINK3_MK)
BROTLI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.brotli+=	brotli>=0.4.0
BUILDLINK_PKGSRCDIR.brotli?=	../../archivers/brotli
.endif	# BROTLI_BUILDLINK3_MK

BUILDLINK_TREE+=	-brotli

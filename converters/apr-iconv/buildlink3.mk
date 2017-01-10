# $NetBSD$

BUILDLINK_TREE+=	apr-iconv

.if !defined(APR_ICONV_BUILDLINK3_MK)
APR_ICONV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.apr-iconv+=	apr-iconv>=1.2.1
BUILDLINK_ABI_DEPENDS.apr-iconv+=	apr-iconv>=1.2.1
BUILDLINK_PKGSRCDIR.apr-iconv?=	../../converters/apr-iconv
.endif # APR_ICONV_BUILDLINK3_MK

BUILDLINK_TREE+=	-apr-iconv

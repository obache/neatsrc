# $NetBSD: buildlink3.mk,v 1.8 2021/01/14 18:17:09 schmonz Exp $

BUILDLINK_TREE+=	xapian

.if !defined(XAPIAN_BUILDLINK3_MK)
XAPIAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xapian+=	xapian>=1.4.18
BUILDLINK_ABI_DEPENDS.xapian+=	xapian>=1.4.18
BUILDLINK_PKGSRCDIR.xapian?=	../../textproc/xapian

.include "../../mk/bsd.prefs.mk"

SUPPORTED_BUILTIN_UUID_OPSYS=	AIX FreeBSD NetBSD
.if empty(SUPPORTED_BUILTIN_UUID_OPSYS:M${OPSYS})
.include "../../devel/libuuid/buildlink3.mk"
.endif
.include "../../devel/zlib/buildlink3.mk"

.endif # XAPIAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-xapian

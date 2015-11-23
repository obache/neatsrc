# $NetBSD$
#

BUILDLINK_TREE+=	zephyr

.if !defined(ZEPHYR_BUILDLINK3_MK)
ZEPHYR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zephyr+=	zephyr>=3.1.2
BUILDLINK_PKGSRCDIR.zephyr?=	../../chat/zephyr

.include "../../mk/krb5.buildlink3.mk"
.endif	# ZEPHYR_BUILDLINK3_MK

BUILDLINK_TREE+=	-zephyr

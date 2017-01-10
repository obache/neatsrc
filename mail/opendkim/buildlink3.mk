# $NetBSD$
#

BUILDLINK_TREE+=	opendkim

.if !defined(OPENDKIM_BUILDLINK3_MK)
OPENDKIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opendkim+=	opendkim>=2.10.3
BUILDLINK_PKGSRCDIR.opendkim?=	../../mail/opendkim

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif	# OPENDKIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-opendkim

# $NetBSD$

BUILDLINK_TREE+=	capnproto

.if !defined(CAPNPROTO_BUILDLINK3_MK)
CAPNPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.capnproto+=	capnproto>=0.8.0
BUILDLINK_PKGSRCDIR.capnproto?=	../../devel/capnproto

.include "../../mk/pthread.buildlink3.mk"
.endif	# CAPNPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-capnproto

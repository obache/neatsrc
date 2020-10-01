# $NetBSD$

BUILDLINK_TREE+=	tqtinterface

.if !defined(TQTINTERFACE_BUILDLINK3_MK)
TQTINTERFACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tqtinterface+=	tqtinterface>=14.0.4
BUILDLINK_PKGSRCDIR.tqtinterface?=	../../x11/tqtinterface

.include "../../x11/tqt3-libs/buildlink3.mk"
.endif	# TQTINTERFACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-tqtinterface

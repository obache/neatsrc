# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:32 joerg Exp $

BUILDLINK_TREE+=	rarian

.if !defined(RARIAN_BUILDLINK3_MK)
RARIAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rarian+=	rarian>=0.6.0
BUILDLINK_PKGSRCDIR.rarian?=	../../textproc/rarian

TOOLS_NOOP+=	scrollkeeper-update
TOOLS_NOOP+=	scrollkeeper-rebuilddb
TOOLS_NOOP+=	rarian-sk-update
TOOLS_NOOP+=	rarian-sk-rebuild

.endif # RARIAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-rarian

# $NetBSD: buildlink3.mk,v 1.4 2019/09/12 20:52:58 rillig Exp $

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

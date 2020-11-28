# $NetBSD: buildlink3.mk,v 1.7 2020/03/08 16:47:31 wiz Exp $
#

BUILDLINK_TREE+=	cutter

.if !defined(CUTTER_BUILDLINK3_MK)
CUTTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cutter+=	cutter>=1.1.3
BUILDLINK_DEPMETHOD.cutter?=	build
BUILDLINK_ABI_DEPENDS.cutter+=	cutter>=1.2.6nb11
BUILDLINK_PKGSRCDIR.cutter?=	../../devel/cutter
BUILDLINK_CFLAGS.cutter+=	-fexceptions

.include "../../devel/glib2/buildlink3.mk"
.endif	# CUTTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-cutter

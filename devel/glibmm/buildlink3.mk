# $NetBSD: buildlink3.mk,v 1.19 2020/03/08 16:47:32 wiz Exp $

BUILDLINK_TREE+=	glibmm

.if !defined(GLIBMM_BUILDLINK3_MK)
GLIBMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glibmm+=	glibmm>=2.24.2
BUILDLINK_ABI_DEPENDS.glibmm+=	glibmm>=2.62.0nb1
BUILDLINK_PKGSRCDIR.glibmm?=	../../devel/glibmm
BUILDLINK_INCDIRS.glibmm+=	include/giomm-2.4 lib/giomm-2.4/include
BUILDLINK_INCDIRS.glibmm+=	include/glibmm-2.4 lib/glibmm-2.4/include

GCC_REQD+=	4.9

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.endif # GLIBMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-glibmm

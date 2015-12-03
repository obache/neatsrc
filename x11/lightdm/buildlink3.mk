# $NetBSD$
#

BUILDLINK_TREE+=	lightdm

.if !defined(LIGHTDM_BUILDLINK3_MK)
LIGHTDM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lightdm+=	lightdm>=1.16.0
BUILDLINK_PKGSRCDIR.lightdm?=	../../x11/lightdm

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.endif	# LIGHTDM_BUILDLINK3_MK

BUILDLINK_TREE+=	-lightdm

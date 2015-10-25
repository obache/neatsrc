# $NetBSD: buildlink3.mk,v 1.18 2013/01/15 16:21:35 morr Exp $

BUILDLINK_TREE+=	Xaw-Xpm

.if !defined(XAW_XPM_BUILDLINK3_MK)
XAW_XPM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Xaw-Xpm+=	Xaw-Xpm>=1.1
BUILDLINK_ABI_DEPENDS.Xaw-Xpm+=	Xaw-Xpm>=1.1nb2
BUILDLINK_PKGSRCDIR.Xaw-Xpm?=	../../x11/Xaw-Xpm

.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.endif # XAW_XPM_BUILDLINK3_MK

BUILDLINK_TREE+=	-Xaw-Xpm

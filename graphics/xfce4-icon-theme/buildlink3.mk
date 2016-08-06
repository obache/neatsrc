# $NetBSD: buildlink3.mk,v 1.40 2016/08/03 10:22:16 adam Exp $

BUILDLINK_TREE+=	xfce4-icon-theme

.if !defined(XFCE4_ICON_THEME_BUILDLINK3_MK)
XFCE4_ICON_THEME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-icon-theme+=	xfce4-icon-theme>=4.4.3
BUILDLINK_ABI_DEPENDS.xfce4-icon-theme+=	xfce4-icon-theme>=4.4.3nb20
BUILDLINK_PKGSRCDIR.xfce4-icon-theme?=	../../graphics/xfce4-icon-theme

.endif # XFCE4_ICON_THEME_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-icon-theme

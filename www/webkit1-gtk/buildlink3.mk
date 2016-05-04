# $NetBSD: buildlink3.mk,v 1.8 2016/05/03 11:40:10 prlw1 Exp $

BUILDLINK_TREE+=	webkit1-gtk

.if !defined(WEBKIT1_GTK_BUILDLINK3_MK)
WEBKIT1_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.webkit1-gtk+=	webkit1-gtk>=1.1.3<2
BUILDLINK_ABI_DEPENDS.webkit1-gtk+=	webkit1-gtk>=1.10.2nb24
BUILDLINK_PKGSRCDIR.webkit1-gtk?=	../../www/webkit1-gtk

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif # WEBKIT1_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-webkit1-gtk

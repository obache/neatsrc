# $NetBSD$

BUILDLINK_TREE+=	gnokii

.if !defined(GNOKII_BUILDLINK3_MK)
GNOKII_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnokii+=	gnokii>=0.6.31
BUILDLINK_PKGSRCDIR.gnokii?=	../../comms/gnokii

pkgbase:=	gnokii
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.gnokii:Mical)
.include "../../time/libical/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.gnokii:Musb)
.include "../../mk/libusb.buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.gnokii:Mpcsc)
.include "../../security/pcsc-lite/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.gnokii:Mgtk2)
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif	# GNOKII_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnokii

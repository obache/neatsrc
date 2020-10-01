# $NetBSD$

BUILDLINK_TREE+=	tdelibs

.if !defined(TDELIBS_BUILDLINK3_MK)
TDELIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tdelibs+=	tdelibs>=14.0.4
BUILDLINK_PKGSRCDIR.tdelibs?=	../../x11/tdelibs


pkgbase := tdelibs
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.tdelibs:Marts)
.  include "../../audio/arts/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.tdelibs:Midn)
.  include "../../devel/libidn/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.tdelibs:Mjasper)
.  include "../../graphics/jasper/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.tdelibs:Malsa)
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.tdelibs:Mavahi)
.  include "../../net/avahi-tqt/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.tdelibs:Mxcomposite)
.include "../../x11/libXcomposite/buildlink3.mk"
.endif

#.include "../../sysutils/dbus1-tqt/buildlink3.mk"
#.include "../../textproc/libxml2/buildlink3.mk"
#.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/tqtinterface/buildlink3.mk"
.endif	# TDELIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-tdelibs

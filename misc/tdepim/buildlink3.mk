# $NetBSD$

BUILDLINK_TREE+=	tdepim

.if !defined(TDEPIM_BUILDLINK3_MK)
TDEPIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tdepim+=	tdepim>=14.0.4
BUILDLINK_PKGSRCDIR.tdepim?=	../../misc/tdepim

.include "../../security/gpgme/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../x11/tqt3-tools/buildlink3.mk"
.include "../../x11/tqtinterface/buildlink3.mk"
.include "../../x11/tdelibs/buildlink3.mk"

pkgbase := tdepim
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.tdepim:Mcaldav)
.include "../../net/libcaldav/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.tdepim:Mcarddav)
.include "../../net/libcarddav/buildlink3.mk"
.endif

.endif	# TDEPIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-tdepim

# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:34 joerg Exp $

BUILDLINK_TREE+=	libical

.if !defined(LIBICAL_BUILDLINK3_MK)
LIBICAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libical+=	libical>=0.42
BUILDLINK_ABI_DEPENDS.libical+=	libical>=2.0.0
BUILDLINK_PKGSRCDIR.libical?=	../../time/libical

pkgbase := libical
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libical:Micu)
.include "../../textproc/icu/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.endif # LIBICAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libical

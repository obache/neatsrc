# $NetBSD$

BUILDLINK_TREE+=	shishi

.if !defined(SHISHI_BUILDLINK3_MK)
SHISHI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.shishi+=	shishi>=1.0.0
BUILDLINK_PKGSRCDIR.shishi?=	../../security/shishi

pkgbase := shishi
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.shishi:Mtls)
.include "../../security/gnutls/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.shishi:Midn)
.include "../../devel/libidn/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
.endif	# SHISHI_BUILDLINK3_MK

BUILDLINK_TREE+=	-shishi

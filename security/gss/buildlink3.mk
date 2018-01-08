# $NetBSD: buildlink3.mk,v 1.10 2018/01/07 13:04:28 rillig Exp $

BUILDLINK_TREE+=	gss

.if !defined(GSS_BUILDLINK3_MK)
GSS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gss+=	gss>=1.0.0
BUILDLINK_PKGSRCDIR.gss?=	../../security/gss

pkgbase := gss
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.gss:Mkerberos)
.  include "../../security/shishi/buildlink3.mk"
.endif

.endif # GSS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gss

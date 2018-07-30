# $NetBSD$

BUILDLINK_TREE+=	gpgme-pp

.if !defined(GPGME_PP_BUILDLINK3_MK)
GPGME_PP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpgme-pp+=	gpgme++>=1.10.0
BUILDLINK_PKGSRCDIR.gpgme-pp?=	../../security/gpgme++

.include "../../security/gpgme/buildlink3.mk"
.endif	# GPGME_PP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpgme-pp

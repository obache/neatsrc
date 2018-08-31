# $NetBSD: buildlink3.mk,v 1.36 2013/12/01 09:45:49 ryoon Exp $

BUILDLINK_TREE+=	apr

.if !defined(APR_BUILDLINK3_MK)
APR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.apr+=	apr>=1.5.0
BUILDLINK_ABI_DEPENDS.apr+=	apr>=1.5.0
BUILDLINK_PKGSRCDIR.apr?=	../../devel/apr
BUILDLINK_INCDIRS.apr?=		include/apr-1

BUILDLINK_FILES.apr+=	bin/apr-1-config
BUILDLINK_FILES.apr+=	lib/apr.exp

BUILDLINK_FNAME_ALIASES.apr+=	bin/apr-1-config bin/apr-config

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
.include "../../devel/libuuid/buildlink3.mk"
.endif
.endif # APR_BUILDLINK3_MK

BUILDLINK_TREE+=	-apr

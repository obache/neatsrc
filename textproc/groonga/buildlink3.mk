# $NetBSD: buildlink3.mk,v 1.1 2017/08/29 12:54:47 fhajny Exp $

BUILDLINK_TREE+=	groonga

.if !defined(GROONGA_BUILDLINK3_MK)
GROONGA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.groonga+=	groonga>=6.0.0
BUILDLINK_PKGSRCDIR.groonga?=	../../textproc/groonga

pkgbase := groonga
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.groonga:Mgroonga-suggest-learner)
.include "../../devel/msgpack/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.groonga:Mzlib)
.include "../../devel/zlib/buildlink3.mk"
.endif
.include "../../textproc/onigmo/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif	# GROONGA_BUILDLINK3_MK

BUILDLINK_TREE+=	-groonga

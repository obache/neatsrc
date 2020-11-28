# $NetBSD: buildlink3.mk,v 1.3 2020/10/06 00:11:47 gutteridge Exp $

BUILDLINK_TREE+=	groonga

.if !defined(GROONGA_BUILDLINK3_MK)
GROONGA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.groonga+=	groonga>=6.0.0
BUILDLINK_ABI_DEPENDS.groonga?=	groonga>=10.0.8nb1
BUILDLINK_PKGSRCDIR.groonga?=	../../textproc/groonga

pkgbase := groonga
.include "../../mk/pkg-build-options.mk"
.if ${PKG_BUILD_OPTIONS.groonga:Mgroonga-suggest-learner}
.include "../../devel/msgpack/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.groonga:Mzlib}
.include "../../devel/zlib/buildlink3.mk"
.endif
.include "../../textproc/onigmo/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif	# GROONGA_BUILDLINK3_MK

BUILDLINK_TREE+=	-groonga

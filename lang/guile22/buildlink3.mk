# $NetBSD: buildlink3.mk,v 1.3 2020/03/08 16:42:27 bsiegert Exp $

BUILDLINK_TREE+=	guile22

.if !defined(GUILE22_BUILDLINK3_MK)
GUILE22_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.guile22+=	guile22>=2.2
BUILDLINK_ABI_DEPENDS.guile22?=	guile22>=2.2.6nb3
BUILDLINK_PKGSRCDIR.guile22?=	../../lang/guile22

GUILE22_SUBDIR=				guile/2.2
BUILDLINK_PREFIX.guile22=		${PREFIX}/${GUILE22_SUBDIR}

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.endif # GUILE22_BUILDLINK3_MK

BUILDLINK_TREE+=	-guile22

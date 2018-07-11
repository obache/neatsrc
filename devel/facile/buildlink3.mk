# $NetBSD$

BUILDLINK_TREE+=	facile

.if !defined(FACILE_BUILDLINK3_MK)
FACILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.facile+=	facile>=1.1.3
BUILDLINK_PKGSRCDIR.facile?=	../../devel/facile

.include "../../lang/ocaml/buildlink3.mk"
.endif	# FACILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-facile

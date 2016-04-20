# $NetBSD$
#

BUILDLINK_TREE+=	groonga

.if !defined(GROONGA_BUILDLINK3_MK)
GROONGA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.groonga+=	groonga>=6.0.0
BUILDLINK_PKGSRCDIR.groonga?=	../../textproc/groonga

.endif	# GROONGA_BUILDLINK3_MK

BUILDLINK_TREE+=	-groonga

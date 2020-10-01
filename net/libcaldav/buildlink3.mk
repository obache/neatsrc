# $NetBSD$

BUILDLINK_TREE+=	libcaldav

.if !defined(LIBCALDAV_BUILDLINK3_MK)
LIBCALDAV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcaldav+=	libcaldav>=14.0.4
BUILDLINK_PKGSRCDIR.libcaldav?=		../../net/libcaldav

.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif	# LIBCALDAV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcaldav

# $NetBSD$

BUILDLINK_TREE+=	tdegames

.if !defined(TDEGAMES_BUILDLINK3_MK)
TDEGAMES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tdegames+=	tdegames>=14.0.4
BUILDLINK_PKGSRCDIR.tdegames?=	../../games/tdegames

.include "../../audio/arts/buildlink3.mk"
.include "../../x11/tdelibs/buildlink3.mk"
.endif	# TDEGAMES_BUILDLINK3_MK

BUILDLINK_TREE+=	-tdegames

# $NetBSD: buildlink3.mk,v 1.12 2018/12/09 18:52:00 adam Exp $

BUILDLINK_TREE+=	kconfig

.if !defined(KCONFIG_BUILDLINK3_MK)
KCONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kconfig+=	kconfig>=5.18.0
BUILDLINK_ABI_DEPENDS.kconfig?=	kconfig>=5.47.0nb4
BUILDLINK_PKGSRCDIR.kconfig?=	../../devel/kconfig
BUILDLINK_CONTENTS_PATTERNS.kconfig+=	^qt5/mkspecs/
BUILDLINK_CONTENTS_PATTERNS.kconfig+=	^libexec/kf5/

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-kconfig

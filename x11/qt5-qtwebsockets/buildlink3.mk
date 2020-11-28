# $NetBSD: buildlink3.mk,v 1.29 2020/08/17 20:18:00 leot Exp $

BUILDLINK_TREE+=	qt5-qtwebsockets

.if !defined(QT5_QTWEBSOCKETS_BUILDLINK3_MK)
QT5_QTWEBSOCKETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtwebsockets+=	qt5-qtwebsockets>=5.9.1
BUILDLINK_ABI_DEPENDS.qt5-qtwebsockets+=	qt5-qtwebsockets>=5.15.0nb1
BUILDLINK_PKGSRCDIR.qt5-qtwebsockets?=		../../x11/qt5-qtwebsockets

BUILDLINK_INCDIRS.qt5-qtwebsockets=		qt5/include
BUILDLINK_LIBDIRS.qt5-qtwebsockets=		qt5/lib
BUILDLINK_PC_DIRS.qt5-qtwebsockets=		lib/pkgconfig
BUILDLINK_CONTENTS_PATTERNS.qt5-qtwebsockets+=	^qt5/mkspecs/
BUILDLINK_CONTENTS_PATTERNS.qt5-qtwebsockets+=	^qt5/plugins/

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# QT5_QTWEBSOCKETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtwebsockets

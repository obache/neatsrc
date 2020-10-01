# $NetBSD$

BUILDLINK_TREE+=	tqt3-tools

.if !defined(TQT3_TOOLS_BUILDLINK3_MK)
TQT3_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tqt3-tools+=	tqt3-tools>=3.1.2nb3
BUILDLINK_ABI_DEPENDS.tqt3-tools+=	tqt3-tools>=3.3.8nb17
BUILDLINK_PKGSRCDIR.tqt3-tools?=	../../x11/tqt3-tools

BUILDLINK_INCDIRS.tqt3-tools+=	tqt3/include
BUILDLINK_LIBDIRS.tqt3-tools+=	tqt3/lib

.include "../../x11/tqt3-libs/buildlink3.mk"

CONFIGURE_ENV+=		UIC="${TQTDIR}/bin/tquic"
MAKE_ENV+=		UIC="${TQTDIR}/bin/tquic"
CONFIGURE_ENV+=		QMAKE="${TQTDIR}/bin/tqmake"
MAKE_ENV+=		QMAKE="${TQTDIR}/bin/tqmake"

# the way the spec files are currently instealled via pkgsrc, they
# are all identical anyway, so just pick one and point to it.
# Without specifying QMAKESPEC, qmake can't figure it out on some
# platforms (solaris for example)
CONFIGURE_ENV+=		QMAKESPEC=${TQTDIR}/mkspecs/netbsd-g++
MAKE_ENV+=		QMAKESPEC=${TQTDIR}/mkspecs/netbsd-g++
.endif # TQT3_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-tqt3-tools

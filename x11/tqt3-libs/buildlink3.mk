# $NetBSD$

BUILDLINK_TREE+=	tqt3-libs

.if !defined(TQT3_LIBS_BUILDLINK3_MK)
TQT3_LIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tqt3-libs+=	tqt3-libs>=3.2.3
BUILDLINK_ABI_DEPENDS.tqt3-libs+=	tqt3-libs>=3.3.8nb29
BUILDLINK_PKGSRCDIR.tqt3-libs?=	../../x11/tqt3-libs

BUILDLINK_INCDIRS.tqt3-libs+=	tqt3/include
BUILDLINK_LIBDIRS.tqt3-libs+=	tqt3/lib

TQTDIR=	${BUILDLINK_PREFIX.tqt3-libs}/tqt3

.include "../../mk/bsd.fast.prefs.mk"

PTHREAD_OPTS+=	require

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.if ${X11_TYPE} == "modular"
.include "../../x11/libXinerama/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"

CONFIGURE_ENV+=		MOC="${TQTDIR}/bin/tqmoc"
MAKE_ENV+=		MOC="${TQTDIR}/bin/tqmoc"

.if !defined(BUILD_TQT3)
CONFIGURE_ENV+=		QTDIR=${TQTDIR:Q}
MAKE_ENV+=		QTDIR=${TQTDIR:Q}
.endif
.endif # TQT3_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-tqt3-libs

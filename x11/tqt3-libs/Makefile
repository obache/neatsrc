# $NetBSD: Makefile,v 1.95 2016/04/11 04:22:35 dbj Exp $

PKGNAME=	tqt3-libs-${TQT3_RELEASE}
COMMENT=	TQt3 C++ X GUI toolkit base libraries

.include "../../x11/tqt3-libs/Makefile.common"

BUILD_TARGET=		src-moc sub-plugins sub-src
INSTALL_TARGET=		moc-install plugins-install src-install

PTHREAD_OPTS+=		require

UNLIMIT_RESOURCES=	datasize

BUILDLINK_PASSTHRU_DIRS+=	${TQTPREFIX}

PKGCONFIG_OVERRIDE=		lib/tqt-mt.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

INSTALLATION_DIRS+=	share/pkgdata/${PKGBASE}

post-build:
	${SED} -e 's,${WRKSRC},@WRKSRC@,g' < ${WRKSRC}/.qmake.cache > ${WRKDIR}/.qmake.cache

post-install:
	${INSTALL_DATA} ${WRKDIR}/.qmake.cache ${DESTDIR}${PREFIX}/share/pkgdata/${PKGBASE}/

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
BUILDLINK_API_DEPENDS.png+=	png>=1.5.1
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

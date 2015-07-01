# $NetBSD$

.if !defined(FCITX_HACKS_MK)
FCITX_HACKS_MK=	# defined

# relative shlib path is not supported
.if !empty(MACHINE_PLATFORM:MNetBSD-*-*)
PKG_HACKS+=	netbsd-ld

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}

post-extract:
		${LN} -sf ${WRKSRC}/src/lib/fcitx-utils/libfcitx-utils.so.0 ${WRKSRC}/src/lib/fcitx-gclient/
		${LN} -sf ${WRKSRC}/src/lib/fcitx-utils/libfcitx-utils.so.0 ${WRKSRC}/
		${LN} -sf ${WRKSRC}/src/lib/fcitx-config/libfcitx-config.so.4 ${WRKSRC}/

.endif

.endif

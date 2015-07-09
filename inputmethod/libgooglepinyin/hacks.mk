# $NetBSD$

.if !defined(LIBGOOGLEPINYIN_HACKS_MK)
LIBGOOGLEPINYIN_HACKS_MK=	# defined

# relative shlib path is not supported
.if !empty(MACHINE_PLATFORM:MNetBSD-*-*)
PKG_HACKS+=	netbsd-ld

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}

post-extract:
		${LN} -sf ${WRKSRC}/src/libgooglepinyin.so.0 ${WRKSRC}/

.endif

.endif

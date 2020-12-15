# $NetBSD$

.if !defined(KCM_FCITX_HACKS_MK)
KCM_FCITX_HACKS_MK=	# defined


# Work-around for librpcsvc.so deprecated and buggy warnings
.if ${OPSYS} == "NetBSD"
BUILDLINK_TRANSFORM+=	rm:-Wl,--fatal-warnings
.endif

.endif

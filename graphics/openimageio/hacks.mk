.if ${OPSYS} == "NetBSD" && !empty(MACHINE_ARCH:Mi386)
CFLAGS+=		-march=i586
.endif

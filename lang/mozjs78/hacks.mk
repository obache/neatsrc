.if !defied(MOZJS78_HACKS_MK)
MOZJS78_HACKS_MK=	#defined

# match NetBSD-*-i386 to rustc target-list
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "i386"
APPEND_ELF=	#empty
GNU_ARCH.i386=	i686
.endif

.endif

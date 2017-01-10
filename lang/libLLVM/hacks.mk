.if !defined(LIBLLVM_HACKS_MK)
LIBLLVM_HACKS_MK=	defined

# for 64bit atomic opts
.if !empty(MACHINE_ARCH:Mi386)
CFLAGS+=	-march=i686
CXXFLAGS+=	-march=i686
.endif

.endif

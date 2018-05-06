.if !defined(SPIDERMONKEY52_HACKS_MK)
SPIDERMONKEY52_HACKS_MK=	defined

# for 64bit atomic opts
.if !empty(MACHINE_ARCH:Mi386)
GNU_ARCH.i386=		i686
_WRAP_EXTRA_ARGS.CC+=		-march=i686
CWRAPPERS_APPEND.cc+=		-march=i686
_WRAP_EXTRA_ARGS.CXX+=		-march=i686
CWRAPPERS_APPEND.cxx+=		-march=i686
.endif

.endif

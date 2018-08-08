# $NetBSD$

.if !defined(PROTOBUF_HACKS_MK)
PROTOBUF_HACKS_MK= # defined

# for 64bit atomic opts
.if !empty(MACHINE_ARCH:Mi386)
GNU_ARCH.i386=		i586
_WRAP_EXTRA_ARGS.CC+=		-march=i586
CWRAPPERS_APPEND.cc+=		-march=i586
_WRAP_EXTRA_ARGS.CXX+=		-march=i586
CWRAPPERS_APPEND.cxx+=		-march=i586
.endif

.endif  # PROTOBUF_HACKS_MK

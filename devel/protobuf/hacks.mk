# $NetBSD: hacks.mk,v 1.1 2020/09/08 08:35:23 he Exp $

.if !defined(PROTOBUF_HACKS_MK)
PROTOBUF_HACKS_MK=	defined

# for 64bit atomic opts
.if !empty(MACHINE_ARCH:Mi386)
GNU_ARCH.i386=		i586
_WRAP_EXTRA_ARGS.CC+=		-march=i586
CWRAPPERS_APPEND.cc+=		-march=i586
_WRAP_EXTRA_ARGS.CXX+=		-march=i586
CWRAPPERS_APPEND.cxx+=		-march=i586
.endif

# [ Tue Sep  8 08:38:08 CEST 2020 : he ]
# Bring -latomic into scope; build insists on it being available
# on this platform (probably due to no native 8-byte atomics).
.if !empty(MACHINE_ARCH:Mpowerpc*)
.include "../../devel/libatomic/buildlink3.mk"
PKG_HACKS+=	powerpc-libatomic
.endif

.endif	# PROTOBUF_HACKS_MK

.if !defined(CAMLP4_HACKS_MK)
FOO_HACKS_MK=	defined

### [4.06pl1]
### Fatal error: exception stack overflow on NetBSD-7.1.1-i386
### for "camlopt.opt camlp4/boot/camlp4.boot.ml"
.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386)
PKG_HACKS+=		unlimit-stacksize
UNLIMIT_RESOURCES+=	stacksize
.endif

.endif  # CAMLP4_HACKS_MK

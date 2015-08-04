# $NetBSD$

.if !defined(MATE_APPLETS_HACKS_MK)
MATE_APPLETS_HACKS_MK=	# defined

# unwanted expansion to pid with $"${datadir}..."
.if !empty(MACHINE_PLATFORM:MNetBSD-*-*)
USE_TOOLS+=	bash
CONFIG_SHELL=	${BASH}
.endif

.endif

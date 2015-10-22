# $NetBSD$

.if !defined(LIBKKC_HACKS_MK)
LIBKKC_HACKS_MK=	# defined

.if !empty(MACHINE_PLATFORM:MNetBSD-7.*-*)
SUBST_CLASSES+=		_libkkc
SUBST_STAGE._libkkc=	post-configure
SUBST_FILES._libkkc=	marisa-glib/Makefile
SUBST_SED._libkkc=	-e 's:-lgcc_s -lgcc -lc -lgcc_s -lgcc::'
.endif

.endif

# $NetBSD$

SUBST_CLASSES+=		rs_sysp
SUBST_STAGE.rs_sysp=	post-build
SUBST_MESSAGE.rs_sysp=	preserving syspath in gpgme-config
SUBST_FILES.rs_sysp=	src/gpgme-config
SUBST_SED.rs_sysp+=	-e 's,-I\/usr\/include|-I\/include),@SYS_INC_OR@),g'
SUBST_SED.rs_sysp+=	-e 's,-L\/usr\/lib|-L\/lib),@SYS_LIB_OR@),g'

SUBST_CLASSES+=		rp_sysp
SUBST_STAGE.rp_sysp=	post-build
SUBST_FILES.rp_sysp=	src/gpgme-config
SUBST_MESSAGE.rp_sysp=	putting syspath in gpgme-config
SUBST_SED.rp_sysp=	-e 's,@SYS_INC_OR@,${COMPILER_INCLUDE_DIRS:S/^/-I/g:tW:S/ /|/g},g'
SUBST_SED.rp_sysp+=	-e 's,@SYS_LIB_OR@,${COMPILER_LIB_DIRS:S/^/-L/g:tW:S/ /|/g},g'

subst-unwrap:	subst-rs_sysp
subst-rp_sysp:	subst-unwrap

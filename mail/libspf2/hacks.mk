# $NetBSD$

SUBST_CLASSES+=		fixac
SUBST_STAGE.fixac=	post-install
SUBST_MESSAGE.fixac=	Strip autoconf macros from installed header
SUBST_FILES.fixac=	${DESTDIR}${PREFIX}/include/spf2/spf_dns.h
SUBST_FILTER_CMD.fixac=	${SETENV} ${ALL_ENV} WRKSRC=${WRKSRC:Q} GREP=${GREP:Q} SED=${SED:Q} ${SH} ${FILESDIR}/fix-ac-include.sh

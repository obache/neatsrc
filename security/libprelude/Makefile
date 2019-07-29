# $NetBSD: Makefile,v 1.61 2019/07/20 22:46:04 wiz Exp $
#

PKGREVISION=	17
COMMENT=	LibPrelude libraries and c++ easy bindings
LICENSE=	gnu-gpl-v2

.include "../../security/libprelude/Makefile.common"

PRELUDE_USER?=		_prelude
PRELUDE_GROUP?=		_prelude
PRELUDE_HOME?=		${VARBASE}/spool/prelude

PKG_GROUPS=		${PRELUDE_GROUP}
PKG_USERS=		${PRELUDE_USER}:${PRELUDE_GROUP}

PKG_GROUPS_VARS+=	PRELUDE_GROUP
PKG_USERS_VARS+=	PRELUDE_USER

PKG_GECOS.${PRELUDE_USER}=	Prelude IDS
PKG_HOME.${PRELUDE_USER}=	${PRELUDE_HOME}

EGDIR=			${PREFIX}/share/examples/libprelude
MAKE_DIRS=		${PKG_SYSCONFDIR}/default ${PKG_SYSCONFDIR}/profile
MAKE_DIRS_PERMS+=	${PKG_SYSCONFDIR}/profile ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0711

CONF_FILES+=	${EGDIR}/client.conf ${PKG_SYSCONFDIR}/default/client.conf
CONF_FILES+=	${EGDIR}/global.conf ${PKG_SYSCONFDIR}/default/global.conf
CONF_FILES+=	${EGDIR}/idmef-client.conf ${PKG_SYSCONFDIR}/default/idmef-client.conf
CONF_FILES+=	${EGDIR}/tls.conf ${PKG_SYSCONFDIR}/default/tls.conf

CONFIGURE_ARGS+=	--without-python --without-lua --without-perl --without-ruby

# Work around mktime configure test failure leading to build issue
.if !empty(MACHINE_PLATFORM:MDarwin-*-x86_64)
CONFIGURE_ENV+=		ac_cv_func_working_mktime=yes
.endif

PKGCONFIG_OVERRIDE+=	src/libprelude.pc.in

PKG_OPTIONS_VAR=	PKG_OPTIONS.libprelude
PKG_SUPPORTED_OPTIONS=	debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CFLAGS=			-O0 -ggdb
.endif

INSTALLATION_DIRS+=	${EGDIR:H}

post-install:
	${RM} -rf ${DESTDIR}${EGDIR}
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/default ${DESTDIR}${EGDIR}

.include "../../devel/libltdl/convenience.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

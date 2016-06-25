# $NetBSD: Makefile,v 1.57 2016/05/25 15:35:32 joerg Exp $

DISTNAME=	open-vm-tools-9.10.3-3167576
PKGNAME=	${DISTNAME:C/-[0-9]+$//}
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=open-vm-tools/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://open-vm-tools.sourceforge.net/
COMMENT=	Open source VMware tools
LICENSE=	gnu-lgpl-v2.1

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=		--disable-deploypkg
CONFIGURE_ARGS+=		--disable-grabbitmqproxy
CONFIGURE_ARGS+=		--sysconfdir=${PKG_SYSCONFBASEDIR}

INSTALLATION_DIRS+=		${PKG_SYSCONFDIR} share/examples/vmware-tools

PKG_SYSCONFSUBDIR=		vmware-tools
EGDIR=				${PREFIX}/share/examples/vmware-tools
OWN_DIRS+=	${PKG_SYSCONFDIR}/scripts/vmware
CONF_FILES_PERMS+=		${EGDIR}/poweroff-vm-default ${PKG_SYSCONFDIR}/poweroff-vm-default ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+=		${EGDIR}/poweron-vm-default ${PKG_SYSCONFDIR}/poweron-vm-default ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+=		${EGDIR}/resume-vm-default ${PKG_SYSCONFDIR}/resume-vm-default ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+=		${EGDIR}/suspend-vm-default ${PKG_SYSCONFDIR}/suspend-vm-default ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+=		${EGDIR}/statechange.subr ${PKG_SYSCONFDIR}/statechange.subr ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+=		${EGDIR}/vm-support ${PKG_SYSCONFDIR}/vm-support ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+=		${EGDIR}/scripts/vmware/network ${PKG_SYSCONFDIR}/scripts/vmware/network ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES+=		${EGDIR}/vgauth.conf ${PKG_SYSCONFDIR}/vgauth.conf
RCD_SCRIPTS=			vmtools

PKGCONFIG_OVERRIDE+=	libDeployPkg/libDeployPkg.pc.in
PKGCONFIG_OVERRIDE+=	libguestlib/vmguestlib.pc.in

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}
INSTALL_MAKE_FLAGS+=	confdir=${EGDIR}
INSTALL_MAKE_FLAGS+=	VGAuthServicedir=${PREFIX}/share/open-vm-tools/vgauth/schemas

SUBST_CLASSES+=		confdir
SUBST_STAGE.confdir=	pre-configure
SUBST_SED.confdir=	-e s,/etc/vmware-tools,${PKG_SYSCONFDIR},g
SUBST_FILES.confdir+=	lib/guestApp/guestApp.c
SUBST_FILES.confdir+=	scripts/Makefile.in
SUBST_FILES.confdir+=	services/vmtoolsd/Makefile.in
SUBST_FILES.confdir+=	vgauth/common/prefs.h
SUBST_FILES.confdir+=	vmware-user-suid-wrapper/wrapper.h

SUBST_CLASSES+=		vgconfdir
SUBST_STAGE.vgconfdir=	pre-configure
SUBST_SED.vgconfdir=	-e s,/etc/vmware-tools/vgauth.conf,${EGDIR}/vgauth.conf,
SUBST_FILES.vgconfdir+=	vgauth/service/Makefile.in

SUBST_CLASSES+=		varbase
SUBST_STAGE.varbase=	pre-configure
SUBST_SED.varbase=	-e s,/var/run/,${VARBASE}/run/,
SUBST_FILES.varbase+=	lib/include/vm_product.h lib/include/vmblock.h

OWN_DIRS+=	${VARBASE}/run/vmblock

.include "../../net/libdnet/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/xml-security-c/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

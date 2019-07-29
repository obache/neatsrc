# $NetBSD: Makefile,v 1.56 2019/07/21 22:24:07 wiz Exp $
#

DISTNAME=		scim-1.4.18
PKGREVISION=		1
CATEGORIES=		inputmethod
MASTER_SITES=		-https://github.com/scim-im/scim/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.scim-im.org/
COMMENT=		Smart Common Input Method
LICENSE=		gnu-lgpl-v2.1

SUPERSEDES+=		scim-bridge-[0-9]*

PKG_SYSCONFSUBDIR=	scim

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt pkg-config
USE_TOOLS+=		gmake	# make scim-setup.desktop
USE_TOOLS+=		perl intltool
USE_TOOLS+=		autopoint autoconf automake

BUILD_DEPENDS+=		gettext>=0.19.4:../../devel/gettext

PKGCONFIG_OVERRIDE=	scim-gtkutils.pc.in
PKGCONFIG_OVERRIDE+=	scim-x11utils.pc.in
PKGCONFIG_OVERRIDE+=	scim.pc.in

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "options.mk"

EGDIR=			${PREFIX}/share/examples/scim
CONF_FILES=		${EGDIR}/config ${PKG_SYSCONFDIR}/config
CONF_FILES+=		${EGDIR}/global ${PKG_SYSCONFDIR}/global

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples

# for DLOPEN_REQUIRE_PTHREADS
PTHREAD_AUTO_VARS=	yes

CONFIGURE_ENV.NetBSD+=	ac_cv_func_gethostbyname_r=no
CONFIGURE_ENV.SunOS+=	ac_cv_func_gethostbyname_r=no
LDFLAGS.SunOS+=		-lsocket -lnsl

# unused test script
CHECK_PORTABILITY_SKIP+=	extras/immodules/tests/test-exec.sh.in

pre-configure:
	${RUN}cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${SH} bootstrap

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
.for m in scim-config-agent scim-im-agent scim-setup scim
	${INSTALL_MAN} ${WRKSRC}/docs/${m}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${m}.1
.endfor


.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

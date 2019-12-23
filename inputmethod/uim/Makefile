# $NetBSD: Makefile,v 1.157 2019/11/11 10:12:35 nia Exp $

.include "../../inputmethod/uim/Makefile.common"

PKGREVISION=	10
COMMENT=	Multilingual input method library
LICENSE=	modified-bsd

CONFLICTS+=	uim-qt4-immodule-[0-9]*

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_PKGLOCALEDIR=	YES

# Do not segfault uim-module-manager during build
BUILDLINK_TRANSFORM+=	rm:-fno-strict-aliasing

USE_TOOLS+=	gmake pkg-config
USE_TOOLS+=	intltool msgfmt msgmerge xgettext
USE_LANGUAGES=	c c++

LDFLAGS.SunOS+=	-mimpure-text
CFLAGS.SunOS+=	-D__EXTENSIONS__

BUILD_DEFS+=	PKG_SYSCONFBASE

CONFIGURE_ARGS+=	--disable-emacs
CONFIGURE_ARGS+=	--with-libgcroots=installed
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

PKGCONFIG_OVERRIDE+=	${WRKSRC}/uim.pc.in

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples

EGDIR=			${PREFIX}/share/examples/uim
CONF_FILES=		${EGDIR}/loader.scm \
			${PKG_SYSCONFDIR}/loader.scm
CONF_FILES+=		${EGDIR}/installed-modules.scm \
			${PKG_SYSCONFDIR}/installed-modules.scm

PKG_SYSCONFSUBDIR=	uim
INSTALLATION_DIRS+=	share/doc/uim

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/COMPATIBILITY ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/CUSTOM ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/DOT-UIM ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/HELPER-CANDWIN ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/HELPER-PROTOCOL ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/KEY ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/PLUGIN ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/UIM-SCM ${DESTDIR}${PREFIX}/share/doc/uim
	${INSTALL_DATA} ${WRKSRC}/doc/UIM-SH ${DESTDIR}${PREFIX}/share/doc/uim

.include "options.mk"

.include "modules.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgcroots+=	libgcroots>=0.2.3
.include "../../devel/libgcroots/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

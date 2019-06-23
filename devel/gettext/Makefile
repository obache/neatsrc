# $NetBSD: Makefile,v 1.85 2019/05/27 13:21:41 ryoon Exp $

.include "../../devel/gettext/Makefile.common"

COMMENT=	Tools for providing messages in different languages

DEPENDS+=	gettext-m4-${PKGVERSION_NOREV}{,nb[0-9]*}:../../devel/gettext-m4
DEPENDS+=	gettext-tools-${PKGVERSION_NOREV}{,nb[0-9]*}:../../devel/gettext-tools
BUILDLINK_API_DEPENDS.gettext+=	gettext-lib>=0.18

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
SHLIBTOOL_OVERRIDE=	# empty
CONFIGURE_ARGS+=	--disable-csharp
CONFIGURE_ARGS+=	--without-git
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--with-libintl-prefix=${BUILDLINK_PREFIX.gettext}
CONFIGURE_ENV+=		GCJ= ac_cv_prog_GCJ=
CONFIGURE_ENV+=		HAVE_GCJ_IN_PATH=
CONFIGURE_ENV+=		HAVE_JAVAC_IN_PATH=
CONFIGURE_ENV+=		HAVE_JIKES_IN_PATH=
CONFIGURE_ENV+=		ac_cv_libexpat=no

INSTALLATION_DIRS+=	lib
TEST_TARGET=		check

USE_BUILTIN.gettext=	no # force use of pkgsrc gettext-lib

SUBST_CLASSES+=	ext-gettext
SUBST_STAGE.ext-gettext=	pre-configure
SUBST_SED.ext-gettext=		-e 's/&& test "$$PACKAGE" != gettext-runtime//'
SUBST_SED.ext-gettext+=		-e 's/&& test "$$PACKAGE" != gettext-tools//'
SUBST_FILES.ext-gettext=	gettext-tools/configure gettext-runtime/configure
.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	glibc
.if ${OPSYS} == "Linux"
PLIST.glibc=	yes
.endif

do-install:
	cd ${WRKSRC}/gettext-tools && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} install-gettextsrcSCRIPTS
	cd ${WRKSRC}/gettext-tools/projects && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} install
	cd ${WRKSRC}/gettext-runtime && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} install-gettextsrcDATA

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gettext-asprintf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

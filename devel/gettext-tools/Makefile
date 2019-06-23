# $NetBSD: Makefile,v 1.38 2019/06/04 17:22:22 nia Exp $

.include "../../devel/gettext/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-tools-/}
COMMENT=	Tools for providing messages in different languages

DISTINFO_FILE=	${.CURDIR}/../../devel/gettext/distinfo
PATCHDIR=	${.CURDIR}/../../devel/gettext/patches

USE_LANGUAGES=		c c++
USE_TOOLS+=		xz:run
USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS+=	--disable-csharp
CONFIGURE_ARGS+=	--disable-java
CONFIGURE_ARGS+=	--with-included-libcroco
CONFIGURE_ARGS+=	--without-git
CONFIGURE_ARGS+=	--with-xz
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--with-libintl-prefix=${BUILDLINK_PREFIX.gettext}
CONFIGURE_ARGS+=	--without-emacs
CONFIGURE_ARGS+=	--disable-openmp
CONFIGURE_ENV+=		GCJ= ac_cv_prog_GCJ= ac_cv_prog_JAR=
CONFIGURE_ENV+=		HAVE_GCJ_IN_PATH=
CONFIGURE_ENV+=		HAVE_JAVAC_IN_PATH=
CONFIGURE_ENV+=		HAVE_JIKES_IN_PATH=
GNU_CONFIGURE_STRICT=	no # because of gettext-runtime
LDFLAGS.AIX+=		-Wl,-brtl

SHLIBTOOL_OVERRIDE=	# empty
INFO_FILES=		yes

USE_BUILTIN.gettext=	no # force use of pkgsrc gettext-lib

BUILDLINK_TRANSFORM.Cygwin+=	rm:-Wl,--disable-auto-import

#bug 20453 in bug-gzip list, passed onto gnulib
CONFIGURE_ENV.AIX+=	ac_cv_header_wctype_h=no

PLIST_VARS+=	glibc

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
PLIST.glibc=	yes
.endif

SUBST_CLASSES+=			ext-gettext
SUBST_STAGE.ext-gettext=	pre-configure
SUBST_SED.ext-gettext=		-e 's/&& test "$$PACKAGE" != gettext-runtime//'
SUBST_SED.ext-gettext+=		-e 's/&& test "$$PACKAGE" != gettext-tools//'
SUBST_FILES.ext-gettext=	gettext-tools/configure gettext-runtime/configure
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

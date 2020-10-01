# $NetBSD$

TDE_PKGNAME=	tqca-tls
CATEGORIES=	security
TDE_SUBDIR=	dependencies

COMMENT=	TLS plugin for the TQt Cryptographic Architecture
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/tde/Makefile.tde"

BUILD_DEPENDS+=	tqt3-tools>=${TQT3_RELEASE}:../../x11/tqt3-tools

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--tqtdir=${TQTDIR}
CONFIGURE_ARGS+=	--with-openssl-inc=${SSLBASE}/include
CONFIGURE_ARGS+=	--with-openssl-lib=${SSLBASE}/lib

SUBST_CLASSES+=	fix-path
SUBST_STAGE.fix-path=	pre-configure
SUBST_FILES.fix-path=	configure
SUBST_SED.fix-path=	-e s,/usr/include/tqt,${BUILDLINK_PREFIX.tqtinterface}/include/tqt,g

DESTDIR_VARNAME=	INSTALL_ROOT

.include "../../security/openssl/buildlink3.mk"
.include "../../x11/tqtinterface/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

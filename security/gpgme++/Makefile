# $NetBSD: Makefile,v 1.4 2018/07/20 03:33:55 ryoon Exp $

DISTNAME=	gpgme-1.11.1
PKGNAME=	${DISTNAME:S/gpgme/gpgme++/}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG:=gpgme/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnupg.org/related_software/gpgme/
COMMENT=	C++ bindings for GPGme
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config gmake
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

BUILD_DIRS=	lang/cpp/src

CONFIGURE_ARGS+=	--enable-languages="cpp"

post-configure:
		${LN} -s ${BUILDLINK_DIR}/lib/libgpgme.la ${WRKSRC}/src/libgpgme.la

BUILDLINK_API_DEPENDS.gpgme+=	gpgme>=${PKGVERSION_NOREV}
.include "../../security/gpgme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

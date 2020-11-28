# $NetBSD: Makefile,v 1.14 2020/08/17 20:17:42 leot Exp $

DISTNAME=	gpgme-1.11.1
PKGNAME=	qgpgme-1.11.1
PKGREVISION=	4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG:=gpgme/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnupg.org/related_software/gpgme/
COMMENT=	Qt bindings for GPGme
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config gmake
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

BUILD_DIRS=	lang/qt/src

CONFIGURE_ARGS+=	--enable-languages="cpp qt"
CONFIGURE_ENV+=	MOC=${QTDIR}/bin/moc

.include "../../security/gpgme++/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

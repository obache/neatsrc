# $NetBSD$

DISTNAME=	mate-user-guide-1.12.0
CATEGORIES=	misc mate
MASTER_SITES=	http://pub.mate-desktop.org/releases/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	MATE user guide
LICENSE=	cc-by-sa-v3.0

DEPENDS+=	yelp-[0-9]*:../../misc/yelp3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool itstool msgfmt xmllint

BUILDLINK_DEPMETHOD.gettext=	build
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

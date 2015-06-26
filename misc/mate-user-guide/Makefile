# $NetBSD$

DISTNAME=	mate-user-guide-1.10.0
CATEGORIES=	misc mate
MASTER_SITES=	http://pub.mate-desktop.org/releases/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	obache@users.sourceforge.net
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	MATE user guide
LICENSE=	cc-by-sa-v3.0

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
DEPENDS+=	yelp-[0-9]*:../../misc/yelp

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt

BUILDLINK_DEPMETHOD.gettext=	build
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

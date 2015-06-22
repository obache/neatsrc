# $NetBSD$

DISTNAME=	mate-terminal-1.10.0
CATEGORIES=	x11 mate
MASTER_SITES=	http://pub.mate-desktop.org/releases/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	obache@users.sourceforge.net
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	MATE terminal emulator application
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config perl:run

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

REPLACE_PERL+=	mate-terminal.wrapper

.include "../../devel/dconf/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.36.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.gtk2:Mx11)
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.endif
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

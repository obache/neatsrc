# $NetBSD$

DISTNAME=	groonga-gobject-1.0.1
CATEGORIES=	textproc
MASTER_SITES=	http://packages.groonga.org/source/groonga-gobject/

HOMEPAGE=	http://github.com/groonga/groonga-gobject
COMMENT=	GObject wrapper of Groonga
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

EXTRACT_USING=	gtar

PKGCONFIG_OVERRIDE+=	groonga-gobject.pc.in

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../textproc/groonga/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

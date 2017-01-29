# $NetBSD: Makefile,v 1.6 2012/10/04 09:19:21 asau Exp $
#

DISTNAME=		shapelib-1.4.0
CATEGORIES=		geography
MASTER_SITES=		http://download.osgeo.org/shapelib/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://shapelib.maptools.org/
COMMENT=		Library for reading, writing and updating (limited) ESRI Shapefiles
LICENSE=		gnu-lgpl-v2 OR mit

GNU_CONFIGURE=		yes
USE_LIBTOOL=		YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

PKGCONFIG_OVERRIDE+=	shapelib.pc.in

TEST_TARGET=		check

.include "../../geography/proj/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

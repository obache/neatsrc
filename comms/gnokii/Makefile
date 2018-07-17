# $NetBSD$

DISTNAME=	gnokii-0.6.31
CATEGORIES=	comms
MASTER_SITES=	http://www.gnokii.org/download/gnokii/0.6.x/
MASTER_SITES=	ftp://ftp.slackware.pl/pub/gnokii/gnokii/0.6.x/

HOMEPAGE=	http://www.gnokii.org/
COMMENT=	Tools and user space driver for use with mobile phone
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake

PKGCONFIG_OVERRIDE+=	common/gnokii.pc.in
PKGCONFIG_OVERRIDE+=	xgnokii/xgnokii.pc.in

.include "options.mk"

CFLAGS.NetBSD+=	-DSDP_COMPAT

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

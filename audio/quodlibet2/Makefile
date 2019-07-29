# $NetBSD: Makefile,v 1.31 2019/07/21 22:24:28 wiz Exp $

DISTNAME=	quodlibet-2.6.3
PKGREVISION=	20
CATEGORIES=	audio
MASTER_SITES=	https://bitbucket.org/lazka/quodlibet-files/raw/default/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/quodlibet/quodlibet
COMMENT=	Finally a good alternative to iTunes
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-mutagen>=1.11:../../audio/py-mutagen
DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.16:../../x11/py-gtk2
DEPENDS+=	${PYPKGPREFIX}-dbus-[0-9]*:../../sysutils/py-dbus

USE_TOOLS+=		msgfmt intltool
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		#

PKG_OPTIONS_VAR=		PKG_OPTIONS.quodlibet2
PKG_OPTIONS_REQUIRED_GROUPS=	audio
PKG_OPTIONS_GROUP.audio=	gstreamer xine-lib
PKG_SUGGESTED_OPTIONS=	gstreamer

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgstreamer)
DEPENDS+=	${PYPKGPREFIX}-gstreamer0.10>=0.10.2:../../multimedia/py-gstreamer0.10
DEPENDS+=	gst-plugins0.10-mad>=0.10.0:../../audio/gst-plugins0.10-mad
DEPENDS+=	gst-plugins0.10-vorbis>=0.10.0:../../audio/gst-plugins0.10-vorbis
DEPENDS+=	gst-plugins0.10-ogg>=0.10.0:../../multimedia/gst-plugins0.10-ogg
.else
DEPENDS+=	xine-lib>=1.1:../../multimedia/xine-lib
.endif

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # py-gtk2, py-gstreamer0.10
REPLACE_PYTHON=	exfalso.py quodlibet.py operon.py

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"

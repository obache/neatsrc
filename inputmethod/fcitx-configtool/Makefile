# $NetBSD: Makefile,v 1.1 2018/08/18 01:15:53 ryoon Exp $

DISTNAME=	fcitx-configtool-0.4.10
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx-configtool/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://fcitx-im.org/wiki/Configtool
COMMENT=	GTK+ based configure tool for Fcitx
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c99 c++
USE_TOOLS+=	msgfmt pkg-config

.include "options.mk"

.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

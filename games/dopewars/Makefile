# $NetBSD: Makefile,v 1.72 2019/07/21 22:24:49 wiz Exp $

DISTNAME=	dopewars-1.5.12
PKGREVISION=	31
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dopewars/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dopewars.sourceforge.net/
COMMENT=	Make a fortune dealing drugs on the streets of New York

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
USE_GAMES_GROUP=	yes

CONFIGURE_ARGS+=	--enable-networking
CONFIGURE_ARGS+=	--without-esd
CONFIGURE_ARGS+=	--without-sdl
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/games

BUILD_DEFS+=		VARBASE

SPECIAL_PERMS+=		bin/dopewars ${SETGID_GAMES_PERMS}
REQD_DIRS+=		${VARBASE}/games
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/dopewars.sco ${GAMEDATA_PERMS}

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.14 2015/03/15 15:29:46 tnn Exp $
#

DISTNAME=	watanabe-vf
PKGNAME=	watanabe-vfont-19930318
CATEGORIES=	fonts
MASTER_SITES=	# ftp://ftp.kuis.kyoto-u.ac.jp/TeX/watanabe-jfonts/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Watanabe-vector Japanese font

NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_TOOLS+=	pax

EXTRACT_DIR=	${WRKDIR}/watanabe_font

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/fonts/watanabe_font
	cd ${EXTRACT_DIR} && ${PAX} -rwpp . ${DESTDIR}${PREFIX}/share/fonts/watanabe_font
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/share/fonts/watanabe_font/*
	${CHOWN} ${SHAREOWN}:${SHAREGRP} \
		${DESTDIR}${PREFIX}/share/fonts/watanabe_font/*

.include "../../mk/bsd.pkg.mk"

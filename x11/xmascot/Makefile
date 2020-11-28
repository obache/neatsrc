# $NetBSD: Makefile,v 1.27 2020/01/26 17:32:28 rillig Exp $

DISTNAME=	xmascot2.6a
PKGNAME=	xmascot-2.6a
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://cclub-flying.dsl.gr.jp/products/xmascot/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp
HOMEPAGE=	https://cclub-flying.dsl.gr.jp/products/xmascot/
COMMENT=	Moving mascot on your X-Window screen

MAKE_JOBS_SAFE=		no

USE_IMAKE=	yes

INSTALL_MAKE_FLAGS+=	LANG=ja_JP.eucJP

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.if ${XAW_TYPE} == "3d" || {XAW_TYPE} == "xpm"
SUBST_CLASSES+=		xaw
SUBST_STAGE.xaw=	pre-configure
SUBST_FILES.xaw=	config.tmpl
SUBST_SED.xaw=		-e 's/undef USE_XAW3D/define USE_XAW3D/'
.endif
.include "../../mk/bsd.pkg.mk"

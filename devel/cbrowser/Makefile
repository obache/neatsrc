# $NetBSD: Makefile,v 1.19 2020/01/26 05:26:22 rillig Exp $
#

DISTNAME=	cbrowser-0.8
PKGREVISION=	1
CATEGORIES=	devel tk
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cbrowser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cbrowser.sourceforge.net/
COMMENT=	Graphical C/C++ source code browsing tool, and call graph viewer

DEPENDS+=	cscope-[0-9]*:../../devel/cscope

USE_TOOLS+=	wish:run

NO_BUILD=	yes

INSTALLATION_DIRS=	bin share/cbrowser

REPLACE_WISH=	ftcllib.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cbrowser ${DESTDIR}${PREFIX}/bin
	for f in *.tcl tclIndex; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/share/cbrowser; \
	done

.include "../../x11/tk/interpreter.mk"
.include "../../mk/bsd.pkg.mk"

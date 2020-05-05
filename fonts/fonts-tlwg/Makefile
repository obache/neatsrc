# $NetBSD$
#

DISTNAME=	fonts-tlwg-0.7.2
CATEGORIES=	fonts
MASTER_SITES=	http://linux.thai.net/pub/thailinux/software/fonts-tlwg/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://linux.thai.net/projects/fonts-tlwg
COMMENT=	The collection of Thai scalable fonts

TOOL_DEPENDS+=	fontforge>=20080110:../../fonts/fontforge

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

FONTDIR=		${PREFIX}/share/fonts/opentype/thai
FONTS_DIRS.ttf+=	${FONTDIR}

FC_AVAILS+=	00-tlwg.conf
FC_AVAILS+=	64-01-tlwg-kinnari.conf
FC_AVAILS+=	64-02-tlwg-norasi.conf
FC_AVAILS+=	64-10-tlwg-loma.conf
FC_AVAILS+=	64-11-tlwg-waree.conf
FC_AVAILS+=	64-13-tlwg-garuda.conf
FC_AVAILS+=	64-14-tlwg-umpush.conf
FC_AVAILS+=	64-15-laksaman.conf
FC_AVAILS+=	64-21-tlwg-typo.conf
FC_AVAILS+=	64-22-tlwg-typist.conf
FC_AVAILS+=	64-23-tlwg-mono.conf
FC_AVAILS+=	89-tlwg-garuda-synthetic.conf
FC_AVAILS+=	89-tlwg-kinnari-synthetic.conf
FC_AVAILS+=	89-tlwg-laksaman-synthetic.conf
FC_AVAILS+=	89-tlwg-umpush-synthetic.conf

.for f in ${FC_AVAILS}
CONF_FILES+=	${PREFIX}/share/fontconfig/conf.avail/${f} \
		${PKG_SYSCONFDIR}/fontconfig/conf.d/${f}
.endfor

post-extract:
	${CP} ${FILESDIR}/00-tlwg.conf ${WRKDIR}

post-install:
	${INSTALL_DATA} ${WRKDIR}/00-tlwg.conf \
		${DESTDIR}${PREFIX}/share/fontconfig/conf.avail/00-tlwg.conf

SUBST_CLASSES+=		fontdir
SUBST_STAGE.fontdir=	post-configure
SUBST_FILES.fontdir=	${WRKDIR}/00-tlwg.conf
SUBST_VARS.fontdir=	FONTDIR

.include "../../mk/bsd.pkg.mk"

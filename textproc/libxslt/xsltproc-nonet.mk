# $NetBSD: xsltproc-nonet.mk,v 1.4 2019/11/06 13:23:45 wiz Exp $

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

# --nonet avoids network connections during builds
# XLSTPROC_PATH allows any necessary files (e.g. dtds) to be found
# locally in the paths provided with the default being '--path .'
TOOLS_CREATE+=		xsltproc
TOOLS_PATH.xsltproc=	${LOCALBASE}/bin/xsltproc
TOOLS_ARGS.xsltproc=	--nonet --path ${XSLTPROC_PATH:U.:O:u:ts::Q}

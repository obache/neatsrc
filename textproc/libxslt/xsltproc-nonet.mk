# $NetBSD: xsltproc-nonet.mk,v 1.3 2015/07/09 01:56:44 richard Exp $

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

# --nonet avoids network connections during builds
# XLSTPROC_PATH allows any necessary files (e.g. dtds) to be found
# locally in the paths provided with the default being '--path .'
TOOLS_CREATE+=		xsltproc
TOOLS_FIND_PREFIX+=	TOOLS_PREFIX.xsltproc=libxslt
TOOLS_PATH.xsltproc=	${TOOLS_PREFIX.xsltproc}/bin/xsltproc
TOOLS_ARGS.xsltproc=	--nonet --path ${XSLTPROC_PATH:U.:O:u:ts::Q}

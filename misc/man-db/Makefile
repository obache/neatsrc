# $NetBSD$

DISTNAME=	man-db-2.7.5
CATEGORIES=	misc
MASTER_SITES=	http://download.savannah.gnu.org/releases/man-db/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://man-db.nongnu.org/
COMMENT=	On-line manual database
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake flex soelim nroff tbl pkg-config
USE_TOOLS+=		groff:run tbl:run tr:run gzip:run

CONFIGURE_ARGS+=	--with-db=${BDB_TYPE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-setuid
CONFIGURE_ARGS+=	--with-systemdtmpfilesdir=${PREFIX}/lib/tmpfiles.d
CONFIGURE_ARGS+=	--with-nroff=${NROFF:Q}
CONFIGURE_ARGS+=	--with-tbl=${TBL:Q}
CONFIGURE_ARGS+=	--with-gzip=${TOOLS_PATH.gzip:Q}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/man-db

CONF_FILES+=		${PREFIX}/share/examples/man-db/man_db.conf \
			${PKG_SYSCONFDIR}/man_db.conf

TEST_TARGET=	check

USE_GNU_ICONV=	yes
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libpipeline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

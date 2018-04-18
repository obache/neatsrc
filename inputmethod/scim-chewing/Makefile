# $NetBSD: Makefile,v 1.44 2018/04/16 14:34:46 wiz Exp $
#

DISTNAME=		scim-chewing-0.5.1
PKGREVISION=		11
CATEGORIES=		chinese inputmethod
MASTER_SITES=		-https://github.com/chewing/scim-chewing/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://chewing.im/
COMMENT=		SCIM IMEngine module for Chewing input method
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake msgfmt pkg-config intltool
USE_TOOLS+=		automake autoheader aclocal autoconf
GNU_CONFIGURE=		yes

USE_SCIM_GTKUTILS=	yes

pre-configure:
	${RUN}cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${CONFIG_SHELL} autogen.sh

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libchewing+=	libchewing>=0.4.0
.include "../../inputmethod/libchewing/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

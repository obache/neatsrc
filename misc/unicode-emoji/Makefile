# $NetBSD$
#

PKGNAME=	unicode-emoji-4.0
CATEGORIES=	misc
MASTER_SITES=	http://www.unicode.org/Public/emoji/${PKGVERSION_NOREV}/
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	ReadMe.txt emoji-data.txt emoji-sequences.txt emoji-test.txt \
		emoji-zwj-sequences.txt

HOMEPAGE=	http://www.unicode.org/emoji/
COMMENT=	Unicode Emoji Data Files
LICENSE=	unicode

USE_LANGUAGES=	# empty

EXTRACT_DIR=	${PKGNAME_NOREV}
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/unicode/emoji

do-install:
.for f in ${DISTFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/unicode/emoji/
.endfor

.include "../../mk/bsd.pkg.mk"

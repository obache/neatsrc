# $NetBSD$

PKGNAME=	fcitx-mozc-2.18.2612.102.1

DISTFILES_VARS+=	icon
DISTFILES.icon=	${PKGBASE}-icon.tar.gz
SITES.icon=	http://download.fcitx-im.org/fcitx-mozc/
PATCHFILES+=	${PKGBASE}-${PKGVERSION_NOREV}.patch
PATCH_SITES=	http://download.fcitx-im.org/fcitx-mozc/
PATCH_DIST_STRIP=	-p2

INSTALLATION_DIRS+=	lib/fcitx share/fcitx/addon share/fcitx/inputmethod
INSTALLATION_DIRS+=	share/fcitx/mozc/icon

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils
DEPENDS+=	mozc-renderer-[0-9]*:../../inputmethod/mozc-renderer
DEPENDS+=	mozc-server-[0-9]*:../../inputmethod/mozc-server
DEPENDS+=	mozc-tool-[0-9]*:../../inputmethod/mozc-tool

do-build:
	${RUN}cd ${WRKSRC};${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} build_mozc.py build -c ${MOZC_BUILD_MODE} \
			unix/fcitx/fcitx.gyp:fcitx-mozc

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-configure
SUBST_FILES.path=	unix/fcitx/mozc.conf
SUBST_SED.path=		-e 's,/usr/share,${PREFIX}/share,g'

do-install:
	for mo in ${WRKSRC}/out_${OSDEST}/${MOZC_BUILD_MODE}/gen/unix/fcitx/po/*.mo; do \
		lang=`basename $${mo} .mo`; \
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/$${lang}/LC_MESSAGES; \
		${INSTALL_DATA} $${mo} ${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/$${lang}/LC_MESSAGES/fcitx-mozc.mo; \
	done
	${INSTALL_PROGRAM} ${WRKSRC}/out_${OSDEST}/${MOZC_BUILD_MODE}/fcitx-mozc.so \
		${DESTDIR}${PREFIX}/lib/fcitx/fcitx-mozc.so
	${INSTALL_DATA} ${WRKSRC}/unix/fcitx/fcitx-mozc.conf 		\
		${DESTDIR}${PREFIX}/share/fcitx/addon/fcitx-mozc.conf
	${INSTALL_DATA} ${WRKSRC}/unix/fcitx/mozc.conf 			\
		${DESTDIR}${PREFIX}/share/fcitx/inputmethod/mozc.conf
	for icon in ${WRKDIR}/fcitx-mozc-icons/*.png; do		\
		${INSTALL_DATA} $${icon} 				\
		${DESTDIR}${PREFIX}/share/fcitx/mozc/icon/; 		\
	done

.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../inputmethod/mozc-server/Makefile.common"

# $NetBSD: desktopdb.mk,v 1.5 2006/06/15 22:13:59 jlam Exp $
#
# This Makefile fragment is intended to be included by packages that install
# desktop entries.  It takes care of registering them in the global database.
#

.if !defined(DESKTOP_FILE_UTILS_MIMEDB_MK)
DESKTOP_FILE_UTILS_MIMEDB_MK=	# defined

.include "../../mk/bsd.prefs.mk"

INSTALL_TEMPLATES+=	${.CURDIR}/../../sysutils/desktop-file-utils/files/install.tmpl
DEINSTALL_TEMPLATES+=	${.CURDIR}/../../sysutils/desktop-file-utils/files/install.tmpl

FILES_SUBST+=		APPLICATIONS_PATH="${LOCALBASE}/share/applications"
FILES_SUBST+=		UPDATE_DESKTOPDB="${LOCALBASE}/bin/update-desktop-database"

PRINT_PLIST_AWK+=	/^share\/applications\/mimeinfo.cache$$/ { next }

TOOLS_NOOP+=		update-desktop-database
DEPENDS+=		desktop-file-utils-[0-9]*:../../sysutils/desktop-file-utils

.endif	# DESKTOP_FILE_UTILS_MIMEDB_MK

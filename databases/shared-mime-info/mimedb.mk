# $NetBSD: mimedb.mk,v 1.6 2009/06/14 22:57:59 joerg Exp $
#
# This Makefile fragment is intended to be included by packages that install
# mime customization files.  It takes care of registering them in the global
# mime database.
#

.if !defined(SHARED_MIME_INFO_MIMEDB_MK)
SHARED_MIME_INFO_MIMEDB_MK=	# defined

.include "../../mk/bsd.prefs.mk"

INSTALL_TEMPLATES+=	${.CURDIR}/../../databases/shared-mime-info/files/install.tmpl
DEINSTALL_TEMPLATES+=	${.CURDIR}/../../databases/shared-mime-info/files/install.tmpl

FILES_SUBST+=		MIMEDB_PATH="${LOCALBASE}/share/mime"
FILES_SUBST+=		UPDATE_MIMEDB="${LOCALBASE}/bin/update-mime-database"

PRINT_PLIST_AWK+=	/^share\/mime\/packages/ { print; next; }
PRINT_PLIST_AWK+=	/^share\/mime\// { next; }

USE_TOOLS+=	update-mime-database:run
TOOLS_CREATE+=	update-mime-database
TOOLS_SCRIPT.update-mime-database?=\
	${TEST} "$$1" != "-v" || ${LOCALBASE}/bin/update-mime-database -v
TOOLS_DEPENDS.update-mime-database?=	shared-mime-info-[0-9]*:../../databases/shared-mime-info

.endif	# SHARED_MIME_INFO_MIMEDB_MK

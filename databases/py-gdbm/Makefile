# $NetBSD: Makefile,v 1.40 2019/12/15 14:42:27 adam Exp $

PKGNAME=	${PYPKGPREFIX}-gdbm-${PY_DISTVERSION}
PKGREVISION=	1
CATEGORIES=	databases python

MAINTAINER=	dolecek@ics.muni.cz
HOMEPAGE=	https://docs.python.org/3/library/dbm.html#module-dbm.gnu
COMMENT=	Python interface to gdbm - GNU database manager

.include "../../lang/python/pyversion.mk"
.if !empty(PYPKGPREFIX:Mpy3?)
GDBM_MODNAME=	_gdbm
.else
GDBM_MODNAME=	gdbm
.endif

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/${GDBM_MODNAME}module.c
PYDISTUTILSPKG=		yes

PY_SETUP_SUBST+=	GDBMPREFIX=${BUILDLINK_PREFIX.gdbm}
PY_SETUP_SUBST+=	GDBM_MODNAME=${GDBM_MODNAME}
PLIST_SUBST+=		GDBM_MODNAME=${GDBM_MODNAME}

.include "../../databases/gdbm/buildlink3.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"

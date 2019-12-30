# $NetBSD: buildlink3.mk,v 1.8 2012/05/07 01:53:38 dholland Exp $

BUILDLINK_TREE+=	anthy

.if !defined(ANTHY_BUILDLINK3_MK)
ANTHY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.anthy+=	anthy>=0.4
BUILDLINK_PKGSRCDIR.anthy?=	../../inputmethod/anthy

.  if !empty(USE_LEGACY_ANTHY_VERSION_SCHEME:M[yY][eE][sS])
SUBST_CLASSES+=				legacy-anthy-version
SUBST_STAGE.legacy-anthy-version=	post-wrapper
SUBST_MESSAGE.legacy-anthy-version=	\
	Use legacy anthy version scheme for pkg-config
SUBST_FILES.legacy-anthy-version=	${BUILDLINK_DIR}/lib/pkgconfig/anthy.pc
SUBST_SED.legacy-anthy-version=		-e 's/^Version: /Version: 9200./'
.  endif

.endif # ANTHY_BUILDLINK3_MK

BUILDLINK_TREE+=	-anthy

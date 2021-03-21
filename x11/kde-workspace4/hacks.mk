# $NetBSD: hacks.mk,v 1.2 2012/04/01 20:53:16 markd Exp $

.if !defined(KDEBASE4_HACKS_MK)
KDEBASE4_HACKS_MK=	# defined

### issue is specific to xproto IPv6 support
.if empty(PKG_OPTIONS:Minet6)
SUBST_CLASSES+=			disable-ipv6-X-h
SUBST_STAGE.disable-ipv6-X-h=	post-wrapper
SUBST_FILES.disable-ipv6-X-h=	${BUILDLINK_X11_DIR}/include/X11/X.h
SUBST_SED.disable-ipv6-X-h=	-e 's,^#define FamilyInternet6.*,/* undef FamilyInternet6 */,'
SUBST_NOOP_OK.disable-ipv6-X-h=	yes
.endif

.endif

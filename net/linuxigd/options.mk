# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.linuxigd
PKG_OPTIONS_REQUIRED_GROUPS+=	filter
PKG_OPTIONS_GROUP.filter=	iptables pf ipfilter

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS=	iptables
.elif ${OPSYS} == "OpenBSD"
PKG_SUGGESTED_OPTIONS=	pf
.else
PKG_SUGGESTED_OPTIONS=	ipfilter
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Miptables)
CFLAGS+=	-DUSE_IPTABLES
.elif !empty(PKG_OPTIONS:Mpf)
CFLAGS+=	-DUSE_PF
MESSAGE_SRC+=	${.CURDIR:Q}/MESSAGE.pf
.elif !empty(PKG_OPTIONS:Mipfilter)
CFLAGS+=	-DUSE_IPFILTER
.endif

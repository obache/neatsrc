# $NetBSD: hacks.mk,v 1.2 2012/04/02 10:23:48 markd Exp $

.if ${OPSYS} == "NetBSD"
post-configure:
	cp ${FILESDIR}/kshareddatacache.cpp ${WRKSRC}/kdecore/util/kshareddatacache.cpp
.endif

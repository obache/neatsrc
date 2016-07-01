# $NetBSD: options.mk,v 1.11 2013/01/13 13:21:18 tron Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.milter-greylist
PKG_OPTIONS_REQUIRED_GROUPS=	mta
PKG_OPTIONS_GROUP.mta=		postfix-milter sendmail-milter
PKG_SUPPORTED_OPTIONS=		curl dnsrbl dkim drac geoip ldap p0f \
				spamassassin spf
PKG_SUGGESTED_OPTIONS=		dnsrbl p0f sendmail-milter spamassassin spf

.include "../../mk/bsd.options.mk"

###
### URL checking
###
.if !empty(PKG_OPTIONS:Mcurl)
.include "../../www/curl/buildlink3.mk"

CONFIGURE_ARGS+=	--with-libcurl=${BUILDLINK_PREFIX.curl}
.endif

###
### GeoIP support
###
.if !empty(PKG_OPTIONS:Mgeoip)
.include "../../net/GeoIP/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libGeoIP=${BUILDLINK_PREFIX.GeoIP}
.endif

###
### DNS Realtime Black List
###
.if !empty(PKG_OPTIONS:Mdnsrbl)
CONFIGURE_ARGS+=	--enable-dnsrbl --with-thread-safe-resolver
.include "../../mk/resolv.buildlink3.mk"
.endif

###
### Dynamic Relay Authorization Control
###
.if empty(PKG_OPTIONS:Mdrac)
CONFIGURE_ARGS+=	--disable-drac
.else
DRACD_DB?=		/etc/mail/dracd.db

CONFIGURE_ARGS+=	--enable-drac --with-drac-db=${DRACD_DB}

.  include "../../mk/bdb.buildlink3.mk"
.  if ${BDB_TYPE} != "db1"
CPPFLAGS+=	-DUSE_DB185_EMULATION
.  endif
LIBS+=		${BDB_LIBS}

.endif

###
### LDAP support
###
.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap-client/buildlink3.mk"

CONFIGURE_ARGS+=	--with-openldap=${BUILDLINK_PREFIX.openldap-client}
.endif

###
### DKIM support
###
.if !empty(PKG_OPTIONS:Mdkim)
.include "../../mail/opendkim/buildlink3.mk"

CONFIGURE_ARGS+=	--with-libopendkim=${BUILDLINK_PREFIX.opendkim}
.endif

###
### P0f support
###
.if !empty(PKG_OPTIONS:Mp0f)
CONFIGURE_ARGS+=	--enable-p0f
.endif

###
### Postfix support
###
.if !empty(PKG_OPTIONS:Mpostfix-milter)
CONFIGURE_ARGS+=	--enable-postfix

POSTFIX_QUEUE_DIR?=	${VARBASE}/spool/postfix

PKG_GECOS.postfix=	Postfix User
PKG_HOME.postfix=	${POSTFIX_QUEUE_DIR}

MILTER_USER?=		postfix
MILTER_GROUP?=		postfix
.endif

###
### Sendmail support
###
.if !empty(PKG_OPTIONS:Msendmail-milter)
PKG_GECOS.smmsp=	Sendmail Message Submission Program

MILTER_USER?=		smmsp
MILTER_GROUP?=		smmsp
.endif

PKG_GROUPS+=		${MILTER_GROUP}
PKG_USERS+=		${MILTER_USER}:${MILTER_GROUP}

###
### SpamAssassin support
###
.if !empty(PKG_OPTIONS:Mspamassassin)
CONFIGURE_ARGS+=	--enable-spamassassin
.endif

###
### Sender Policy Framework
###
.if empty(PKG_OPTIONS:Mspf)
CONFIGURE_ARGS+=	--disable-libspf2
.else
.include "../../mail/libspf2/buildlink3.mk"

CONFIGURE_ARGS+=	--with-libspf2=${BUILDLINK_PREFIX.libspf2}
.endif

# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.tdepim
PKG_SUPPORTED_OPTIONS=	arts sasl gnokii caldav carddav xscreensaver
PKG_SUGGESTED_OPTIONS=	arts sasl gnokii caldav carddav xscreensaver

.include "../../mk/bsd.options.mk"

CMAKE_ARGS+=	-DWITH_ALL_OPTIONS:BOOL=ON

PLIST_VARS+=	sasl gnokii caldav carddav indexlib

#option( WITH_ARTS "Enable aRts support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Marts)
.include "../../audio/arts/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_ARTS:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_ARTS:BOOL=OFF
.endif

#option( WITH_SASL "Enable cyrus-sasl support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Msasl)
PLIST.sasl=	yes
.include "../../security/cyrus-sasl/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_SASL:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_SASL:BOOL=OFF
.endif

#option( WITH_NEWDISTRLISTS "Enable the new distribution lists" ON )

#option( WITH_GNOKII "Enable gnokii support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Msasl)
PLIST.sasl=	yes
.include "../../comms/gnokii/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_GNOKII:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_GNOKII:BOOL=OFF
.endif

#option( WITH_EXCHANGE "Enable Microsoft Exchange 2000 support" ${WITH_ALL_OPTIONS} )
#option( WITH_EGROUPWARE "Enable egroupware support" ${WITH_ALL_OPTIONS} )
#option( WITH_KOLAB "Enable kolab support" ${WITH_ALL_OPTIONS} )
#option( WITH_SLOX "Enable slox support" ${WITH_ALL_OPTIONS} )
#option( WITH_GROUPWISE "Enable groupwise support" ${WITH_ALL_OPTIONS} )
#option( WITH_FEATUREPLAN "Enable featureplan support" ${WITH_ALL_OPTIONS} )
#option( WITH_GROUPDAV "Enable groupdav support" ${WITH_ALL_OPTIONS} )
#option( WITH_BIRTHDAYS "Enable birthdays support" ${WITH_ALL_OPTIONS} )
#option( WITH_NEWEXCHANGE "Enable newexchange support" ${WITH_ALL_OPTIONS} )
#option( WITH_SCALIX "Enable scalix support" ${WITH_ALL_OPTIONS} )

#option( WITH_CALDAV "Enable caldav support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mcaldav)
PLIST.caldav=	yes
.include "../../net/libcaldav/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_CALDAV:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_CALDAV:BOOL=OFF
.endif

#option( WITH_CARDDAV "Enable carddav support" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mcarddav)
PLIST.carddav=	yes
.include "../../net/libcarddav/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_CARDDAV:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_CARDDAV:BOOL=OFF
.endif

#option( WITH_INDEXLIB "Enable indexlib support (in kmail)" ${WITH_ALL_OPTIONS} )
CMAKE_ARGS+=	-DWITH_INDEXLIB:BOOL=ON

#option( WITH_XSCREENSAVER "Enable xscreensaver support (idle detection in karm)" ${WITH_ALL_OPTIONS} )
.if !empty(PKG_OPTIONS:Mxscreensaver)
.include "../../x11/libXScrnSaver/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_XSCREENSAVER:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_XSCREENSAVER:BOOL=OFF
.endif

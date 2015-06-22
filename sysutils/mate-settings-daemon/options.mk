# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.mate-settings-daemon
PKG_SUPPORTED_OPTIONS=	nss polkit canberra pulseaudio matemixer libnotify
PKG_SUGGESTED_OPTIONS=	nss polkit pulseaudio canberra matemixer libnotify

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	nss polkit

.if !empty(PKG_OPTIONS:Mnss)
.include "../../devel/nss/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-smartcard-support
PLIST.nss=	yes
.else
CONFIGURE_ARGS+=	--disable-smartcard-support
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pulse
.else
CONFIGURE_ARGS+=	--disable-pulse
.endif

.if !empty(PKG_OPTIONS:Mcanberra)
.include "../../audio/libcanberra/buildlink3.mk"
CONFIGURE_ARGS+=	--with-canberra
.else
CONFIGURE_ARGS+=	--without-canberra
.endif

.if !empty(PKG_OPTIONS:Mmatemixer)
.include "../../audio/libmatemixer/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libmatemixer
.else
CONFIGURE_ARGS+=	--without-libmatemixer
.endif

.if !empty(PKG_OPTIONS:Mlibnotify)
.include "../../sysutils/libnotify/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libnotify
.else
CONFIGURE_ARGS+=	--without-libnotify
.endif

.if !empty(PKG_OPTIONS:Mpolkit)
.include "../../security/polkit/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-polkit
PLIST.polkit=	yes
MAKE_DIRS+=	${PKG_SYSCONFDIR}/dbus-1/system.d
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/dbus-1/system.d/org.mate.SettingsDaemon.DateTimeMechanism.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.mate.SettingsDaemon.DateTimeMechanism.conf
.else
CONFIGURE_ARGS+=	--disable-polkit
.endif

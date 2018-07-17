# $NetBSD$
PKG_OPTIONS_VAR=	PKG_OPTIONS.gnokii
PKG_SUPPORTED_OPTIONS=	bluetooth ical usb pgsql sqlite mysql pcsc gtk2 readline
PKG_SUGGESTED_OPTIONS=	bluetooth ical usb pcsc gtk2 readline

PLIST_VARS+=	pgsql sqlite mysql x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mical)
.include "../../time/libical/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libical
.else
CONFIGURE_ARGS+=	--disable-libical
.endif

.if !empty(PKG_OPTIONS:Musb)
.include "../../mk/libusb.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libusb
.else
CONFIGURE_ARGS+=	--disable-libusb
.endif

.if !empty(PKG_OPTIONS:Mbluetooth)
CONFIGURE_ARGS+=	--enable-bluetooth
.else
CONFIGURE_ARGS+=	--disable-bluetooth
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
PLIST.pgsql=	yes
.include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-postgres
.else
CONFIGURE_ARGS+=	--disable-postgres
.endif

.if !empty(PKG_OPTIONS:Msqlite)
PLIST.sqlite=	yes
.include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-sqlite
.else
CONFIGURE_ARGS+=	--disable-sqlite
.endif

.if !empty(PKG_OPTIONS:Mmysql)
PLIST.mysql=	yes
.include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-mysql
.else
CONFIGURE_ARGS+=	--disable-mysql
.endif

.if !empty(PKG_OPTIONS:Mpcsc)
.include "../../security/pcsc-lite/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libpcsclite
.else
CONFIGURE_ARGS+=	--disable-libpcsclite
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
PLIST.x11=	yes
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if !empty(PKG_OPTIONS:Mreadline)
.include "../../mk/readline.buildlink3.mk"
CONFIGURE_ARGS+=	--with-readline
.else
CONFIGURE_ARGS+=	--without-readline
.endif

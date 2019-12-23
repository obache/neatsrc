# $NetBSD: options.mk,v 1.5 2019/11/04 21:28:48 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libvirt

# Common options.
PKG_SUPPORTED_OPTIONS+=	xen libssh2 lvm hal dbus avahi polkit
PKG_SUGGESTED_OPTIONS=	libssh2

.include "../../mk/bsd.options.mk"

# xentools42 is the only version to install
# the include files
PLIST_VARS+=	xen hal polkit

# xen means xen 4.2.
.if !empty(PKG_OPTIONS:Mxen)
PLIST.xen= yes
CONFIGURE_ARGS+=	--without-xen
CONFIGURE_ARGS+=	--with-libxl=${BUILDLINK_PREFIX.xentools42}
CONFIGURE_ARGS+=	--with-xenapi=${BUILDLINK_PREFIX.xentools42}
.  include "../../sysutils/xentools42/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibssh2)
CONFIGURE_ARGS+=	--with-ssh2=${BUILDLINK_PREFIX.libssh2}
.  include "../../security/libssh2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ssh2
.endif

.if !empty(PKG_OPTIONS:Mlvm)
CONFIGURE_ARGS+=	--with-storage-lvm
.endif

.if !empty(PKG_OPTIONS:Mhal)
PLIST.hal= yes
CONFIGURE_ARGS+=	--with-hal=${BUILDLINK_PREFIX.hal}
.  include "../../sysutils/hal/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-hal
.endif

.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--with-dbus=${BUILDLINK_PREFIX.dbus}
.  include "../../sysutils/dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-dbus
.endif

.if !empty(PKG_OPTIONS:Mavahi)
CONFIGURE_ARGS+=	--with-avahi=${BUILDLINK_PREFIX.avahi}
.  include "../../net/avahi/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-avahi
.endif

.if !empty(PKG_OPTIONS:Mpolkit)
PLIST.polkit= yes
CONFIGURE_ARGS+=	--with-polkit
CONFIGURE_ENV+=		ac_cv_path_PKCHECK_PATH=${BUILDLINK_PREFIX.polkit}/bin/pkcheck
.  include "../../security/polkit/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-polkit
.endif

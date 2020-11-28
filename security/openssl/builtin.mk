# $NetBSD: builtin.mk,v 1.46 2020/01/28 07:34:57 triaxx Exp $

BUILTIN_PKG:=	openssl

BUILTIN_FIND_LIBS:=			crypto ssl
BUILTIN_FIND_HEADERS_VAR:=		H_OPENSSLCONF H_OPENSSLV
BUILTIN_FIND_HEADERS.H_OPENSSLCONF=	openssl/opensslconf.h
BUILTIN_FIND_HEADERS.H_OPENSSLV=	openssl/opensslv.h
BUILTIN_FIND_PKGCONFIGS:=	openssl libcrypto libssl

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.openssl)
IS_BUILTIN.openssl=	no
.  if empty(H_OPENSSLV:M__nonexistent__) && empty(H_OPENSSLV:M${LOCALBASE}/*)
IS_BUILTIN.openssl=	yes
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.openssl

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.openssl) && \
    !empty(IS_BUILTIN.openssl:M[yY][eE][sS])
.  if ${BUILTIN_PKGCONFIG_FOUND.openssl} == "yes"
BUILTIN_VERSION.openssl=	${BUILTIN_PKGCONFIG_VERSION.openssl}
.  elif  empty(H_OPENSSLV:M__nonexistent__)
BUILTIN_VERSION.openssl!=						\
	${AWK} 'BEGIN { hex="0123456789abcdef";				\
			alpha="abcdefghijklmnopqrstuvwxyz";	\
		}							\
		/\#[ 	]+define/ { sub("\#[ \\t]+define", "\#define", $$0); } \
		/\#define[ 	]*OPENSSL_VERSION_NUMBER/ {		\
			major = index(hex, substr($$3, 3, 1)) - 1;	\
			i = 16 * (index(hex, substr($$3, 4, 1)) - 1);	\
			i += index(hex, substr($$3, 5, 1)) - 1;		\
			minor = "."i;					\
			i = 16 * (index(hex, substr($$3, 6, 1)) - 1);	\
			i += index(hex, substr($$3, 7, 1)) - 1;		\
			teeny = "."i;					\
			i = 16 * (index(hex, substr($$3, 8, 1)) - 1);	\
			i += index(hex, substr($$3, 9, 1)) - 1;		\
			if (i == 0) {					\
				patchlevel = "";			\
			} else if (i > 26) {				\
				patchlevel = "a";			\
			} else {					\
				patchlevel = substr(alpha,i,1);		\
			}						\
			printf "%s%s%s%s\n",				\
				major, minor, teeny, patchlevel;	\
			exit 0;						\
		}							\
	' ${H_OPENSSLV}
.  endif
BUILTIN_PKG.openssl=	openssl-${BUILTIN_VERSION.openssl}
.endif
MAKEVARS+=		BUILTIN_PKG.openssl
MAKEVARS+=		BUILTIN_VERSION.openssl

.if !defined(BUILTIN_OPENSSL_HAS_THREADS) && \
    !empty(IS_BUILTIN.openssl:M[yY][eE][sS]) && \
    empty(H_OPENSSLCONF:M__nonexistent__)
BUILTIN_OPENSSL_HAS_THREADS!=						\
	${AWK} 'BEGIN { ans = "no" }					\
		/\#[ 	]*define[ 	]*OPENSSL_THREADS/ { ans= "yes" } \
		/\#[ 	]*define[ 	]*THREADS/ { ans = "yes" }	\
		END { print ans; exit 0 }				\
	' ${H_OPENSSLCONF:Q}
.endif
MAKEVARS+=	BUILTIN_OPENSSL_HAS_THREADS

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.openssl)
.  if ${PREFER.openssl} == "pkgsrc"
USE_BUILTIN.openssl=		no
.  else
USE_BUILTIN.openssl=		${IS_BUILTIN.openssl}
.    if defined(BUILTIN_PKG.openssl) && \
        !empty(IS_BUILTIN.openssl:M[yY][eE][sS])
USE_BUILTIN.openssl=		yes
### take care builtin check case, BUILDLINK_API_DEPENDS may not be defined yet.
CHECK_BUILTIN.openssl?=		no
.      if !empty(CHECK_BUILTIN.openssl:M[yY][eE][sS])
BUILDLINK_API_DEPENDS.openssl?=	openssl>=1.1.1
.      endif
.      for dep_ in ${BUILDLINK_API_DEPENDS.openssl}
.        if !empty(USE_BUILTIN.openssl:M[yY][eE][sS])
USE_BUILTIN.openssl!=							\
	if ${PKG_ADMIN} pmatch ${dep_:Q} ${BUILTIN_PKG.openssl:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.    if !empty(IS_BUILTIN.openssl:M[yY][eE][sS]) && \
	defined(USE_FEATURES.openssl)
.      if !empty(USE_FEATURES.openssl:Mthreads) && \
	  !empty(BUILTIN_OPENSSL_HAS_THREADS:M[nN][oO])
USE_BUILTIN.openssl=		no
.      endif
.    endif
.  endif  # PREFER.openssl
.endif
MAKEVARS+=			USE_BUILTIN.openssl

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.openssl?=	no
.if !empty(CHECK_BUILTIN.openssl:M[nN][oO])

.  if !empty(USE_BUILTIN.openssl:M[yY][eE][sS])
.    if ${BUILTIN_PKGCONFIG_FOUND.openssl} == "yes"
BUILDLINK_PREFIX.openssl=	${BUILTIN_PKGCONFIG_PREFIX.openssl}
.    elif empty(H_OPENSSLV:M__nonexistent__)
.      if !empty(H_OPENSSLV:M/usr/sfw/*)
BUILDLINK_PREFIX.openssl=	/usr/sfw
BUILDLINK_PASSTHRU_DIRS+=	/usr/sfw
.      elif !empty(H_OPENSSLV:M/usr/*)
BUILDLINK_PREFIX.openssl=	/usr
.      elif !empty(H_OPENSSLV:M/boot/system/develop/*)
BUILDLINK_PREFIX.openssl=	/boot/system/develop
.      endif
.    endif
.  endif

.  if defined(PKG_SYSCONFDIR.openssl)
SSLDIR=	${PKG_SYSCONFDIR.openssl}
.  elif !empty(USE_BUILTIN.openssl:M[yY][eE][sS])
.    if ${OPSYS} == "NetBSD"
SSLDIR=	/etc/openssl
.    elif ${OPSYS} == "Haiku"
SSLDIR=	/boot/system/data/ssl
.    else
SSLDIR=	/etc/ssl 		# most likely place
.    endif
.  else
SSLDIR=	${PKG_SYSCONFBASEDIR}/openssl
.  endif

SSLCERTS=	${SSLDIR}/certs
SSLKEYS=	${SSLDIR}/private

BUILD_DEFS+=	SSLDIR SSLCERTS SSLKEYS

BUILTIN_FAKE_PC_FILES.openssl=	libcrypto libssl openssl
.  for pc in ${BUILTIN_FAKE_PC_FILES.openssl}
FAKE_PC_SRC.${pc}=	../../security/openssl/files/${pc}.pc
FAKE_PC_SUBST_VARS.${pc}=	BUILDLINK_PREFIX.openssl
FAKE_PC_SUBST_VARS.${pc}+=	BUILTIN_VERSION.openssl
FAKE_PC_SUBST_VARS.${pc}+=	LIBABISUFFIX
.  endfor

.endif	# CHECK_BUILTIN.openssl

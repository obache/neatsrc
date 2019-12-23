# $NetBSD: builtin.mk,v 1.10 2019/11/03 11:45:41 rillig Exp $

BUILTIN_PKG:=	mDNSResponder

BUILTIN_FIND_HEADERS_VAR:=	H_DNSSD
BUILTIN_FIND_HEADERS.H_DNSSD=	dns_sd.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.mDNSResponder)
IS_BUILTIN.mDNSResponder=	no
.  if empty(H_DNSSD:M__nonexistent__)
IS_BUILTIN.mDNSResponder=	yes
.  endif
.endif	# IS_BUILTIN.mDNSResponder
MAKEVARS+=			IS_BUILTIN.mDNSResponder

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.mDNSResponder) && \
    !empty(IS_BUILTIN.mDNSResponder:M[yY][eE][sS]) && \
    empty(H_DNSSD:M__nonexistent__)
BUILTIN_VERSION.mDNSResponder!=						\
	${AWK} 'BEGIN { version_str = "0"; }				\
		/\#define[ 	]+_DNS_SD_H[ 	]+[0-9]+/ {		\
			major = $$3 / 10000;				\
			minor = ( $$3 % 10000 ) / 100;			\
			teeny = $$3 % 100;				\
			version_str = sprintf ( "%d.%d.%d",		\
				 major, minor, teeny); 			\
			exit 0;						\
		}							\
		END { print version_str; }				\
	' ${H_DNSSD}
BUILTIN_PKG.mDNSResponder=	mDNSResponder-${BUILTIN_VERSION.mDNSResponder}
.endif

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.mDNSResponder)
.  if ${PREFER.mDNSResponder} == "pkgsrc"
USE_BUILTIN.mDNSResponder=	no
.  else
USE_BUILTIN.mDNSResponder=	${IS_BUILTIN.mDNSResponder}
.    if defined(BUILTIN_PKG.mDNSResponder) && \
        !empty(IS_BUILTIN.mDNSResponder:M[yY][eE][sS])
USE_BUILTIN.mDNSResponder=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.mDNSResponder}
.        if !empty(USE_BUILTIN.mDNSResponder:M[yY][eE][sS])
USE_BUILTIN.mDNSResponder!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.mDNSResponder:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.mDNSResponder
.endif
MAKEVARS+=			USE_BUILTIN.mDNSResponder

# $NetBSD: builtin.mk,v 1.18 2016/11/30 13:21:47 wiz Exp $

BUILTIN_PKG:=	libevent

BUILTIN_FIND_HEADERS_VAR:=		H_LIBEVENT H_LIBEVENTCONFIG
BUILTIN_FIND_HEADERS.H_LIBEVENT=	event.h
BUILTIN_FIND_HEADERS.H_LIBEVENTCONFIG=	event-config.h event2/event-config.h
BUILTIN_FIND_LIBS:=			event
BUILTIN_FIND_LIBS+=			event_openssl event_pthreads
BUILTIN_FIND_LIBS+=			event_core event_extra
BUILTIN_FIND_PKGCONFIGS:=		${BUILTIN_FIND_LIBS:S/^/lib/}

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.libevent)
IS_BUILTIN.libevent=	no
.  if empty(H_LIBEVENT:M__nonexistent__) && empty(H_LIBEVENT:M${LOCALBASE}/*)
IS_BUILTIN.libevent=	yes
.  endif
.endif	# IS_BUILTIN.libevent
MAKEVARS+=	IS_BUILTIN.libevent

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.libevent) && \
    !empty(IS_BUILTIN.libevent:M[yY][eE][sS]) && \
    empty(H_LIBEVENT:M__nonexistent__)
.  if ${BUILTIN_PKGCONFIG_FOUND.libevent} == "yes"
BUILTIN_VERSION_STRING.libevent=	${BUILTIN_PKGCONFIG_VERSION.libevent}
.  elif empty(H_LIBEVENTCONFIG:M__nonexistent__)
BUILTIN_VERSION_STRING.libevent!=					\
	${AWK} '/\#define[ 	]*EVENT__PACKAGE_VERSION/ {		\
			vers = $$3;					\
			gsub("\"", "", vers);				\
			print vers;					\
		}							\
	' ${H_LIBEVENTCONFIG:Q}
.  else
# libevent>=1.3: bufferevent_base_set added
_BLTN_EVENT_13!=	\
	${GREP} -c bufferevent_base_set ${H_LIBEVENT} || ${TRUE}
# libevent>=1.2: evtag_*, event_base_free added
_BLTN_EVENT_12!=	\
	${GREP} -c evtag_ ${H_LIBEVENT} || ${TRUE}
# libevent>=1.1b: evbuffer_add_vprintf added
_BLTN_EVENT_11b!=	\
	${GREP} -c evbuffer_add_vprintf ${H_LIBEVENT} || ${TRUE}
# libevent>=1.0d: evbuffer_readline added
_BLTN_EVENT_10d!=	\
	${GREP} -c event_base_loopexit ${H_LIBEVENT} || ${TRUE}
# libevent>=1.0c: event_set_log_callback, event_base_loopexit and
#                 event_get_{version,method} added
_BLTN_EVENT_10c!=	\
	${GREP} -c event_base_loopexit ${H_LIBEVENT} || ${TRUE}
# libevent>=1.0: event_base_* and event_priority_* added
_BLTN_EVENT_10!=	\
	${GREP} -c event_base_ ${H_LIBEVENT} || ${TRUE}
# libevent>=0.9: evbuffer_{expand,remove} added
_BLTN_EVENT_09!=	\
	${GREP} -c evbuffer_expand ${H_LIBEVENT} || ${TRUE}
# libevent>=0.8: buffering functions added
_BLTN_EVENT_08!=	\
	${GREP} -c evbuffer ${H_LIBEVENT} || ${TRUE}
# libevent>=0.7b: WIN32 support added
_BLTN_EVENT_07b!=	\
	${GREP} -c WIN32 ${H_LIBEVENT} || ${TRUE}
# libevent>=0.6: evtimer_* added
_BLTN_EVENT_06!=	\
	${GREP} -c evtimer_ ${H_LIBEVENT} || ${TRUE}

.    if ${_BLTN_EVENT_13} == "1"
BUILTIN_VERSION.libevent=	1.3
.    elif ${_BLTN_EVENT_12} == "1"
BUILTIN_VERSION.libevent=	1.2
.    elif ${_BLTN_EVENT_11b} == "1"
BUILTIN_VERSION.libevent=	1.1b
.    elif ${_BLTN_EVENT_10d} == "1"
BUILTIN_VERSION.libevent=	1.0d
.    elif ${_BLTN_EVENT_10c} == "1"
BUILTIN_VERSION.libevent=	1.0c
.    elif ${_BLTN_EVENT_10} == "1"
BUILTIN_VERSION.libevent=	1.0
.    elif ${_BLTN_EVENT_09} == "1"
BUILTIN_VERSION.libevent=	0.9
.    elif ${_BLTN_EVENT_08} == "1"
BUILTIN_VERSION.libevent=	0.8
.    elif ${_BLTN_EVENT_07b} == "1"
BUILTIN_VERSION.libevent=	0.7b
.    elif ${_BLTN_EVENT_06} == "1"
BUILTIN_VERSION.libevent=	0.6
.    else
BUILTIN_VERSION.libevent=	0.5
.    endif
.  endif
BUILTIN_VERSION_STRING.libevent?=	${BUILTIN_VERSION.libevent:U1.4.4}
BUILTIN_VERSION.libevent?=	${BUILTIN_VERSION_STRING.libevent:C/-[a-zA-Z]*$//}
BUILTIN_PKG.libevent=	libevent-${BUILTIN_VERSION.libevent}
.endif
MAKEVARS+=	BUILTIN_PKG.libevent

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libevent)
.  if ${PREFER.libevent} == "pkgsrc"
USE_BUILTIN.libevent=	no
.  else
USE_BUILTIN.libevent=	${IS_BUILTIN.libevent}
.    if defined(BUILTIN_PKG.libevent) && \
        !empty(IS_BUILTIN.libevent:M[yY][eE][sS])
USE_BUILTIN.libevent=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libevent}
.        if !empty(USE_BUILTIN.libevent:M[yY][eE][sS])
USE_BUILTIN.libevent!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libevent:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libevent
.endif
MAKEVARS+=	USE_BUILTIN.libevent

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.libevent?=	no
.if !empty(CHECK_BUILTIN.libevent:M[nN][oO])
.  if !empty(USE_BUILTIN.libevent:M[yY][eE][sS])
.    if ${BUILTIN_PKGCONFIG_FOUND.libevent} == "yes"
BUIDLINK_PREFIX.libevent?=	${BUILTIN_PKGCONFIG_PREFIX.libevent}
.    endif
BUILTIN_FAKE_PC_FILES.libevent=	libevent
FAKE_PC_SRC.libevent:=		${.PARSEDIR}/files/libevent.pc.in
FAKE_PC_SUBST_SED.libevent+=	-e s,@VERSION@,${BUILTIN_VERSION_STRING.libevent},g
FAKE_PC_SUBST_SED.libevent+=	-e s,@prefix@,${BUILDLINK_PREFIX.libevent},g
FAKE_PC_SUBST_SED.libevent+=	-e s,@exec_prefix@,${BUILDLINK_PREFIX.libevent},g
FAKE_PC_SUBST_SED.libevent+=	-e s,@includedir@,${BUILTIN_HEADER_FOUND_DIR.H_LIBEVENT},g
FAKE_PC_SUBST_SED.libevent+=	-e s,@libdir@,${BUILTIN_LIB_FOUND_DIR.event},g
FAKE_PC_SUBST_SED.libevent+=	-e s,@LIBS@,-lcrypto,g
.    for l in openssl pthreads core extra
.      if ${BUILTIN_LIB_FOUND.event_${l}} == "yes"
BUILTIN_FAKE_PC_FILES.libevent+=	libevent_${l}
FAKE_PC_SRC.libevent_${l}:=		${.PARSEDIR}/files/libevent_${l}.pc.in
FAKE_PC_SUBST_SED.libevent_${l}=	${FAKE_PC_SUBST_SED.libevent}
.      endif
.    endfor
FAKE_PC_SUBST_SED.libevent_openssl+=	-e 's,@OPENSSL_LIBS@,-lssl -lcrypto,g'
FAKE_PC_SUBST_SED.libevent_openssl+=	-e 's,@OPENSSL_INCS@,,g'
FAKE_PC_SUBST_SED.libevent_pthreads+=	-e 's,@PTHREAD_LIBS@,${PTHREAD_LIBS},g'
FAKE_PC_SUBST_SED.libevent_pthreads+=	-e 's,@PTHREAD_CFLAGS@,${PTHREAD_CFLAGS},g'
.  endif
.endif # CHECK_BUILTIN.libevent

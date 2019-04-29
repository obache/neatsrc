# $NetBSD: config-override.mk,v 1.7 2013/10/13 10:10:05 wiz Exp $

######################################################################
### config-{guess,sub}-override (PRIVATE)
######################################################################
### config-{guess,sub}-override replace any existing config.guess and
### config.sub under ${WRKSRC} with the specially-kept versions
### under pkgsrc/mk/gnu-config.
###
do-configure-pre-hook: config-guess-override
do-configure-pre-hook: config-sub-override

_OVERRIDE_VAR.guess=	CONFIG_GUESS_OVERRIDE
_OVERRIDE_VAR.sub=	CONFIG_SUB_OVERRIDE

CONFIG_EXTRA_OVERRIDE_DIRS?=	# empty
CONFIG_OVERRIDE_DIRS?=	${WRKSRC} ${CONFIG_EXTRA_OVERRIDE_DIRS}

OVERRIDE_DIRDEPTH.config-guess?=	${OVERRIDE_DIRDEPTH}
OVERRIDE_DIRDEPTH.config-sub?=		${OVERRIDE_DIRDEPTH}

.for _sub_ in guess sub
_SCRIPT.config-${_sub_}-override=					\
	${RM} -f $$file;						\
	${LN} -fs ${PKGSRCDIR}/mk/gnu-config/config.${_sub_} $$file

.PHONY: config-${_sub_}-override
config-${_sub_}-override:
	@${STEP_MSG} "Replacing config-${_sub_} with pkgsrc versions"
.  if defined(${_OVERRIDE_VAR.${_sub_}}) && !empty(${_OVERRIDE_VAR.${_sub_}})
	${RUN} \
	cd ${WRKSRC};							\
	for file in ${${_OVERRIDE_VAR.${_sub_}}}; do			\
		[ -f "$$file" ] || [ -h "$$file" ] || continue;		\
		${_SCRIPT.${.TARGET}};					\
	done
.  else
.    for d in ${CONFIG_OVERRIDE_DIRS}
	${RUN} \
	cd ${d};							\
	depth=0; pattern=config.${_sub_};				\
	while [ $$depth -le ${OVERRIDE_DIRDEPTH.config-${_sub_}} ]; do	\
		for file in $$pattern; do				\
			[ -f "$$file" ] || [ -h "$$file" ] || continue;	\
			${_SCRIPT.${.TARGET}};				\
		done;							\
		depth=`${EXPR} $$depth + 1`; pattern="*/$$pattern";	\
	done
.    endfor
.  endif
.endfor

######################################################################
### configure-scripts-override (PRIVATE)
######################################################################
### configure-scripts-override modifies the GNU configure scripts in
### ${WRKSRC} so that the generated config.status scripts never do
### anything on "--recheck".  This is important in pkgsrc because we
### only ever want to run the configure checks during the configure
### phase, and "recheck" is often run during the build and install
### phases.
###
### configure-scripts-osdep modifies the GNU configure scripts in
### ${WRKSRC} to support operating systems without upstream support
### in for example libtool.
do-configure-pre-hook: configure-scripts-override

_SCRIPT.configure-scripts-osdep.MirBSD=					\
	| ${AWK} 'BEGIN { found = 0 }					\
		/dynamic linker characteristics.../ { found = 1 }	\
		/^netbsd/ {						\
			if (found) {					\
				sub("netbsd","mirbsd*|netbsd");		\
				found = 0;				\
			}						\
		}							\
		{ print $$0 }'

_SCRIPT.configure-scripts-osdep.skyos=					\
	| ${SED} -e 's,test -x / ,test -x ./ ,g'

_SCRIPT.configure-scripts-osdep.${OPSYS}?=	# empty

_SCRIPT.configure-scripts-override=					\
	${AWK} '/ *-recheck *\| *--recheck.*\)/ {			\
			print;						\
			print "	: Avoid regenerating within pkgsrc";	\
			print "	exit 0";				\
			next;						\
		}							\
		{ print }' $$file 					\
		${_SCRIPT.configure-scripts-osdep.${OPSYS}}		\
		> $$file.override;					\
	${CHMOD} +x $$file.override;					\
	${TOUCH} -r $$file $$file.override;				\
	${MV} -f $$file.override $$file

OVERRIDE_DIRDEPTH.configure?=	${OVERRIDE_DIRDEPTH}

.PHONY: configure-scripts-override
configure-scripts-override:
	@${STEP_MSG} "Modifying GNU configure scripts to avoid --recheck"
.if defined(CONFIGURE_SCRIPTS_OVERRIDE) && !empty(CONFIGURE_SCRIPTS_OVERRIDE)
	@echo HERE
	${RUN} \
	cd ${WRKSRC};							\
	for file in ${CONFIGURE_SCRIPTS_OVERRIDE}; do			\
		${TEST} -f "$$file" || continue;			\
		${_SCRIPT.${.TARGET}};					\
	done
.else
.    for d in ${CONFIG_OVERRIDE_DIRS}
	${RUN} \
	cd $d;								\
	depth=0; pattern=${CONFIGURE_SCRIPT:T};				\
	while ${TEST} $$depth -le ${OVERRIDE_DIRDEPTH.configure}; do	\
		for file in $$pattern; do				\
			${TEST} -f "$$file" || continue;		\
			${_SCRIPT.${.TARGET}};				\
		done;							\
		depth=`${EXPR} $$depth + 1`; pattern="*/$$pattern";	\
	done
.    endfor
.endif

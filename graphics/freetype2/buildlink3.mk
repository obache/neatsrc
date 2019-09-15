# $NetBSD: buildlink3.mk,v 1.49 2019/09/09 12:40:50 wiz Exp $

BUILDLINK_TREE+=	freetype2

.if !defined(FREETYPE2_BUILDLINK3_MK)
FREETYPE2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.8.1
BUILDLINK_PKGSRCDIR.freetype2?=		../../graphics/freetype2
BUILDLINK_INCDIRS.freetype2?=		include/freetype2

BUILDLINK_FILES.freetype2+=	bin/freetype-config

FREETYPE_CONFIG?=	${BUILDLINK_PREFIX.freetype2}/bin/freetype-config
CONFIGURE_ENV+=		FREETYPE_CONFIG=${FREETYPE_CONFIG:Q}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

pkgbase := freetype2
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.freetype2:Mpng)
CHECK_BUILTIN.freetype2:=	yes
.include "../../graphics/freetype2/builtin.mk"
CHECK_BUILTIN.freetype2:=	no

.  if empty(USE_BUILTIN.freetype2:M[yY][eE][sS])
.    include "../../graphics/png/buildlink3.mk"
.  endif
.endif

BUILDLINK_TARGETS+=	fake-freetype-config

_FT2_VER_MAP.2.9.1=	22.1.16
_FT2_VER_MAP.2.9.0=	22.0.16
_FT2_VER_MAP.2.8.1=	21.0.15
_FT2_VER_MAP.2.8.0=	20.0.14
_FT2_VER_MAP.2.7.1=	19.0.13
_FT2_VER_MAP.2.7.0=	18.6.12
_FT2_VER_MAP.2.6.5=	18.5.12
_FT2_VER_MAP.2.6.4=	18.4.12
_FT2_VER_MAP.2.6.3=	18.3.12
_FT2_VER_MAP.2.6.2=	18.2.12
_FT2_VER_MAP.2.6.1=	18.1.12
_FT2_VER_MAP.2.6.0=	18.0.12
_FT2_VER_MAP.2.5.5=	17.4.11
_FT2_VER_MAP.2.5.4=	17.3.11
_FT2_VER_MAP.2.5.3=	17.2.11
_FT2_VER_MAP.2.5.2=	17.1.11
_FT2_VER_MAP.2.5.1=	17.0.11
_FT2_VER_MAP.2.5.0=	16.2.10
_FT2_VER_MAP.2.4.12=	16.1.10
_FT2_VER_MAP.2.4.11=	16.0.10
_FT2_VER_MAP.2.4.10=	15.0.9
_FT2_VER_MAP.2.4.9=	14.1.8
_FT2_VER_MAP.2.4.8=	14.0.8
_FT2_VER_MAP.2.4.7=	13.2.7
_FT2_VER_MAP.2.4.6=	13.1.7
_FT2_VER_MAP.2.4.5=	13.0.7
_FT2_VER_MAP.2.4.4=	12.2.6
_FT2_VER_MAP.2.4.3=	12.1.6
_FT2_VER_MAP.2.4.2=	12.0.6
_FT2_VER_MAP.2.4.1=	11.1.5
_FT2_VER_MAP.2.4.0=	11.0.5
_FT2_VER=	${_FT2_VER_MAP.${${USE_BUILTIN.freetype2:M[Nn][Oo]}=="":? ${BUILTIN_VERSION.freetype2}:${BUILDLINK_PKGNAME.freetype2:C/^.*-//:C/nb[0-9]*$//}}}

.PHONY: fake-freetype-config
fake-freetype-config:
	${RUN}\
	if ${TEST} -x ${BUILDLINK_BINDIR}/freetype-config; then ${TRUE}; \
	elif ${TEST} -x ${FREETYPE_CONFIG}; then \
		${LN} -s ${FREETYPE_CONFIG} \
			${BUILDLINK_BINDIR}/freetype-config; \
	else \
		${SED}	\
			-e 's,%PKG_CONFIG%,${TOOLS_DIR}/bin/pkg-config,g' \
			-e 's,%prefix%,${BUILDLINK_PREFIX.freetype2},g' \
			-e 's,%exec_prefix%,${BUILDLINK_PREFIX.freetype2},g' \
			-e 's,%includedir%,${BUILDLINK_PREFIX.freetype2}/include,g' \
			-e 's,%libdir%,${BUILDLINK_PREFIX.freetype2}/lib,g' \
			-e 's,%ft_version%,${_FT2_VER},g' \
			-e 's,%LIBSDYNAMIC_CONFIG%,${COMPILER_RPATH_FLAG:S/,/\\,/g}$$libdir -lfreetype,g' \
			-e 's,%LIBSSTATIC_CONFIG%,-lfreetype -lz -lbz2,g' \
		${BUILDLINK_PKGSRCDIR.freetype2}/files/freetype-config.in \
			> ${BUILDLINK_BINDIR}/freetype-config; \
		${CHMOD} ${BINMODE} ${BUILDLINK_BINDIR}/freetype-config; \
	fi

.endif # FREETYPE2_BUILDLINK3_MK

BUILDLINK_TREE+=	-freetype2

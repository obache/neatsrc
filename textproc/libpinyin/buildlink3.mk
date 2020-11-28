# $NetBSD: buildlink3.mk,v 1.3 2020/03/08 16:48:15 wiz Exp $
#

BUILDLINK_TREE+=	libpinyin

.if !defined(LIBPINYIN_BUILDLINK3_MK)
LIBPINYIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpinyin+=	libpinyin>=2.1.0
BUILDLINK_ABI_DEPENDS.libpinyin?=	libpinyin>=2.3.0nb1
BUILDLINK_PKGSRCDIR.libpinyin?=		../../textproc/libpinyin

pkgbase := libpinyin
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.libpinyin:Mbdb)
BDB_INCOMPATIBLE+=	db1 db2 db3
.  include "../../mk/bdb.buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.libpinyin:Mkyotocabinet)
.  include "../../databases/kyotocabinet/buildlink3.mk"
.endif
.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBPINYIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpinyin

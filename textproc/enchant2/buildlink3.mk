# $NetBSD: buildlink3.mk,v 1.6 2020/10/26 17:19:29 nia Exp $

BUILDLINK_TREE+=	enchant2

.if !defined(ENCHANT2_BUILDLINK3_MK)
ENCHANT2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.enchant2+=	enchant2>=2
BUILDLINK_ABI_DEPENDS.enchant2+=	enchant2>=2.2.8nb1
BUILDLINK_PKGSRCDIR.enchant2?=		../../textproc/enchant2

GCC_REQD+=	4.8

# Lots of older software looks for enchant.pc instead of enchant-2.pc.
BUILDLINK_FNAME_ALIASES.enchant2+= \
	lib/pkgconfig/enchant-2.pc lib/pkgconfig/enchant.pc

# spelling libraries are loaded dynamically and do not need
# to be included here
.include "../../devel/glib2/buildlink3.mk"
.endif # ENCHANT2_BUILDLINK3_MK

BUILDLINK_TREE+=	-enchant2

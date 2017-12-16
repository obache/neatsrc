# $NetBSD$

BUILDLINK_TREE+=	cmake-fedora

.if !defined(CMAKE_FEDORA_BUILDLINK3_MK)
CMAKE_FEDORA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cmake-fedora+=	cmake-fedora>=2.2.1
BUILDLINK_DEPMETHOD.cmake-fedora?=	build
BUILDLINK_PKGSRCDIR.cmake-fedora?=	../../devel/cmake-fedora

BUILDLINK_CONTENTS_FILTER.cmake-fedora=	${EGREP} '^share/cmake/Modules/'
.endif	# CMAKE_FEDORA_BUILDLINK3_MK

BUILDLINK_TREE+=	-cmake-fedora

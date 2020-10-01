# $NetBSD$

.include "Makefile.common"

META_PACKAGE=YES

.include "../../meta-pkgs/tde/Makefile.tde"

TDE_LOCALES=	af ar az be bg bn br bs ca cs csb cy da de el en_GB eo es et eu
TDE_LOCALES+=	fa fi fr fy ga gl he hi hr hu is it ja kk km ko lt lv mk mn ms
TDE_LOCALES+=	nb nds nl nn pa pl pt pt_BR ro ru rw se sk sl sr sr@Latn ss sv
TDE_LOCALES+=	ta te tg th tr uk uz uz@cyrillic vi wa zh_CN zh_TW 

DEPENDS+=	${TDE_LOCALES:@l@tde-i18n-${l}>=${_TDE_RELEASE}:../../x11/tde-i18n-${l}@}

create-sub:
.for p in ${TDE_LOCALES:@l@tde-i18n-${l}@}
	test -d ../../x11/${p} || (\
		mkdir -p ../../x11/$p; \
		cd ../../x11/$p; \
		cp ../../x11/tde-i18n-ja/Makefile .; \
		touch PLIST; \
		make stage-install || make print-PLIST > PLIST; \
		make clean \
	)
.endfor

.include "../../mk/bsd.pkg.mk"

# $NetBSD: tool.mk,v 1.3 2019/12/15 23:59:00 gutteridge Exp $
#
# Create `python' interpreter wrapper for applicable Python bin.
#
# This mk fragment can be included in all packages that use `python'
# as a tool without a pkgsrc-style version suffix.
#
# Keywords: python
#

.if !defined(PYTHON_TOOL_MK)
PYTHON_TOOL_MK=	defined

.if !defined(PYTHON_PYVERSION_MK)
.include "../../lang/python/pyversion.mk"
.endif

BUILDLINK_TARGETS+=	buildlink-python-alternatives

.PHONY: buildlink-python-alternatives
buildlink-python-alternatives:
	${RUN} \
	${SED} ${FILES_SUBST_SED} < ${PYPKGSRCDIR}/ALTERNATIVES | \
	while read t f; do \
		if ${TEST} -f $$f -a ! -f $$t ; then \
		${LN} -sf $$f ${BUILDLINK_DIR}/$$t; \
		fi \
	done

.endif # PYTHON_TOOL_MK

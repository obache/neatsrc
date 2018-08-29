#!/bin/sh

: ${PKG_CONFIG=/usr/pkg/bin/pkg-config}
: ${PKG_CONFIG_PATH=}
: ${PWD_CMD=pwd -P}
: ${TEST=test}
: ${WRKDIR=}

case "${PKG_CONFIG}" in
/*)	;;
*)	echo 1>&2 "$0: \`\`${PKG_CONFIG}'' must be an absolute pathname."
	exit 1
	;;
esac
if test ! -x "${PKG_CONFIG}"; then
	echo 1>&2 "$0: \`\`${PKG_CONFIG}'' does not exist."
	exit 1
fi

if test -z "${WRKDIR}"; then
	echo 1>&2 "$0: \`\`\${WRKDIR}'' is not specified."
	exit 1
fi

CURDIR=`${PWD_CMD}`

addpath() {
	if $TEST -z "$1"; then
		echo $2
	else
		echo $1:$2
	fi
}

sanitalize_path() {
	save_IFS="${IFS}"; IFS=":"
	set -- $1
	IFS="${save_IFS}"
	result_path=""

	while $TEST $# -gt 0; do
		case $1 in
		/*)	d=$1 ;;
		*)	d="$CURDIR/$1";;
		esac
		shift
		case $d in
		${WRKDIR}/*)
			result_path=`addpath "$result_path" "$d"`;;
		*)	;;
		esac
	done
	echo $result_path
}

PKG_CONFIG_PATH=`sanitalize_path "$PKG_CONFIG_PATH"`
export PKG_CONFIG_PATH
${PKG_CONFIG} $@

#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: lightdm
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

$_rc_subr_loaded . /etc/rc.subr

name="lightdm"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
command_args="--pid-file ${pidfile}"
procname="@PREFIX@/sbin/gdm-binary"
required_files="@PKG_SYSCONFDIR@/custom.conf"
extra_commands="reload"

load_rc_config ${name}
run_rc_command "$1"

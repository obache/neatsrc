# $NetBSD$
#
# System-supplied tools for the MSYS operating system.

TOOLS_PLATFORM.[?=		[			# shell builtin
.if exists(/usr/bin/autopoint)
TOOLS_PLATFORM.autopoint?=	/usr/bin/autopoint
.endif
TOOLS_PLATFORM.awk?=		/usr/bin/awk
TOOLS_PLATFORM.basename?=	/usr/bin/basename
TOOLS_PLATFORM.bash?=		/usr/bin/bash
.if exists(/usr/bin/bison)
TOOLS_PLATFORM.bison?=		/usr/bin/bison
TOOLS_PLATFORM.bison-yacc?=	/usr/bin/bison -y
.endif
.if exists(/usr/bin/bsdtar)
TOOLS_PLATFORM.bsdtar?=		/usr/bin/bsdtar
.endif
.if exists(/usr/bin/byacc)
TOOLS_PLATFORM.byacc?=		/usr/bin/byacc
.endif
TOOLS_PLATFORM.bzcat?=		/usr/bin/bzcat
TOOLS_PLATFORM.bzip2?=		/usr/bin/bzip2
TOOLS_PLATFORM.cat?=		/usr/bin/cat
TOOLS_PLATFORM.chgrp?=		/usr/bin/chgrp
TOOLS_PLATFORM.chmod?=		/usr/bin/chmod
TOOLS_PLATFORM.chown?=		/usr/bin/chown
.if exists(/usr/bin/cmp)
TOOLS_PLATFORM.cmp?=		/usr/bin/cmp
.endif
TOOLS_PLATFORM.cp?=		/usr/bin/cp
.if exists(/usr/bin/tcsh)
TOOLS_PLATFORM.csh?=		/usr/bin/tcsh
.endif
.if exists(/usr/bin/curl)
TOOLS_PLATFORM.curl?=		/usr/bin/curl
.endif
TOOLS_PLATFORM.cut?=		/usr/bin/cut
TOOLS_PLATFORM.date?=		/usr/bin/date
.if exists(/usr/bin/diff)
TOOLS_PLATFORM.diff?=		/usr/bin/diff
.endif
.if exists(/usr/bin/diff3)
TOOLS_PLATFORM.diff3?=		/usr/bin/diff3
.endif
TOOLS_PLATFORM.dirname?=	/usr/bin/dirname
TOOLS_PLATFORM.echo?=		echo			# shell builtin
TOOLS_PLATFORM.egrep?=		/usr/bin/egrep
TOOLS_PLATFORM.env?=		/usr/bin/env
TOOLS_PLATFORM.expr?=		/usr/bin/expr
TOOLS_PLATFORM.false?=		false			# shell builtin
TOOLS_PLATFORM.fgrep?=		/usr/bin/fgrep
TOOLS_PLATFORM.file?=		/usr/bin/file
TOOLS_PLATFORM.find?=		/usr/bin/find
.if exists(/usr/bin/flex)
TOOLS_PLATFORM.flex?=		/usr/bin/flex
.endif
.if exists(/usr/bin/tnftp)
TOOLS_PLATFORM.ftp?=		/usr/bin/tnftp
.endif
TOOLS_PLATFORM.gawk?=		/usr/bin/gawk
.if exists(/usr/bin/gettext)
TOOLS_PLATFORM.gettext?=	/usr/bin/gettext
.endif
.if exists(/usr/bin/m4)
TOOLS_PLATFORM.gm4?=		/usr/bin/m4
.endif
TOOLS_PLATFORM.grep?=		/usr/bin/grep
TOOLS_PLATFORM.gsed?=		/usr/bin/sed
.if exists(/usr/bin/soelim)
TOOLS_PLATFORM.gsoelim?=	/usr/bin/soelim
.endif
.if exists(/usr/bin/tar)
TOOLS_PLATFORM.gtar?=		/usr/bin/tar
.endif
TOOLS_PLATFORM.gunzip?=		/usr/bin/gunzip -f
TOOLS_PLATFORM.gzcat?=		/usr/bin/zcat
TOOLS_PLATFORM.gzip?=		/usr/bin/gzip -nf ${GZIP}
TOOLS_PLATFORM.head?=		/usr/bin/head
TOOLS_PLATFORM.hostname?=	/usr/bin/hostname
TOOLS_PLATFORM.id?=		/usr/bin/id
.if exists(/usr/bin/ident)
TOOLS_PLATFORM.ident?=		/usr/bin/ident
.endif
TOOLS_PLATFORM.install?=	/usr/bin/install
TOOLS_PLATFORM.install-info?=	/usr/bin/install-info
.if exists(/usr/bin/flex)
TOOLS_PLATFORM.lex?=		/usr/bin/flex
.endif
TOOLS_PLATFORM.ln?=		/usr/bin/ln
TOOLS_PLATFORM.ls?=		/usr/bin/ls
.if exists(/usr/bin/m4)
TOOLS_PLATFORM.m4?=		/usr/bin/m4
.endif
.if exists(/usr/bin/make)
TOOLS_PLATFORM.gmake?=		/usr/bin/make
.endif
.if exists(/usr/bin/makeinfo)
TOOLS_PLATFORM.makeinfo?=	/usr/bin/makeinfo
.endif
TOOLS_PLATFORM.mkdir?=		/usr/bin/mkdir -p
TOOLS_PLATFORM.mktemp?=		/usr/bin/mktemp
.if exists(/usr/bin/msgconv)
TOOLS_PLATFORM.msgconv?=	/usr/bin/msgconv
.endif
.if exists(/usr/bin/msgfmt)
TOOLS_PLATFORM.msgfmt?=		/usr/bin/msgfmt
.endif
.if exists(/usr/bin/msgmerge)
TOOLS_PLATFORM.msgmerge?=	/usr/bin/msgmerge
.endif
TOOLS_PLATFORM.mv?=		/usr/bin/mv
TOOLS_PLATFORM.nice?=		/usr/bin/nice
.if exists(/usr/bin/nroff)
TOOLS_PLATFORM.nroff?=		/usr/bin/nroff
.endif
.if exists(/usr/bin/openssl)
TOOLS_PLATFORM.openssl?=	/usr/bin/openssl
.endif
.if exists(/usr/bin/pax)
TOOLS_PLATFORM.pax?=		/usr/bin/pax
.endif
.if exists(/usr/bin/perl)
TOOLS_PLATFORM.perl?=		/usr/bin/perl
TOOLS_PLATFORM.pod2man?=	/usr/bin/pod2man
.endif
# Don't use GNU patch
#.if exists(/usr/bin/patch)
#TOOLS_PLATFORM.patch?=		/usr/bin/patch
#.endif
.if exists(/usr/bin/pkg-config)
TOOLS_PLATFORM.pkg-config?=	/usr/bin/pkg-config
.endif
TOOLS_PLATFORM.printf?=		/usr/bin/printf
TOOLS_PLATFORM.pwd?=		/usr/bin/pwd
TOOLS_PLATFORM.readlink?=	/usr/bin/readlink
TOOLS_PLATFORM.rm?=		/usr/bin/rm
TOOLS_PLATFORM.rmdir?=		/usr/bin/rmdir
.if exists(/usr/bin/sdiff)
TOOLS_PLATFORM.sdiff?=		/usr/bin/sdiff
.endif
TOOLS_PLATFORM.sed?=		/usr/bin/sed
TOOLS_PLATFORM.sh?=		/usr/bin/sh
TOOLS_PLATFORM.sleep?=		/usr/bin/sleep
.if exists(/usr/bin/soelim)
TOOLS_PLATFORM.soelim?=		/usr/bin/soelim
.endif
TOOLS_PLATFORM.sort?=		/usr/bin/sort
.if exists(/usr/bin/strip)
TOOLS_PLATFORM.strip?=		/usr/bin/strip
.endif
TOOLS_PLATFORM.tail?=		/usr/bin/tail
.if exists(/usr/bin/bsdtar)
TOOLS_PLATFORM.tar?=		/usr/bin/bsdtar
.elif exists(/usr/bin/tar)
TOOLS_PLATFORM.tar?=		/usr/bin/tar
.endif
.if exists(/usr/bin/tbl)
TOOLS_PLATFORM.tbl?=		/usr/bin/tbl
.endif
TOOLS_PLATFORM.tee?=		/usr/bin/tee
TOOLS_PLATFORM.test?=		test			# shell builtin
.if exists(/usr/bin/texi2html)
TOOLS_PLATFORM.texi2html?=	/usr/bin/texi2html
.endif
TOOLS_PLATFORM.touch?=		/usr/bin/touch
TOOLS_PLATFORM.tr?=		/usr/bin/tr
TOOLS_PLATFORM.true?=		true			# shell builtin
TOOLS_PLATFORM.tsort?=		/usr/bin/tsort
TOOLS_PLATFORM.uniq?=		/usr/bin/uniq
.if exists(/usr/bin/unzip)
TOOLS_PLATFORM.unzip?=		/usr/bin/unzip
.endif
TOOLS_PLATFORM.wc?=		/usr/bin/wc
.if exists(/usr/bin/wget)
TOOLS_PLATFORM.wget?=		/usr/bin/wget
.endif
TOOLS_PLATFORM.xargs?=		/usr/bin/xargs -r
.if exists(/usr/bin/xgettext)
TOOLS_PLATFORM.xgettext?=	/usr/bin/xgettext
.endif
TOOLS_PLATFORM.xz?=		/usr/bin/xz
TOOLS_PLATFORM.xzcat?=		/usr/bin/xzcat
.if exists(/usr/bin/yacc)
TOOLS_PLATFORM.yacc?=		/usr/bin/yacc
.endif
.if exists(/usr/bin/zip)
TOOLS_PLATFORM.zip?=		/usr/bin/zip
.endif

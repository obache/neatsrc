#! /bin/sh
#
# drop autoconf macros from installed header files with evaluated config.h
#

have_ns_type=1
have_decl_ns_t_spf=1
have_decl_ns_t_invalid=1
have_netdb_h=1

conf_file=${WRKSRC}/config.h

${GREP} -q -e '^\#define HAVE_NS_TYPE' ${conf_file} || have_ns_type=0
${GREP} -q -e '^\#define HAVE_DECL_NS_T_SPF' ${conf_file} || have_decl_t_spf=0
${GREP} -q -e '^\#define HAVE_DECL_NS_T_INVALID' ${conf_file} || have_decl_t_invalid=0
${GREP} -q -e '^\#define HAVE_NETDB_H' ${conf_file} || have_netdb_h=0

${SED}	-e "s,defined( HAVE_NS_TYPE ),${have_ns_type}," \
	-e "s,HAVE_DECL_NS_T_SPF,${have_decl_ns_t_spf}," \
	-e "s,HAVE_DECL_NS_T_INVALID,${have_decl_ns_t_invalid}," \
	-e "s,defined(HAVE_NETDB_H),${have_netdb_h},"

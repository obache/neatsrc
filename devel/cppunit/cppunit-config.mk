# $NetBSD$

# Makefile intended to be included by packages that need "cppunit-config"
# during build time.

USE_TOOLS+=	pkg-config

TOOLS_CREATE+=	cppunit-config

TOOLS_SCRIPT.cppunit-config=	\
	  case $$1 in	\
	  --cflags|--libs) pkg-config $$1 cppunit;;	\
	  --version) pkg-config --modversion cppunit;;	\
	  *) exit 1;;			\
	  esac

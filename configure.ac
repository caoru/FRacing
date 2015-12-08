#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([FRacing], [0.1], [frag@frag.kr])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])

#AM_INIT_AUTOMAKE([foreign])
AM_INIT_AUTOMAKE

# Checks for programs.
#AC_PROG_CXX
AC_PROG_CC
AC_PROG_LIBTOOL
#AC_USE_SYSTEM_EXTENSION

# Checks for libraries.
AC_ARG_WITH([libts],
	[AS_HELP_STRING([--without-libts],
		[Disable library for touch screen support @<:@default=yes@:>@])],
	[:],
	[with_libts=yes])

AS_IF([test "$with_libts" != "no"],
	[AC_CHECK_LIB([ts],
		[ts_open],
		[AS_IF([test "$with_libts" != "no"],
			[AC_CHECK_HEADER([tslib.h],
				[with_libts=yes],
				[with_libts=no])])],
		[with_libts=no])])

if test "$with_libts" = "yes"; then
	AC_DEFINE([HAVE_LIBTS], [1], [Define if libts exist.])
	LIBTS_CFLAGS=""
	LIBTS_LDADD="-lts"
else
	LIBTS_CFLAGS=""
	LIBTS_LDADD=""
fi
AC_SUBST(LIBTS_CFLAGS)
AC_SUBST(LIBTS_LDADD)

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_SIZEOF([void *])

AX_CHECK_COMPILE_FLAG([-Wall], [CFLAGS="$CFLAGS -Wall"])
AX_CHECK_COMPILE_FLAG([-Werror], [CFLAGS="$CFLAGS -Werror"])

#AC_DEFINE(_GNU_SOURCE)

# We need some BSD extensions, but the latest glibc does a #warn when using
# _BSD_SOURCE

AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <features.h>
#ifndef __GLIBC__
#error not glibc
#endif
]], [])],
CFLAGS="$CFLAGS -D_GNU_SOURCE",
CFLAGS="$CFLAGS -D_BSD_SOURCE")
#source_level_define="-D_GNU_SOURCE",
#source_level_define="-D_BSD_SOURCE")

#AC_SUBST(source_level_define)


#                 lib/utillity/Makefile
#                 lib/gps/Makefile
AC_CONFIG_FILES([Makefile
                 lib/Makefile
                 lib/configini/Makefile
                 lib/cssl/Makefile
                 lib/framebuffer/Makefile
                 test/Makefile
                 src/Makefile])
AC_OUTPUT

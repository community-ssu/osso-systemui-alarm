AC_INIT([osso-systemui-alarm], [0.2.1.31])

AM_INIT_AUTOMAKE

# Specify dir for local macros
AC_CONFIG_MACRO_DIR([m4])

AC_ISC_POSIX
AC_PROG_CC
AC_PROG_MAKE_SET
AM_PROG_CC_STDC
AC_PROG_LIBTOOL
AC_HEADER_STDC

PKG_CHECK_MODULES(DEPS, gtk+-2.0 >= 2.4.0 gconf-2.0 > 2.0 glib-2.0 >= 2.20.3 x11 dbus-1 alarm libnotify hildon-1)
AC_SUBST(DEPS_CFLAGS)
AC_SUBST(DEPS_LIBS)

AC_OUTPUT([ Makefile src/Makefile])


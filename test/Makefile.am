#
#  FRacing/test/Makefile.am
#
#  Copyright (C) 2015 Ikhyun Kim.
#
# This file is placed under the GPL.  Please see the file
# COPYING for more details.
#
#

bin_PROGRAMS = config_test fb_test

config_test_SOURCES = config_test.c
config_test_CFLAGS = -I$(top_srcdir)/lib/configini
config_test_LDADD = $(top_srcdir)/lib/configini/libfrconfigini.la

fb_test_SOURCES = fb_test.c
fb_test_CFLAGS = -I$(top_srcdir)/lib/common
fb_test_CFLAGS += -I$(top_srcdir)/lib/configini
fb_test_CFLAGS += -I$(top_srcdir)/lib/framebuffer
fb_test_LDADD = $(top_srcdir)/lib/configini/libfrconfigini.la
fb_test_LDADD += $(top_srcdir)/lib/framebuffer/libfrframebuffer.la


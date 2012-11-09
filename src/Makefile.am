INCLUDES = \
       $(DEPS_CFLAGS)

libosso_systemui_alarm_LTLIBRARIES = libosso-systemui-alarm.la
libosso_systemui_alarmdir = /usr/lib/systemui

libosso_systemui_alarm_la_SOURCES =  osso-systemui-alarm.c
libosso_systemui_alarm_la_CFLAGS = $(HILDONIMVKBRENDERER_CFLAGS)
libosso_systemui_alarm_la_LDFLAGS = -module -fPIC
libosso_systemui_alarm_la_LIBADD = $(DEPS_LIBS) -l:/usr/bin/systemui -ltime -lhildon-plugins-notify-sv

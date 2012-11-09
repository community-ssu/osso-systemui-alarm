#ifndef __SYSTEMUI_H_INCLUDED__
#define __SYSTEMUI_H_INCLUDED__

#include <dbus/dbus.h>
#include <gconf/gconf-client.h>

struct systemui
{
  int handlers;
  int field_4;
  int field_8;
  int field_C;
  int field_10;
  int field_14;
  GConfClient *client;
  int field_1C;
  int field_20;
  int field_24;
  int field_28;
  int field_2C;
  DBusConnection *dbus;
};

extern void *nsv_sv_init(void*);
extern void *nsv_sv_shutdown(void*);

extern void *nsv_sv_play_event(void*);
extern void nsv_sv_stop_event(void*, void*);

extern void add_handler(const char *,
                        int (*)(const char *,const char *, GArray *, struct systemui *, int *),
                        struct systemui *);

extern void remove_handler(const char *, struct systemui *);

extern void WindowPriority_HideWindow(GtkWidget*);
extern gboolean WindowPriority_ShowWindow(GtkWidget*, int);


#endif /* __SYSTEMUI_H_INCLUDED__ */

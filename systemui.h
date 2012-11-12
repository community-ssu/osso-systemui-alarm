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
  DBusConnection *system_bus;
};

typedef struct
{
  dbus_uint32_t first32;
  dbus_uint32_t second32;
} DBus8ByteStruct;

typedef union
{
  unsigned char bytes[8];
  dbus_int16_t i16;
  dbus_uint16_t u16;
  dbus_int32_t i32;
  dbus_uint32_t u32;
  dbus_bool_t bool_val;
#ifdef DBUS_HAVE_INT64
  dbus_int64_t i64;
  dbus_uint64_t u64;
#endif
  DBus8ByteStruct eight;
  double dbl;
  unsigned char byt;
  char *str;
  int fd;
} DBusBasicValue;

struct systemui_alarm_param
{
  int arg_type;
  DBusBasicValue data;
};

extern void nsv_sv_init(void*);
extern void nsv_sv_shutdown(void*);

extern guint nsv_sv_play_event(void*, guint);
extern void nsv_sv_stop_event(void*, guint);

extern void add_handler(const char *,
                        int (*)(const char *,const char *, GArray *, struct systemui *, struct systemui_alarm_param *),
                        struct systemui *);

extern void remove_handler(const char *, struct systemui *);

extern void WindowPriority_HideWindow(GtkWidget*);
extern gboolean WindowPriority_ShowWindow(GtkWidget*, int);


#endif /* __SYSTEMUI_H_INCLUDED__ */

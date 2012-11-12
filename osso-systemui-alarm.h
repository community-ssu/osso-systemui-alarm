#ifndef __OSSO_SYSTEMUI_ALARM_H_INCLUDED__
#define __OSSO_SYSTEMUI_ALARM_H_INCLUDED__
#include <mce/dbus-names.h>
#include <mce/mode-names.h>

typedef enum {
  UP,
  DOWN
}device_orientation_t;

static void alarm_mce_turn_display_on(DBusConnection *system_bus)
{
  DBusMessage *message;

  message = dbus_message_new_method_call(
          MCE_SERVICE,
          MCE_REQUEST_PATH,
          MCE_REQUEST_IF,
          MCE_DISPLAY_ON_REQ);
  dbus_message_set_no_reply(message, TRUE);
  dbus_connection_send(system_bus, message, 0);
  dbus_connection_flush(system_bus);
  dbus_message_unref(message);
}

static void alarm_mce_accel_enable(DBusConnection *system_bus)
{
  DBusMessage *message;

  message = dbus_message_new_method_call(
         MCE_SERVICE,
         MCE_REQUEST_PATH,
         MCE_REQUEST_IF,
         MCE_ACCELEROMETER_ENABLE_REQ);

  dbus_message_set_no_reply(message, TRUE);
  dbus_connection_send(system_bus, message, NULL);
  dbus_connection_flush(system_bus);
  dbus_message_unref(message);
}

static void alarm_mce_accel_disable(DBusConnection *system_bus)
{
  DBusMessage *message;

  message = dbus_message_new_method_call(
         MCE_SERVICE,
         MCE_REQUEST_PATH,
         MCE_REQUEST_IF,
         MCE_ACCELEROMETER_DISABLE_REQ);

  dbus_message_set_no_reply(message, TRUE);
  dbus_connection_send(system_bus, message, NULL);
  dbus_connection_flush(system_bus);
  dbus_message_unref(message);
}

static void alarm_mce_tklock_unlock(DBusConnection *system_bus)
{
  DBusMessage *message;
  const char * unlock = MCE_TK_UNLOCKED;
  message = dbus_message_new_method_call(
         MCE_SERVICE,
         MCE_REQUEST_PATH,
         MCE_REQUEST_IF,
         MCE_TKLOCK_MODE_CHANGE_REQ);

  dbus_message_append_args(message,
                           DBUS_TYPE_STRING, &unlock,
                           DBUS_TYPE_INVALID);

  dbus_message_set_no_reply(message, TRUE);
  dbus_connection_send(system_bus, message, NULL);
  dbus_connection_flush(system_bus);
  dbus_message_unref(message);
}

static device_orientation_t alarm_mce_get_orientation(DBusConnection *system_bus)
{
  DBusMessage *message;
  DBusMessage  *reply;
  DBusError error = DBUS_ERROR_INIT;
  int x,y,z;
  gchar *orientation,*stand,*face;
  device_orientation_t rv = UP;
  message = dbus_message_new_method_call(
         "com.nokia.mce",
         "/com/nokia/mce/request",
         "com.nokia.mce.request",
         "get_device_orientation");

  reply = dbus_connection_send_with_reply_and_block(system_bus, message, -1, &error);

  if ( reply )
  {
    dbus_message_get_args( reply, &error,
                           DBUS_TYPE_STRING, &orientation,
                           DBUS_TYPE_STRING, &stand,
                           DBUS_TYPE_STRING, &face,
                           DBUS_TYPE_INT32, &x,
                           DBUS_TYPE_INT32, &y,
                           DBUS_TYPE_INT32, &z,
                           DBUS_TYPE_INVALID);

    rv = (!strcmp(orientation, MCE_ORIENTATION_FACE_DOWN))? DOWN : UP;
    dbus_message_unref(reply);
  }

  dbus_message_unref(message);

  if(dbus_error_is_set(&error))
    dbus_error_free(&error);

  return rv;
}

static gboolean dbus_send_alarm_dialog_status(DBusConnection *system_bus, dbus_int32_t status)
{
  DBusMessage *message;
  gboolean result = FALSE;

  message = dbus_message_new_signal("/com/nokia/system_ui/signal",
                                    "com.nokia.system_ui.signal",
                                    "alarm_dialog_status");

  if ( message )
  {
    if ( dbus_message_append_args(message,
                                  DBUS_TYPE_UINT32, &status,
                                  DBUS_TYPE_INVALID) )
    {
      dbus_message_set_no_reply(message, TRUE);

      if( dbus_connection_send(system_bus, message, NULL) )
      {
        dbus_connection_flush(system_bus);
        result = TRUE;
      }
    }

    dbus_message_unref(message);
  }

  return result;
}
#endif /* __OSSO_SYSTEMUI_ALARM_H_INCLUDED__ */

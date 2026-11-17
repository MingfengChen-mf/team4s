// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from team4s_interfaces:msg/RangeReading.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "team4s_interfaces/msg/detail/range_reading__struct.h"
#include "team4s_interfaces/msg/detail/range_reading__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool team4s_interfaces__msg__range_reading__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[50];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("team4s_interfaces.msg._range_reading.RangeReading", full_classname_dest, 49) == 0);
  }
  team4s_interfaces__msg__RangeReading * ros_message = _ros_message;
  {  // sensor_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "sensor_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->sensor_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // sensor_frame_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "sensor_frame_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->sensor_frame_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "valid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->valid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // reason
    PyObject * field = PyObject_GetAttrString(_pymsg, "reason");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->reason, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // checksum_ok
    PyObject * field = PyObject_GetAttrString(_pymsg, "checksum_ok");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->checksum_ok = (Py_True == field);
    Py_DECREF(field);
  }
  {  // device_status_raw
    PyObject * field = PyObject_GetAttrString(_pymsg, "device_status_raw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->device_status_raw = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // distance_m
    PyObject * field = PyObject_GetAttrString(_pymsg, "distance_m");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->distance_m = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // signal_strength
    PyObject * field = PyObject_GetAttrString(_pymsg, "signal_strength");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->signal_strength = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // sensor_time_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "sensor_time_ms");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sensor_time_ms = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // bearing_known
    PyObject * field = PyObject_GetAttrString(_pymsg, "bearing_known");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->bearing_known = (Py_True == field);
    Py_DECREF(field);
  }
  {  // bearing_rad
    PyObject * field = PyObject_GetAttrString(_pymsg, "bearing_rad");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bearing_rad = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * team4s_interfaces__msg__range_reading__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RangeReading */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("team4s_interfaces.msg._range_reading");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RangeReading");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  team4s_interfaces__msg__RangeReading * ros_message = (team4s_interfaces__msg__RangeReading *)raw_ros_message;
  {  // sensor_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->sensor_id.data,
      strlen(ros_message->sensor_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "sensor_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sensor_frame_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->sensor_frame_id.data,
      strlen(ros_message->sensor_frame_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "sensor_frame_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // valid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->valid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reason
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->reason.data,
      strlen(ros_message->reason.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "reason", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // checksum_ok
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->checksum_ok ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "checksum_ok", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // device_status_raw
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->device_status_raw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "device_status_raw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // distance_m
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->distance_m);
    {
      int rc = PyObject_SetAttrString(_pymessage, "distance_m", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // signal_strength
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->signal_strength);
    {
      int rc = PyObject_SetAttrString(_pymessage, "signal_strength", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sensor_time_ms
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->sensor_time_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sensor_time_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bearing_known
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->bearing_known ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bearing_known", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bearing_rad
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bearing_rad);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bearing_rad", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

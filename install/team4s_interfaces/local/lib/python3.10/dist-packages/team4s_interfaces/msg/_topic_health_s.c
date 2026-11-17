// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from team4s_interfaces:msg/TopicHealth.idl
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
#include "team4s_interfaces/msg/detail/topic_health__struct.h"
#include "team4s_interfaces/msg/detail/topic_health__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool team4s_interfaces__msg__topic_health__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[48];
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
    assert(strncmp("team4s_interfaces.msg._topic_health.TopicHealth", full_classname_dest, 47) == 0);
  }
  team4s_interfaces__msg__TopicHealth * ros_message = _ros_message;
  {  // state
    PyObject * field = PyObject_GetAttrString(_pymsg, "state");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->state = (uint8_t)PyLong_AsUnsignedLong(field);
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
  {  // age_known
    PyObject * field = PyObject_GetAttrString(_pymsg, "age_known");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->age_known = (Py_True == field);
    Py_DECREF(field);
  }
  {  // age_s
    PyObject * field = PyObject_GetAttrString(_pymsg, "age_s");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->age_s = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // max_age_s
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_age_s");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_age_s = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * team4s_interfaces__msg__topic_health__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of TopicHealth */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("team4s_interfaces.msg._topic_health");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "TopicHealth");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  team4s_interfaces__msg__TopicHealth * ros_message = (team4s_interfaces__msg__TopicHealth *)raw_ros_message;
  {  // state
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->state);
    {
      int rc = PyObject_SetAttrString(_pymessage, "state", field);
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
  {  // age_known
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->age_known ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "age_known", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // age_s
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->age_s);
    {
      int rc = PyObject_SetAttrString(_pymessage, "age_s", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_age_s
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_age_s);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_age_s", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

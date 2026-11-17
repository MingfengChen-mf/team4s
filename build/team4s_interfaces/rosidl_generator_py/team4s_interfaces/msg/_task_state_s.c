// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from team4s_interfaces:msg/TaskState.idl
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
#include "team4s_interfaces/msg/detail/task_state__struct.h"
#include "team4s_interfaces/msg/detail/task_state__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool team4s_interfaces__msg__task_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[44];
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
    assert(strncmp("team4s_interfaces.msg._task_state.TaskState", full_classname_dest, 43) == 0);
  }
  team4s_interfaces__msg__TaskState * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // run_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "run_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->run_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // controller_session_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "controller_session_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->controller_session_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // sequence
    PyObject * field = PyObject_GetAttrString(_pymsg, "sequence");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sequence = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // task_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "task_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->task_id = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // phase
    PyObject * field = PyObject_GetAttrString(_pymsg, "phase");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->phase = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // target_lane
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_lane");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->target_lane = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // control_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "control_mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->control_mode = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // lap_complete
    PyObject * field = PyObject_GetAttrString(_pymsg, "lap_complete");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->lap_complete = (Py_True == field);
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

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * team4s_interfaces__msg__task_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of TaskState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("team4s_interfaces.msg._task_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "TaskState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  team4s_interfaces__msg__TaskState * ros_message = (team4s_interfaces__msg__TaskState *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // run_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->run_id.data,
      strlen(ros_message->run_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "run_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // controller_session_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->controller_session_id.data,
      strlen(ros_message->controller_session_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "controller_session_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sequence
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->sequence);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sequence", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // task_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->task_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "task_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // phase
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->phase);
    {
      int rc = PyObject_SetAttrString(_pymessage, "phase", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_lane
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->target_lane);
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_lane", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // control_mode
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->control_mode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "control_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lap_complete
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->lap_complete ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lap_complete", field);
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

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

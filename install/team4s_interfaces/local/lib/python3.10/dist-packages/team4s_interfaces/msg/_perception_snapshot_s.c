// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from team4s_interfaces:msg/PerceptionSnapshot.idl
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
#include "team4s_interfaces/msg/detail/perception_snapshot__struct.h"
#include "team4s_interfaces/msg/detail/perception_snapshot__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
bool team4s_interfaces__msg__lane_observation__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * team4s_interfaces__msg__lane_observation__convert_to_py(void * raw_ros_message);
bool team4s_interfaces__msg__topic_health__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * team4s_interfaces__msg__topic_health__convert_to_py(void * raw_ros_message);
bool team4s_interfaces__msg__obstacle_observation__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * team4s_interfaces__msg__obstacle_observation__convert_to_py(void * raw_ros_message);
bool team4s_interfaces__msg__topic_health__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * team4s_interfaces__msg__topic_health__convert_to_py(void * raw_ros_message);
bool team4s_interfaces__msg__scene_observation__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * team4s_interfaces__msg__scene_observation__convert_to_py(void * raw_ros_message);
bool team4s_interfaces__msg__topic_health__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * team4s_interfaces__msg__topic_health__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool team4s_interfaces__msg__perception_snapshot__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[62];
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
    assert(strncmp("team4s_interfaces.msg._perception_snapshot.PerceptionSnapshot", full_classname_dest, 61) == 0);
  }
  team4s_interfaces__msg__PerceptionSnapshot * ros_message = _ros_message;
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
  {  // aggregator_session_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "aggregator_session_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->aggregator_session_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
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
  {  // sequence
    PyObject * field = PyObject_GetAttrString(_pymsg, "sequence");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sequence = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // lane
    PyObject * field = PyObject_GetAttrString(_pymsg, "lane");
    if (!field) {
      return false;
    }
    if (!team4s_interfaces__msg__lane_observation__convert_from_py(field, &ros_message->lane)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // lane_health
    PyObject * field = PyObject_GetAttrString(_pymsg, "lane_health");
    if (!field) {
      return false;
    }
    if (!team4s_interfaces__msg__topic_health__convert_from_py(field, &ros_message->lane_health)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // obstacles
    PyObject * field = PyObject_GetAttrString(_pymsg, "obstacles");
    if (!field) {
      return false;
    }
    if (!team4s_interfaces__msg__obstacle_observation__convert_from_py(field, &ros_message->obstacles)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // obstacles_health
    PyObject * field = PyObject_GetAttrString(_pymsg, "obstacles_health");
    if (!field) {
      return false;
    }
    if (!team4s_interfaces__msg__topic_health__convert_from_py(field, &ros_message->obstacles_health)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // scene
    PyObject * field = PyObject_GetAttrString(_pymsg, "scene");
    if (!field) {
      return false;
    }
    if (!team4s_interfaces__msg__scene_observation__convert_from_py(field, &ros_message->scene)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // scene_health
    PyObject * field = PyObject_GetAttrString(_pymsg, "scene_health");
    if (!field) {
      return false;
    }
    if (!team4s_interfaces__msg__topic_health__convert_from_py(field, &ros_message->scene_health)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * team4s_interfaces__msg__perception_snapshot__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PerceptionSnapshot */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("team4s_interfaces.msg._perception_snapshot");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PerceptionSnapshot");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  team4s_interfaces__msg__PerceptionSnapshot * ros_message = (team4s_interfaces__msg__PerceptionSnapshot *)raw_ros_message;
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
  {  // aggregator_session_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->aggregator_session_id.data,
      strlen(ros_message->aggregator_session_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "aggregator_session_id", field);
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
  {  // lane
    PyObject * field = NULL;
    field = team4s_interfaces__msg__lane_observation__convert_to_py(&ros_message->lane);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "lane", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lane_health
    PyObject * field = NULL;
    field = team4s_interfaces__msg__topic_health__convert_to_py(&ros_message->lane_health);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "lane_health", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // obstacles
    PyObject * field = NULL;
    field = team4s_interfaces__msg__obstacle_observation__convert_to_py(&ros_message->obstacles);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "obstacles", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // obstacles_health
    PyObject * field = NULL;
    field = team4s_interfaces__msg__topic_health__convert_to_py(&ros_message->obstacles_health);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "obstacles_health", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // scene
    PyObject * field = NULL;
    field = team4s_interfaces__msg__scene_observation__convert_to_py(&ros_message->scene);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "scene", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // scene_health
    PyObject * field = NULL;
    field = team4s_interfaces__msg__topic_health__convert_to_py(&ros_message->scene_health);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "scene_health", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

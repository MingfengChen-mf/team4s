// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from team4s_interfaces:msg/LaneCandidate.idl
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
#include "team4s_interfaces/msg/detail/lane_candidate__struct.h"
#include "team4s_interfaces/msg/detail/lane_candidate__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool team4s_interfaces__msg__lane_candidate__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[52];
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
    assert(strncmp("team4s_interfaces.msg._lane_candidate.LaneCandidate", full_classname_dest, 51) == 0);
  }
  team4s_interfaces__msg__LaneCandidate * ros_message = _ros_message;
  {  // candidate_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "candidate_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->candidate_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // route_lane
    PyObject * field = PyObject_GetAttrString(_pymsg, "route_lane");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->route_lane = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // is_branch
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_branch");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_branch = (Py_True == field);
    Py_DECREF(field);
  }
  {  // left_visible
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_visible");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->left_visible = (Py_True == field);
    Py_DECREF(field);
  }
  {  // right_visible
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_visible");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->right_visible = (Py_True == field);
    Py_DECREF(field);
  }
  {  // center_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "center_valid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->center_valid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // offset_px
    PyObject * field = PyObject_GetAttrString(_pymsg, "offset_px");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->offset_px = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // reference_y_px
    PyObject * field = PyObject_GetAttrString(_pymsg, "reference_y_px");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->reference_y_px = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // heading_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "heading_valid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->heading_valid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // heading_rad
    PyObject * field = PyObject_GetAttrString(_pymsg, "heading_rad");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->heading_rad = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * team4s_interfaces__msg__lane_candidate__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of LaneCandidate */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("team4s_interfaces.msg._lane_candidate");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "LaneCandidate");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  team4s_interfaces__msg__LaneCandidate * ros_message = (team4s_interfaces__msg__LaneCandidate *)raw_ros_message;
  {  // candidate_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->candidate_id.data,
      strlen(ros_message->candidate_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "candidate_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // route_lane
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->route_lane);
    {
      int rc = PyObject_SetAttrString(_pymessage, "route_lane", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_branch
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_branch ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_branch", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_visible
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->left_visible ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_visible", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_visible
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->right_visible ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_visible", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // center_valid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->center_valid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "center_valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // offset_px
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->offset_px);
    {
      int rc = PyObject_SetAttrString(_pymessage, "offset_px", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reference_y_px
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->reference_y_px);
    {
      int rc = PyObject_SetAttrString(_pymessage, "reference_y_px", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // heading_valid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->heading_valid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "heading_valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // heading_rad
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->heading_rad);
    {
      int rc = PyObject_SetAttrString(_pymessage, "heading_rad", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

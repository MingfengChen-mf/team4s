// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from team4s_interfaces:msg/LaneObservation.idl
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
#include "team4s_interfaces/msg/detail/lane_observation__struct.h"
#include "team4s_interfaces/msg/detail/lane_observation__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

// Nested array functions includes
#include "team4s_interfaces/msg/detail/lane_candidate__functions.h"
// end nested array functions include
bool team4s_interfaces__msg__source_header__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * team4s_interfaces__msg__source_header__convert_to_py(void * raw_ros_message);
bool team4s_interfaces__msg__lane_candidate__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * team4s_interfaces__msg__lane_candidate__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool team4s_interfaces__msg__lane_observation__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[56];
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
    assert(strncmp("team4s_interfaces.msg._lane_observation.LaneObservation", full_classname_dest, 55) == 0);
  }
  team4s_interfaces__msg__LaneObservation * ros_message = _ros_message;
  {  // meta
    PyObject * field = PyObject_GetAttrString(_pymsg, "meta");
    if (!field) {
      return false;
    }
    if (!team4s_interfaces__msg__source_header__convert_from_py(field, &ros_message->meta)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // image_width
    PyObject * field = PyObject_GetAttrString(_pymsg, "image_width");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->image_width = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // image_height
    PyObject * field = PyObject_GetAttrString(_pymsg, "image_height");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->image_height = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // candidates
    PyObject * field = PyObject_GetAttrString(_pymsg, "candidates");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'candidates'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!team4s_interfaces__msg__LaneCandidate__Sequence__init(&(ros_message->candidates), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create team4s_interfaces__msg__LaneCandidate__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    team4s_interfaces__msg__LaneCandidate * dest = ros_message->candidates.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!team4s_interfaces__msg__lane_candidate__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // selected_candidate_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "selected_candidate_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->selected_candidate_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // offset_m_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "offset_m_valid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->offset_m_valid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // offset_m
    PyObject * field = PyObject_GetAttrString(_pymsg, "offset_m");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->offset_m = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // metric_reason
    PyObject * field = PyObject_GetAttrString(_pymsg, "metric_reason");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->metric_reason, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // calibration_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "calibration_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->calibration_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // metric_frame_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "metric_frame_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->metric_frame_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // metric_reference_x_m
    PyObject * field = PyObject_GetAttrString(_pymsg, "metric_reference_x_m");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->metric_reference_x_m = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // metric_reference_y_m
    PyObject * field = PyObject_GetAttrString(_pymsg, "metric_reference_y_m");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->metric_reference_y_m = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * team4s_interfaces__msg__lane_observation__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of LaneObservation */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("team4s_interfaces.msg._lane_observation");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "LaneObservation");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  team4s_interfaces__msg__LaneObservation * ros_message = (team4s_interfaces__msg__LaneObservation *)raw_ros_message;
  {  // meta
    PyObject * field = NULL;
    field = team4s_interfaces__msg__source_header__convert_to_py(&ros_message->meta);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "meta", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // image_width
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->image_width);
    {
      int rc = PyObject_SetAttrString(_pymessage, "image_width", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // image_height
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->image_height);
    {
      int rc = PyObject_SetAttrString(_pymessage, "image_height", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // candidates
    PyObject * field = NULL;
    size_t size = ros_message->candidates.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    team4s_interfaces__msg__LaneCandidate * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->candidates.data[i]);
      PyObject * pyitem = team4s_interfaces__msg__lane_candidate__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "candidates", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // selected_candidate_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->selected_candidate_id.data,
      strlen(ros_message->selected_candidate_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "selected_candidate_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // offset_m_valid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->offset_m_valid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "offset_m_valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // offset_m
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->offset_m);
    {
      int rc = PyObject_SetAttrString(_pymessage, "offset_m", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // metric_reason
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->metric_reason.data,
      strlen(ros_message->metric_reason.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "metric_reason", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // calibration_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->calibration_id.data,
      strlen(ros_message->calibration_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "calibration_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // metric_frame_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->metric_frame_id.data,
      strlen(ros_message->metric_frame_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "metric_frame_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // metric_reference_x_m
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->metric_reference_x_m);
    {
      int rc = PyObject_SetAttrString(_pymessage, "metric_reference_x_m", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // metric_reference_y_m
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->metric_reference_y_m);
    {
      int rc = PyObject_SetAttrString(_pymessage, "metric_reference_y_m", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

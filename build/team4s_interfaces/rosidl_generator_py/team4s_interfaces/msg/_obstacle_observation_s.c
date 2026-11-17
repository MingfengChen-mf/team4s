// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from team4s_interfaces:msg/ObstacleObservation.idl
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
#include "team4s_interfaces/msg/detail/obstacle_observation__struct.h"
#include "team4s_interfaces/msg/detail/obstacle_observation__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "team4s_interfaces/msg/detail/range_reading__functions.h"
// end nested array functions include
bool team4s_interfaces__msg__source_header__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * team4s_interfaces__msg__source_header__convert_to_py(void * raw_ros_message);
bool team4s_interfaces__msg__range_reading__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * team4s_interfaces__msg__range_reading__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool team4s_interfaces__msg__obstacle_observation__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[64];
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
    assert(strncmp("team4s_interfaces.msg._obstacle_observation.ObstacleObservation", full_classname_dest, 63) == 0);
  }
  team4s_interfaces__msg__ObstacleObservation * ros_message = _ros_message;
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
  {  // readings
    PyObject * field = PyObject_GetAttrString(_pymsg, "readings");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'readings'");
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
    if (!team4s_interfaces__msg__RangeReading__Sequence__init(&(ros_message->readings), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create team4s_interfaces__msg__RangeReading__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    team4s_interfaces__msg__RangeReading * dest = ros_message->readings.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!team4s_interfaces__msg__range_reading__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // left_clear_known
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_clear_known");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->left_clear_known = (Py_True == field);
    Py_DECREF(field);
  }
  {  // left_clear
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_clear");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->left_clear = (Py_True == field);
    Py_DECREF(field);
  }
  {  // right_clear_known
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_clear_known");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->right_clear_known = (Py_True == field);
    Py_DECREF(field);
  }
  {  // right_clear
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_clear");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->right_clear = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * team4s_interfaces__msg__obstacle_observation__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ObstacleObservation */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("team4s_interfaces.msg._obstacle_observation");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ObstacleObservation");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  team4s_interfaces__msg__ObstacleObservation * ros_message = (team4s_interfaces__msg__ObstacleObservation *)raw_ros_message;
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
  {  // readings
    PyObject * field = NULL;
    size_t size = ros_message->readings.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    team4s_interfaces__msg__RangeReading * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->readings.data[i]);
      PyObject * pyitem = team4s_interfaces__msg__range_reading__convert_to_py(item);
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
      int rc = PyObject_SetAttrString(_pymessage, "readings", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_clear_known
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->left_clear_known ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_clear_known", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_clear
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->left_clear ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_clear", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_clear_known
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->right_clear_known ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_clear_known", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_clear
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->right_clear ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_clear", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

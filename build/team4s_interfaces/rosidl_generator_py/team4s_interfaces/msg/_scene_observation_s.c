// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from team4s_interfaces:msg/SceneObservation.idl
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
#include "team4s_interfaces/msg/detail/scene_observation__struct.h"
#include "team4s_interfaces/msg/detail/scene_observation__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

// Nested array functions includes
#include "team4s_interfaces/msg/detail/cone_detection__functions.h"
// end nested array functions include
bool team4s_interfaces__msg__source_header__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * team4s_interfaces__msg__source_header__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool builtin_interfaces__msg__time__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * builtin_interfaces__msg__time__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool builtin_interfaces__msg__time__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * builtin_interfaces__msg__time__convert_to_py(void * raw_ros_message);
bool team4s_interfaces__msg__cone_detection__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * team4s_interfaces__msg__cone_detection__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool builtin_interfaces__msg__time__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * builtin_interfaces__msg__time__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool team4s_interfaces__msg__scene_observation__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[58];
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
    assert(strncmp("team4s_interfaces.msg._scene_observation.SceneObservation", full_classname_dest, 57) == 0);
  }
  team4s_interfaces__msg__SceneObservation * ros_message = _ros_message;
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
  {  // cone_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "cone_valid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->cone_valid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // cone_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "cone_state");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->cone_state = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // cone_bbox_known
    PyObject * field = PyObject_GetAttrString(_pymsg, "cone_bbox_known");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->cone_bbox_known = (Py_True == field);
    Py_DECREF(field);
  }
  {  // cone_bbox_xyxy
    PyObject * field = PyObject_GetAttrString(_pymsg, "cone_bbox_xyxy");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_INT32);
      Py_ssize_t size = 4;
      int32_t * dest = ros_message->cone_bbox_xyxy;
      for (Py_ssize_t i = 0; i < size; ++i) {
        int32_t tmp = *(npy_int32 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(int32_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // zebra_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "zebra_valid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->zebra_valid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // zebra_visible
    PyObject * field = PyObject_GetAttrString(_pymsg, "zebra_visible");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->zebra_visible = (Py_True == field);
    Py_DECREF(field);
  }
  {  // zebra_bbox_known
    PyObject * field = PyObject_GetAttrString(_pymsg, "zebra_bbox_known");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->zebra_bbox_known = (Py_True == field);
    Py_DECREF(field);
  }
  {  // zebra_bbox_xyxy
    PyObject * field = PyObject_GetAttrString(_pymsg, "zebra_bbox_xyxy");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_INT32);
      Py_ssize_t size = 4;
      int32_t * dest = ros_message->zebra_bbox_xyxy;
      for (Py_ssize_t i = 0; i < size; ++i) {
        int32_t tmp = *(npy_int32 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(int32_t));
      }
      Py_DECREF(seq_field);
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
  {  // cone_event_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "cone_event_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->cone_event_id = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // cone_event_stamp
    PyObject * field = PyObject_GetAttrString(_pymsg, "cone_event_stamp");
    if (!field) {
      return false;
    }
    if (!builtin_interfaces__msg__time__convert_from_py(field, &ros_message->cone_event_stamp)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // zebra_event_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "zebra_event_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->zebra_event_id = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // zebra_event_stamp
    PyObject * field = PyObject_GetAttrString(_pymsg, "zebra_event_stamp");
    if (!field) {
      return false;
    }
    if (!builtin_interfaces__msg__time__convert_from_py(field, &ros_message->zebra_event_stamp)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // zebra_event_confirmed
    PyObject * field = PyObject_GetAttrString(_pymsg, "zebra_event_confirmed");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->zebra_event_confirmed = (Py_True == field);
    Py_DECREF(field);
  }
  {  // cones_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "cones_valid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->cones_valid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // cones_reason
    PyObject * field = PyObject_GetAttrString(_pymsg, "cones_reason");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->cones_reason, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // cones
    PyObject * field = PyObject_GetAttrString(_pymsg, "cones");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'cones'");
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
    if (!team4s_interfaces__msg__ConeDetection__Sequence__init(&(ros_message->cones), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create team4s_interfaces__msg__ConeDetection__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    team4s_interfaces__msg__ConeDetection * dest = ros_message->cones.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!team4s_interfaces__msg__cone_detection__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // green_start_visible
    PyObject * field = PyObject_GetAttrString(_pymsg, "green_start_visible");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->green_start_visible = (Py_True == field);
    Py_DECREF(field);
  }
  {  // red_finish_visible
    PyObject * field = PyObject_GetAttrString(_pymsg, "red_finish_visible");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->red_finish_visible = (Py_True == field);
    Py_DECREF(field);
  }
  {  // red_finish_confirmed
    PyObject * field = PyObject_GetAttrString(_pymsg, "red_finish_confirmed");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->red_finish_confirmed = (Py_True == field);
    Py_DECREF(field);
  }
  {  // red_finish_event_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "red_finish_event_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->red_finish_event_id = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // red_finish_event_stamp
    PyObject * field = PyObject_GetAttrString(_pymsg, "red_finish_event_stamp");
    if (!field) {
      return false;
    }
    if (!builtin_interfaces__msg__time__convert_from_py(field, &ros_message->red_finish_event_stamp)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * team4s_interfaces__msg__scene_observation__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SceneObservation */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("team4s_interfaces.msg._scene_observation");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SceneObservation");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  team4s_interfaces__msg__SceneObservation * ros_message = (team4s_interfaces__msg__SceneObservation *)raw_ros_message;
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
  {  // cone_valid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->cone_valid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cone_valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cone_state
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->cone_state);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cone_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cone_bbox_known
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->cone_bbox_known ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cone_bbox_known", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cone_bbox_xyxy
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "cone_bbox_xyxy");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_INT32);
    assert(sizeof(npy_int32) == sizeof(int32_t));
    npy_int32 * dst = (npy_int32 *)PyArray_GETPTR1(seq_field, 0);
    int32_t * src = &(ros_message->cone_bbox_xyxy[0]);
    memcpy(dst, src, 4 * sizeof(int32_t));
    Py_DECREF(field);
  }
  {  // zebra_valid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->zebra_valid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "zebra_valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // zebra_visible
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->zebra_visible ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "zebra_visible", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // zebra_bbox_known
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->zebra_bbox_known ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "zebra_bbox_known", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // zebra_bbox_xyxy
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "zebra_bbox_xyxy");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_INT32);
    assert(sizeof(npy_int32) == sizeof(int32_t));
    npy_int32 * dst = (npy_int32 *)PyArray_GETPTR1(seq_field, 0);
    int32_t * src = &(ros_message->zebra_bbox_xyxy[0]);
    memcpy(dst, src, 4 * sizeof(int32_t));
    Py_DECREF(field);
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
  {  // cone_event_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->cone_event_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cone_event_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cone_event_stamp
    PyObject * field = NULL;
    field = builtin_interfaces__msg__time__convert_to_py(&ros_message->cone_event_stamp);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "cone_event_stamp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // zebra_event_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->zebra_event_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "zebra_event_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // zebra_event_stamp
    PyObject * field = NULL;
    field = builtin_interfaces__msg__time__convert_to_py(&ros_message->zebra_event_stamp);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "zebra_event_stamp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // zebra_event_confirmed
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->zebra_event_confirmed ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "zebra_event_confirmed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cones_valid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->cones_valid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cones_valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cones_reason
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->cones_reason.data,
      strlen(ros_message->cones_reason.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "cones_reason", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cones
    PyObject * field = NULL;
    size_t size = ros_message->cones.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    team4s_interfaces__msg__ConeDetection * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->cones.data[i]);
      PyObject * pyitem = team4s_interfaces__msg__cone_detection__convert_to_py(item);
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
      int rc = PyObject_SetAttrString(_pymessage, "cones", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // green_start_visible
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->green_start_visible ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "green_start_visible", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // red_finish_visible
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->red_finish_visible ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "red_finish_visible", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // red_finish_confirmed
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->red_finish_confirmed ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "red_finish_confirmed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // red_finish_event_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->red_finish_event_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "red_finish_event_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // red_finish_event_stamp
    PyObject * field = NULL;
    field = builtin_interfaces__msg__time__convert_to_py(&ros_message->red_finish_event_stamp);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "red_finish_event_stamp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

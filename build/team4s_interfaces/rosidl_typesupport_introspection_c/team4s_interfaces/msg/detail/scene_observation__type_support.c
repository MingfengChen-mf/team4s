// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from team4s_interfaces:msg/SceneObservation.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "team4s_interfaces/msg/detail/scene_observation__rosidl_typesupport_introspection_c.h"
#include "team4s_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "team4s_interfaces/msg/detail/scene_observation__functions.h"
#include "team4s_interfaces/msg/detail/scene_observation__struct.h"


// Include directives for member types
// Member `meta`
#include "team4s_interfaces/msg/source_header.h"
// Member `meta`
#include "team4s_interfaces/msg/detail/source_header__rosidl_typesupport_introspection_c.h"
// Member `cone_event_stamp`
// Member `zebra_event_stamp`
// Member `red_finish_event_stamp`
#include "builtin_interfaces/msg/time.h"
// Member `cone_event_stamp`
// Member `zebra_event_stamp`
// Member `red_finish_event_stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"
// Member `cones_reason`
#include "rosidl_runtime_c/string_functions.h"
// Member `cones`
#include "team4s_interfaces/msg/cone_detection.h"
// Member `cones`
#include "team4s_interfaces/msg/detail/cone_detection__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__SceneObservation_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  team4s_interfaces__msg__SceneObservation__init(message_memory);
}

void team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__SceneObservation_fini_function(void * message_memory)
{
  team4s_interfaces__msg__SceneObservation__fini(message_memory);
}

size_t team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__size_function__SceneObservation__cone_bbox_xyxy(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__get_const_function__SceneObservation__cone_bbox_xyxy(
  const void * untyped_member, size_t index)
{
  const int32_t * member =
    (const int32_t *)(untyped_member);
  return &member[index];
}

void * team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__get_function__SceneObservation__cone_bbox_xyxy(
  void * untyped_member, size_t index)
{
  int32_t * member =
    (int32_t *)(untyped_member);
  return &member[index];
}

void team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__fetch_function__SceneObservation__cone_bbox_xyxy(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__get_const_function__SceneObservation__cone_bbox_xyxy(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__assign_function__SceneObservation__cone_bbox_xyxy(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__get_function__SceneObservation__cone_bbox_xyxy(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

size_t team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__size_function__SceneObservation__zebra_bbox_xyxy(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__get_const_function__SceneObservation__zebra_bbox_xyxy(
  const void * untyped_member, size_t index)
{
  const int32_t * member =
    (const int32_t *)(untyped_member);
  return &member[index];
}

void * team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__get_function__SceneObservation__zebra_bbox_xyxy(
  void * untyped_member, size_t index)
{
  int32_t * member =
    (int32_t *)(untyped_member);
  return &member[index];
}

void team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__fetch_function__SceneObservation__zebra_bbox_xyxy(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__get_const_function__SceneObservation__zebra_bbox_xyxy(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__assign_function__SceneObservation__zebra_bbox_xyxy(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__get_function__SceneObservation__zebra_bbox_xyxy(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

size_t team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__size_function__SceneObservation__cones(
  const void * untyped_member)
{
  const team4s_interfaces__msg__ConeDetection__Sequence * member =
    (const team4s_interfaces__msg__ConeDetection__Sequence *)(untyped_member);
  return member->size;
}

const void * team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__get_const_function__SceneObservation__cones(
  const void * untyped_member, size_t index)
{
  const team4s_interfaces__msg__ConeDetection__Sequence * member =
    (const team4s_interfaces__msg__ConeDetection__Sequence *)(untyped_member);
  return &member->data[index];
}

void * team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__get_function__SceneObservation__cones(
  void * untyped_member, size_t index)
{
  team4s_interfaces__msg__ConeDetection__Sequence * member =
    (team4s_interfaces__msg__ConeDetection__Sequence *)(untyped_member);
  return &member->data[index];
}

void team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__fetch_function__SceneObservation__cones(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const team4s_interfaces__msg__ConeDetection * item =
    ((const team4s_interfaces__msg__ConeDetection *)
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__get_const_function__SceneObservation__cones(untyped_member, index));
  team4s_interfaces__msg__ConeDetection * value =
    (team4s_interfaces__msg__ConeDetection *)(untyped_value);
  *value = *item;
}

void team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__assign_function__SceneObservation__cones(
  void * untyped_member, size_t index, const void * untyped_value)
{
  team4s_interfaces__msg__ConeDetection * item =
    ((team4s_interfaces__msg__ConeDetection *)
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__get_function__SceneObservation__cones(untyped_member, index));
  const team4s_interfaces__msg__ConeDetection * value =
    (const team4s_interfaces__msg__ConeDetection *)(untyped_value);
  *item = *value;
}

bool team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__resize_function__SceneObservation__cones(
  void * untyped_member, size_t size)
{
  team4s_interfaces__msg__ConeDetection__Sequence * member =
    (team4s_interfaces__msg__ConeDetection__Sequence *)(untyped_member);
  team4s_interfaces__msg__ConeDetection__Sequence__fini(member);
  return team4s_interfaces__msg__ConeDetection__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__SceneObservation_message_member_array[24] = {
  {
    "meta",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, meta),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cone_valid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, cone_valid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cone_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, cone_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cone_bbox_known",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, cone_bbox_known),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cone_bbox_xyxy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, cone_bbox_xyxy),  // bytes offset in struct
    NULL,  // default value
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__size_function__SceneObservation__cone_bbox_xyxy,  // size() function pointer
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__get_const_function__SceneObservation__cone_bbox_xyxy,  // get_const(index) function pointer
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__get_function__SceneObservation__cone_bbox_xyxy,  // get(index) function pointer
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__fetch_function__SceneObservation__cone_bbox_xyxy,  // fetch(index, &value) function pointer
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__assign_function__SceneObservation__cone_bbox_xyxy,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "zebra_valid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, zebra_valid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "zebra_visible",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, zebra_visible),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "zebra_bbox_known",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, zebra_bbox_known),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "zebra_bbox_xyxy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, zebra_bbox_xyxy),  // bytes offset in struct
    NULL,  // default value
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__size_function__SceneObservation__zebra_bbox_xyxy,  // size() function pointer
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__get_const_function__SceneObservation__zebra_bbox_xyxy,  // get_const(index) function pointer
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__get_function__SceneObservation__zebra_bbox_xyxy,  // get(index) function pointer
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__fetch_function__SceneObservation__zebra_bbox_xyxy,  // fetch(index, &value) function pointer
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__assign_function__SceneObservation__zebra_bbox_xyxy,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "image_width",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, image_width),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "image_height",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, image_height),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cone_event_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, cone_event_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cone_event_stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, cone_event_stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "zebra_event_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, zebra_event_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "zebra_event_stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, zebra_event_stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "zebra_event_confirmed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, zebra_event_confirmed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cones_valid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, cones_valid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cones_reason",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, cones_reason),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cones",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, cones),  // bytes offset in struct
    NULL,  // default value
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__size_function__SceneObservation__cones,  // size() function pointer
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__get_const_function__SceneObservation__cones,  // get_const(index) function pointer
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__get_function__SceneObservation__cones,  // get(index) function pointer
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__fetch_function__SceneObservation__cones,  // fetch(index, &value) function pointer
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__assign_function__SceneObservation__cones,  // assign(index, value) function pointer
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__resize_function__SceneObservation__cones  // resize(index) function pointer
  },
  {
    "green_start_visible",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, green_start_visible),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "red_finish_visible",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, red_finish_visible),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "red_finish_confirmed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, red_finish_confirmed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "red_finish_event_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, red_finish_event_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "red_finish_event_stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__SceneObservation, red_finish_event_stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__SceneObservation_message_members = {
  "team4s_interfaces__msg",  // message namespace
  "SceneObservation",  // message name
  24,  // number of fields
  sizeof(team4s_interfaces__msg__SceneObservation),
  team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__SceneObservation_message_member_array,  // message members
  team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__SceneObservation_init_function,  // function to initialize message memory (memory has to be allocated)
  team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__SceneObservation_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__SceneObservation_message_type_support_handle = {
  0,
  &team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__SceneObservation_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_team4s_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, team4s_interfaces, msg, SceneObservation)() {
  team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__SceneObservation_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, team4s_interfaces, msg, SourceHeader)();
  team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__SceneObservation_message_member_array[12].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__SceneObservation_message_member_array[14].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__SceneObservation_message_member_array[18].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, team4s_interfaces, msg, ConeDetection)();
  team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__SceneObservation_message_member_array[23].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__SceneObservation_message_type_support_handle.typesupport_identifier) {
    team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__SceneObservation_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &team4s_interfaces__msg__SceneObservation__rosidl_typesupport_introspection_c__SceneObservation_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

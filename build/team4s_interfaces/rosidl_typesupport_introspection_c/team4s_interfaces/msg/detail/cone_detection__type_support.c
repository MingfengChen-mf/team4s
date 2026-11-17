// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from team4s_interfaces:msg/ConeDetection.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "team4s_interfaces/msg/detail/cone_detection__rosidl_typesupport_introspection_c.h"
#include "team4s_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "team4s_interfaces/msg/detail/cone_detection__functions.h"
#include "team4s_interfaces/msg/detail/cone_detection__struct.h"


// Include directives for member types
// Member `candidate_id`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__ConeDetection_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  team4s_interfaces__msg__ConeDetection__init(message_memory);
}

void team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__ConeDetection_fini_function(void * message_memory)
{
  team4s_interfaces__msg__ConeDetection__fini(message_memory);
}

size_t team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__size_function__ConeDetection__bbox_xyxy(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__get_const_function__ConeDetection__bbox_xyxy(
  const void * untyped_member, size_t index)
{
  const int32_t * member =
    (const int32_t *)(untyped_member);
  return &member[index];
}

void * team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__get_function__ConeDetection__bbox_xyxy(
  void * untyped_member, size_t index)
{
  int32_t * member =
    (int32_t *)(untyped_member);
  return &member[index];
}

void team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__fetch_function__ConeDetection__bbox_xyxy(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__get_const_function__ConeDetection__bbox_xyxy(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__assign_function__ConeDetection__bbox_xyxy(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__get_function__ConeDetection__bbox_xyxy(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__ConeDetection_message_member_array[5] = {
  {
    "candidate_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__ConeDetection, candidate_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "color",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__ConeDetection, color),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bbox_known",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__ConeDetection, bbox_known),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bbox_xyxy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__ConeDetection, bbox_xyxy),  // bytes offset in struct
    NULL,  // default value
    team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__size_function__ConeDetection__bbox_xyxy,  // size() function pointer
    team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__get_const_function__ConeDetection__bbox_xyxy,  // get_const(index) function pointer
    team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__get_function__ConeDetection__bbox_xyxy,  // get(index) function pointer
    team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__fetch_function__ConeDetection__bbox_xyxy,  // fetch(index, &value) function pointer
    team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__assign_function__ConeDetection__bbox_xyxy,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "color_pixels",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__ConeDetection, color_pixels),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__ConeDetection_message_members = {
  "team4s_interfaces__msg",  // message namespace
  "ConeDetection",  // message name
  5,  // number of fields
  sizeof(team4s_interfaces__msg__ConeDetection),
  team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__ConeDetection_message_member_array,  // message members
  team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__ConeDetection_init_function,  // function to initialize message memory (memory has to be allocated)
  team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__ConeDetection_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__ConeDetection_message_type_support_handle = {
  0,
  &team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__ConeDetection_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_team4s_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, team4s_interfaces, msg, ConeDetection)() {
  if (!team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__ConeDetection_message_type_support_handle.typesupport_identifier) {
    team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__ConeDetection_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &team4s_interfaces__msg__ConeDetection__rosidl_typesupport_introspection_c__ConeDetection_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

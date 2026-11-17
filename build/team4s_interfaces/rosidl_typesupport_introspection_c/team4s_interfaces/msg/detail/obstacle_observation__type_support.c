// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from team4s_interfaces:msg/ObstacleObservation.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "team4s_interfaces/msg/detail/obstacle_observation__rosidl_typesupport_introspection_c.h"
#include "team4s_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "team4s_interfaces/msg/detail/obstacle_observation__functions.h"
#include "team4s_interfaces/msg/detail/obstacle_observation__struct.h"


// Include directives for member types
// Member `meta`
#include "team4s_interfaces/msg/source_header.h"
// Member `meta`
#include "team4s_interfaces/msg/detail/source_header__rosidl_typesupport_introspection_c.h"
// Member `readings`
#include "team4s_interfaces/msg/range_reading.h"
// Member `readings`
#include "team4s_interfaces/msg/detail/range_reading__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__ObstacleObservation_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  team4s_interfaces__msg__ObstacleObservation__init(message_memory);
}

void team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__ObstacleObservation_fini_function(void * message_memory)
{
  team4s_interfaces__msg__ObstacleObservation__fini(message_memory);
}

size_t team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__size_function__ObstacleObservation__readings(
  const void * untyped_member)
{
  const team4s_interfaces__msg__RangeReading__Sequence * member =
    (const team4s_interfaces__msg__RangeReading__Sequence *)(untyped_member);
  return member->size;
}

const void * team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__get_const_function__ObstacleObservation__readings(
  const void * untyped_member, size_t index)
{
  const team4s_interfaces__msg__RangeReading__Sequence * member =
    (const team4s_interfaces__msg__RangeReading__Sequence *)(untyped_member);
  return &member->data[index];
}

void * team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__get_function__ObstacleObservation__readings(
  void * untyped_member, size_t index)
{
  team4s_interfaces__msg__RangeReading__Sequence * member =
    (team4s_interfaces__msg__RangeReading__Sequence *)(untyped_member);
  return &member->data[index];
}

void team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__fetch_function__ObstacleObservation__readings(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const team4s_interfaces__msg__RangeReading * item =
    ((const team4s_interfaces__msg__RangeReading *)
    team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__get_const_function__ObstacleObservation__readings(untyped_member, index));
  team4s_interfaces__msg__RangeReading * value =
    (team4s_interfaces__msg__RangeReading *)(untyped_value);
  *value = *item;
}

void team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__assign_function__ObstacleObservation__readings(
  void * untyped_member, size_t index, const void * untyped_value)
{
  team4s_interfaces__msg__RangeReading * item =
    ((team4s_interfaces__msg__RangeReading *)
    team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__get_function__ObstacleObservation__readings(untyped_member, index));
  const team4s_interfaces__msg__RangeReading * value =
    (const team4s_interfaces__msg__RangeReading *)(untyped_value);
  *item = *value;
}

bool team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__resize_function__ObstacleObservation__readings(
  void * untyped_member, size_t size)
{
  team4s_interfaces__msg__RangeReading__Sequence * member =
    (team4s_interfaces__msg__RangeReading__Sequence *)(untyped_member);
  team4s_interfaces__msg__RangeReading__Sequence__fini(member);
  return team4s_interfaces__msg__RangeReading__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__ObstacleObservation_message_member_array[6] = {
  {
    "meta",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__ObstacleObservation, meta),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "readings",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__ObstacleObservation, readings),  // bytes offset in struct
    NULL,  // default value
    team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__size_function__ObstacleObservation__readings,  // size() function pointer
    team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__get_const_function__ObstacleObservation__readings,  // get_const(index) function pointer
    team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__get_function__ObstacleObservation__readings,  // get(index) function pointer
    team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__fetch_function__ObstacleObservation__readings,  // fetch(index, &value) function pointer
    team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__assign_function__ObstacleObservation__readings,  // assign(index, value) function pointer
    team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__resize_function__ObstacleObservation__readings  // resize(index) function pointer
  },
  {
    "left_clear_known",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__ObstacleObservation, left_clear_known),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "left_clear",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__ObstacleObservation, left_clear),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "right_clear_known",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__ObstacleObservation, right_clear_known),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "right_clear",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__ObstacleObservation, right_clear),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__ObstacleObservation_message_members = {
  "team4s_interfaces__msg",  // message namespace
  "ObstacleObservation",  // message name
  6,  // number of fields
  sizeof(team4s_interfaces__msg__ObstacleObservation),
  team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__ObstacleObservation_message_member_array,  // message members
  team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__ObstacleObservation_init_function,  // function to initialize message memory (memory has to be allocated)
  team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__ObstacleObservation_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__ObstacleObservation_message_type_support_handle = {
  0,
  &team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__ObstacleObservation_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_team4s_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, team4s_interfaces, msg, ObstacleObservation)() {
  team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__ObstacleObservation_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, team4s_interfaces, msg, SourceHeader)();
  team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__ObstacleObservation_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, team4s_interfaces, msg, RangeReading)();
  if (!team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__ObstacleObservation_message_type_support_handle.typesupport_identifier) {
    team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__ObstacleObservation_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &team4s_interfaces__msg__ObstacleObservation__rosidl_typesupport_introspection_c__ObstacleObservation_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

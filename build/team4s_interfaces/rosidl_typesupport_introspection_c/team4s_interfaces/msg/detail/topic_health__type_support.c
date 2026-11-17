// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from team4s_interfaces:msg/TopicHealth.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "team4s_interfaces/msg/detail/topic_health__rosidl_typesupport_introspection_c.h"
#include "team4s_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "team4s_interfaces/msg/detail/topic_health__functions.h"
#include "team4s_interfaces/msg/detail/topic_health__struct.h"


// Include directives for member types
// Member `reason`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void team4s_interfaces__msg__TopicHealth__rosidl_typesupport_introspection_c__TopicHealth_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  team4s_interfaces__msg__TopicHealth__init(message_memory);
}

void team4s_interfaces__msg__TopicHealth__rosidl_typesupport_introspection_c__TopicHealth_fini_function(void * message_memory)
{
  team4s_interfaces__msg__TopicHealth__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember team4s_interfaces__msg__TopicHealth__rosidl_typesupport_introspection_c__TopicHealth_message_member_array[5] = {
  {
    "state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__TopicHealth, state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "reason",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__TopicHealth, reason),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "age_known",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__TopicHealth, age_known),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "age_s",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__TopicHealth, age_s),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "max_age_s",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__TopicHealth, max_age_s),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers team4s_interfaces__msg__TopicHealth__rosidl_typesupport_introspection_c__TopicHealth_message_members = {
  "team4s_interfaces__msg",  // message namespace
  "TopicHealth",  // message name
  5,  // number of fields
  sizeof(team4s_interfaces__msg__TopicHealth),
  team4s_interfaces__msg__TopicHealth__rosidl_typesupport_introspection_c__TopicHealth_message_member_array,  // message members
  team4s_interfaces__msg__TopicHealth__rosidl_typesupport_introspection_c__TopicHealth_init_function,  // function to initialize message memory (memory has to be allocated)
  team4s_interfaces__msg__TopicHealth__rosidl_typesupport_introspection_c__TopicHealth_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t team4s_interfaces__msg__TopicHealth__rosidl_typesupport_introspection_c__TopicHealth_message_type_support_handle = {
  0,
  &team4s_interfaces__msg__TopicHealth__rosidl_typesupport_introspection_c__TopicHealth_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_team4s_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, team4s_interfaces, msg, TopicHealth)() {
  if (!team4s_interfaces__msg__TopicHealth__rosidl_typesupport_introspection_c__TopicHealth_message_type_support_handle.typesupport_identifier) {
    team4s_interfaces__msg__TopicHealth__rosidl_typesupport_introspection_c__TopicHealth_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &team4s_interfaces__msg__TopicHealth__rosidl_typesupport_introspection_c__TopicHealth_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

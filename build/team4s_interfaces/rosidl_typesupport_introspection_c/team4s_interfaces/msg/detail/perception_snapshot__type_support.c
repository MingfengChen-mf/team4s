// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from team4s_interfaces:msg/PerceptionSnapshot.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "team4s_interfaces/msg/detail/perception_snapshot__rosidl_typesupport_introspection_c.h"
#include "team4s_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "team4s_interfaces/msg/detail/perception_snapshot__functions.h"
#include "team4s_interfaces/msg/detail/perception_snapshot__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `aggregator_session_id`
// Member `run_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `lane`
#include "team4s_interfaces/msg/lane_observation.h"
// Member `lane`
#include "team4s_interfaces/msg/detail/lane_observation__rosidl_typesupport_introspection_c.h"
// Member `lane_health`
// Member `obstacles_health`
// Member `scene_health`
#include "team4s_interfaces/msg/topic_health.h"
// Member `lane_health`
// Member `obstacles_health`
// Member `scene_health`
#include "team4s_interfaces/msg/detail/topic_health__rosidl_typesupport_introspection_c.h"
// Member `obstacles`
#include "team4s_interfaces/msg/obstacle_observation.h"
// Member `obstacles`
#include "team4s_interfaces/msg/detail/obstacle_observation__rosidl_typesupport_introspection_c.h"
// Member `scene`
#include "team4s_interfaces/msg/scene_observation.h"
// Member `scene`
#include "team4s_interfaces/msg/detail/scene_observation__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void team4s_interfaces__msg__PerceptionSnapshot__rosidl_typesupport_introspection_c__PerceptionSnapshot_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  team4s_interfaces__msg__PerceptionSnapshot__init(message_memory);
}

void team4s_interfaces__msg__PerceptionSnapshot__rosidl_typesupport_introspection_c__PerceptionSnapshot_fini_function(void * message_memory)
{
  team4s_interfaces__msg__PerceptionSnapshot__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember team4s_interfaces__msg__PerceptionSnapshot__rosidl_typesupport_introspection_c__PerceptionSnapshot_message_member_array[10] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__PerceptionSnapshot, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "aggregator_session_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__PerceptionSnapshot, aggregator_session_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "run_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__PerceptionSnapshot, run_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sequence",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__PerceptionSnapshot, sequence),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "lane",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__PerceptionSnapshot, lane),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "lane_health",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__PerceptionSnapshot, lane_health),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "obstacles",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__PerceptionSnapshot, obstacles),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "obstacles_health",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__PerceptionSnapshot, obstacles_health),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "scene",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__PerceptionSnapshot, scene),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "scene_health",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__PerceptionSnapshot, scene_health),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers team4s_interfaces__msg__PerceptionSnapshot__rosidl_typesupport_introspection_c__PerceptionSnapshot_message_members = {
  "team4s_interfaces__msg",  // message namespace
  "PerceptionSnapshot",  // message name
  10,  // number of fields
  sizeof(team4s_interfaces__msg__PerceptionSnapshot),
  team4s_interfaces__msg__PerceptionSnapshot__rosidl_typesupport_introspection_c__PerceptionSnapshot_message_member_array,  // message members
  team4s_interfaces__msg__PerceptionSnapshot__rosidl_typesupport_introspection_c__PerceptionSnapshot_init_function,  // function to initialize message memory (memory has to be allocated)
  team4s_interfaces__msg__PerceptionSnapshot__rosidl_typesupport_introspection_c__PerceptionSnapshot_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t team4s_interfaces__msg__PerceptionSnapshot__rosidl_typesupport_introspection_c__PerceptionSnapshot_message_type_support_handle = {
  0,
  &team4s_interfaces__msg__PerceptionSnapshot__rosidl_typesupport_introspection_c__PerceptionSnapshot_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_team4s_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, team4s_interfaces, msg, PerceptionSnapshot)() {
  team4s_interfaces__msg__PerceptionSnapshot__rosidl_typesupport_introspection_c__PerceptionSnapshot_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  team4s_interfaces__msg__PerceptionSnapshot__rosidl_typesupport_introspection_c__PerceptionSnapshot_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, team4s_interfaces, msg, LaneObservation)();
  team4s_interfaces__msg__PerceptionSnapshot__rosidl_typesupport_introspection_c__PerceptionSnapshot_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, team4s_interfaces, msg, TopicHealth)();
  team4s_interfaces__msg__PerceptionSnapshot__rosidl_typesupport_introspection_c__PerceptionSnapshot_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, team4s_interfaces, msg, ObstacleObservation)();
  team4s_interfaces__msg__PerceptionSnapshot__rosidl_typesupport_introspection_c__PerceptionSnapshot_message_member_array[7].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, team4s_interfaces, msg, TopicHealth)();
  team4s_interfaces__msg__PerceptionSnapshot__rosidl_typesupport_introspection_c__PerceptionSnapshot_message_member_array[8].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, team4s_interfaces, msg, SceneObservation)();
  team4s_interfaces__msg__PerceptionSnapshot__rosidl_typesupport_introspection_c__PerceptionSnapshot_message_member_array[9].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, team4s_interfaces, msg, TopicHealth)();
  if (!team4s_interfaces__msg__PerceptionSnapshot__rosidl_typesupport_introspection_c__PerceptionSnapshot_message_type_support_handle.typesupport_identifier) {
    team4s_interfaces__msg__PerceptionSnapshot__rosidl_typesupport_introspection_c__PerceptionSnapshot_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &team4s_interfaces__msg__PerceptionSnapshot__rosidl_typesupport_introspection_c__PerceptionSnapshot_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

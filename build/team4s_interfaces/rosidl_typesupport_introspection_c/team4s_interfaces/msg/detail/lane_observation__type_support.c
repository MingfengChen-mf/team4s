// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from team4s_interfaces:msg/LaneObservation.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "team4s_interfaces/msg/detail/lane_observation__rosidl_typesupport_introspection_c.h"
#include "team4s_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "team4s_interfaces/msg/detail/lane_observation__functions.h"
#include "team4s_interfaces/msg/detail/lane_observation__struct.h"


// Include directives for member types
// Member `meta`
#include "team4s_interfaces/msg/source_header.h"
// Member `meta`
#include "team4s_interfaces/msg/detail/source_header__rosidl_typesupport_introspection_c.h"
// Member `candidates`
#include "team4s_interfaces/msg/lane_candidate.h"
// Member `candidates`
#include "team4s_interfaces/msg/detail/lane_candidate__rosidl_typesupport_introspection_c.h"
// Member `selected_candidate_id`
// Member `metric_reason`
// Member `calibration_id`
// Member `metric_frame_id`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__LaneObservation_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  team4s_interfaces__msg__LaneObservation__init(message_memory);
}

void team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__LaneObservation_fini_function(void * message_memory)
{
  team4s_interfaces__msg__LaneObservation__fini(message_memory);
}

size_t team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__size_function__LaneObservation__candidates(
  const void * untyped_member)
{
  const team4s_interfaces__msg__LaneCandidate__Sequence * member =
    (const team4s_interfaces__msg__LaneCandidate__Sequence *)(untyped_member);
  return member->size;
}

const void * team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__get_const_function__LaneObservation__candidates(
  const void * untyped_member, size_t index)
{
  const team4s_interfaces__msg__LaneCandidate__Sequence * member =
    (const team4s_interfaces__msg__LaneCandidate__Sequence *)(untyped_member);
  return &member->data[index];
}

void * team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__get_function__LaneObservation__candidates(
  void * untyped_member, size_t index)
{
  team4s_interfaces__msg__LaneCandidate__Sequence * member =
    (team4s_interfaces__msg__LaneCandidate__Sequence *)(untyped_member);
  return &member->data[index];
}

void team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__fetch_function__LaneObservation__candidates(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const team4s_interfaces__msg__LaneCandidate * item =
    ((const team4s_interfaces__msg__LaneCandidate *)
    team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__get_const_function__LaneObservation__candidates(untyped_member, index));
  team4s_interfaces__msg__LaneCandidate * value =
    (team4s_interfaces__msg__LaneCandidate *)(untyped_value);
  *value = *item;
}

void team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__assign_function__LaneObservation__candidates(
  void * untyped_member, size_t index, const void * untyped_value)
{
  team4s_interfaces__msg__LaneCandidate * item =
    ((team4s_interfaces__msg__LaneCandidate *)
    team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__get_function__LaneObservation__candidates(untyped_member, index));
  const team4s_interfaces__msg__LaneCandidate * value =
    (const team4s_interfaces__msg__LaneCandidate *)(untyped_value);
  *item = *value;
}

bool team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__resize_function__LaneObservation__candidates(
  void * untyped_member, size_t size)
{
  team4s_interfaces__msg__LaneCandidate__Sequence * member =
    (team4s_interfaces__msg__LaneCandidate__Sequence *)(untyped_member);
  team4s_interfaces__msg__LaneCandidate__Sequence__fini(member);
  return team4s_interfaces__msg__LaneCandidate__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__LaneObservation_message_member_array[12] = {
  {
    "meta",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__LaneObservation, meta),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
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
    offsetof(team4s_interfaces__msg__LaneObservation, image_width),  // bytes offset in struct
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
    offsetof(team4s_interfaces__msg__LaneObservation, image_height),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "candidates",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__LaneObservation, candidates),  // bytes offset in struct
    NULL,  // default value
    team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__size_function__LaneObservation__candidates,  // size() function pointer
    team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__get_const_function__LaneObservation__candidates,  // get_const(index) function pointer
    team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__get_function__LaneObservation__candidates,  // get(index) function pointer
    team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__fetch_function__LaneObservation__candidates,  // fetch(index, &value) function pointer
    team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__assign_function__LaneObservation__candidates,  // assign(index, value) function pointer
    team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__resize_function__LaneObservation__candidates  // resize(index) function pointer
  },
  {
    "selected_candidate_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__LaneObservation, selected_candidate_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "offset_m_valid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__LaneObservation, offset_m_valid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "offset_m",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__LaneObservation, offset_m),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "metric_reason",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__LaneObservation, metric_reason),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "calibration_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__LaneObservation, calibration_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "metric_frame_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__LaneObservation, metric_frame_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "metric_reference_x_m",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__LaneObservation, metric_reference_x_m),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "metric_reference_y_m",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces__msg__LaneObservation, metric_reference_y_m),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__LaneObservation_message_members = {
  "team4s_interfaces__msg",  // message namespace
  "LaneObservation",  // message name
  12,  // number of fields
  sizeof(team4s_interfaces__msg__LaneObservation),
  team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__LaneObservation_message_member_array,  // message members
  team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__LaneObservation_init_function,  // function to initialize message memory (memory has to be allocated)
  team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__LaneObservation_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__LaneObservation_message_type_support_handle = {
  0,
  &team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__LaneObservation_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_team4s_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, team4s_interfaces, msg, LaneObservation)() {
  team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__LaneObservation_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, team4s_interfaces, msg, SourceHeader)();
  team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__LaneObservation_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, team4s_interfaces, msg, LaneCandidate)();
  if (!team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__LaneObservation_message_type_support_handle.typesupport_identifier) {
    team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__LaneObservation_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &team4s_interfaces__msg__LaneObservation__rosidl_typesupport_introspection_c__LaneObservation_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

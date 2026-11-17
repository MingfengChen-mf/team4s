// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from team4s_interfaces:msg/PerceptionSnapshot.idl
// generated code does not contain a copyright notice
#include "team4s_interfaces/msg/detail/perception_snapshot__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "team4s_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "team4s_interfaces/msg/detail/perception_snapshot__struct.h"
#include "team4s_interfaces/msg/detail/perception_snapshot__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // aggregator_session_id, run_id
#include "rosidl_runtime_c/string_functions.h"  // aggregator_session_id, run_id
#include "std_msgs/msg/detail/header__functions.h"  // header
#include "team4s_interfaces/msg/detail/lane_observation__functions.h"  // lane
#include "team4s_interfaces/msg/detail/obstacle_observation__functions.h"  // obstacles
#include "team4s_interfaces/msg/detail/scene_observation__functions.h"  // scene
#include "team4s_interfaces/msg/detail/topic_health__functions.h"  // lane_health, obstacles_health, scene_health

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_team4s_interfaces
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_team4s_interfaces
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_team4s_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();
size_t get_serialized_size_team4s_interfaces__msg__LaneObservation(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_team4s_interfaces__msg__LaneObservation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, LaneObservation)();
size_t get_serialized_size_team4s_interfaces__msg__ObstacleObservation(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_team4s_interfaces__msg__ObstacleObservation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, ObstacleObservation)();
size_t get_serialized_size_team4s_interfaces__msg__SceneObservation(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_team4s_interfaces__msg__SceneObservation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, SceneObservation)();
size_t get_serialized_size_team4s_interfaces__msg__TopicHealth(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_team4s_interfaces__msg__TopicHealth(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, TopicHealth)();


using _PerceptionSnapshot__ros_msg_type = team4s_interfaces__msg__PerceptionSnapshot;

static bool _PerceptionSnapshot__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PerceptionSnapshot__ros_msg_type * ros_message = static_cast<const _PerceptionSnapshot__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: aggregator_session_id
  {
    const rosidl_runtime_c__String * str = &ros_message->aggregator_session_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: run_id
  {
    const rosidl_runtime_c__String * str = &ros_message->run_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: sequence
  {
    cdr << ros_message->sequence;
  }

  // Field name: lane
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, LaneObservation
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->lane, cdr))
    {
      return false;
    }
  }

  // Field name: lane_health
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, TopicHealth
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->lane_health, cdr))
    {
      return false;
    }
  }

  // Field name: obstacles
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, ObstacleObservation
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->obstacles, cdr))
    {
      return false;
    }
  }

  // Field name: obstacles_health
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, TopicHealth
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->obstacles_health, cdr))
    {
      return false;
    }
  }

  // Field name: scene
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, SceneObservation
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->scene, cdr))
    {
      return false;
    }
  }

  // Field name: scene_health
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, TopicHealth
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->scene_health, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _PerceptionSnapshot__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PerceptionSnapshot__ros_msg_type * ros_message = static_cast<_PerceptionSnapshot__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: aggregator_session_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->aggregator_session_id.data) {
      rosidl_runtime_c__String__init(&ros_message->aggregator_session_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->aggregator_session_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'aggregator_session_id'\n");
      return false;
    }
  }

  // Field name: run_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->run_id.data) {
      rosidl_runtime_c__String__init(&ros_message->run_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->run_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'run_id'\n");
      return false;
    }
  }

  // Field name: sequence
  {
    cdr >> ros_message->sequence;
  }

  // Field name: lane
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, LaneObservation
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->lane))
    {
      return false;
    }
  }

  // Field name: lane_health
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, TopicHealth
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->lane_health))
    {
      return false;
    }
  }

  // Field name: obstacles
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, ObstacleObservation
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->obstacles))
    {
      return false;
    }
  }

  // Field name: obstacles_health
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, TopicHealth
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->obstacles_health))
    {
      return false;
    }
  }

  // Field name: scene
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, SceneObservation
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->scene))
    {
      return false;
    }
  }

  // Field name: scene_health
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, TopicHealth
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->scene_health))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_team4s_interfaces
size_t get_serialized_size_team4s_interfaces__msg__PerceptionSnapshot(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PerceptionSnapshot__ros_msg_type * ros_message = static_cast<const _PerceptionSnapshot__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name aggregator_session_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->aggregator_session_id.size + 1);
  // field.name run_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->run_id.size + 1);
  // field.name sequence
  {
    size_t item_size = sizeof(ros_message->sequence);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name lane

  current_alignment += get_serialized_size_team4s_interfaces__msg__LaneObservation(
    &(ros_message->lane), current_alignment);
  // field.name lane_health

  current_alignment += get_serialized_size_team4s_interfaces__msg__TopicHealth(
    &(ros_message->lane_health), current_alignment);
  // field.name obstacles

  current_alignment += get_serialized_size_team4s_interfaces__msg__ObstacleObservation(
    &(ros_message->obstacles), current_alignment);
  // field.name obstacles_health

  current_alignment += get_serialized_size_team4s_interfaces__msg__TopicHealth(
    &(ros_message->obstacles_health), current_alignment);
  // field.name scene

  current_alignment += get_serialized_size_team4s_interfaces__msg__SceneObservation(
    &(ros_message->scene), current_alignment);
  // field.name scene_health

  current_alignment += get_serialized_size_team4s_interfaces__msg__TopicHealth(
    &(ros_message->scene_health), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _PerceptionSnapshot__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_team4s_interfaces__msg__PerceptionSnapshot(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_team4s_interfaces
size_t max_serialized_size_team4s_interfaces__msg__PerceptionSnapshot(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: aggregator_session_id
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: run_id
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: sequence
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: lane
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_team4s_interfaces__msg__LaneObservation(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: lane_health
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_team4s_interfaces__msg__TopicHealth(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: obstacles
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_team4s_interfaces__msg__ObstacleObservation(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: obstacles_health
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_team4s_interfaces__msg__TopicHealth(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: scene
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_team4s_interfaces__msg__SceneObservation(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: scene_health
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_team4s_interfaces__msg__TopicHealth(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = team4s_interfaces__msg__PerceptionSnapshot;
    is_plain =
      (
      offsetof(DataType, scene_health) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _PerceptionSnapshot__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_team4s_interfaces__msg__PerceptionSnapshot(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PerceptionSnapshot = {
  "team4s_interfaces::msg",
  "PerceptionSnapshot",
  _PerceptionSnapshot__cdr_serialize,
  _PerceptionSnapshot__cdr_deserialize,
  _PerceptionSnapshot__get_serialized_size,
  _PerceptionSnapshot__max_serialized_size
};

static rosidl_message_type_support_t _PerceptionSnapshot__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PerceptionSnapshot,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, PerceptionSnapshot)() {
  return &_PerceptionSnapshot__type_support;
}

#if defined(__cplusplus)
}
#endif

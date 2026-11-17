// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from team4s_interfaces:msg/PerceptionSnapshot.idl
// generated code does not contain a copyright notice
#include "team4s_interfaces/msg/detail/perception_snapshot__rosidl_typesupport_fastrtps_cpp.hpp"
#include "team4s_interfaces/msg/detail/perception_snapshot__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs

namespace team4s_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const team4s_interfaces::msg::LaneObservation &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  team4s_interfaces::msg::LaneObservation &);
size_t get_serialized_size(
  const team4s_interfaces::msg::LaneObservation &,
  size_t current_alignment);
size_t
max_serialized_size_LaneObservation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace team4s_interfaces

namespace team4s_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const team4s_interfaces::msg::TopicHealth &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  team4s_interfaces::msg::TopicHealth &);
size_t get_serialized_size(
  const team4s_interfaces::msg::TopicHealth &,
  size_t current_alignment);
size_t
max_serialized_size_TopicHealth(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace team4s_interfaces

namespace team4s_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const team4s_interfaces::msg::ObstacleObservation &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  team4s_interfaces::msg::ObstacleObservation &);
size_t get_serialized_size(
  const team4s_interfaces::msg::ObstacleObservation &,
  size_t current_alignment);
size_t
max_serialized_size_ObstacleObservation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace team4s_interfaces

// functions for team4s_interfaces::msg::TopicHealth already declared above

namespace team4s_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const team4s_interfaces::msg::SceneObservation &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  team4s_interfaces::msg::SceneObservation &);
size_t get_serialized_size(
  const team4s_interfaces::msg::SceneObservation &,
  size_t current_alignment);
size_t
max_serialized_size_SceneObservation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace team4s_interfaces

// functions for team4s_interfaces::msg::TopicHealth already declared above


namespace team4s_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
cdr_serialize(
  const team4s_interfaces::msg::PerceptionSnapshot & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: aggregator_session_id
  cdr << ros_message.aggregator_session_id;
  // Member: run_id
  cdr << ros_message.run_id;
  // Member: sequence
  cdr << ros_message.sequence;
  // Member: lane
  team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.lane,
    cdr);
  // Member: lane_health
  team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.lane_health,
    cdr);
  // Member: obstacles
  team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.obstacles,
    cdr);
  // Member: obstacles_health
  team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.obstacles_health,
    cdr);
  // Member: scene
  team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.scene,
    cdr);
  // Member: scene_health
  team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.scene_health,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  team4s_interfaces::msg::PerceptionSnapshot & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: aggregator_session_id
  cdr >> ros_message.aggregator_session_id;

  // Member: run_id
  cdr >> ros_message.run_id;

  // Member: sequence
  cdr >> ros_message.sequence;

  // Member: lane
  team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.lane);

  // Member: lane_health
  team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.lane_health);

  // Member: obstacles
  team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.obstacles);

  // Member: obstacles_health
  team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.obstacles_health);

  // Member: scene
  team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.scene);

  // Member: scene_health
  team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.scene_health);

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
get_serialized_size(
  const team4s_interfaces::msg::PerceptionSnapshot & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: aggregator_session_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.aggregator_session_id.size() + 1);
  // Member: run_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.run_id.size() + 1);
  // Member: sequence
  {
    size_t item_size = sizeof(ros_message.sequence);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: lane

  current_alignment +=
    team4s_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.lane, current_alignment);
  // Member: lane_health

  current_alignment +=
    team4s_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.lane_health, current_alignment);
  // Member: obstacles

  current_alignment +=
    team4s_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.obstacles, current_alignment);
  // Member: obstacles_health

  current_alignment +=
    team4s_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.obstacles_health, current_alignment);
  // Member: scene

  current_alignment +=
    team4s_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.scene, current_alignment);
  // Member: scene_health

  current_alignment +=
    team4s_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.scene_health, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
max_serialized_size_PerceptionSnapshot(
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


  // Member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: aggregator_session_id
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

  // Member: run_id
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

  // Member: sequence
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: lane
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        team4s_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_LaneObservation(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: lane_health
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        team4s_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_TopicHealth(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: obstacles
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        team4s_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_ObstacleObservation(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: obstacles_health
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        team4s_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_TopicHealth(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: scene
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        team4s_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_SceneObservation(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: scene_health
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        team4s_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_TopicHealth(
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
    using DataType = team4s_interfaces::msg::PerceptionSnapshot;
    is_plain =
      (
      offsetof(DataType, scene_health) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _PerceptionSnapshot__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const team4s_interfaces::msg::PerceptionSnapshot *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _PerceptionSnapshot__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<team4s_interfaces::msg::PerceptionSnapshot *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _PerceptionSnapshot__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const team4s_interfaces::msg::PerceptionSnapshot *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _PerceptionSnapshot__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_PerceptionSnapshot(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _PerceptionSnapshot__callbacks = {
  "team4s_interfaces::msg",
  "PerceptionSnapshot",
  _PerceptionSnapshot__cdr_serialize,
  _PerceptionSnapshot__cdr_deserialize,
  _PerceptionSnapshot__get_serialized_size,
  _PerceptionSnapshot__max_serialized_size
};

static rosidl_message_type_support_t _PerceptionSnapshot__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PerceptionSnapshot__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace team4s_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_team4s_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<team4s_interfaces::msg::PerceptionSnapshot>()
{
  return &team4s_interfaces::msg::typesupport_fastrtps_cpp::_PerceptionSnapshot__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, team4s_interfaces, msg, PerceptionSnapshot)() {
  return &team4s_interfaces::msg::typesupport_fastrtps_cpp::_PerceptionSnapshot__handle;
}

#ifdef __cplusplus
}
#endif

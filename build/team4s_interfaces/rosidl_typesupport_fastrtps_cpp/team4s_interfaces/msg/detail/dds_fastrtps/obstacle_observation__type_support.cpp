// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from team4s_interfaces:msg/ObstacleObservation.idl
// generated code does not contain a copyright notice
#include "team4s_interfaces/msg/detail/obstacle_observation__rosidl_typesupport_fastrtps_cpp.hpp"
#include "team4s_interfaces/msg/detail/obstacle_observation__struct.hpp"

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
namespace team4s_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const team4s_interfaces::msg::SourceHeader &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  team4s_interfaces::msg::SourceHeader &);
size_t get_serialized_size(
  const team4s_interfaces::msg::SourceHeader &,
  size_t current_alignment);
size_t
max_serialized_size_SourceHeader(
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
  const team4s_interfaces::msg::RangeReading &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  team4s_interfaces::msg::RangeReading &);
size_t get_serialized_size(
  const team4s_interfaces::msg::RangeReading &,
  size_t current_alignment);
size_t
max_serialized_size_RangeReading(
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

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
cdr_serialize(
  const team4s_interfaces::msg::ObstacleObservation & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: meta
  team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.meta,
    cdr);
  // Member: readings
  {
    size_t size = ros_message.readings.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.readings[i],
        cdr);
    }
  }
  // Member: left_clear_known
  cdr << (ros_message.left_clear_known ? true : false);
  // Member: left_clear
  cdr << (ros_message.left_clear ? true : false);
  // Member: right_clear_known
  cdr << (ros_message.right_clear_known ? true : false);
  // Member: right_clear
  cdr << (ros_message.right_clear ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  team4s_interfaces::msg::ObstacleObservation & ros_message)
{
  // Member: meta
  team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.meta);

  // Member: readings
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.getState();
    bool correct_size = cdr.jump(size);
    cdr.setState(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    ros_message.readings.resize(size);
    for (size_t i = 0; i < size; i++) {
      team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.readings[i]);
    }
  }

  // Member: left_clear_known
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.left_clear_known = tmp ? true : false;
  }

  // Member: left_clear
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.left_clear = tmp ? true : false;
  }

  // Member: right_clear_known
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.right_clear_known = tmp ? true : false;
  }

  // Member: right_clear
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.right_clear = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
get_serialized_size(
  const team4s_interfaces::msg::ObstacleObservation & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: meta

  current_alignment +=
    team4s_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.meta, current_alignment);
  // Member: readings
  {
    size_t array_size = ros_message.readings.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        team4s_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.readings[index], current_alignment);
    }
  }
  // Member: left_clear_known
  {
    size_t item_size = sizeof(ros_message.left_clear_known);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left_clear
  {
    size_t item_size = sizeof(ros_message.left_clear);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_clear_known
  {
    size_t item_size = sizeof(ros_message.right_clear_known);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_clear
  {
    size_t item_size = sizeof(ros_message.right_clear);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
max_serialized_size_ObstacleObservation(
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


  // Member: meta
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        team4s_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_SourceHeader(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: readings
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        team4s_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_RangeReading(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: left_clear_known
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: left_clear
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: right_clear_known
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: right_clear
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = team4s_interfaces::msg::ObstacleObservation;
    is_plain =
      (
      offsetof(DataType, right_clear) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ObstacleObservation__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const team4s_interfaces::msg::ObstacleObservation *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ObstacleObservation__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<team4s_interfaces::msg::ObstacleObservation *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ObstacleObservation__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const team4s_interfaces::msg::ObstacleObservation *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ObstacleObservation__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ObstacleObservation(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ObstacleObservation__callbacks = {
  "team4s_interfaces::msg",
  "ObstacleObservation",
  _ObstacleObservation__cdr_serialize,
  _ObstacleObservation__cdr_deserialize,
  _ObstacleObservation__get_serialized_size,
  _ObstacleObservation__max_serialized_size
};

static rosidl_message_type_support_t _ObstacleObservation__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ObstacleObservation__callbacks,
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
get_message_type_support_handle<team4s_interfaces::msg::ObstacleObservation>()
{
  return &team4s_interfaces::msg::typesupport_fastrtps_cpp::_ObstacleObservation__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, team4s_interfaces, msg, ObstacleObservation)() {
  return &team4s_interfaces::msg::typesupport_fastrtps_cpp::_ObstacleObservation__handle;
}

#ifdef __cplusplus
}
#endif

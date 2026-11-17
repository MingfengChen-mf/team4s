// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from team4s_interfaces:msg/LaneCandidate.idl
// generated code does not contain a copyright notice
#include "team4s_interfaces/msg/detail/lane_candidate__rosidl_typesupport_fastrtps_cpp.hpp"
#include "team4s_interfaces/msg/detail/lane_candidate__struct.hpp"

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

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
cdr_serialize(
  const team4s_interfaces::msg::LaneCandidate & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: candidate_id
  cdr << ros_message.candidate_id;
  // Member: route_lane
  cdr << ros_message.route_lane;
  // Member: is_branch
  cdr << (ros_message.is_branch ? true : false);
  // Member: left_visible
  cdr << (ros_message.left_visible ? true : false);
  // Member: right_visible
  cdr << (ros_message.right_visible ? true : false);
  // Member: center_valid
  cdr << (ros_message.center_valid ? true : false);
  // Member: offset_px
  cdr << ros_message.offset_px;
  // Member: reference_y_px
  cdr << ros_message.reference_y_px;
  // Member: heading_valid
  cdr << (ros_message.heading_valid ? true : false);
  // Member: heading_rad
  cdr << ros_message.heading_rad;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  team4s_interfaces::msg::LaneCandidate & ros_message)
{
  // Member: candidate_id
  cdr >> ros_message.candidate_id;

  // Member: route_lane
  cdr >> ros_message.route_lane;

  // Member: is_branch
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_branch = tmp ? true : false;
  }

  // Member: left_visible
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.left_visible = tmp ? true : false;
  }

  // Member: right_visible
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.right_visible = tmp ? true : false;
  }

  // Member: center_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.center_valid = tmp ? true : false;
  }

  // Member: offset_px
  cdr >> ros_message.offset_px;

  // Member: reference_y_px
  cdr >> ros_message.reference_y_px;

  // Member: heading_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.heading_valid = tmp ? true : false;
  }

  // Member: heading_rad
  cdr >> ros_message.heading_rad;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
get_serialized_size(
  const team4s_interfaces::msg::LaneCandidate & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: candidate_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.candidate_id.size() + 1);
  // Member: route_lane
  {
    size_t item_size = sizeof(ros_message.route_lane);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_branch
  {
    size_t item_size = sizeof(ros_message.is_branch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left_visible
  {
    size_t item_size = sizeof(ros_message.left_visible);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_visible
  {
    size_t item_size = sizeof(ros_message.right_visible);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: center_valid
  {
    size_t item_size = sizeof(ros_message.center_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: offset_px
  {
    size_t item_size = sizeof(ros_message.offset_px);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reference_y_px
  {
    size_t item_size = sizeof(ros_message.reference_y_px);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: heading_valid
  {
    size_t item_size = sizeof(ros_message.heading_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: heading_rad
  {
    size_t item_size = sizeof(ros_message.heading_rad);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
max_serialized_size_LaneCandidate(
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


  // Member: candidate_id
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

  // Member: route_lane
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: is_branch
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: left_visible
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: right_visible
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: center_valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: offset_px
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: reference_y_px
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: heading_valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: heading_rad
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = team4s_interfaces::msg::LaneCandidate;
    is_plain =
      (
      offsetof(DataType, heading_rad) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _LaneCandidate__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const team4s_interfaces::msg::LaneCandidate *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _LaneCandidate__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<team4s_interfaces::msg::LaneCandidate *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _LaneCandidate__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const team4s_interfaces::msg::LaneCandidate *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _LaneCandidate__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_LaneCandidate(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _LaneCandidate__callbacks = {
  "team4s_interfaces::msg",
  "LaneCandidate",
  _LaneCandidate__cdr_serialize,
  _LaneCandidate__cdr_deserialize,
  _LaneCandidate__get_serialized_size,
  _LaneCandidate__max_serialized_size
};

static rosidl_message_type_support_t _LaneCandidate__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_LaneCandidate__callbacks,
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
get_message_type_support_handle<team4s_interfaces::msg::LaneCandidate>()
{
  return &team4s_interfaces::msg::typesupport_fastrtps_cpp::_LaneCandidate__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, team4s_interfaces, msg, LaneCandidate)() {
  return &team4s_interfaces::msg::typesupport_fastrtps_cpp::_LaneCandidate__handle;
}

#ifdef __cplusplus
}
#endif

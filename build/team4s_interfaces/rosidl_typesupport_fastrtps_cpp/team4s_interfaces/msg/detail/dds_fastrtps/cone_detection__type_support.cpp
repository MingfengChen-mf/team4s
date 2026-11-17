// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from team4s_interfaces:msg/ConeDetection.idl
// generated code does not contain a copyright notice
#include "team4s_interfaces/msg/detail/cone_detection__rosidl_typesupport_fastrtps_cpp.hpp"
#include "team4s_interfaces/msg/detail/cone_detection__struct.hpp"

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
  const team4s_interfaces::msg::ConeDetection & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: candidate_id
  cdr << ros_message.candidate_id;
  // Member: color
  cdr << ros_message.color;
  // Member: bbox_known
  cdr << (ros_message.bbox_known ? true : false);
  // Member: bbox_xyxy
  {
    cdr << ros_message.bbox_xyxy;
  }
  // Member: color_pixels
  cdr << ros_message.color_pixels;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  team4s_interfaces::msg::ConeDetection & ros_message)
{
  // Member: candidate_id
  cdr >> ros_message.candidate_id;

  // Member: color
  cdr >> ros_message.color;

  // Member: bbox_known
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.bbox_known = tmp ? true : false;
  }

  // Member: bbox_xyxy
  {
    cdr >> ros_message.bbox_xyxy;
  }

  // Member: color_pixels
  cdr >> ros_message.color_pixels;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
get_serialized_size(
  const team4s_interfaces::msg::ConeDetection & ros_message,
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
  // Member: color
  {
    size_t item_size = sizeof(ros_message.color);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: bbox_known
  {
    size_t item_size = sizeof(ros_message.bbox_known);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: bbox_xyxy
  {
    size_t array_size = 4;
    size_t item_size = sizeof(ros_message.bbox_xyxy[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: color_pixels
  {
    size_t item_size = sizeof(ros_message.color_pixels);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
max_serialized_size_ConeDetection(
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

  // Member: color
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: bbox_known
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: bbox_xyxy
  {
    size_t array_size = 4;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: color_pixels
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
    using DataType = team4s_interfaces::msg::ConeDetection;
    is_plain =
      (
      offsetof(DataType, color_pixels) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ConeDetection__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const team4s_interfaces::msg::ConeDetection *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ConeDetection__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<team4s_interfaces::msg::ConeDetection *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ConeDetection__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const team4s_interfaces::msg::ConeDetection *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ConeDetection__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ConeDetection(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ConeDetection__callbacks = {
  "team4s_interfaces::msg",
  "ConeDetection",
  _ConeDetection__cdr_serialize,
  _ConeDetection__cdr_deserialize,
  _ConeDetection__get_serialized_size,
  _ConeDetection__max_serialized_size
};

static rosidl_message_type_support_t _ConeDetection__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ConeDetection__callbacks,
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
get_message_type_support_handle<team4s_interfaces::msg::ConeDetection>()
{
  return &team4s_interfaces::msg::typesupport_fastrtps_cpp::_ConeDetection__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, team4s_interfaces, msg, ConeDetection)() {
  return &team4s_interfaces::msg::typesupport_fastrtps_cpp::_ConeDetection__handle;
}

#ifdef __cplusplus
}
#endif

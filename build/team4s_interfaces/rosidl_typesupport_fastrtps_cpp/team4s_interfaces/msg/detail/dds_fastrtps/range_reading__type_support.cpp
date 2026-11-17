// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from team4s_interfaces:msg/RangeReading.idl
// generated code does not contain a copyright notice
#include "team4s_interfaces/msg/detail/range_reading__rosidl_typesupport_fastrtps_cpp.hpp"
#include "team4s_interfaces/msg/detail/range_reading__struct.hpp"

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
  const team4s_interfaces::msg::RangeReading & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: sensor_id
  cdr << ros_message.sensor_id;
  // Member: sensor_frame_id
  cdr << ros_message.sensor_frame_id;
  // Member: valid
  cdr << (ros_message.valid ? true : false);
  // Member: reason
  cdr << ros_message.reason;
  // Member: checksum_ok
  cdr << (ros_message.checksum_ok ? true : false);
  // Member: device_status_raw
  cdr << ros_message.device_status_raw;
  // Member: distance_m
  cdr << ros_message.distance_m;
  // Member: signal_strength
  cdr << ros_message.signal_strength;
  // Member: sensor_time_ms
  cdr << ros_message.sensor_time_ms;
  // Member: bearing_known
  cdr << (ros_message.bearing_known ? true : false);
  // Member: bearing_rad
  cdr << ros_message.bearing_rad;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  team4s_interfaces::msg::RangeReading & ros_message)
{
  // Member: sensor_id
  cdr >> ros_message.sensor_id;

  // Member: sensor_frame_id
  cdr >> ros_message.sensor_frame_id;

  // Member: valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.valid = tmp ? true : false;
  }

  // Member: reason
  cdr >> ros_message.reason;

  // Member: checksum_ok
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.checksum_ok = tmp ? true : false;
  }

  // Member: device_status_raw
  cdr >> ros_message.device_status_raw;

  // Member: distance_m
  cdr >> ros_message.distance_m;

  // Member: signal_strength
  cdr >> ros_message.signal_strength;

  // Member: sensor_time_ms
  cdr >> ros_message.sensor_time_ms;

  // Member: bearing_known
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.bearing_known = tmp ? true : false;
  }

  // Member: bearing_rad
  cdr >> ros_message.bearing_rad;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
get_serialized_size(
  const team4s_interfaces::msg::RangeReading & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: sensor_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.sensor_id.size() + 1);
  // Member: sensor_frame_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.sensor_frame_id.size() + 1);
  // Member: valid
  {
    size_t item_size = sizeof(ros_message.valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reason
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.reason.size() + 1);
  // Member: checksum_ok
  {
    size_t item_size = sizeof(ros_message.checksum_ok);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: device_status_raw
  {
    size_t item_size = sizeof(ros_message.device_status_raw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: distance_m
  {
    size_t item_size = sizeof(ros_message.distance_m);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: signal_strength
  {
    size_t item_size = sizeof(ros_message.signal_strength);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: sensor_time_ms
  {
    size_t item_size = sizeof(ros_message.sensor_time_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: bearing_known
  {
    size_t item_size = sizeof(ros_message.bearing_known);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: bearing_rad
  {
    size_t item_size = sizeof(ros_message.bearing_rad);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
max_serialized_size_RangeReading(
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


  // Member: sensor_id
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

  // Member: sensor_frame_id
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

  // Member: valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: reason
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

  // Member: checksum_ok
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: device_status_raw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: distance_m
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: signal_strength
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: sensor_time_ms
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: bearing_known
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: bearing_rad
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
    using DataType = team4s_interfaces::msg::RangeReading;
    is_plain =
      (
      offsetof(DataType, bearing_rad) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _RangeReading__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const team4s_interfaces::msg::RangeReading *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RangeReading__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<team4s_interfaces::msg::RangeReading *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RangeReading__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const team4s_interfaces::msg::RangeReading *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RangeReading__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_RangeReading(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _RangeReading__callbacks = {
  "team4s_interfaces::msg",
  "RangeReading",
  _RangeReading__cdr_serialize,
  _RangeReading__cdr_deserialize,
  _RangeReading__get_serialized_size,
  _RangeReading__max_serialized_size
};

static rosidl_message_type_support_t _RangeReading__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RangeReading__callbacks,
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
get_message_type_support_handle<team4s_interfaces::msg::RangeReading>()
{
  return &team4s_interfaces::msg::typesupport_fastrtps_cpp::_RangeReading__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, team4s_interfaces, msg, RangeReading)() {
  return &team4s_interfaces::msg::typesupport_fastrtps_cpp::_RangeReading__handle;
}

#ifdef __cplusplus
}
#endif

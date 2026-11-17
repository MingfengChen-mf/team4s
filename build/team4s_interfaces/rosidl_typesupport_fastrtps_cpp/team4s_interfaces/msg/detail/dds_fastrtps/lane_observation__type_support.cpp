// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from team4s_interfaces:msg/LaneObservation.idl
// generated code does not contain a copyright notice
#include "team4s_interfaces/msg/detail/lane_observation__rosidl_typesupport_fastrtps_cpp.hpp"
#include "team4s_interfaces/msg/detail/lane_observation__struct.hpp"

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
  const team4s_interfaces::msg::LaneCandidate &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  team4s_interfaces::msg::LaneCandidate &);
size_t get_serialized_size(
  const team4s_interfaces::msg::LaneCandidate &,
  size_t current_alignment);
size_t
max_serialized_size_LaneCandidate(
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
  const team4s_interfaces::msg::LaneObservation & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: meta
  team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.meta,
    cdr);
  // Member: image_width
  cdr << ros_message.image_width;
  // Member: image_height
  cdr << ros_message.image_height;
  // Member: candidates
  {
    size_t size = ros_message.candidates.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.candidates[i],
        cdr);
    }
  }
  // Member: selected_candidate_id
  cdr << ros_message.selected_candidate_id;
  // Member: offset_m_valid
  cdr << (ros_message.offset_m_valid ? true : false);
  // Member: offset_m
  cdr << ros_message.offset_m;
  // Member: metric_reason
  cdr << ros_message.metric_reason;
  // Member: calibration_id
  cdr << ros_message.calibration_id;
  // Member: metric_frame_id
  cdr << ros_message.metric_frame_id;
  // Member: metric_reference_x_m
  cdr << ros_message.metric_reference_x_m;
  // Member: metric_reference_y_m
  cdr << ros_message.metric_reference_y_m;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  team4s_interfaces::msg::LaneObservation & ros_message)
{
  // Member: meta
  team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.meta);

  // Member: image_width
  cdr >> ros_message.image_width;

  // Member: image_height
  cdr >> ros_message.image_height;

  // Member: candidates
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

    ros_message.candidates.resize(size);
    for (size_t i = 0; i < size; i++) {
      team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.candidates[i]);
    }
  }

  // Member: selected_candidate_id
  cdr >> ros_message.selected_candidate_id;

  // Member: offset_m_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.offset_m_valid = tmp ? true : false;
  }

  // Member: offset_m
  cdr >> ros_message.offset_m;

  // Member: metric_reason
  cdr >> ros_message.metric_reason;

  // Member: calibration_id
  cdr >> ros_message.calibration_id;

  // Member: metric_frame_id
  cdr >> ros_message.metric_frame_id;

  // Member: metric_reference_x_m
  cdr >> ros_message.metric_reference_x_m;

  // Member: metric_reference_y_m
  cdr >> ros_message.metric_reference_y_m;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
get_serialized_size(
  const team4s_interfaces::msg::LaneObservation & ros_message,
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
  // Member: image_width
  {
    size_t item_size = sizeof(ros_message.image_width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: image_height
  {
    size_t item_size = sizeof(ros_message.image_height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: candidates
  {
    size_t array_size = ros_message.candidates.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        team4s_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.candidates[index], current_alignment);
    }
  }
  // Member: selected_candidate_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.selected_candidate_id.size() + 1);
  // Member: offset_m_valid
  {
    size_t item_size = sizeof(ros_message.offset_m_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: offset_m
  {
    size_t item_size = sizeof(ros_message.offset_m);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: metric_reason
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.metric_reason.size() + 1);
  // Member: calibration_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.calibration_id.size() + 1);
  // Member: metric_frame_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.metric_frame_id.size() + 1);
  // Member: metric_reference_x_m
  {
    size_t item_size = sizeof(ros_message.metric_reference_x_m);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: metric_reference_y_m
  {
    size_t item_size = sizeof(ros_message.metric_reference_y_m);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
max_serialized_size_LaneObservation(
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

  // Member: image_width
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: image_height
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: candidates
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
        team4s_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_LaneCandidate(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: selected_candidate_id
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

  // Member: offset_m_valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: offset_m
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: metric_reason
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

  // Member: calibration_id
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

  // Member: metric_frame_id
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

  // Member: metric_reference_x_m
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: metric_reference_y_m
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
    using DataType = team4s_interfaces::msg::LaneObservation;
    is_plain =
      (
      offsetof(DataType, metric_reference_y_m) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _LaneObservation__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const team4s_interfaces::msg::LaneObservation *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _LaneObservation__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<team4s_interfaces::msg::LaneObservation *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _LaneObservation__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const team4s_interfaces::msg::LaneObservation *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _LaneObservation__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_LaneObservation(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _LaneObservation__callbacks = {
  "team4s_interfaces::msg",
  "LaneObservation",
  _LaneObservation__cdr_serialize,
  _LaneObservation__cdr_deserialize,
  _LaneObservation__get_serialized_size,
  _LaneObservation__max_serialized_size
};

static rosidl_message_type_support_t _LaneObservation__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_LaneObservation__callbacks,
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
get_message_type_support_handle<team4s_interfaces::msg::LaneObservation>()
{
  return &team4s_interfaces::msg::typesupport_fastrtps_cpp::_LaneObservation__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, team4s_interfaces, msg, LaneObservation)() {
  return &team4s_interfaces::msg::typesupport_fastrtps_cpp::_LaneObservation__handle;
}

#ifdef __cplusplus
}
#endif

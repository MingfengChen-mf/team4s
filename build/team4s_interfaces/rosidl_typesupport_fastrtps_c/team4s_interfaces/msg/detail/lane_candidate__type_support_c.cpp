// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from team4s_interfaces:msg/LaneCandidate.idl
// generated code does not contain a copyright notice
#include "team4s_interfaces/msg/detail/lane_candidate__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "team4s_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "team4s_interfaces/msg/detail/lane_candidate__struct.h"
#include "team4s_interfaces/msg/detail/lane_candidate__functions.h"
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

#include "rosidl_runtime_c/string.h"  // candidate_id
#include "rosidl_runtime_c/string_functions.h"  // candidate_id

// forward declare type support functions


using _LaneCandidate__ros_msg_type = team4s_interfaces__msg__LaneCandidate;

static bool _LaneCandidate__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _LaneCandidate__ros_msg_type * ros_message = static_cast<const _LaneCandidate__ros_msg_type *>(untyped_ros_message);
  // Field name: candidate_id
  {
    const rosidl_runtime_c__String * str = &ros_message->candidate_id;
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

  // Field name: route_lane
  {
    cdr << ros_message->route_lane;
  }

  // Field name: is_branch
  {
    cdr << (ros_message->is_branch ? true : false);
  }

  // Field name: left_visible
  {
    cdr << (ros_message->left_visible ? true : false);
  }

  // Field name: right_visible
  {
    cdr << (ros_message->right_visible ? true : false);
  }

  // Field name: center_valid
  {
    cdr << (ros_message->center_valid ? true : false);
  }

  // Field name: offset_px
  {
    cdr << ros_message->offset_px;
  }

  // Field name: reference_y_px
  {
    cdr << ros_message->reference_y_px;
  }

  // Field name: heading_valid
  {
    cdr << (ros_message->heading_valid ? true : false);
  }

  // Field name: heading_rad
  {
    cdr << ros_message->heading_rad;
  }

  return true;
}

static bool _LaneCandidate__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LaneCandidate__ros_msg_type * ros_message = static_cast<_LaneCandidate__ros_msg_type *>(untyped_ros_message);
  // Field name: candidate_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->candidate_id.data) {
      rosidl_runtime_c__String__init(&ros_message->candidate_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->candidate_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'candidate_id'\n");
      return false;
    }
  }

  // Field name: route_lane
  {
    cdr >> ros_message->route_lane;
  }

  // Field name: is_branch
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_branch = tmp ? true : false;
  }

  // Field name: left_visible
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->left_visible = tmp ? true : false;
  }

  // Field name: right_visible
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->right_visible = tmp ? true : false;
  }

  // Field name: center_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->center_valid = tmp ? true : false;
  }

  // Field name: offset_px
  {
    cdr >> ros_message->offset_px;
  }

  // Field name: reference_y_px
  {
    cdr >> ros_message->reference_y_px;
  }

  // Field name: heading_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->heading_valid = tmp ? true : false;
  }

  // Field name: heading_rad
  {
    cdr >> ros_message->heading_rad;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_team4s_interfaces
size_t get_serialized_size_team4s_interfaces__msg__LaneCandidate(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LaneCandidate__ros_msg_type * ros_message = static_cast<const _LaneCandidate__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name candidate_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->candidate_id.size + 1);
  // field.name route_lane
  {
    size_t item_size = sizeof(ros_message->route_lane);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_branch
  {
    size_t item_size = sizeof(ros_message->is_branch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name left_visible
  {
    size_t item_size = sizeof(ros_message->left_visible);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name right_visible
  {
    size_t item_size = sizeof(ros_message->right_visible);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name center_valid
  {
    size_t item_size = sizeof(ros_message->center_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name offset_px
  {
    size_t item_size = sizeof(ros_message->offset_px);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reference_y_px
  {
    size_t item_size = sizeof(ros_message->reference_y_px);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name heading_valid
  {
    size_t item_size = sizeof(ros_message->heading_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name heading_rad
  {
    size_t item_size = sizeof(ros_message->heading_rad);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _LaneCandidate__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_team4s_interfaces__msg__LaneCandidate(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_team4s_interfaces
size_t max_serialized_size_team4s_interfaces__msg__LaneCandidate(
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

  // member: candidate_id
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
  // member: route_lane
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: is_branch
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: left_visible
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: right_visible
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: center_valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: offset_px
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: reference_y_px
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: heading_valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: heading_rad
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
    using DataType = team4s_interfaces__msg__LaneCandidate;
    is_plain =
      (
      offsetof(DataType, heading_rad) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _LaneCandidate__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_team4s_interfaces__msg__LaneCandidate(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_LaneCandidate = {
  "team4s_interfaces::msg",
  "LaneCandidate",
  _LaneCandidate__cdr_serialize,
  _LaneCandidate__cdr_deserialize,
  _LaneCandidate__get_serialized_size,
  _LaneCandidate__max_serialized_size
};

static rosidl_message_type_support_t _LaneCandidate__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_LaneCandidate,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, LaneCandidate)() {
  return &_LaneCandidate__type_support;
}

#if defined(__cplusplus)
}
#endif

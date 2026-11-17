// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from team4s_interfaces:msg/LaneObservation.idl
// generated code does not contain a copyright notice
#include "team4s_interfaces/msg/detail/lane_observation__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "team4s_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "team4s_interfaces/msg/detail/lane_observation__struct.h"
#include "team4s_interfaces/msg/detail/lane_observation__functions.h"
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

#include "rosidl_runtime_c/string.h"  // calibration_id, metric_frame_id, metric_reason, selected_candidate_id
#include "rosidl_runtime_c/string_functions.h"  // calibration_id, metric_frame_id, metric_reason, selected_candidate_id
#include "team4s_interfaces/msg/detail/lane_candidate__functions.h"  // candidates
#include "team4s_interfaces/msg/detail/source_header__functions.h"  // meta

// forward declare type support functions
size_t get_serialized_size_team4s_interfaces__msg__LaneCandidate(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_team4s_interfaces__msg__LaneCandidate(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, LaneCandidate)();
size_t get_serialized_size_team4s_interfaces__msg__SourceHeader(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_team4s_interfaces__msg__SourceHeader(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, SourceHeader)();


using _LaneObservation__ros_msg_type = team4s_interfaces__msg__LaneObservation;

static bool _LaneObservation__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _LaneObservation__ros_msg_type * ros_message = static_cast<const _LaneObservation__ros_msg_type *>(untyped_ros_message);
  // Field name: meta
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, SourceHeader
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->meta, cdr))
    {
      return false;
    }
  }

  // Field name: image_width
  {
    cdr << ros_message->image_width;
  }

  // Field name: image_height
  {
    cdr << ros_message->image_height;
  }

  // Field name: candidates
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, LaneCandidate
      )()->data);
    size_t size = ros_message->candidates.size;
    auto array_ptr = ros_message->candidates.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: selected_candidate_id
  {
    const rosidl_runtime_c__String * str = &ros_message->selected_candidate_id;
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

  // Field name: offset_m_valid
  {
    cdr << (ros_message->offset_m_valid ? true : false);
  }

  // Field name: offset_m
  {
    cdr << ros_message->offset_m;
  }

  // Field name: metric_reason
  {
    const rosidl_runtime_c__String * str = &ros_message->metric_reason;
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

  // Field name: calibration_id
  {
    const rosidl_runtime_c__String * str = &ros_message->calibration_id;
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

  // Field name: metric_frame_id
  {
    const rosidl_runtime_c__String * str = &ros_message->metric_frame_id;
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

  // Field name: metric_reference_x_m
  {
    cdr << ros_message->metric_reference_x_m;
  }

  // Field name: metric_reference_y_m
  {
    cdr << ros_message->metric_reference_y_m;
  }

  return true;
}

static bool _LaneObservation__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LaneObservation__ros_msg_type * ros_message = static_cast<_LaneObservation__ros_msg_type *>(untyped_ros_message);
  // Field name: meta
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, SourceHeader
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->meta))
    {
      return false;
    }
  }

  // Field name: image_width
  {
    cdr >> ros_message->image_width;
  }

  // Field name: image_height
  {
    cdr >> ros_message->image_height;
  }

  // Field name: candidates
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, LaneCandidate
      )()->data);
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

    if (ros_message->candidates.data) {
      team4s_interfaces__msg__LaneCandidate__Sequence__fini(&ros_message->candidates);
    }
    if (!team4s_interfaces__msg__LaneCandidate__Sequence__init(&ros_message->candidates, size)) {
      fprintf(stderr, "failed to create array for field 'candidates'");
      return false;
    }
    auto array_ptr = ros_message->candidates.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: selected_candidate_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->selected_candidate_id.data) {
      rosidl_runtime_c__String__init(&ros_message->selected_candidate_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->selected_candidate_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'selected_candidate_id'\n");
      return false;
    }
  }

  // Field name: offset_m_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->offset_m_valid = tmp ? true : false;
  }

  // Field name: offset_m
  {
    cdr >> ros_message->offset_m;
  }

  // Field name: metric_reason
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->metric_reason.data) {
      rosidl_runtime_c__String__init(&ros_message->metric_reason);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->metric_reason,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'metric_reason'\n");
      return false;
    }
  }

  // Field name: calibration_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->calibration_id.data) {
      rosidl_runtime_c__String__init(&ros_message->calibration_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->calibration_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'calibration_id'\n");
      return false;
    }
  }

  // Field name: metric_frame_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->metric_frame_id.data) {
      rosidl_runtime_c__String__init(&ros_message->metric_frame_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->metric_frame_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'metric_frame_id'\n");
      return false;
    }
  }

  // Field name: metric_reference_x_m
  {
    cdr >> ros_message->metric_reference_x_m;
  }

  // Field name: metric_reference_y_m
  {
    cdr >> ros_message->metric_reference_y_m;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_team4s_interfaces
size_t get_serialized_size_team4s_interfaces__msg__LaneObservation(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LaneObservation__ros_msg_type * ros_message = static_cast<const _LaneObservation__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name meta

  current_alignment += get_serialized_size_team4s_interfaces__msg__SourceHeader(
    &(ros_message->meta), current_alignment);
  // field.name image_width
  {
    size_t item_size = sizeof(ros_message->image_width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name image_height
  {
    size_t item_size = sizeof(ros_message->image_height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name candidates
  {
    size_t array_size = ros_message->candidates.size;
    auto array_ptr = ros_message->candidates.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_team4s_interfaces__msg__LaneCandidate(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name selected_candidate_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->selected_candidate_id.size + 1);
  // field.name offset_m_valid
  {
    size_t item_size = sizeof(ros_message->offset_m_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name offset_m
  {
    size_t item_size = sizeof(ros_message->offset_m);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name metric_reason
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->metric_reason.size + 1);
  // field.name calibration_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->calibration_id.size + 1);
  // field.name metric_frame_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->metric_frame_id.size + 1);
  // field.name metric_reference_x_m
  {
    size_t item_size = sizeof(ros_message->metric_reference_x_m);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name metric_reference_y_m
  {
    size_t item_size = sizeof(ros_message->metric_reference_y_m);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _LaneObservation__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_team4s_interfaces__msg__LaneObservation(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_team4s_interfaces
size_t max_serialized_size_team4s_interfaces__msg__LaneObservation(
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

  // member: meta
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_team4s_interfaces__msg__SourceHeader(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: image_width
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: image_height
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: candidates
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
      size_t inner_size;
      inner_size =
        max_serialized_size_team4s_interfaces__msg__LaneCandidate(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: selected_candidate_id
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
  // member: offset_m_valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: offset_m
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: metric_reason
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
  // member: calibration_id
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
  // member: metric_frame_id
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
  // member: metric_reference_x_m
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: metric_reference_y_m
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
    using DataType = team4s_interfaces__msg__LaneObservation;
    is_plain =
      (
      offsetof(DataType, metric_reference_y_m) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _LaneObservation__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_team4s_interfaces__msg__LaneObservation(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_LaneObservation = {
  "team4s_interfaces::msg",
  "LaneObservation",
  _LaneObservation__cdr_serialize,
  _LaneObservation__cdr_deserialize,
  _LaneObservation__get_serialized_size,
  _LaneObservation__max_serialized_size
};

static rosidl_message_type_support_t _LaneObservation__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_LaneObservation,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, LaneObservation)() {
  return &_LaneObservation__type_support;
}

#if defined(__cplusplus)
}
#endif

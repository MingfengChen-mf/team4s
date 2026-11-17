// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from team4s_interfaces:msg/ObstacleObservation.idl
// generated code does not contain a copyright notice
#include "team4s_interfaces/msg/detail/obstacle_observation__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "team4s_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "team4s_interfaces/msg/detail/obstacle_observation__struct.h"
#include "team4s_interfaces/msg/detail/obstacle_observation__functions.h"
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

#include "team4s_interfaces/msg/detail/range_reading__functions.h"  // readings
#include "team4s_interfaces/msg/detail/source_header__functions.h"  // meta

// forward declare type support functions
size_t get_serialized_size_team4s_interfaces__msg__RangeReading(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_team4s_interfaces__msg__RangeReading(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, RangeReading)();
size_t get_serialized_size_team4s_interfaces__msg__SourceHeader(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_team4s_interfaces__msg__SourceHeader(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, SourceHeader)();


using _ObstacleObservation__ros_msg_type = team4s_interfaces__msg__ObstacleObservation;

static bool _ObstacleObservation__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ObstacleObservation__ros_msg_type * ros_message = static_cast<const _ObstacleObservation__ros_msg_type *>(untyped_ros_message);
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

  // Field name: readings
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, RangeReading
      )()->data);
    size_t size = ros_message->readings.size;
    auto array_ptr = ros_message->readings.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: left_clear_known
  {
    cdr << (ros_message->left_clear_known ? true : false);
  }

  // Field name: left_clear
  {
    cdr << (ros_message->left_clear ? true : false);
  }

  // Field name: right_clear_known
  {
    cdr << (ros_message->right_clear_known ? true : false);
  }

  // Field name: right_clear
  {
    cdr << (ros_message->right_clear ? true : false);
  }

  return true;
}

static bool _ObstacleObservation__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ObstacleObservation__ros_msg_type * ros_message = static_cast<_ObstacleObservation__ros_msg_type *>(untyped_ros_message);
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

  // Field name: readings
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, RangeReading
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

    if (ros_message->readings.data) {
      team4s_interfaces__msg__RangeReading__Sequence__fini(&ros_message->readings);
    }
    if (!team4s_interfaces__msg__RangeReading__Sequence__init(&ros_message->readings, size)) {
      fprintf(stderr, "failed to create array for field 'readings'");
      return false;
    }
    auto array_ptr = ros_message->readings.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: left_clear_known
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->left_clear_known = tmp ? true : false;
  }

  // Field name: left_clear
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->left_clear = tmp ? true : false;
  }

  // Field name: right_clear_known
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->right_clear_known = tmp ? true : false;
  }

  // Field name: right_clear
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->right_clear = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_team4s_interfaces
size_t get_serialized_size_team4s_interfaces__msg__ObstacleObservation(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ObstacleObservation__ros_msg_type * ros_message = static_cast<const _ObstacleObservation__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name meta

  current_alignment += get_serialized_size_team4s_interfaces__msg__SourceHeader(
    &(ros_message->meta), current_alignment);
  // field.name readings
  {
    size_t array_size = ros_message->readings.size;
    auto array_ptr = ros_message->readings.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_team4s_interfaces__msg__RangeReading(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name left_clear_known
  {
    size_t item_size = sizeof(ros_message->left_clear_known);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name left_clear
  {
    size_t item_size = sizeof(ros_message->left_clear);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name right_clear_known
  {
    size_t item_size = sizeof(ros_message->right_clear_known);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name right_clear
  {
    size_t item_size = sizeof(ros_message->right_clear);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ObstacleObservation__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_team4s_interfaces__msg__ObstacleObservation(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_team4s_interfaces
size_t max_serialized_size_team4s_interfaces__msg__ObstacleObservation(
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
  // member: readings
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
        max_serialized_size_team4s_interfaces__msg__RangeReading(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: left_clear_known
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: left_clear
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: right_clear_known
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: right_clear
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
    using DataType = team4s_interfaces__msg__ObstacleObservation;
    is_plain =
      (
      offsetof(DataType, right_clear) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _ObstacleObservation__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_team4s_interfaces__msg__ObstacleObservation(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ObstacleObservation = {
  "team4s_interfaces::msg",
  "ObstacleObservation",
  _ObstacleObservation__cdr_serialize,
  _ObstacleObservation__cdr_deserialize,
  _ObstacleObservation__get_serialized_size,
  _ObstacleObservation__max_serialized_size
};

static rosidl_message_type_support_t _ObstacleObservation__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ObstacleObservation,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, ObstacleObservation)() {
  return &_ObstacleObservation__type_support;
}

#if defined(__cplusplus)
}
#endif

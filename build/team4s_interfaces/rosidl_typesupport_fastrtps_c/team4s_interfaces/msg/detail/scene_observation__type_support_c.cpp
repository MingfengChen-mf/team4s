// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from team4s_interfaces:msg/SceneObservation.idl
// generated code does not contain a copyright notice
#include "team4s_interfaces/msg/detail/scene_observation__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "team4s_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "team4s_interfaces/msg/detail/scene_observation__struct.h"
#include "team4s_interfaces/msg/detail/scene_observation__functions.h"
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

#include "builtin_interfaces/msg/detail/time__functions.h"  // cone_event_stamp, red_finish_event_stamp, zebra_event_stamp
#include "rosidl_runtime_c/string.h"  // cones_reason
#include "rosidl_runtime_c/string_functions.h"  // cones_reason
#include "team4s_interfaces/msg/detail/cone_detection__functions.h"  // cones
#include "team4s_interfaces/msg/detail/source_header__functions.h"  // meta

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_team4s_interfaces
size_t get_serialized_size_builtin_interfaces__msg__Time(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_team4s_interfaces
size_t max_serialized_size_builtin_interfaces__msg__Time(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_team4s_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time)();
size_t get_serialized_size_team4s_interfaces__msg__ConeDetection(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_team4s_interfaces__msg__ConeDetection(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, ConeDetection)();
size_t get_serialized_size_team4s_interfaces__msg__SourceHeader(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_team4s_interfaces__msg__SourceHeader(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, SourceHeader)();


using _SceneObservation__ros_msg_type = team4s_interfaces__msg__SceneObservation;

static bool _SceneObservation__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SceneObservation__ros_msg_type * ros_message = static_cast<const _SceneObservation__ros_msg_type *>(untyped_ros_message);
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

  // Field name: cone_valid
  {
    cdr << (ros_message->cone_valid ? true : false);
  }

  // Field name: cone_state
  {
    cdr << ros_message->cone_state;
  }

  // Field name: cone_bbox_known
  {
    cdr << (ros_message->cone_bbox_known ? true : false);
  }

  // Field name: cone_bbox_xyxy
  {
    size_t size = 4;
    auto array_ptr = ros_message->cone_bbox_xyxy;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: zebra_valid
  {
    cdr << (ros_message->zebra_valid ? true : false);
  }

  // Field name: zebra_visible
  {
    cdr << (ros_message->zebra_visible ? true : false);
  }

  // Field name: zebra_bbox_known
  {
    cdr << (ros_message->zebra_bbox_known ? true : false);
  }

  // Field name: zebra_bbox_xyxy
  {
    size_t size = 4;
    auto array_ptr = ros_message->zebra_bbox_xyxy;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: image_width
  {
    cdr << ros_message->image_width;
  }

  // Field name: image_height
  {
    cdr << ros_message->image_height;
  }

  // Field name: cone_event_id
  {
    cdr << ros_message->cone_event_id;
  }

  // Field name: cone_event_stamp
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->cone_event_stamp, cdr))
    {
      return false;
    }
  }

  // Field name: zebra_event_id
  {
    cdr << ros_message->zebra_event_id;
  }

  // Field name: zebra_event_stamp
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->zebra_event_stamp, cdr))
    {
      return false;
    }
  }

  // Field name: zebra_event_confirmed
  {
    cdr << (ros_message->zebra_event_confirmed ? true : false);
  }

  // Field name: cones_valid
  {
    cdr << (ros_message->cones_valid ? true : false);
  }

  // Field name: cones_reason
  {
    const rosidl_runtime_c__String * str = &ros_message->cones_reason;
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

  // Field name: cones
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, ConeDetection
      )()->data);
    size_t size = ros_message->cones.size;
    auto array_ptr = ros_message->cones.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: green_start_visible
  {
    cdr << (ros_message->green_start_visible ? true : false);
  }

  // Field name: red_finish_visible
  {
    cdr << (ros_message->red_finish_visible ? true : false);
  }

  // Field name: red_finish_confirmed
  {
    cdr << (ros_message->red_finish_confirmed ? true : false);
  }

  // Field name: red_finish_event_id
  {
    cdr << ros_message->red_finish_event_id;
  }

  // Field name: red_finish_event_stamp
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->red_finish_event_stamp, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _SceneObservation__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SceneObservation__ros_msg_type * ros_message = static_cast<_SceneObservation__ros_msg_type *>(untyped_ros_message);
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

  // Field name: cone_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->cone_valid = tmp ? true : false;
  }

  // Field name: cone_state
  {
    cdr >> ros_message->cone_state;
  }

  // Field name: cone_bbox_known
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->cone_bbox_known = tmp ? true : false;
  }

  // Field name: cone_bbox_xyxy
  {
    size_t size = 4;
    auto array_ptr = ros_message->cone_bbox_xyxy;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: zebra_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->zebra_valid = tmp ? true : false;
  }

  // Field name: zebra_visible
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->zebra_visible = tmp ? true : false;
  }

  // Field name: zebra_bbox_known
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->zebra_bbox_known = tmp ? true : false;
  }

  // Field name: zebra_bbox_xyxy
  {
    size_t size = 4;
    auto array_ptr = ros_message->zebra_bbox_xyxy;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: image_width
  {
    cdr >> ros_message->image_width;
  }

  // Field name: image_height
  {
    cdr >> ros_message->image_height;
  }

  // Field name: cone_event_id
  {
    cdr >> ros_message->cone_event_id;
  }

  // Field name: cone_event_stamp
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->cone_event_stamp))
    {
      return false;
    }
  }

  // Field name: zebra_event_id
  {
    cdr >> ros_message->zebra_event_id;
  }

  // Field name: zebra_event_stamp
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->zebra_event_stamp))
    {
      return false;
    }
  }

  // Field name: zebra_event_confirmed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->zebra_event_confirmed = tmp ? true : false;
  }

  // Field name: cones_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->cones_valid = tmp ? true : false;
  }

  // Field name: cones_reason
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->cones_reason.data) {
      rosidl_runtime_c__String__init(&ros_message->cones_reason);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->cones_reason,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'cones_reason'\n");
      return false;
    }
  }

  // Field name: cones
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, ConeDetection
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

    if (ros_message->cones.data) {
      team4s_interfaces__msg__ConeDetection__Sequence__fini(&ros_message->cones);
    }
    if (!team4s_interfaces__msg__ConeDetection__Sequence__init(&ros_message->cones, size)) {
      fprintf(stderr, "failed to create array for field 'cones'");
      return false;
    }
    auto array_ptr = ros_message->cones.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: green_start_visible
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->green_start_visible = tmp ? true : false;
  }

  // Field name: red_finish_visible
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->red_finish_visible = tmp ? true : false;
  }

  // Field name: red_finish_confirmed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->red_finish_confirmed = tmp ? true : false;
  }

  // Field name: red_finish_event_id
  {
    cdr >> ros_message->red_finish_event_id;
  }

  // Field name: red_finish_event_stamp
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->red_finish_event_stamp))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_team4s_interfaces
size_t get_serialized_size_team4s_interfaces__msg__SceneObservation(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SceneObservation__ros_msg_type * ros_message = static_cast<const _SceneObservation__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name meta

  current_alignment += get_serialized_size_team4s_interfaces__msg__SourceHeader(
    &(ros_message->meta), current_alignment);
  // field.name cone_valid
  {
    size_t item_size = sizeof(ros_message->cone_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cone_state
  {
    size_t item_size = sizeof(ros_message->cone_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cone_bbox_known
  {
    size_t item_size = sizeof(ros_message->cone_bbox_known);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cone_bbox_xyxy
  {
    size_t array_size = 4;
    auto array_ptr = ros_message->cone_bbox_xyxy;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name zebra_valid
  {
    size_t item_size = sizeof(ros_message->zebra_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name zebra_visible
  {
    size_t item_size = sizeof(ros_message->zebra_visible);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name zebra_bbox_known
  {
    size_t item_size = sizeof(ros_message->zebra_bbox_known);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name zebra_bbox_xyxy
  {
    size_t array_size = 4;
    auto array_ptr = ros_message->zebra_bbox_xyxy;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
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
  // field.name cone_event_id
  {
    size_t item_size = sizeof(ros_message->cone_event_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cone_event_stamp

  current_alignment += get_serialized_size_builtin_interfaces__msg__Time(
    &(ros_message->cone_event_stamp), current_alignment);
  // field.name zebra_event_id
  {
    size_t item_size = sizeof(ros_message->zebra_event_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name zebra_event_stamp

  current_alignment += get_serialized_size_builtin_interfaces__msg__Time(
    &(ros_message->zebra_event_stamp), current_alignment);
  // field.name zebra_event_confirmed
  {
    size_t item_size = sizeof(ros_message->zebra_event_confirmed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cones_valid
  {
    size_t item_size = sizeof(ros_message->cones_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cones_reason
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->cones_reason.size + 1);
  // field.name cones
  {
    size_t array_size = ros_message->cones.size;
    auto array_ptr = ros_message->cones.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_team4s_interfaces__msg__ConeDetection(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name green_start_visible
  {
    size_t item_size = sizeof(ros_message->green_start_visible);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name red_finish_visible
  {
    size_t item_size = sizeof(ros_message->red_finish_visible);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name red_finish_confirmed
  {
    size_t item_size = sizeof(ros_message->red_finish_confirmed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name red_finish_event_id
  {
    size_t item_size = sizeof(ros_message->red_finish_event_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name red_finish_event_stamp

  current_alignment += get_serialized_size_builtin_interfaces__msg__Time(
    &(ros_message->red_finish_event_stamp), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _SceneObservation__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_team4s_interfaces__msg__SceneObservation(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_team4s_interfaces
size_t max_serialized_size_team4s_interfaces__msg__SceneObservation(
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
  // member: cone_valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: cone_state
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: cone_bbox_known
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: cone_bbox_xyxy
  {
    size_t array_size = 4;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: zebra_valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: zebra_visible
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: zebra_bbox_known
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: zebra_bbox_xyxy
  {
    size_t array_size = 4;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
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
  // member: cone_event_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: cone_event_stamp
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_builtin_interfaces__msg__Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: zebra_event_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: zebra_event_stamp
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_builtin_interfaces__msg__Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: zebra_event_confirmed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: cones_valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: cones_reason
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
  // member: cones
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
        max_serialized_size_team4s_interfaces__msg__ConeDetection(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: green_start_visible
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: red_finish_visible
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: red_finish_confirmed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: red_finish_event_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: red_finish_event_stamp
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_builtin_interfaces__msg__Time(
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
    using DataType = team4s_interfaces__msg__SceneObservation;
    is_plain =
      (
      offsetof(DataType, red_finish_event_stamp) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _SceneObservation__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_team4s_interfaces__msg__SceneObservation(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SceneObservation = {
  "team4s_interfaces::msg",
  "SceneObservation",
  _SceneObservation__cdr_serialize,
  _SceneObservation__cdr_deserialize,
  _SceneObservation__get_serialized_size,
  _SceneObservation__max_serialized_size
};

static rosidl_message_type_support_t _SceneObservation__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SceneObservation,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, team4s_interfaces, msg, SceneObservation)() {
  return &_SceneObservation__type_support;
}

#if defined(__cplusplus)
}
#endif

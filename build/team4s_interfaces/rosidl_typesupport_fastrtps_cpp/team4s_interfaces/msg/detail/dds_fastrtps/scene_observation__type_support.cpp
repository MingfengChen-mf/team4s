// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from team4s_interfaces:msg/SceneObservation.idl
// generated code does not contain a copyright notice
#include "team4s_interfaces/msg/detail/scene_observation__rosidl_typesupport_fastrtps_cpp.hpp"
#include "team4s_interfaces/msg/detail/scene_observation__struct.hpp"

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

namespace builtin_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const builtin_interfaces::msg::Time &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  builtin_interfaces::msg::Time &);
size_t get_serialized_size(
  const builtin_interfaces::msg::Time &,
  size_t current_alignment);
size_t
max_serialized_size_Time(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace builtin_interfaces

// functions for builtin_interfaces::msg::Time already declared above

namespace team4s_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const team4s_interfaces::msg::ConeDetection &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  team4s_interfaces::msg::ConeDetection &);
size_t get_serialized_size(
  const team4s_interfaces::msg::ConeDetection &,
  size_t current_alignment);
size_t
max_serialized_size_ConeDetection(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace team4s_interfaces

// functions for builtin_interfaces::msg::Time already declared above


namespace team4s_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
cdr_serialize(
  const team4s_interfaces::msg::SceneObservation & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: meta
  team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.meta,
    cdr);
  // Member: cone_valid
  cdr << (ros_message.cone_valid ? true : false);
  // Member: cone_state
  cdr << ros_message.cone_state;
  // Member: cone_bbox_known
  cdr << (ros_message.cone_bbox_known ? true : false);
  // Member: cone_bbox_xyxy
  {
    cdr << ros_message.cone_bbox_xyxy;
  }
  // Member: zebra_valid
  cdr << (ros_message.zebra_valid ? true : false);
  // Member: zebra_visible
  cdr << (ros_message.zebra_visible ? true : false);
  // Member: zebra_bbox_known
  cdr << (ros_message.zebra_bbox_known ? true : false);
  // Member: zebra_bbox_xyxy
  {
    cdr << ros_message.zebra_bbox_xyxy;
  }
  // Member: image_width
  cdr << ros_message.image_width;
  // Member: image_height
  cdr << ros_message.image_height;
  // Member: cone_event_id
  cdr << ros_message.cone_event_id;
  // Member: cone_event_stamp
  builtin_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.cone_event_stamp,
    cdr);
  // Member: zebra_event_id
  cdr << ros_message.zebra_event_id;
  // Member: zebra_event_stamp
  builtin_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.zebra_event_stamp,
    cdr);
  // Member: zebra_event_confirmed
  cdr << (ros_message.zebra_event_confirmed ? true : false);
  // Member: cones_valid
  cdr << (ros_message.cones_valid ? true : false);
  // Member: cones_reason
  cdr << ros_message.cones_reason;
  // Member: cones
  {
    size_t size = ros_message.cones.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.cones[i],
        cdr);
    }
  }
  // Member: green_start_visible
  cdr << (ros_message.green_start_visible ? true : false);
  // Member: red_finish_visible
  cdr << (ros_message.red_finish_visible ? true : false);
  // Member: red_finish_confirmed
  cdr << (ros_message.red_finish_confirmed ? true : false);
  // Member: red_finish_event_id
  cdr << ros_message.red_finish_event_id;
  // Member: red_finish_event_stamp
  builtin_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.red_finish_event_stamp,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  team4s_interfaces::msg::SceneObservation & ros_message)
{
  // Member: meta
  team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.meta);

  // Member: cone_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.cone_valid = tmp ? true : false;
  }

  // Member: cone_state
  cdr >> ros_message.cone_state;

  // Member: cone_bbox_known
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.cone_bbox_known = tmp ? true : false;
  }

  // Member: cone_bbox_xyxy
  {
    cdr >> ros_message.cone_bbox_xyxy;
  }

  // Member: zebra_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.zebra_valid = tmp ? true : false;
  }

  // Member: zebra_visible
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.zebra_visible = tmp ? true : false;
  }

  // Member: zebra_bbox_known
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.zebra_bbox_known = tmp ? true : false;
  }

  // Member: zebra_bbox_xyxy
  {
    cdr >> ros_message.zebra_bbox_xyxy;
  }

  // Member: image_width
  cdr >> ros_message.image_width;

  // Member: image_height
  cdr >> ros_message.image_height;

  // Member: cone_event_id
  cdr >> ros_message.cone_event_id;

  // Member: cone_event_stamp
  builtin_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.cone_event_stamp);

  // Member: zebra_event_id
  cdr >> ros_message.zebra_event_id;

  // Member: zebra_event_stamp
  builtin_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.zebra_event_stamp);

  // Member: zebra_event_confirmed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.zebra_event_confirmed = tmp ? true : false;
  }

  // Member: cones_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.cones_valid = tmp ? true : false;
  }

  // Member: cones_reason
  cdr >> ros_message.cones_reason;

  // Member: cones
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

    ros_message.cones.resize(size);
    for (size_t i = 0; i < size; i++) {
      team4s_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.cones[i]);
    }
  }

  // Member: green_start_visible
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.green_start_visible = tmp ? true : false;
  }

  // Member: red_finish_visible
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.red_finish_visible = tmp ? true : false;
  }

  // Member: red_finish_confirmed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.red_finish_confirmed = tmp ? true : false;
  }

  // Member: red_finish_event_id
  cdr >> ros_message.red_finish_event_id;

  // Member: red_finish_event_stamp
  builtin_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.red_finish_event_stamp);

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
get_serialized_size(
  const team4s_interfaces::msg::SceneObservation & ros_message,
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
  // Member: cone_valid
  {
    size_t item_size = sizeof(ros_message.cone_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: cone_state
  {
    size_t item_size = sizeof(ros_message.cone_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: cone_bbox_known
  {
    size_t item_size = sizeof(ros_message.cone_bbox_known);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: cone_bbox_xyxy
  {
    size_t array_size = 4;
    size_t item_size = sizeof(ros_message.cone_bbox_xyxy[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: zebra_valid
  {
    size_t item_size = sizeof(ros_message.zebra_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: zebra_visible
  {
    size_t item_size = sizeof(ros_message.zebra_visible);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: zebra_bbox_known
  {
    size_t item_size = sizeof(ros_message.zebra_bbox_known);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: zebra_bbox_xyxy
  {
    size_t array_size = 4;
    size_t item_size = sizeof(ros_message.zebra_bbox_xyxy[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
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
  // Member: cone_event_id
  {
    size_t item_size = sizeof(ros_message.cone_event_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: cone_event_stamp

  current_alignment +=
    builtin_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.cone_event_stamp, current_alignment);
  // Member: zebra_event_id
  {
    size_t item_size = sizeof(ros_message.zebra_event_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: zebra_event_stamp

  current_alignment +=
    builtin_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.zebra_event_stamp, current_alignment);
  // Member: zebra_event_confirmed
  {
    size_t item_size = sizeof(ros_message.zebra_event_confirmed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: cones_valid
  {
    size_t item_size = sizeof(ros_message.cones_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: cones_reason
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.cones_reason.size() + 1);
  // Member: cones
  {
    size_t array_size = ros_message.cones.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        team4s_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.cones[index], current_alignment);
    }
  }
  // Member: green_start_visible
  {
    size_t item_size = sizeof(ros_message.green_start_visible);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: red_finish_visible
  {
    size_t item_size = sizeof(ros_message.red_finish_visible);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: red_finish_confirmed
  {
    size_t item_size = sizeof(ros_message.red_finish_confirmed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: red_finish_event_id
  {
    size_t item_size = sizeof(ros_message.red_finish_event_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: red_finish_event_stamp

  current_alignment +=
    builtin_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.red_finish_event_stamp, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_team4s_interfaces
max_serialized_size_SceneObservation(
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

  // Member: cone_valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: cone_state
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: cone_bbox_known
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: cone_bbox_xyxy
  {
    size_t array_size = 4;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: zebra_valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: zebra_visible
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: zebra_bbox_known
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: zebra_bbox_xyxy
  {
    size_t array_size = 4;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
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

  // Member: cone_event_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: cone_event_stamp
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        builtin_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: zebra_event_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: zebra_event_stamp
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        builtin_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: zebra_event_confirmed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: cones_valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: cones_reason
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

  // Member: cones
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
        team4s_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_ConeDetection(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: green_start_visible
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: red_finish_visible
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: red_finish_confirmed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: red_finish_event_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: red_finish_event_stamp
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        builtin_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_Time(
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
    using DataType = team4s_interfaces::msg::SceneObservation;
    is_plain =
      (
      offsetof(DataType, red_finish_event_stamp) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _SceneObservation__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const team4s_interfaces::msg::SceneObservation *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SceneObservation__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<team4s_interfaces::msg::SceneObservation *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SceneObservation__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const team4s_interfaces::msg::SceneObservation *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SceneObservation__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SceneObservation(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SceneObservation__callbacks = {
  "team4s_interfaces::msg",
  "SceneObservation",
  _SceneObservation__cdr_serialize,
  _SceneObservation__cdr_deserialize,
  _SceneObservation__get_serialized_size,
  _SceneObservation__max_serialized_size
};

static rosidl_message_type_support_t _SceneObservation__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SceneObservation__callbacks,
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
get_message_type_support_handle<team4s_interfaces::msg::SceneObservation>()
{
  return &team4s_interfaces::msg::typesupport_fastrtps_cpp::_SceneObservation__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, team4s_interfaces, msg, SceneObservation)() {
  return &team4s_interfaces::msg::typesupport_fastrtps_cpp::_SceneObservation__handle;
}

#ifdef __cplusplus
}
#endif

// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from team4s_interfaces:msg/SceneObservation.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__SCENE_OBSERVATION__STRUCT_H_
#define TEAM4S_INTERFACES__MSG__DETAIL__SCENE_OBSERVATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'CONE_UNKNOWN'.
enum
{
  team4s_interfaces__msg__SceneObservation__CONE_UNKNOWN = 0
};

/// Constant 'CONE_PRESENT'.
enum
{
  team4s_interfaces__msg__SceneObservation__CONE_PRESENT = 1
};

/// Constant 'CONE_LEAVING'.
enum
{
  team4s_interfaces__msg__SceneObservation__CONE_LEAVING = 2
};

/// Constant 'CONE_REMOVED'.
enum
{
  team4s_interfaces__msg__SceneObservation__CONE_REMOVED = 3
};

// Include directives for member types
// Member 'meta'
#include "team4s_interfaces/msg/detail/source_header__struct.h"
// Member 'cone_event_stamp'
// Member 'zebra_event_stamp'
// Member 'red_finish_event_stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'cones_reason'
#include "rosidl_runtime_c/string.h"
// Member 'cones'
#include "team4s_interfaces/msg/detail/cone_detection__struct.h"

/// Struct defined in msg/SceneObservation in the package team4s_interfaces.
typedef struct team4s_interfaces__msg__SceneObservation
{
  team4s_interfaces__msg__SourceHeader meta;
  bool cone_valid;
  uint8_t cone_state;
  bool cone_bbox_known;
  int32_t cone_bbox_xyxy[4];
  bool zebra_valid;
  bool zebra_visible;
  bool zebra_bbox_known;
  int32_t zebra_bbox_xyxy[4];
  /// Boxes refer to input-image pixels only; half-open right/bottom limits.
  uint32_t image_width;
  uint32_t image_height;
  /// Tracking IDs, scoped to source_session_id. These do NOT prove lap completion.
  uint64_t cone_event_id;
  builtin_interfaces__msg__Time cone_event_stamp;
  uint64_t zebra_event_id;
  builtin_interfaces__msg__Time zebra_event_stamp;
  bool zebra_event_confirmed;
  /// v2 cone_* legacy fields above now refer ONLY to the green start cone.
  bool cones_valid;
  rosidl_runtime_c__String cones_reason;
  team4s_interfaces__msg__ConeDetection__Sequence cones;
  bool green_start_visible;
  bool red_finish_visible;
  /// Observation confirmation only. Control decides whether this is a finish.
  bool red_finish_confirmed;
  uint64_t red_finish_event_id;
  builtin_interfaces__msg__Time red_finish_event_stamp;
} team4s_interfaces__msg__SceneObservation;

// Struct for a sequence of team4s_interfaces__msg__SceneObservation.
typedef struct team4s_interfaces__msg__SceneObservation__Sequence
{
  team4s_interfaces__msg__SceneObservation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} team4s_interfaces__msg__SceneObservation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__SCENE_OBSERVATION__STRUCT_H_

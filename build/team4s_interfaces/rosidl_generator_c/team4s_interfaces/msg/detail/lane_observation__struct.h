// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from team4s_interfaces:msg/LaneObservation.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__LANE_OBSERVATION__STRUCT_H_
#define TEAM4S_INTERFACES__MSG__DETAIL__LANE_OBSERVATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'meta'
#include "team4s_interfaces/msg/detail/source_header__struct.h"
// Member 'candidates'
#include "team4s_interfaces/msg/detail/lane_candidate__struct.h"
// Member 'selected_candidate_id'
// Member 'metric_reason'
// Member 'calibration_id'
// Member 'metric_frame_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/LaneObservation in the package team4s_interfaces.
typedef struct team4s_interfaces__msg__LaneObservation
{
  team4s_interfaces__msg__SourceHeader meta;
  uint32_t image_width;
  uint32_t image_height;
  team4s_interfaces__msg__LaneCandidate__Sequence candidates;
  /// Metric summary belongs to exactly one candidate selected by task context.
  rosidl_runtime_c__String selected_candidate_id;
  bool offset_m_valid;
  /// Positive right, at the projected reference point; NOT axle lateral error.
  float offset_m;
  rosidl_runtime_c__String metric_reason;
  rosidl_runtime_c__String calibration_id;
  rosidl_runtime_c__String metric_frame_id;
  float metric_reference_x_m;
  float metric_reference_y_m;
} team4s_interfaces__msg__LaneObservation;

// Struct for a sequence of team4s_interfaces__msg__LaneObservation.
typedef struct team4s_interfaces__msg__LaneObservation__Sequence
{
  team4s_interfaces__msg__LaneObservation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} team4s_interfaces__msg__LaneObservation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__LANE_OBSERVATION__STRUCT_H_

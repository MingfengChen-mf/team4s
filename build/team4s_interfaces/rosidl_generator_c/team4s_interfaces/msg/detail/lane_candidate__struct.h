// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from team4s_interfaces:msg/LaneCandidate.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__LANE_CANDIDATE__STRUCT_H_
#define TEAM4S_INTERFACES__MSG__DETAIL__LANE_CANDIDATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'UNKNOWN'.
enum
{
  team4s_interfaces__msg__LaneCandidate__UNKNOWN = 0
};

/// Constant 'FIRST'.
enum
{
  team4s_interfaces__msg__LaneCandidate__FIRST = 1
};

/// Constant 'SECOND'.
enum
{
  team4s_interfaces__msg__LaneCandidate__SECOND = 2
};

// Include directives for member types
// Member 'candidate_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/LaneCandidate in the package team4s_interfaces.
typedef struct team4s_interfaces__msg__LaneCandidate
{
  rosidl_runtime_c__String candidate_id;
  uint8_t route_lane;
  bool is_branch;
  bool left_visible;
  bool right_visible;
  bool center_valid;
  /// lane center x - image center x, original input image pixels, positive right
  float offset_px;
  int32_t reference_y_px;
  /// Positive heading means path points right of image-up. Not a steering angle.
  bool heading_valid;
  float heading_rad;
} team4s_interfaces__msg__LaneCandidate;

// Struct for a sequence of team4s_interfaces__msg__LaneCandidate.
typedef struct team4s_interfaces__msg__LaneCandidate__Sequence
{
  team4s_interfaces__msg__LaneCandidate * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} team4s_interfaces__msg__LaneCandidate__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__LANE_CANDIDATE__STRUCT_H_

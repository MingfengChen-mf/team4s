// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from team4s_interfaces:msg/ConeDetection.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__CONE_DETECTION__STRUCT_H_
#define TEAM4S_INTERFACES__MSG__DETAIL__CONE_DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'COLOR_UNKNOWN'.
enum
{
  team4s_interfaces__msg__ConeDetection__COLOR_UNKNOWN = 0
};

/// Constant 'COLOR_GREEN'.
enum
{
  team4s_interfaces__msg__ConeDetection__COLOR_GREEN = 1
};

/// Constant 'COLOR_RED'.
enum
{
  team4s_interfaces__msg__ConeDetection__COLOR_RED = 2
};

// Include directives for member types
// Member 'candidate_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ConeDetection in the package team4s_interfaces.
typedef struct team4s_interfaces__msg__ConeDetection
{
  /// Frame-local candidate ID, not a stable tracking identifier.
  rosidl_runtime_c__String candidate_id;
  uint8_t color;
  bool bbox_known;
  int32_t bbox_xyxy[4];
  uint32_t color_pixels;
} team4s_interfaces__msg__ConeDetection;

// Struct for a sequence of team4s_interfaces__msg__ConeDetection.
typedef struct team4s_interfaces__msg__ConeDetection__Sequence
{
  team4s_interfaces__msg__ConeDetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} team4s_interfaces__msg__ConeDetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__CONE_DETECTION__STRUCT_H_

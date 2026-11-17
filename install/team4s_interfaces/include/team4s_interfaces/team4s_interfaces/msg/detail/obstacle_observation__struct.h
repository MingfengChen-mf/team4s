// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from team4s_interfaces:msg/ObstacleObservation.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__OBSTACLE_OBSERVATION__STRUCT_H_
#define TEAM4S_INTERFACES__MSG__DETAIL__OBSTACLE_OBSERVATION__STRUCT_H_

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
// Member 'readings'
#include "team4s_interfaces/msg/detail/range_reading__struct.h"

/// Struct defined in msg/ObstacleObservation in the package team4s_interfaces.
typedef struct team4s_interfaces__msg__ObstacleObservation
{
  team4s_interfaces__msg__SourceHeader meta;
  team4s_interfaces__msg__RangeReading__Sequence readings;
  /// Unknown space must not be encoded as clear.
  bool left_clear_known;
  bool left_clear;
  bool right_clear_known;
  bool right_clear;
} team4s_interfaces__msg__ObstacleObservation;

// Struct for a sequence of team4s_interfaces__msg__ObstacleObservation.
typedef struct team4s_interfaces__msg__ObstacleObservation__Sequence
{
  team4s_interfaces__msg__ObstacleObservation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} team4s_interfaces__msg__ObstacleObservation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__OBSTACLE_OBSERVATION__STRUCT_H_

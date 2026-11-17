// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from team4s_interfaces:msg/RangeReading.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__RANGE_READING__STRUCT_H_
#define TEAM4S_INTERFACES__MSG__DETAIL__RANGE_READING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'sensor_id'
// Member 'sensor_frame_id'
// Member 'reason'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/RangeReading in the package team4s_interfaces.
typedef struct team4s_interfaces__msg__RangeReading
{
  rosidl_runtime_c__String sensor_id;
  rosidl_runtime_c__String sensor_frame_id;
  bool valid;
  rosidl_runtime_c__String reason;
  bool checksum_ok;
  uint8_t device_status_raw;
  float distance_m;
  uint32_t signal_strength;
  uint32_t sensor_time_ms;
  /// Bearing relative to base_link only when transform has been verified.
  bool bearing_known;
  float bearing_rad;
} team4s_interfaces__msg__RangeReading;

// Struct for a sequence of team4s_interfaces__msg__RangeReading.
typedef struct team4s_interfaces__msg__RangeReading__Sequence
{
  team4s_interfaces__msg__RangeReading * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} team4s_interfaces__msg__RangeReading__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__RANGE_READING__STRUCT_H_

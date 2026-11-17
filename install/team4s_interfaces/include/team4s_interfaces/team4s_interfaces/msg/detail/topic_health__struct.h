// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from team4s_interfaces:msg/TopicHealth.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__TOPIC_HEALTH__STRUCT_H_
#define TEAM4S_INTERFACES__MSG__DETAIL__TOPIC_HEALTH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'MISSING'.
enum
{
  team4s_interfaces__msg__TopicHealth__MISSING = 0
};

/// Constant 'VALID'.
enum
{
  team4s_interfaces__msg__TopicHealth__VALID = 1
};

/// Constant 'INVALID'.
enum
{
  team4s_interfaces__msg__TopicHealth__INVALID = 2
};

/// Constant 'STALE'.
enum
{
  team4s_interfaces__msg__TopicHealth__STALE = 3
};

// Include directives for member types
// Member 'reason'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TopicHealth in the package team4s_interfaces.
typedef struct team4s_interfaces__msg__TopicHealth
{
  uint8_t state;
  rosidl_runtime_c__String reason;
  bool age_known;
  float age_s;
  /// Must be configured > 0 before control integration; 0 = unconfigured.
  float max_age_s;
} team4s_interfaces__msg__TopicHealth;

// Struct for a sequence of team4s_interfaces__msg__TopicHealth.
typedef struct team4s_interfaces__msg__TopicHealth__Sequence
{
  team4s_interfaces__msg__TopicHealth * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} team4s_interfaces__msg__TopicHealth__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__TOPIC_HEALTH__STRUCT_H_

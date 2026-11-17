// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from team4s_interfaces:msg/SourceHeader.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__SOURCE_HEADER__STRUCT_H_
#define TEAM4S_INTERFACES__MSG__DETAIL__SOURCE_HEADER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'STAMP_UNKNOWN'.
enum
{
  team4s_interfaces__msg__SourceHeader__STAMP_UNKNOWN = 0
};

/// Constant 'STAMP_READ_START'.
enum
{
  team4s_interfaces__msg__SourceHeader__STAMP_READ_START = 1
};

/// Constant 'STAMP_HARDWARE_SYNCED'.
enum
{
  team4s_interfaces__msg__SourceHeader__STAMP_HARDWARE_SYNCED = 2
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'source_id'
// Member 'source_session_id'
// Member 'run_id'
// Member 'reason'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SourceHeader in the package team4s_interfaces.
/**
  * ROS time of acquisition; read-start approximation is explicitly labelled.
 */
typedef struct team4s_interfaces__msg__SourceHeader
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String source_id;
  rosidl_runtime_c__String source_session_id;
  rosidl_runtime_c__String run_id;
  uint64_t sequence;
  uint8_t stamp_source;
  bool valid;
  rosidl_runtime_c__String reason;
} team4s_interfaces__msg__SourceHeader;

// Struct for a sequence of team4s_interfaces__msg__SourceHeader.
typedef struct team4s_interfaces__msg__SourceHeader__Sequence
{
  team4s_interfaces__msg__SourceHeader * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} team4s_interfaces__msg__SourceHeader__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__SOURCE_HEADER__STRUCT_H_

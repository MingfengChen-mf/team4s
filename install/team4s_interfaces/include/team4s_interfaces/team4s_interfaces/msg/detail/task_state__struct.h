// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from team4s_interfaces:msg/TaskState.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__TASK_STATE__STRUCT_H_
#define TEAM4S_INTERFACES__MSG__DETAIL__TASK_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'TASK_NONE'.
enum
{
  team4s_interfaces__msg__TaskState__TASK_NONE = 0
};

/// Constant 'TASK_LAP'.
enum
{
  team4s_interfaces__msg__TaskState__TASK_LAP = 1
};

/// Constant 'TASK_STRAIGHT'.
enum
{
  team4s_interfaces__msg__TaskState__TASK_STRAIGHT = 2
};

/// Constant 'LANE_UNKNOWN'.
enum
{
  team4s_interfaces__msg__TaskState__LANE_UNKNOWN = 0
};

/// Constant 'LANE_FIRST'.
enum
{
  team4s_interfaces__msg__TaskState__LANE_FIRST = 1
};

/// Constant 'LANE_SECOND'.
enum
{
  team4s_interfaces__msg__TaskState__LANE_SECOND = 2
};

/// Constant 'MODE_IDLE'.
enum
{
  team4s_interfaces__msg__TaskState__MODE_IDLE = 0
};

/// Constant 'MODE_AUTO'.
enum
{
  team4s_interfaces__msg__TaskState__MODE_AUTO = 1
};

/// Constant 'MODE_MANUAL'.
enum
{
  team4s_interfaces__msg__TaskState__MODE_MANUAL = 2
};

/// Constant 'MODE_PAUSED'.
enum
{
  team4s_interfaces__msg__TaskState__MODE_PAUSED = 3
};

/// Constant 'MODE_FINISHED'.
enum
{
  team4s_interfaces__msg__TaskState__MODE_FINISHED = 4
};

/// Constant 'MODE_FAULT'.
enum
{
  team4s_interfaces__msg__TaskState__MODE_FAULT = 5
};

/// Constant 'PHASE_IDLE'.
enum
{
  team4s_interfaces__msg__TaskState__PHASE_IDLE = 0
};

/// Constant 'PHASE_WAIT_START'.
enum
{
  team4s_interfaces__msg__TaskState__PHASE_WAIT_START = 1
};

/// Constant 'PHASE_FOLLOW_LAP'.
enum
{
  team4s_interfaces__msg__TaskState__PHASE_FOLLOW_LAP = 2
};

/// Constant 'PHASE_FOLLOW_FIRST'.
enum
{
  team4s_interfaces__msg__TaskState__PHASE_FOLLOW_FIRST = 3
};

/// Constant 'PHASE_AVOIDING'.
enum
{
  team4s_interfaces__msg__TaskState__PHASE_AVOIDING = 4
};

/// Constant 'PHASE_FOLLOW_SECOND'.
enum
{
  team4s_interfaces__msg__TaskState__PHASE_FOLLOW_SECOND = 5
};

/// Constant 'PHASE_ZEBRA_SLOW'.
enum
{
  team4s_interfaces__msg__TaskState__PHASE_ZEBRA_SLOW = 6
};

/// Constant 'PHASE_FINISH_APPROACH'.
enum
{
  team4s_interfaces__msg__TaskState__PHASE_FINISH_APPROACH = 7
};

/// Constant 'PHASE_STOPPED'.
enum
{
  team4s_interfaces__msg__TaskState__PHASE_STOPPED = 8
};

/// Constant 'PHASE_FAULT'.
enum
{
  team4s_interfaces__msg__TaskState__PHASE_FAULT = 9
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'run_id'
// Member 'controller_session_id'
// Member 'reason'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TaskState in the package team4s_interfaces.
typedef struct team4s_interfaces__msg__TaskState
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String run_id;
  rosidl_runtime_c__String controller_session_id;
  uint64_t sequence;
  uint8_t task_id;
  uint8_t phase;
  uint8_t target_lane;
  uint8_t control_mode;
  bool lap_complete;
  rosidl_runtime_c__String reason;
} team4s_interfaces__msg__TaskState;

// Struct for a sequence of team4s_interfaces__msg__TaskState.
typedef struct team4s_interfaces__msg__TaskState__Sequence
{
  team4s_interfaces__msg__TaskState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} team4s_interfaces__msg__TaskState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__TASK_STATE__STRUCT_H_

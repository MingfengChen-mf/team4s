// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from team4s_interfaces:msg/PerceptionSnapshot.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__PERCEPTION_SNAPSHOT__STRUCT_H_
#define TEAM4S_INTERFACES__MSG__DETAIL__PERCEPTION_SNAPSHOT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'aggregator_session_id'
// Member 'run_id'
#include "rosidl_runtime_c/string.h"
// Member 'lane'
#include "team4s_interfaces/msg/detail/lane_observation__struct.h"
// Member 'lane_health'
// Member 'obstacles_health'
// Member 'scene_health'
#include "team4s_interfaces/msg/detail/topic_health__struct.h"
// Member 'obstacles'
#include "team4s_interfaces/msg/detail/obstacle_observation__struct.h"
// Member 'scene'
#include "team4s_interfaces/msg/detail/scene_observation__struct.h"

/// Struct defined in msg/PerceptionSnapshot in the package team4s_interfaces.
/**
  * Aggregate time, not the acquisition time of all children.
 */
typedef struct team4s_interfaces__msg__PerceptionSnapshot
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String aggregator_session_id;
  rosidl_runtime_c__String run_id;
  uint64_t sequence;
  team4s_interfaces__msg__LaneObservation lane;
  team4s_interfaces__msg__TopicHealth lane_health;
  team4s_interfaces__msg__ObstacleObservation obstacles;
  team4s_interfaces__msg__TopicHealth obstacles_health;
  team4s_interfaces__msg__SceneObservation scene;
  team4s_interfaces__msg__TopicHealth scene_health;
} team4s_interfaces__msg__PerceptionSnapshot;

// Struct for a sequence of team4s_interfaces__msg__PerceptionSnapshot.
typedef struct team4s_interfaces__msg__PerceptionSnapshot__Sequence
{
  team4s_interfaces__msg__PerceptionSnapshot * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} team4s_interfaces__msg__PerceptionSnapshot__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__PERCEPTION_SNAPSHOT__STRUCT_H_

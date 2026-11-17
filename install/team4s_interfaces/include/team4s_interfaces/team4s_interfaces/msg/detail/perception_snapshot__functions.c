// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from team4s_interfaces:msg/PerceptionSnapshot.idl
// generated code does not contain a copyright notice
#include "team4s_interfaces/msg/detail/perception_snapshot__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `aggregator_session_id`
// Member `run_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `lane`
#include "team4s_interfaces/msg/detail/lane_observation__functions.h"
// Member `lane_health`
// Member `obstacles_health`
// Member `scene_health`
#include "team4s_interfaces/msg/detail/topic_health__functions.h"
// Member `obstacles`
#include "team4s_interfaces/msg/detail/obstacle_observation__functions.h"
// Member `scene`
#include "team4s_interfaces/msg/detail/scene_observation__functions.h"

bool
team4s_interfaces__msg__PerceptionSnapshot__init(team4s_interfaces__msg__PerceptionSnapshot * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    team4s_interfaces__msg__PerceptionSnapshot__fini(msg);
    return false;
  }
  // aggregator_session_id
  if (!rosidl_runtime_c__String__init(&msg->aggregator_session_id)) {
    team4s_interfaces__msg__PerceptionSnapshot__fini(msg);
    return false;
  }
  // run_id
  if (!rosidl_runtime_c__String__init(&msg->run_id)) {
    team4s_interfaces__msg__PerceptionSnapshot__fini(msg);
    return false;
  }
  // sequence
  // lane
  if (!team4s_interfaces__msg__LaneObservation__init(&msg->lane)) {
    team4s_interfaces__msg__PerceptionSnapshot__fini(msg);
    return false;
  }
  // lane_health
  if (!team4s_interfaces__msg__TopicHealth__init(&msg->lane_health)) {
    team4s_interfaces__msg__PerceptionSnapshot__fini(msg);
    return false;
  }
  // obstacles
  if (!team4s_interfaces__msg__ObstacleObservation__init(&msg->obstacles)) {
    team4s_interfaces__msg__PerceptionSnapshot__fini(msg);
    return false;
  }
  // obstacles_health
  if (!team4s_interfaces__msg__TopicHealth__init(&msg->obstacles_health)) {
    team4s_interfaces__msg__PerceptionSnapshot__fini(msg);
    return false;
  }
  // scene
  if (!team4s_interfaces__msg__SceneObservation__init(&msg->scene)) {
    team4s_interfaces__msg__PerceptionSnapshot__fini(msg);
    return false;
  }
  // scene_health
  if (!team4s_interfaces__msg__TopicHealth__init(&msg->scene_health)) {
    team4s_interfaces__msg__PerceptionSnapshot__fini(msg);
    return false;
  }
  return true;
}

void
team4s_interfaces__msg__PerceptionSnapshot__fini(team4s_interfaces__msg__PerceptionSnapshot * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // aggregator_session_id
  rosidl_runtime_c__String__fini(&msg->aggregator_session_id);
  // run_id
  rosidl_runtime_c__String__fini(&msg->run_id);
  // sequence
  // lane
  team4s_interfaces__msg__LaneObservation__fini(&msg->lane);
  // lane_health
  team4s_interfaces__msg__TopicHealth__fini(&msg->lane_health);
  // obstacles
  team4s_interfaces__msg__ObstacleObservation__fini(&msg->obstacles);
  // obstacles_health
  team4s_interfaces__msg__TopicHealth__fini(&msg->obstacles_health);
  // scene
  team4s_interfaces__msg__SceneObservation__fini(&msg->scene);
  // scene_health
  team4s_interfaces__msg__TopicHealth__fini(&msg->scene_health);
}

bool
team4s_interfaces__msg__PerceptionSnapshot__are_equal(const team4s_interfaces__msg__PerceptionSnapshot * lhs, const team4s_interfaces__msg__PerceptionSnapshot * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // aggregator_session_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->aggregator_session_id), &(rhs->aggregator_session_id)))
  {
    return false;
  }
  // run_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->run_id), &(rhs->run_id)))
  {
    return false;
  }
  // sequence
  if (lhs->sequence != rhs->sequence) {
    return false;
  }
  // lane
  if (!team4s_interfaces__msg__LaneObservation__are_equal(
      &(lhs->lane), &(rhs->lane)))
  {
    return false;
  }
  // lane_health
  if (!team4s_interfaces__msg__TopicHealth__are_equal(
      &(lhs->lane_health), &(rhs->lane_health)))
  {
    return false;
  }
  // obstacles
  if (!team4s_interfaces__msg__ObstacleObservation__are_equal(
      &(lhs->obstacles), &(rhs->obstacles)))
  {
    return false;
  }
  // obstacles_health
  if (!team4s_interfaces__msg__TopicHealth__are_equal(
      &(lhs->obstacles_health), &(rhs->obstacles_health)))
  {
    return false;
  }
  // scene
  if (!team4s_interfaces__msg__SceneObservation__are_equal(
      &(lhs->scene), &(rhs->scene)))
  {
    return false;
  }
  // scene_health
  if (!team4s_interfaces__msg__TopicHealth__are_equal(
      &(lhs->scene_health), &(rhs->scene_health)))
  {
    return false;
  }
  return true;
}

bool
team4s_interfaces__msg__PerceptionSnapshot__copy(
  const team4s_interfaces__msg__PerceptionSnapshot * input,
  team4s_interfaces__msg__PerceptionSnapshot * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // aggregator_session_id
  if (!rosidl_runtime_c__String__copy(
      &(input->aggregator_session_id), &(output->aggregator_session_id)))
  {
    return false;
  }
  // run_id
  if (!rosidl_runtime_c__String__copy(
      &(input->run_id), &(output->run_id)))
  {
    return false;
  }
  // sequence
  output->sequence = input->sequence;
  // lane
  if (!team4s_interfaces__msg__LaneObservation__copy(
      &(input->lane), &(output->lane)))
  {
    return false;
  }
  // lane_health
  if (!team4s_interfaces__msg__TopicHealth__copy(
      &(input->lane_health), &(output->lane_health)))
  {
    return false;
  }
  // obstacles
  if (!team4s_interfaces__msg__ObstacleObservation__copy(
      &(input->obstacles), &(output->obstacles)))
  {
    return false;
  }
  // obstacles_health
  if (!team4s_interfaces__msg__TopicHealth__copy(
      &(input->obstacles_health), &(output->obstacles_health)))
  {
    return false;
  }
  // scene
  if (!team4s_interfaces__msg__SceneObservation__copy(
      &(input->scene), &(output->scene)))
  {
    return false;
  }
  // scene_health
  if (!team4s_interfaces__msg__TopicHealth__copy(
      &(input->scene_health), &(output->scene_health)))
  {
    return false;
  }
  return true;
}

team4s_interfaces__msg__PerceptionSnapshot *
team4s_interfaces__msg__PerceptionSnapshot__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__PerceptionSnapshot * msg = (team4s_interfaces__msg__PerceptionSnapshot *)allocator.allocate(sizeof(team4s_interfaces__msg__PerceptionSnapshot), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(team4s_interfaces__msg__PerceptionSnapshot));
  bool success = team4s_interfaces__msg__PerceptionSnapshot__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
team4s_interfaces__msg__PerceptionSnapshot__destroy(team4s_interfaces__msg__PerceptionSnapshot * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    team4s_interfaces__msg__PerceptionSnapshot__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
team4s_interfaces__msg__PerceptionSnapshot__Sequence__init(team4s_interfaces__msg__PerceptionSnapshot__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__PerceptionSnapshot * data = NULL;

  if (size) {
    data = (team4s_interfaces__msg__PerceptionSnapshot *)allocator.zero_allocate(size, sizeof(team4s_interfaces__msg__PerceptionSnapshot), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = team4s_interfaces__msg__PerceptionSnapshot__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        team4s_interfaces__msg__PerceptionSnapshot__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
team4s_interfaces__msg__PerceptionSnapshot__Sequence__fini(team4s_interfaces__msg__PerceptionSnapshot__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      team4s_interfaces__msg__PerceptionSnapshot__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

team4s_interfaces__msg__PerceptionSnapshot__Sequence *
team4s_interfaces__msg__PerceptionSnapshot__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__PerceptionSnapshot__Sequence * array = (team4s_interfaces__msg__PerceptionSnapshot__Sequence *)allocator.allocate(sizeof(team4s_interfaces__msg__PerceptionSnapshot__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = team4s_interfaces__msg__PerceptionSnapshot__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
team4s_interfaces__msg__PerceptionSnapshot__Sequence__destroy(team4s_interfaces__msg__PerceptionSnapshot__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    team4s_interfaces__msg__PerceptionSnapshot__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
team4s_interfaces__msg__PerceptionSnapshot__Sequence__are_equal(const team4s_interfaces__msg__PerceptionSnapshot__Sequence * lhs, const team4s_interfaces__msg__PerceptionSnapshot__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!team4s_interfaces__msg__PerceptionSnapshot__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
team4s_interfaces__msg__PerceptionSnapshot__Sequence__copy(
  const team4s_interfaces__msg__PerceptionSnapshot__Sequence * input,
  team4s_interfaces__msg__PerceptionSnapshot__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(team4s_interfaces__msg__PerceptionSnapshot);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    team4s_interfaces__msg__PerceptionSnapshot * data =
      (team4s_interfaces__msg__PerceptionSnapshot *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!team4s_interfaces__msg__PerceptionSnapshot__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          team4s_interfaces__msg__PerceptionSnapshot__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!team4s_interfaces__msg__PerceptionSnapshot__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

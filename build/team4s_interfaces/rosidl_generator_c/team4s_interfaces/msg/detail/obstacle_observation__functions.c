// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from team4s_interfaces:msg/ObstacleObservation.idl
// generated code does not contain a copyright notice
#include "team4s_interfaces/msg/detail/obstacle_observation__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `meta`
#include "team4s_interfaces/msg/detail/source_header__functions.h"
// Member `readings`
#include "team4s_interfaces/msg/detail/range_reading__functions.h"

bool
team4s_interfaces__msg__ObstacleObservation__init(team4s_interfaces__msg__ObstacleObservation * msg)
{
  if (!msg) {
    return false;
  }
  // meta
  if (!team4s_interfaces__msg__SourceHeader__init(&msg->meta)) {
    team4s_interfaces__msg__ObstacleObservation__fini(msg);
    return false;
  }
  // readings
  if (!team4s_interfaces__msg__RangeReading__Sequence__init(&msg->readings, 0)) {
    team4s_interfaces__msg__ObstacleObservation__fini(msg);
    return false;
  }
  // left_clear_known
  // left_clear
  // right_clear_known
  // right_clear
  return true;
}

void
team4s_interfaces__msg__ObstacleObservation__fini(team4s_interfaces__msg__ObstacleObservation * msg)
{
  if (!msg) {
    return;
  }
  // meta
  team4s_interfaces__msg__SourceHeader__fini(&msg->meta);
  // readings
  team4s_interfaces__msg__RangeReading__Sequence__fini(&msg->readings);
  // left_clear_known
  // left_clear
  // right_clear_known
  // right_clear
}

bool
team4s_interfaces__msg__ObstacleObservation__are_equal(const team4s_interfaces__msg__ObstacleObservation * lhs, const team4s_interfaces__msg__ObstacleObservation * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // meta
  if (!team4s_interfaces__msg__SourceHeader__are_equal(
      &(lhs->meta), &(rhs->meta)))
  {
    return false;
  }
  // readings
  if (!team4s_interfaces__msg__RangeReading__Sequence__are_equal(
      &(lhs->readings), &(rhs->readings)))
  {
    return false;
  }
  // left_clear_known
  if (lhs->left_clear_known != rhs->left_clear_known) {
    return false;
  }
  // left_clear
  if (lhs->left_clear != rhs->left_clear) {
    return false;
  }
  // right_clear_known
  if (lhs->right_clear_known != rhs->right_clear_known) {
    return false;
  }
  // right_clear
  if (lhs->right_clear != rhs->right_clear) {
    return false;
  }
  return true;
}

bool
team4s_interfaces__msg__ObstacleObservation__copy(
  const team4s_interfaces__msg__ObstacleObservation * input,
  team4s_interfaces__msg__ObstacleObservation * output)
{
  if (!input || !output) {
    return false;
  }
  // meta
  if (!team4s_interfaces__msg__SourceHeader__copy(
      &(input->meta), &(output->meta)))
  {
    return false;
  }
  // readings
  if (!team4s_interfaces__msg__RangeReading__Sequence__copy(
      &(input->readings), &(output->readings)))
  {
    return false;
  }
  // left_clear_known
  output->left_clear_known = input->left_clear_known;
  // left_clear
  output->left_clear = input->left_clear;
  // right_clear_known
  output->right_clear_known = input->right_clear_known;
  // right_clear
  output->right_clear = input->right_clear;
  return true;
}

team4s_interfaces__msg__ObstacleObservation *
team4s_interfaces__msg__ObstacleObservation__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__ObstacleObservation * msg = (team4s_interfaces__msg__ObstacleObservation *)allocator.allocate(sizeof(team4s_interfaces__msg__ObstacleObservation), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(team4s_interfaces__msg__ObstacleObservation));
  bool success = team4s_interfaces__msg__ObstacleObservation__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
team4s_interfaces__msg__ObstacleObservation__destroy(team4s_interfaces__msg__ObstacleObservation * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    team4s_interfaces__msg__ObstacleObservation__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
team4s_interfaces__msg__ObstacleObservation__Sequence__init(team4s_interfaces__msg__ObstacleObservation__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__ObstacleObservation * data = NULL;

  if (size) {
    data = (team4s_interfaces__msg__ObstacleObservation *)allocator.zero_allocate(size, sizeof(team4s_interfaces__msg__ObstacleObservation), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = team4s_interfaces__msg__ObstacleObservation__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        team4s_interfaces__msg__ObstacleObservation__fini(&data[i - 1]);
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
team4s_interfaces__msg__ObstacleObservation__Sequence__fini(team4s_interfaces__msg__ObstacleObservation__Sequence * array)
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
      team4s_interfaces__msg__ObstacleObservation__fini(&array->data[i]);
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

team4s_interfaces__msg__ObstacleObservation__Sequence *
team4s_interfaces__msg__ObstacleObservation__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__ObstacleObservation__Sequence * array = (team4s_interfaces__msg__ObstacleObservation__Sequence *)allocator.allocate(sizeof(team4s_interfaces__msg__ObstacleObservation__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = team4s_interfaces__msg__ObstacleObservation__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
team4s_interfaces__msg__ObstacleObservation__Sequence__destroy(team4s_interfaces__msg__ObstacleObservation__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    team4s_interfaces__msg__ObstacleObservation__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
team4s_interfaces__msg__ObstacleObservation__Sequence__are_equal(const team4s_interfaces__msg__ObstacleObservation__Sequence * lhs, const team4s_interfaces__msg__ObstacleObservation__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!team4s_interfaces__msg__ObstacleObservation__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
team4s_interfaces__msg__ObstacleObservation__Sequence__copy(
  const team4s_interfaces__msg__ObstacleObservation__Sequence * input,
  team4s_interfaces__msg__ObstacleObservation__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(team4s_interfaces__msg__ObstacleObservation);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    team4s_interfaces__msg__ObstacleObservation * data =
      (team4s_interfaces__msg__ObstacleObservation *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!team4s_interfaces__msg__ObstacleObservation__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          team4s_interfaces__msg__ObstacleObservation__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!team4s_interfaces__msg__ObstacleObservation__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

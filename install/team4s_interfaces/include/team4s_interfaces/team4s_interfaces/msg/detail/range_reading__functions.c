// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from team4s_interfaces:msg/RangeReading.idl
// generated code does not contain a copyright notice
#include "team4s_interfaces/msg/detail/range_reading__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `sensor_id`
// Member `sensor_frame_id`
// Member `reason`
#include "rosidl_runtime_c/string_functions.h"

bool
team4s_interfaces__msg__RangeReading__init(team4s_interfaces__msg__RangeReading * msg)
{
  if (!msg) {
    return false;
  }
  // sensor_id
  if (!rosidl_runtime_c__String__init(&msg->sensor_id)) {
    team4s_interfaces__msg__RangeReading__fini(msg);
    return false;
  }
  // sensor_frame_id
  if (!rosidl_runtime_c__String__init(&msg->sensor_frame_id)) {
    team4s_interfaces__msg__RangeReading__fini(msg);
    return false;
  }
  // valid
  // reason
  if (!rosidl_runtime_c__String__init(&msg->reason)) {
    team4s_interfaces__msg__RangeReading__fini(msg);
    return false;
  }
  // checksum_ok
  // device_status_raw
  // distance_m
  // signal_strength
  // sensor_time_ms
  // bearing_known
  // bearing_rad
  return true;
}

void
team4s_interfaces__msg__RangeReading__fini(team4s_interfaces__msg__RangeReading * msg)
{
  if (!msg) {
    return;
  }
  // sensor_id
  rosidl_runtime_c__String__fini(&msg->sensor_id);
  // sensor_frame_id
  rosidl_runtime_c__String__fini(&msg->sensor_frame_id);
  // valid
  // reason
  rosidl_runtime_c__String__fini(&msg->reason);
  // checksum_ok
  // device_status_raw
  // distance_m
  // signal_strength
  // sensor_time_ms
  // bearing_known
  // bearing_rad
}

bool
team4s_interfaces__msg__RangeReading__are_equal(const team4s_interfaces__msg__RangeReading * lhs, const team4s_interfaces__msg__RangeReading * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // sensor_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->sensor_id), &(rhs->sensor_id)))
  {
    return false;
  }
  // sensor_frame_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->sensor_frame_id), &(rhs->sensor_frame_id)))
  {
    return false;
  }
  // valid
  if (lhs->valid != rhs->valid) {
    return false;
  }
  // reason
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->reason), &(rhs->reason)))
  {
    return false;
  }
  // checksum_ok
  if (lhs->checksum_ok != rhs->checksum_ok) {
    return false;
  }
  // device_status_raw
  if (lhs->device_status_raw != rhs->device_status_raw) {
    return false;
  }
  // distance_m
  if (lhs->distance_m != rhs->distance_m) {
    return false;
  }
  // signal_strength
  if (lhs->signal_strength != rhs->signal_strength) {
    return false;
  }
  // sensor_time_ms
  if (lhs->sensor_time_ms != rhs->sensor_time_ms) {
    return false;
  }
  // bearing_known
  if (lhs->bearing_known != rhs->bearing_known) {
    return false;
  }
  // bearing_rad
  if (lhs->bearing_rad != rhs->bearing_rad) {
    return false;
  }
  return true;
}

bool
team4s_interfaces__msg__RangeReading__copy(
  const team4s_interfaces__msg__RangeReading * input,
  team4s_interfaces__msg__RangeReading * output)
{
  if (!input || !output) {
    return false;
  }
  // sensor_id
  if (!rosidl_runtime_c__String__copy(
      &(input->sensor_id), &(output->sensor_id)))
  {
    return false;
  }
  // sensor_frame_id
  if (!rosidl_runtime_c__String__copy(
      &(input->sensor_frame_id), &(output->sensor_frame_id)))
  {
    return false;
  }
  // valid
  output->valid = input->valid;
  // reason
  if (!rosidl_runtime_c__String__copy(
      &(input->reason), &(output->reason)))
  {
    return false;
  }
  // checksum_ok
  output->checksum_ok = input->checksum_ok;
  // device_status_raw
  output->device_status_raw = input->device_status_raw;
  // distance_m
  output->distance_m = input->distance_m;
  // signal_strength
  output->signal_strength = input->signal_strength;
  // sensor_time_ms
  output->sensor_time_ms = input->sensor_time_ms;
  // bearing_known
  output->bearing_known = input->bearing_known;
  // bearing_rad
  output->bearing_rad = input->bearing_rad;
  return true;
}

team4s_interfaces__msg__RangeReading *
team4s_interfaces__msg__RangeReading__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__RangeReading * msg = (team4s_interfaces__msg__RangeReading *)allocator.allocate(sizeof(team4s_interfaces__msg__RangeReading), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(team4s_interfaces__msg__RangeReading));
  bool success = team4s_interfaces__msg__RangeReading__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
team4s_interfaces__msg__RangeReading__destroy(team4s_interfaces__msg__RangeReading * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    team4s_interfaces__msg__RangeReading__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
team4s_interfaces__msg__RangeReading__Sequence__init(team4s_interfaces__msg__RangeReading__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__RangeReading * data = NULL;

  if (size) {
    data = (team4s_interfaces__msg__RangeReading *)allocator.zero_allocate(size, sizeof(team4s_interfaces__msg__RangeReading), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = team4s_interfaces__msg__RangeReading__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        team4s_interfaces__msg__RangeReading__fini(&data[i - 1]);
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
team4s_interfaces__msg__RangeReading__Sequence__fini(team4s_interfaces__msg__RangeReading__Sequence * array)
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
      team4s_interfaces__msg__RangeReading__fini(&array->data[i]);
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

team4s_interfaces__msg__RangeReading__Sequence *
team4s_interfaces__msg__RangeReading__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__RangeReading__Sequence * array = (team4s_interfaces__msg__RangeReading__Sequence *)allocator.allocate(sizeof(team4s_interfaces__msg__RangeReading__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = team4s_interfaces__msg__RangeReading__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
team4s_interfaces__msg__RangeReading__Sequence__destroy(team4s_interfaces__msg__RangeReading__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    team4s_interfaces__msg__RangeReading__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
team4s_interfaces__msg__RangeReading__Sequence__are_equal(const team4s_interfaces__msg__RangeReading__Sequence * lhs, const team4s_interfaces__msg__RangeReading__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!team4s_interfaces__msg__RangeReading__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
team4s_interfaces__msg__RangeReading__Sequence__copy(
  const team4s_interfaces__msg__RangeReading__Sequence * input,
  team4s_interfaces__msg__RangeReading__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(team4s_interfaces__msg__RangeReading);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    team4s_interfaces__msg__RangeReading * data =
      (team4s_interfaces__msg__RangeReading *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!team4s_interfaces__msg__RangeReading__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          team4s_interfaces__msg__RangeReading__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!team4s_interfaces__msg__RangeReading__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from team4s_interfaces:msg/ConeDetection.idl
// generated code does not contain a copyright notice
#include "team4s_interfaces/msg/detail/cone_detection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `candidate_id`
#include "rosidl_runtime_c/string_functions.h"

bool
team4s_interfaces__msg__ConeDetection__init(team4s_interfaces__msg__ConeDetection * msg)
{
  if (!msg) {
    return false;
  }
  // candidate_id
  if (!rosidl_runtime_c__String__init(&msg->candidate_id)) {
    team4s_interfaces__msg__ConeDetection__fini(msg);
    return false;
  }
  // color
  // bbox_known
  // bbox_xyxy
  // color_pixels
  return true;
}

void
team4s_interfaces__msg__ConeDetection__fini(team4s_interfaces__msg__ConeDetection * msg)
{
  if (!msg) {
    return;
  }
  // candidate_id
  rosidl_runtime_c__String__fini(&msg->candidate_id);
  // color
  // bbox_known
  // bbox_xyxy
  // color_pixels
}

bool
team4s_interfaces__msg__ConeDetection__are_equal(const team4s_interfaces__msg__ConeDetection * lhs, const team4s_interfaces__msg__ConeDetection * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // candidate_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->candidate_id), &(rhs->candidate_id)))
  {
    return false;
  }
  // color
  if (lhs->color != rhs->color) {
    return false;
  }
  // bbox_known
  if (lhs->bbox_known != rhs->bbox_known) {
    return false;
  }
  // bbox_xyxy
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->bbox_xyxy[i] != rhs->bbox_xyxy[i]) {
      return false;
    }
  }
  // color_pixels
  if (lhs->color_pixels != rhs->color_pixels) {
    return false;
  }
  return true;
}

bool
team4s_interfaces__msg__ConeDetection__copy(
  const team4s_interfaces__msg__ConeDetection * input,
  team4s_interfaces__msg__ConeDetection * output)
{
  if (!input || !output) {
    return false;
  }
  // candidate_id
  if (!rosidl_runtime_c__String__copy(
      &(input->candidate_id), &(output->candidate_id)))
  {
    return false;
  }
  // color
  output->color = input->color;
  // bbox_known
  output->bbox_known = input->bbox_known;
  // bbox_xyxy
  for (size_t i = 0; i < 4; ++i) {
    output->bbox_xyxy[i] = input->bbox_xyxy[i];
  }
  // color_pixels
  output->color_pixels = input->color_pixels;
  return true;
}

team4s_interfaces__msg__ConeDetection *
team4s_interfaces__msg__ConeDetection__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__ConeDetection * msg = (team4s_interfaces__msg__ConeDetection *)allocator.allocate(sizeof(team4s_interfaces__msg__ConeDetection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(team4s_interfaces__msg__ConeDetection));
  bool success = team4s_interfaces__msg__ConeDetection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
team4s_interfaces__msg__ConeDetection__destroy(team4s_interfaces__msg__ConeDetection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    team4s_interfaces__msg__ConeDetection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
team4s_interfaces__msg__ConeDetection__Sequence__init(team4s_interfaces__msg__ConeDetection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__ConeDetection * data = NULL;

  if (size) {
    data = (team4s_interfaces__msg__ConeDetection *)allocator.zero_allocate(size, sizeof(team4s_interfaces__msg__ConeDetection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = team4s_interfaces__msg__ConeDetection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        team4s_interfaces__msg__ConeDetection__fini(&data[i - 1]);
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
team4s_interfaces__msg__ConeDetection__Sequence__fini(team4s_interfaces__msg__ConeDetection__Sequence * array)
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
      team4s_interfaces__msg__ConeDetection__fini(&array->data[i]);
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

team4s_interfaces__msg__ConeDetection__Sequence *
team4s_interfaces__msg__ConeDetection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__ConeDetection__Sequence * array = (team4s_interfaces__msg__ConeDetection__Sequence *)allocator.allocate(sizeof(team4s_interfaces__msg__ConeDetection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = team4s_interfaces__msg__ConeDetection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
team4s_interfaces__msg__ConeDetection__Sequence__destroy(team4s_interfaces__msg__ConeDetection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    team4s_interfaces__msg__ConeDetection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
team4s_interfaces__msg__ConeDetection__Sequence__are_equal(const team4s_interfaces__msg__ConeDetection__Sequence * lhs, const team4s_interfaces__msg__ConeDetection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!team4s_interfaces__msg__ConeDetection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
team4s_interfaces__msg__ConeDetection__Sequence__copy(
  const team4s_interfaces__msg__ConeDetection__Sequence * input,
  team4s_interfaces__msg__ConeDetection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(team4s_interfaces__msg__ConeDetection);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    team4s_interfaces__msg__ConeDetection * data =
      (team4s_interfaces__msg__ConeDetection *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!team4s_interfaces__msg__ConeDetection__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          team4s_interfaces__msg__ConeDetection__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!team4s_interfaces__msg__ConeDetection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

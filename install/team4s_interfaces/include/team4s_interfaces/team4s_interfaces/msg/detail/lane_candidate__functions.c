// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from team4s_interfaces:msg/LaneCandidate.idl
// generated code does not contain a copyright notice
#include "team4s_interfaces/msg/detail/lane_candidate__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `candidate_id`
#include "rosidl_runtime_c/string_functions.h"

bool
team4s_interfaces__msg__LaneCandidate__init(team4s_interfaces__msg__LaneCandidate * msg)
{
  if (!msg) {
    return false;
  }
  // candidate_id
  if (!rosidl_runtime_c__String__init(&msg->candidate_id)) {
    team4s_interfaces__msg__LaneCandidate__fini(msg);
    return false;
  }
  // route_lane
  // is_branch
  // left_visible
  // right_visible
  // center_valid
  // offset_px
  // reference_y_px
  // heading_valid
  // heading_rad
  return true;
}

void
team4s_interfaces__msg__LaneCandidate__fini(team4s_interfaces__msg__LaneCandidate * msg)
{
  if (!msg) {
    return;
  }
  // candidate_id
  rosidl_runtime_c__String__fini(&msg->candidate_id);
  // route_lane
  // is_branch
  // left_visible
  // right_visible
  // center_valid
  // offset_px
  // reference_y_px
  // heading_valid
  // heading_rad
}

bool
team4s_interfaces__msg__LaneCandidate__are_equal(const team4s_interfaces__msg__LaneCandidate * lhs, const team4s_interfaces__msg__LaneCandidate * rhs)
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
  // route_lane
  if (lhs->route_lane != rhs->route_lane) {
    return false;
  }
  // is_branch
  if (lhs->is_branch != rhs->is_branch) {
    return false;
  }
  // left_visible
  if (lhs->left_visible != rhs->left_visible) {
    return false;
  }
  // right_visible
  if (lhs->right_visible != rhs->right_visible) {
    return false;
  }
  // center_valid
  if (lhs->center_valid != rhs->center_valid) {
    return false;
  }
  // offset_px
  if (lhs->offset_px != rhs->offset_px) {
    return false;
  }
  // reference_y_px
  if (lhs->reference_y_px != rhs->reference_y_px) {
    return false;
  }
  // heading_valid
  if (lhs->heading_valid != rhs->heading_valid) {
    return false;
  }
  // heading_rad
  if (lhs->heading_rad != rhs->heading_rad) {
    return false;
  }
  return true;
}

bool
team4s_interfaces__msg__LaneCandidate__copy(
  const team4s_interfaces__msg__LaneCandidate * input,
  team4s_interfaces__msg__LaneCandidate * output)
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
  // route_lane
  output->route_lane = input->route_lane;
  // is_branch
  output->is_branch = input->is_branch;
  // left_visible
  output->left_visible = input->left_visible;
  // right_visible
  output->right_visible = input->right_visible;
  // center_valid
  output->center_valid = input->center_valid;
  // offset_px
  output->offset_px = input->offset_px;
  // reference_y_px
  output->reference_y_px = input->reference_y_px;
  // heading_valid
  output->heading_valid = input->heading_valid;
  // heading_rad
  output->heading_rad = input->heading_rad;
  return true;
}

team4s_interfaces__msg__LaneCandidate *
team4s_interfaces__msg__LaneCandidate__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__LaneCandidate * msg = (team4s_interfaces__msg__LaneCandidate *)allocator.allocate(sizeof(team4s_interfaces__msg__LaneCandidate), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(team4s_interfaces__msg__LaneCandidate));
  bool success = team4s_interfaces__msg__LaneCandidate__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
team4s_interfaces__msg__LaneCandidate__destroy(team4s_interfaces__msg__LaneCandidate * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    team4s_interfaces__msg__LaneCandidate__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
team4s_interfaces__msg__LaneCandidate__Sequence__init(team4s_interfaces__msg__LaneCandidate__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__LaneCandidate * data = NULL;

  if (size) {
    data = (team4s_interfaces__msg__LaneCandidate *)allocator.zero_allocate(size, sizeof(team4s_interfaces__msg__LaneCandidate), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = team4s_interfaces__msg__LaneCandidate__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        team4s_interfaces__msg__LaneCandidate__fini(&data[i - 1]);
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
team4s_interfaces__msg__LaneCandidate__Sequence__fini(team4s_interfaces__msg__LaneCandidate__Sequence * array)
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
      team4s_interfaces__msg__LaneCandidate__fini(&array->data[i]);
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

team4s_interfaces__msg__LaneCandidate__Sequence *
team4s_interfaces__msg__LaneCandidate__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__LaneCandidate__Sequence * array = (team4s_interfaces__msg__LaneCandidate__Sequence *)allocator.allocate(sizeof(team4s_interfaces__msg__LaneCandidate__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = team4s_interfaces__msg__LaneCandidate__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
team4s_interfaces__msg__LaneCandidate__Sequence__destroy(team4s_interfaces__msg__LaneCandidate__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    team4s_interfaces__msg__LaneCandidate__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
team4s_interfaces__msg__LaneCandidate__Sequence__are_equal(const team4s_interfaces__msg__LaneCandidate__Sequence * lhs, const team4s_interfaces__msg__LaneCandidate__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!team4s_interfaces__msg__LaneCandidate__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
team4s_interfaces__msg__LaneCandidate__Sequence__copy(
  const team4s_interfaces__msg__LaneCandidate__Sequence * input,
  team4s_interfaces__msg__LaneCandidate__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(team4s_interfaces__msg__LaneCandidate);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    team4s_interfaces__msg__LaneCandidate * data =
      (team4s_interfaces__msg__LaneCandidate *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!team4s_interfaces__msg__LaneCandidate__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          team4s_interfaces__msg__LaneCandidate__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!team4s_interfaces__msg__LaneCandidate__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

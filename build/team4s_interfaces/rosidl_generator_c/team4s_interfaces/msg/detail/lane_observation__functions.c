// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from team4s_interfaces:msg/LaneObservation.idl
// generated code does not contain a copyright notice
#include "team4s_interfaces/msg/detail/lane_observation__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `meta`
#include "team4s_interfaces/msg/detail/source_header__functions.h"
// Member `candidates`
#include "team4s_interfaces/msg/detail/lane_candidate__functions.h"
// Member `selected_candidate_id`
// Member `metric_reason`
// Member `calibration_id`
// Member `metric_frame_id`
#include "rosidl_runtime_c/string_functions.h"

bool
team4s_interfaces__msg__LaneObservation__init(team4s_interfaces__msg__LaneObservation * msg)
{
  if (!msg) {
    return false;
  }
  // meta
  if (!team4s_interfaces__msg__SourceHeader__init(&msg->meta)) {
    team4s_interfaces__msg__LaneObservation__fini(msg);
    return false;
  }
  // image_width
  // image_height
  // candidates
  if (!team4s_interfaces__msg__LaneCandidate__Sequence__init(&msg->candidates, 0)) {
    team4s_interfaces__msg__LaneObservation__fini(msg);
    return false;
  }
  // selected_candidate_id
  if (!rosidl_runtime_c__String__init(&msg->selected_candidate_id)) {
    team4s_interfaces__msg__LaneObservation__fini(msg);
    return false;
  }
  // offset_m_valid
  // offset_m
  // metric_reason
  if (!rosidl_runtime_c__String__init(&msg->metric_reason)) {
    team4s_interfaces__msg__LaneObservation__fini(msg);
    return false;
  }
  // calibration_id
  if (!rosidl_runtime_c__String__init(&msg->calibration_id)) {
    team4s_interfaces__msg__LaneObservation__fini(msg);
    return false;
  }
  // metric_frame_id
  if (!rosidl_runtime_c__String__init(&msg->metric_frame_id)) {
    team4s_interfaces__msg__LaneObservation__fini(msg);
    return false;
  }
  // metric_reference_x_m
  // metric_reference_y_m
  return true;
}

void
team4s_interfaces__msg__LaneObservation__fini(team4s_interfaces__msg__LaneObservation * msg)
{
  if (!msg) {
    return;
  }
  // meta
  team4s_interfaces__msg__SourceHeader__fini(&msg->meta);
  // image_width
  // image_height
  // candidates
  team4s_interfaces__msg__LaneCandidate__Sequence__fini(&msg->candidates);
  // selected_candidate_id
  rosidl_runtime_c__String__fini(&msg->selected_candidate_id);
  // offset_m_valid
  // offset_m
  // metric_reason
  rosidl_runtime_c__String__fini(&msg->metric_reason);
  // calibration_id
  rosidl_runtime_c__String__fini(&msg->calibration_id);
  // metric_frame_id
  rosidl_runtime_c__String__fini(&msg->metric_frame_id);
  // metric_reference_x_m
  // metric_reference_y_m
}

bool
team4s_interfaces__msg__LaneObservation__are_equal(const team4s_interfaces__msg__LaneObservation * lhs, const team4s_interfaces__msg__LaneObservation * rhs)
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
  // image_width
  if (lhs->image_width != rhs->image_width) {
    return false;
  }
  // image_height
  if (lhs->image_height != rhs->image_height) {
    return false;
  }
  // candidates
  if (!team4s_interfaces__msg__LaneCandidate__Sequence__are_equal(
      &(lhs->candidates), &(rhs->candidates)))
  {
    return false;
  }
  // selected_candidate_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->selected_candidate_id), &(rhs->selected_candidate_id)))
  {
    return false;
  }
  // offset_m_valid
  if (lhs->offset_m_valid != rhs->offset_m_valid) {
    return false;
  }
  // offset_m
  if (lhs->offset_m != rhs->offset_m) {
    return false;
  }
  // metric_reason
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->metric_reason), &(rhs->metric_reason)))
  {
    return false;
  }
  // calibration_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->calibration_id), &(rhs->calibration_id)))
  {
    return false;
  }
  // metric_frame_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->metric_frame_id), &(rhs->metric_frame_id)))
  {
    return false;
  }
  // metric_reference_x_m
  if (lhs->metric_reference_x_m != rhs->metric_reference_x_m) {
    return false;
  }
  // metric_reference_y_m
  if (lhs->metric_reference_y_m != rhs->metric_reference_y_m) {
    return false;
  }
  return true;
}

bool
team4s_interfaces__msg__LaneObservation__copy(
  const team4s_interfaces__msg__LaneObservation * input,
  team4s_interfaces__msg__LaneObservation * output)
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
  // image_width
  output->image_width = input->image_width;
  // image_height
  output->image_height = input->image_height;
  // candidates
  if (!team4s_interfaces__msg__LaneCandidate__Sequence__copy(
      &(input->candidates), &(output->candidates)))
  {
    return false;
  }
  // selected_candidate_id
  if (!rosidl_runtime_c__String__copy(
      &(input->selected_candidate_id), &(output->selected_candidate_id)))
  {
    return false;
  }
  // offset_m_valid
  output->offset_m_valid = input->offset_m_valid;
  // offset_m
  output->offset_m = input->offset_m;
  // metric_reason
  if (!rosidl_runtime_c__String__copy(
      &(input->metric_reason), &(output->metric_reason)))
  {
    return false;
  }
  // calibration_id
  if (!rosidl_runtime_c__String__copy(
      &(input->calibration_id), &(output->calibration_id)))
  {
    return false;
  }
  // metric_frame_id
  if (!rosidl_runtime_c__String__copy(
      &(input->metric_frame_id), &(output->metric_frame_id)))
  {
    return false;
  }
  // metric_reference_x_m
  output->metric_reference_x_m = input->metric_reference_x_m;
  // metric_reference_y_m
  output->metric_reference_y_m = input->metric_reference_y_m;
  return true;
}

team4s_interfaces__msg__LaneObservation *
team4s_interfaces__msg__LaneObservation__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__LaneObservation * msg = (team4s_interfaces__msg__LaneObservation *)allocator.allocate(sizeof(team4s_interfaces__msg__LaneObservation), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(team4s_interfaces__msg__LaneObservation));
  bool success = team4s_interfaces__msg__LaneObservation__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
team4s_interfaces__msg__LaneObservation__destroy(team4s_interfaces__msg__LaneObservation * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    team4s_interfaces__msg__LaneObservation__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
team4s_interfaces__msg__LaneObservation__Sequence__init(team4s_interfaces__msg__LaneObservation__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__LaneObservation * data = NULL;

  if (size) {
    data = (team4s_interfaces__msg__LaneObservation *)allocator.zero_allocate(size, sizeof(team4s_interfaces__msg__LaneObservation), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = team4s_interfaces__msg__LaneObservation__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        team4s_interfaces__msg__LaneObservation__fini(&data[i - 1]);
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
team4s_interfaces__msg__LaneObservation__Sequence__fini(team4s_interfaces__msg__LaneObservation__Sequence * array)
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
      team4s_interfaces__msg__LaneObservation__fini(&array->data[i]);
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

team4s_interfaces__msg__LaneObservation__Sequence *
team4s_interfaces__msg__LaneObservation__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__LaneObservation__Sequence * array = (team4s_interfaces__msg__LaneObservation__Sequence *)allocator.allocate(sizeof(team4s_interfaces__msg__LaneObservation__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = team4s_interfaces__msg__LaneObservation__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
team4s_interfaces__msg__LaneObservation__Sequence__destroy(team4s_interfaces__msg__LaneObservation__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    team4s_interfaces__msg__LaneObservation__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
team4s_interfaces__msg__LaneObservation__Sequence__are_equal(const team4s_interfaces__msg__LaneObservation__Sequence * lhs, const team4s_interfaces__msg__LaneObservation__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!team4s_interfaces__msg__LaneObservation__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
team4s_interfaces__msg__LaneObservation__Sequence__copy(
  const team4s_interfaces__msg__LaneObservation__Sequence * input,
  team4s_interfaces__msg__LaneObservation__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(team4s_interfaces__msg__LaneObservation);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    team4s_interfaces__msg__LaneObservation * data =
      (team4s_interfaces__msg__LaneObservation *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!team4s_interfaces__msg__LaneObservation__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          team4s_interfaces__msg__LaneObservation__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!team4s_interfaces__msg__LaneObservation__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

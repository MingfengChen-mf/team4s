// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from team4s_interfaces:msg/SceneObservation.idl
// generated code does not contain a copyright notice
#include "team4s_interfaces/msg/detail/scene_observation__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `meta`
#include "team4s_interfaces/msg/detail/source_header__functions.h"
// Member `cone_event_stamp`
// Member `zebra_event_stamp`
// Member `red_finish_event_stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"
// Member `cones_reason`
#include "rosidl_runtime_c/string_functions.h"
// Member `cones`
#include "team4s_interfaces/msg/detail/cone_detection__functions.h"

bool
team4s_interfaces__msg__SceneObservation__init(team4s_interfaces__msg__SceneObservation * msg)
{
  if (!msg) {
    return false;
  }
  // meta
  if (!team4s_interfaces__msg__SourceHeader__init(&msg->meta)) {
    team4s_interfaces__msg__SceneObservation__fini(msg);
    return false;
  }
  // cone_valid
  // cone_state
  // cone_bbox_known
  // cone_bbox_xyxy
  // zebra_valid
  // zebra_visible
  // zebra_bbox_known
  // zebra_bbox_xyxy
  // image_width
  // image_height
  // cone_event_id
  // cone_event_stamp
  if (!builtin_interfaces__msg__Time__init(&msg->cone_event_stamp)) {
    team4s_interfaces__msg__SceneObservation__fini(msg);
    return false;
  }
  // zebra_event_id
  // zebra_event_stamp
  if (!builtin_interfaces__msg__Time__init(&msg->zebra_event_stamp)) {
    team4s_interfaces__msg__SceneObservation__fini(msg);
    return false;
  }
  // zebra_event_confirmed
  // cones_valid
  // cones_reason
  if (!rosidl_runtime_c__String__init(&msg->cones_reason)) {
    team4s_interfaces__msg__SceneObservation__fini(msg);
    return false;
  }
  // cones
  if (!team4s_interfaces__msg__ConeDetection__Sequence__init(&msg->cones, 0)) {
    team4s_interfaces__msg__SceneObservation__fini(msg);
    return false;
  }
  // green_start_visible
  // red_finish_visible
  // red_finish_confirmed
  // red_finish_event_id
  // red_finish_event_stamp
  if (!builtin_interfaces__msg__Time__init(&msg->red_finish_event_stamp)) {
    team4s_interfaces__msg__SceneObservation__fini(msg);
    return false;
  }
  return true;
}

void
team4s_interfaces__msg__SceneObservation__fini(team4s_interfaces__msg__SceneObservation * msg)
{
  if (!msg) {
    return;
  }
  // meta
  team4s_interfaces__msg__SourceHeader__fini(&msg->meta);
  // cone_valid
  // cone_state
  // cone_bbox_known
  // cone_bbox_xyxy
  // zebra_valid
  // zebra_visible
  // zebra_bbox_known
  // zebra_bbox_xyxy
  // image_width
  // image_height
  // cone_event_id
  // cone_event_stamp
  builtin_interfaces__msg__Time__fini(&msg->cone_event_stamp);
  // zebra_event_id
  // zebra_event_stamp
  builtin_interfaces__msg__Time__fini(&msg->zebra_event_stamp);
  // zebra_event_confirmed
  // cones_valid
  // cones_reason
  rosidl_runtime_c__String__fini(&msg->cones_reason);
  // cones
  team4s_interfaces__msg__ConeDetection__Sequence__fini(&msg->cones);
  // green_start_visible
  // red_finish_visible
  // red_finish_confirmed
  // red_finish_event_id
  // red_finish_event_stamp
  builtin_interfaces__msg__Time__fini(&msg->red_finish_event_stamp);
}

bool
team4s_interfaces__msg__SceneObservation__are_equal(const team4s_interfaces__msg__SceneObservation * lhs, const team4s_interfaces__msg__SceneObservation * rhs)
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
  // cone_valid
  if (lhs->cone_valid != rhs->cone_valid) {
    return false;
  }
  // cone_state
  if (lhs->cone_state != rhs->cone_state) {
    return false;
  }
  // cone_bbox_known
  if (lhs->cone_bbox_known != rhs->cone_bbox_known) {
    return false;
  }
  // cone_bbox_xyxy
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->cone_bbox_xyxy[i] != rhs->cone_bbox_xyxy[i]) {
      return false;
    }
  }
  // zebra_valid
  if (lhs->zebra_valid != rhs->zebra_valid) {
    return false;
  }
  // zebra_visible
  if (lhs->zebra_visible != rhs->zebra_visible) {
    return false;
  }
  // zebra_bbox_known
  if (lhs->zebra_bbox_known != rhs->zebra_bbox_known) {
    return false;
  }
  // zebra_bbox_xyxy
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->zebra_bbox_xyxy[i] != rhs->zebra_bbox_xyxy[i]) {
      return false;
    }
  }
  // image_width
  if (lhs->image_width != rhs->image_width) {
    return false;
  }
  // image_height
  if (lhs->image_height != rhs->image_height) {
    return false;
  }
  // cone_event_id
  if (lhs->cone_event_id != rhs->cone_event_id) {
    return false;
  }
  // cone_event_stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->cone_event_stamp), &(rhs->cone_event_stamp)))
  {
    return false;
  }
  // zebra_event_id
  if (lhs->zebra_event_id != rhs->zebra_event_id) {
    return false;
  }
  // zebra_event_stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->zebra_event_stamp), &(rhs->zebra_event_stamp)))
  {
    return false;
  }
  // zebra_event_confirmed
  if (lhs->zebra_event_confirmed != rhs->zebra_event_confirmed) {
    return false;
  }
  // cones_valid
  if (lhs->cones_valid != rhs->cones_valid) {
    return false;
  }
  // cones_reason
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->cones_reason), &(rhs->cones_reason)))
  {
    return false;
  }
  // cones
  if (!team4s_interfaces__msg__ConeDetection__Sequence__are_equal(
      &(lhs->cones), &(rhs->cones)))
  {
    return false;
  }
  // green_start_visible
  if (lhs->green_start_visible != rhs->green_start_visible) {
    return false;
  }
  // red_finish_visible
  if (lhs->red_finish_visible != rhs->red_finish_visible) {
    return false;
  }
  // red_finish_confirmed
  if (lhs->red_finish_confirmed != rhs->red_finish_confirmed) {
    return false;
  }
  // red_finish_event_id
  if (lhs->red_finish_event_id != rhs->red_finish_event_id) {
    return false;
  }
  // red_finish_event_stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->red_finish_event_stamp), &(rhs->red_finish_event_stamp)))
  {
    return false;
  }
  return true;
}

bool
team4s_interfaces__msg__SceneObservation__copy(
  const team4s_interfaces__msg__SceneObservation * input,
  team4s_interfaces__msg__SceneObservation * output)
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
  // cone_valid
  output->cone_valid = input->cone_valid;
  // cone_state
  output->cone_state = input->cone_state;
  // cone_bbox_known
  output->cone_bbox_known = input->cone_bbox_known;
  // cone_bbox_xyxy
  for (size_t i = 0; i < 4; ++i) {
    output->cone_bbox_xyxy[i] = input->cone_bbox_xyxy[i];
  }
  // zebra_valid
  output->zebra_valid = input->zebra_valid;
  // zebra_visible
  output->zebra_visible = input->zebra_visible;
  // zebra_bbox_known
  output->zebra_bbox_known = input->zebra_bbox_known;
  // zebra_bbox_xyxy
  for (size_t i = 0; i < 4; ++i) {
    output->zebra_bbox_xyxy[i] = input->zebra_bbox_xyxy[i];
  }
  // image_width
  output->image_width = input->image_width;
  // image_height
  output->image_height = input->image_height;
  // cone_event_id
  output->cone_event_id = input->cone_event_id;
  // cone_event_stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->cone_event_stamp), &(output->cone_event_stamp)))
  {
    return false;
  }
  // zebra_event_id
  output->zebra_event_id = input->zebra_event_id;
  // zebra_event_stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->zebra_event_stamp), &(output->zebra_event_stamp)))
  {
    return false;
  }
  // zebra_event_confirmed
  output->zebra_event_confirmed = input->zebra_event_confirmed;
  // cones_valid
  output->cones_valid = input->cones_valid;
  // cones_reason
  if (!rosidl_runtime_c__String__copy(
      &(input->cones_reason), &(output->cones_reason)))
  {
    return false;
  }
  // cones
  if (!team4s_interfaces__msg__ConeDetection__Sequence__copy(
      &(input->cones), &(output->cones)))
  {
    return false;
  }
  // green_start_visible
  output->green_start_visible = input->green_start_visible;
  // red_finish_visible
  output->red_finish_visible = input->red_finish_visible;
  // red_finish_confirmed
  output->red_finish_confirmed = input->red_finish_confirmed;
  // red_finish_event_id
  output->red_finish_event_id = input->red_finish_event_id;
  // red_finish_event_stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->red_finish_event_stamp), &(output->red_finish_event_stamp)))
  {
    return false;
  }
  return true;
}

team4s_interfaces__msg__SceneObservation *
team4s_interfaces__msg__SceneObservation__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__SceneObservation * msg = (team4s_interfaces__msg__SceneObservation *)allocator.allocate(sizeof(team4s_interfaces__msg__SceneObservation), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(team4s_interfaces__msg__SceneObservation));
  bool success = team4s_interfaces__msg__SceneObservation__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
team4s_interfaces__msg__SceneObservation__destroy(team4s_interfaces__msg__SceneObservation * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    team4s_interfaces__msg__SceneObservation__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
team4s_interfaces__msg__SceneObservation__Sequence__init(team4s_interfaces__msg__SceneObservation__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__SceneObservation * data = NULL;

  if (size) {
    data = (team4s_interfaces__msg__SceneObservation *)allocator.zero_allocate(size, sizeof(team4s_interfaces__msg__SceneObservation), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = team4s_interfaces__msg__SceneObservation__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        team4s_interfaces__msg__SceneObservation__fini(&data[i - 1]);
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
team4s_interfaces__msg__SceneObservation__Sequence__fini(team4s_interfaces__msg__SceneObservation__Sequence * array)
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
      team4s_interfaces__msg__SceneObservation__fini(&array->data[i]);
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

team4s_interfaces__msg__SceneObservation__Sequence *
team4s_interfaces__msg__SceneObservation__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__SceneObservation__Sequence * array = (team4s_interfaces__msg__SceneObservation__Sequence *)allocator.allocate(sizeof(team4s_interfaces__msg__SceneObservation__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = team4s_interfaces__msg__SceneObservation__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
team4s_interfaces__msg__SceneObservation__Sequence__destroy(team4s_interfaces__msg__SceneObservation__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    team4s_interfaces__msg__SceneObservation__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
team4s_interfaces__msg__SceneObservation__Sequence__are_equal(const team4s_interfaces__msg__SceneObservation__Sequence * lhs, const team4s_interfaces__msg__SceneObservation__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!team4s_interfaces__msg__SceneObservation__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
team4s_interfaces__msg__SceneObservation__Sequence__copy(
  const team4s_interfaces__msg__SceneObservation__Sequence * input,
  team4s_interfaces__msg__SceneObservation__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(team4s_interfaces__msg__SceneObservation);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    team4s_interfaces__msg__SceneObservation * data =
      (team4s_interfaces__msg__SceneObservation *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!team4s_interfaces__msg__SceneObservation__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          team4s_interfaces__msg__SceneObservation__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!team4s_interfaces__msg__SceneObservation__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

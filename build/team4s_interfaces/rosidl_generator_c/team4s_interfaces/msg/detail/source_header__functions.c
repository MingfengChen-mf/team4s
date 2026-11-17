// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from team4s_interfaces:msg/SourceHeader.idl
// generated code does not contain a copyright notice
#include "team4s_interfaces/msg/detail/source_header__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `source_id`
// Member `source_session_id`
// Member `run_id`
// Member `reason`
#include "rosidl_runtime_c/string_functions.h"

bool
team4s_interfaces__msg__SourceHeader__init(team4s_interfaces__msg__SourceHeader * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    team4s_interfaces__msg__SourceHeader__fini(msg);
    return false;
  }
  // source_id
  if (!rosidl_runtime_c__String__init(&msg->source_id)) {
    team4s_interfaces__msg__SourceHeader__fini(msg);
    return false;
  }
  // source_session_id
  if (!rosidl_runtime_c__String__init(&msg->source_session_id)) {
    team4s_interfaces__msg__SourceHeader__fini(msg);
    return false;
  }
  // run_id
  if (!rosidl_runtime_c__String__init(&msg->run_id)) {
    team4s_interfaces__msg__SourceHeader__fini(msg);
    return false;
  }
  // sequence
  // stamp_source
  // valid
  // reason
  if (!rosidl_runtime_c__String__init(&msg->reason)) {
    team4s_interfaces__msg__SourceHeader__fini(msg);
    return false;
  }
  return true;
}

void
team4s_interfaces__msg__SourceHeader__fini(team4s_interfaces__msg__SourceHeader * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // source_id
  rosidl_runtime_c__String__fini(&msg->source_id);
  // source_session_id
  rosidl_runtime_c__String__fini(&msg->source_session_id);
  // run_id
  rosidl_runtime_c__String__fini(&msg->run_id);
  // sequence
  // stamp_source
  // valid
  // reason
  rosidl_runtime_c__String__fini(&msg->reason);
}

bool
team4s_interfaces__msg__SourceHeader__are_equal(const team4s_interfaces__msg__SourceHeader * lhs, const team4s_interfaces__msg__SourceHeader * rhs)
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
  // source_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->source_id), &(rhs->source_id)))
  {
    return false;
  }
  // source_session_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->source_session_id), &(rhs->source_session_id)))
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
  // stamp_source
  if (lhs->stamp_source != rhs->stamp_source) {
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
  return true;
}

bool
team4s_interfaces__msg__SourceHeader__copy(
  const team4s_interfaces__msg__SourceHeader * input,
  team4s_interfaces__msg__SourceHeader * output)
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
  // source_id
  if (!rosidl_runtime_c__String__copy(
      &(input->source_id), &(output->source_id)))
  {
    return false;
  }
  // source_session_id
  if (!rosidl_runtime_c__String__copy(
      &(input->source_session_id), &(output->source_session_id)))
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
  // stamp_source
  output->stamp_source = input->stamp_source;
  // valid
  output->valid = input->valid;
  // reason
  if (!rosidl_runtime_c__String__copy(
      &(input->reason), &(output->reason)))
  {
    return false;
  }
  return true;
}

team4s_interfaces__msg__SourceHeader *
team4s_interfaces__msg__SourceHeader__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__SourceHeader * msg = (team4s_interfaces__msg__SourceHeader *)allocator.allocate(sizeof(team4s_interfaces__msg__SourceHeader), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(team4s_interfaces__msg__SourceHeader));
  bool success = team4s_interfaces__msg__SourceHeader__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
team4s_interfaces__msg__SourceHeader__destroy(team4s_interfaces__msg__SourceHeader * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    team4s_interfaces__msg__SourceHeader__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
team4s_interfaces__msg__SourceHeader__Sequence__init(team4s_interfaces__msg__SourceHeader__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__SourceHeader * data = NULL;

  if (size) {
    data = (team4s_interfaces__msg__SourceHeader *)allocator.zero_allocate(size, sizeof(team4s_interfaces__msg__SourceHeader), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = team4s_interfaces__msg__SourceHeader__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        team4s_interfaces__msg__SourceHeader__fini(&data[i - 1]);
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
team4s_interfaces__msg__SourceHeader__Sequence__fini(team4s_interfaces__msg__SourceHeader__Sequence * array)
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
      team4s_interfaces__msg__SourceHeader__fini(&array->data[i]);
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

team4s_interfaces__msg__SourceHeader__Sequence *
team4s_interfaces__msg__SourceHeader__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__SourceHeader__Sequence * array = (team4s_interfaces__msg__SourceHeader__Sequence *)allocator.allocate(sizeof(team4s_interfaces__msg__SourceHeader__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = team4s_interfaces__msg__SourceHeader__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
team4s_interfaces__msg__SourceHeader__Sequence__destroy(team4s_interfaces__msg__SourceHeader__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    team4s_interfaces__msg__SourceHeader__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
team4s_interfaces__msg__SourceHeader__Sequence__are_equal(const team4s_interfaces__msg__SourceHeader__Sequence * lhs, const team4s_interfaces__msg__SourceHeader__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!team4s_interfaces__msg__SourceHeader__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
team4s_interfaces__msg__SourceHeader__Sequence__copy(
  const team4s_interfaces__msg__SourceHeader__Sequence * input,
  team4s_interfaces__msg__SourceHeader__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(team4s_interfaces__msg__SourceHeader);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    team4s_interfaces__msg__SourceHeader * data =
      (team4s_interfaces__msg__SourceHeader *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!team4s_interfaces__msg__SourceHeader__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          team4s_interfaces__msg__SourceHeader__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!team4s_interfaces__msg__SourceHeader__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

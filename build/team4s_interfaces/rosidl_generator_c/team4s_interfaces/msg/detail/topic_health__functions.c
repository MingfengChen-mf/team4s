// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from team4s_interfaces:msg/TopicHealth.idl
// generated code does not contain a copyright notice
#include "team4s_interfaces/msg/detail/topic_health__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `reason`
#include "rosidl_runtime_c/string_functions.h"

bool
team4s_interfaces__msg__TopicHealth__init(team4s_interfaces__msg__TopicHealth * msg)
{
  if (!msg) {
    return false;
  }
  // state
  // reason
  if (!rosidl_runtime_c__String__init(&msg->reason)) {
    team4s_interfaces__msg__TopicHealth__fini(msg);
    return false;
  }
  // age_known
  // age_s
  // max_age_s
  return true;
}

void
team4s_interfaces__msg__TopicHealth__fini(team4s_interfaces__msg__TopicHealth * msg)
{
  if (!msg) {
    return;
  }
  // state
  // reason
  rosidl_runtime_c__String__fini(&msg->reason);
  // age_known
  // age_s
  // max_age_s
}

bool
team4s_interfaces__msg__TopicHealth__are_equal(const team4s_interfaces__msg__TopicHealth * lhs, const team4s_interfaces__msg__TopicHealth * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // state
  if (lhs->state != rhs->state) {
    return false;
  }
  // reason
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->reason), &(rhs->reason)))
  {
    return false;
  }
  // age_known
  if (lhs->age_known != rhs->age_known) {
    return false;
  }
  // age_s
  if (lhs->age_s != rhs->age_s) {
    return false;
  }
  // max_age_s
  if (lhs->max_age_s != rhs->max_age_s) {
    return false;
  }
  return true;
}

bool
team4s_interfaces__msg__TopicHealth__copy(
  const team4s_interfaces__msg__TopicHealth * input,
  team4s_interfaces__msg__TopicHealth * output)
{
  if (!input || !output) {
    return false;
  }
  // state
  output->state = input->state;
  // reason
  if (!rosidl_runtime_c__String__copy(
      &(input->reason), &(output->reason)))
  {
    return false;
  }
  // age_known
  output->age_known = input->age_known;
  // age_s
  output->age_s = input->age_s;
  // max_age_s
  output->max_age_s = input->max_age_s;
  return true;
}

team4s_interfaces__msg__TopicHealth *
team4s_interfaces__msg__TopicHealth__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__TopicHealth * msg = (team4s_interfaces__msg__TopicHealth *)allocator.allocate(sizeof(team4s_interfaces__msg__TopicHealth), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(team4s_interfaces__msg__TopicHealth));
  bool success = team4s_interfaces__msg__TopicHealth__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
team4s_interfaces__msg__TopicHealth__destroy(team4s_interfaces__msg__TopicHealth * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    team4s_interfaces__msg__TopicHealth__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
team4s_interfaces__msg__TopicHealth__Sequence__init(team4s_interfaces__msg__TopicHealth__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__TopicHealth * data = NULL;

  if (size) {
    data = (team4s_interfaces__msg__TopicHealth *)allocator.zero_allocate(size, sizeof(team4s_interfaces__msg__TopicHealth), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = team4s_interfaces__msg__TopicHealth__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        team4s_interfaces__msg__TopicHealth__fini(&data[i - 1]);
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
team4s_interfaces__msg__TopicHealth__Sequence__fini(team4s_interfaces__msg__TopicHealth__Sequence * array)
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
      team4s_interfaces__msg__TopicHealth__fini(&array->data[i]);
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

team4s_interfaces__msg__TopicHealth__Sequence *
team4s_interfaces__msg__TopicHealth__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__TopicHealth__Sequence * array = (team4s_interfaces__msg__TopicHealth__Sequence *)allocator.allocate(sizeof(team4s_interfaces__msg__TopicHealth__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = team4s_interfaces__msg__TopicHealth__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
team4s_interfaces__msg__TopicHealth__Sequence__destroy(team4s_interfaces__msg__TopicHealth__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    team4s_interfaces__msg__TopicHealth__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
team4s_interfaces__msg__TopicHealth__Sequence__are_equal(const team4s_interfaces__msg__TopicHealth__Sequence * lhs, const team4s_interfaces__msg__TopicHealth__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!team4s_interfaces__msg__TopicHealth__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
team4s_interfaces__msg__TopicHealth__Sequence__copy(
  const team4s_interfaces__msg__TopicHealth__Sequence * input,
  team4s_interfaces__msg__TopicHealth__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(team4s_interfaces__msg__TopicHealth);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    team4s_interfaces__msg__TopicHealth * data =
      (team4s_interfaces__msg__TopicHealth *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!team4s_interfaces__msg__TopicHealth__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          team4s_interfaces__msg__TopicHealth__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!team4s_interfaces__msg__TopicHealth__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

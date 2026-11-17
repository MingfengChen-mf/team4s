// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from team4s_interfaces:msg/TaskState.idl
// generated code does not contain a copyright notice
#include "team4s_interfaces/msg/detail/task_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `run_id`
// Member `controller_session_id`
// Member `reason`
#include "rosidl_runtime_c/string_functions.h"

bool
team4s_interfaces__msg__TaskState__init(team4s_interfaces__msg__TaskState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    team4s_interfaces__msg__TaskState__fini(msg);
    return false;
  }
  // run_id
  if (!rosidl_runtime_c__String__init(&msg->run_id)) {
    team4s_interfaces__msg__TaskState__fini(msg);
    return false;
  }
  // controller_session_id
  if (!rosidl_runtime_c__String__init(&msg->controller_session_id)) {
    team4s_interfaces__msg__TaskState__fini(msg);
    return false;
  }
  // sequence
  // task_id
  // phase
  // target_lane
  // control_mode
  // lap_complete
  // reason
  if (!rosidl_runtime_c__String__init(&msg->reason)) {
    team4s_interfaces__msg__TaskState__fini(msg);
    return false;
  }
  return true;
}

void
team4s_interfaces__msg__TaskState__fini(team4s_interfaces__msg__TaskState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // run_id
  rosidl_runtime_c__String__fini(&msg->run_id);
  // controller_session_id
  rosidl_runtime_c__String__fini(&msg->controller_session_id);
  // sequence
  // task_id
  // phase
  // target_lane
  // control_mode
  // lap_complete
  // reason
  rosidl_runtime_c__String__fini(&msg->reason);
}

bool
team4s_interfaces__msg__TaskState__are_equal(const team4s_interfaces__msg__TaskState * lhs, const team4s_interfaces__msg__TaskState * rhs)
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
  // run_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->run_id), &(rhs->run_id)))
  {
    return false;
  }
  // controller_session_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->controller_session_id), &(rhs->controller_session_id)))
  {
    return false;
  }
  // sequence
  if (lhs->sequence != rhs->sequence) {
    return false;
  }
  // task_id
  if (lhs->task_id != rhs->task_id) {
    return false;
  }
  // phase
  if (lhs->phase != rhs->phase) {
    return false;
  }
  // target_lane
  if (lhs->target_lane != rhs->target_lane) {
    return false;
  }
  // control_mode
  if (lhs->control_mode != rhs->control_mode) {
    return false;
  }
  // lap_complete
  if (lhs->lap_complete != rhs->lap_complete) {
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
team4s_interfaces__msg__TaskState__copy(
  const team4s_interfaces__msg__TaskState * input,
  team4s_interfaces__msg__TaskState * output)
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
  // run_id
  if (!rosidl_runtime_c__String__copy(
      &(input->run_id), &(output->run_id)))
  {
    return false;
  }
  // controller_session_id
  if (!rosidl_runtime_c__String__copy(
      &(input->controller_session_id), &(output->controller_session_id)))
  {
    return false;
  }
  // sequence
  output->sequence = input->sequence;
  // task_id
  output->task_id = input->task_id;
  // phase
  output->phase = input->phase;
  // target_lane
  output->target_lane = input->target_lane;
  // control_mode
  output->control_mode = input->control_mode;
  // lap_complete
  output->lap_complete = input->lap_complete;
  // reason
  if (!rosidl_runtime_c__String__copy(
      &(input->reason), &(output->reason)))
  {
    return false;
  }
  return true;
}

team4s_interfaces__msg__TaskState *
team4s_interfaces__msg__TaskState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__TaskState * msg = (team4s_interfaces__msg__TaskState *)allocator.allocate(sizeof(team4s_interfaces__msg__TaskState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(team4s_interfaces__msg__TaskState));
  bool success = team4s_interfaces__msg__TaskState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
team4s_interfaces__msg__TaskState__destroy(team4s_interfaces__msg__TaskState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    team4s_interfaces__msg__TaskState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
team4s_interfaces__msg__TaskState__Sequence__init(team4s_interfaces__msg__TaskState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__TaskState * data = NULL;

  if (size) {
    data = (team4s_interfaces__msg__TaskState *)allocator.zero_allocate(size, sizeof(team4s_interfaces__msg__TaskState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = team4s_interfaces__msg__TaskState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        team4s_interfaces__msg__TaskState__fini(&data[i - 1]);
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
team4s_interfaces__msg__TaskState__Sequence__fini(team4s_interfaces__msg__TaskState__Sequence * array)
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
      team4s_interfaces__msg__TaskState__fini(&array->data[i]);
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

team4s_interfaces__msg__TaskState__Sequence *
team4s_interfaces__msg__TaskState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  team4s_interfaces__msg__TaskState__Sequence * array = (team4s_interfaces__msg__TaskState__Sequence *)allocator.allocate(sizeof(team4s_interfaces__msg__TaskState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = team4s_interfaces__msg__TaskState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
team4s_interfaces__msg__TaskState__Sequence__destroy(team4s_interfaces__msg__TaskState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    team4s_interfaces__msg__TaskState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
team4s_interfaces__msg__TaskState__Sequence__are_equal(const team4s_interfaces__msg__TaskState__Sequence * lhs, const team4s_interfaces__msg__TaskState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!team4s_interfaces__msg__TaskState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
team4s_interfaces__msg__TaskState__Sequence__copy(
  const team4s_interfaces__msg__TaskState__Sequence * input,
  team4s_interfaces__msg__TaskState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(team4s_interfaces__msg__TaskState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    team4s_interfaces__msg__TaskState * data =
      (team4s_interfaces__msg__TaskState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!team4s_interfaces__msg__TaskState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          team4s_interfaces__msg__TaskState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!team4s_interfaces__msg__TaskState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

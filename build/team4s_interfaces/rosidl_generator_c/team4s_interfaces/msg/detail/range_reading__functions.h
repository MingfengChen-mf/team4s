// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from team4s_interfaces:msg/RangeReading.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__RANGE_READING__FUNCTIONS_H_
#define TEAM4S_INTERFACES__MSG__DETAIL__RANGE_READING__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "team4s_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "team4s_interfaces/msg/detail/range_reading__struct.h"

/// Initialize msg/RangeReading message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * team4s_interfaces__msg__RangeReading
 * )) before or use
 * team4s_interfaces__msg__RangeReading__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_team4s_interfaces
bool
team4s_interfaces__msg__RangeReading__init(team4s_interfaces__msg__RangeReading * msg);

/// Finalize msg/RangeReading message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_team4s_interfaces
void
team4s_interfaces__msg__RangeReading__fini(team4s_interfaces__msg__RangeReading * msg);

/// Create msg/RangeReading message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * team4s_interfaces__msg__RangeReading__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_team4s_interfaces
team4s_interfaces__msg__RangeReading *
team4s_interfaces__msg__RangeReading__create();

/// Destroy msg/RangeReading message.
/**
 * It calls
 * team4s_interfaces__msg__RangeReading__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_team4s_interfaces
void
team4s_interfaces__msg__RangeReading__destroy(team4s_interfaces__msg__RangeReading * msg);

/// Check for msg/RangeReading message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_team4s_interfaces
bool
team4s_interfaces__msg__RangeReading__are_equal(const team4s_interfaces__msg__RangeReading * lhs, const team4s_interfaces__msg__RangeReading * rhs);

/// Copy a msg/RangeReading message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_team4s_interfaces
bool
team4s_interfaces__msg__RangeReading__copy(
  const team4s_interfaces__msg__RangeReading * input,
  team4s_interfaces__msg__RangeReading * output);

/// Initialize array of msg/RangeReading messages.
/**
 * It allocates the memory for the number of elements and calls
 * team4s_interfaces__msg__RangeReading__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_team4s_interfaces
bool
team4s_interfaces__msg__RangeReading__Sequence__init(team4s_interfaces__msg__RangeReading__Sequence * array, size_t size);

/// Finalize array of msg/RangeReading messages.
/**
 * It calls
 * team4s_interfaces__msg__RangeReading__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_team4s_interfaces
void
team4s_interfaces__msg__RangeReading__Sequence__fini(team4s_interfaces__msg__RangeReading__Sequence * array);

/// Create array of msg/RangeReading messages.
/**
 * It allocates the memory for the array and calls
 * team4s_interfaces__msg__RangeReading__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_team4s_interfaces
team4s_interfaces__msg__RangeReading__Sequence *
team4s_interfaces__msg__RangeReading__Sequence__create(size_t size);

/// Destroy array of msg/RangeReading messages.
/**
 * It calls
 * team4s_interfaces__msg__RangeReading__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_team4s_interfaces
void
team4s_interfaces__msg__RangeReading__Sequence__destroy(team4s_interfaces__msg__RangeReading__Sequence * array);

/// Check for msg/RangeReading message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_team4s_interfaces
bool
team4s_interfaces__msg__RangeReading__Sequence__are_equal(const team4s_interfaces__msg__RangeReading__Sequence * lhs, const team4s_interfaces__msg__RangeReading__Sequence * rhs);

/// Copy an array of msg/RangeReading messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_team4s_interfaces
bool
team4s_interfaces__msg__RangeReading__Sequence__copy(
  const team4s_interfaces__msg__RangeReading__Sequence * input,
  team4s_interfaces__msg__RangeReading__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__RANGE_READING__FUNCTIONS_H_

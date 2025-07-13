// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from upc_mrn:msg/Frontier.idl
// generated code does not contain a copyright notice

#ifndef UPC_MRN__MSG__DETAIL__FRONTIER__FUNCTIONS_H_
#define UPC_MRN__MSG__DETAIL__FRONTIER__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "upc_mrn/msg/rosidl_generator_c__visibility_control.h"

#include "upc_mrn/msg/detail/frontier__struct.h"

/// Initialize msg/Frontier message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * upc_mrn__msg__Frontier
 * )) before or use
 * upc_mrn__msg__Frontier__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_upc_mrn
bool
upc_mrn__msg__Frontier__init(upc_mrn__msg__Frontier * msg);

/// Finalize msg/Frontier message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_upc_mrn
void
upc_mrn__msg__Frontier__fini(upc_mrn__msg__Frontier * msg);

/// Create msg/Frontier message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * upc_mrn__msg__Frontier__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_upc_mrn
upc_mrn__msg__Frontier *
upc_mrn__msg__Frontier__create();

/// Destroy msg/Frontier message.
/**
 * It calls
 * upc_mrn__msg__Frontier__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_upc_mrn
void
upc_mrn__msg__Frontier__destroy(upc_mrn__msg__Frontier * msg);

/// Check for msg/Frontier message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_upc_mrn
bool
upc_mrn__msg__Frontier__are_equal(const upc_mrn__msg__Frontier * lhs, const upc_mrn__msg__Frontier * rhs);

/// Copy a msg/Frontier message.
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
ROSIDL_GENERATOR_C_PUBLIC_upc_mrn
bool
upc_mrn__msg__Frontier__copy(
  const upc_mrn__msg__Frontier * input,
  upc_mrn__msg__Frontier * output);

/// Initialize array of msg/Frontier messages.
/**
 * It allocates the memory for the number of elements and calls
 * upc_mrn__msg__Frontier__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_upc_mrn
bool
upc_mrn__msg__Frontier__Sequence__init(upc_mrn__msg__Frontier__Sequence * array, size_t size);

/// Finalize array of msg/Frontier messages.
/**
 * It calls
 * upc_mrn__msg__Frontier__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_upc_mrn
void
upc_mrn__msg__Frontier__Sequence__fini(upc_mrn__msg__Frontier__Sequence * array);

/// Create array of msg/Frontier messages.
/**
 * It allocates the memory for the array and calls
 * upc_mrn__msg__Frontier__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_upc_mrn
upc_mrn__msg__Frontier__Sequence *
upc_mrn__msg__Frontier__Sequence__create(size_t size);

/// Destroy array of msg/Frontier messages.
/**
 * It calls
 * upc_mrn__msg__Frontier__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_upc_mrn
void
upc_mrn__msg__Frontier__Sequence__destroy(upc_mrn__msg__Frontier__Sequence * array);

/// Check for msg/Frontier message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_upc_mrn
bool
upc_mrn__msg__Frontier__Sequence__are_equal(const upc_mrn__msg__Frontier__Sequence * lhs, const upc_mrn__msg__Frontier__Sequence * rhs);

/// Copy an array of msg/Frontier messages.
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
ROSIDL_GENERATOR_C_PUBLIC_upc_mrn
bool
upc_mrn__msg__Frontier__Sequence__copy(
  const upc_mrn__msg__Frontier__Sequence * input,
  upc_mrn__msg__Frontier__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // UPC_MRN__MSG__DETAIL__FRONTIER__FUNCTIONS_H_

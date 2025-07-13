// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from upc_mrn:msg/Frontiers.idl
// generated code does not contain a copyright notice

#ifndef UPC_MRN__MSG__DETAIL__FRONTIERS__STRUCT_H_
#define UPC_MRN__MSG__DETAIL__FRONTIERS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'frontiers'
#include "upc_mrn/msg/detail/frontier__struct.h"

/// Struct defined in msg/Frontiers in the package upc_mrn.
typedef struct upc_mrn__msg__Frontiers
{
  std_msgs__msg__Header header;
  /// vector containing all detected frontiers
  upc_mrn__msg__Frontier__Sequence frontiers;
} upc_mrn__msg__Frontiers;

// Struct for a sequence of upc_mrn__msg__Frontiers.
typedef struct upc_mrn__msg__Frontiers__Sequence
{
  upc_mrn__msg__Frontiers * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} upc_mrn__msg__Frontiers__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UPC_MRN__MSG__DETAIL__FRONTIERS__STRUCT_H_

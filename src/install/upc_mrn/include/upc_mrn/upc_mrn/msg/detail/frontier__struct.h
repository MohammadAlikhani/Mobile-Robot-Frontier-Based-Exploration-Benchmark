// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from upc_mrn:msg/Frontier.idl
// generated code does not contain a copyright notice

#ifndef UPC_MRN__MSG__DETAIL__FRONTIER__STRUCT_H_
#define UPC_MRN__MSG__DETAIL__FRONTIER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'center_point'
// Member 'cells_points'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'cells'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Frontier in the package upc_mrn.
typedef struct upc_mrn__msg__Frontier
{
  /// frontier size (amount of cells)
  uint32_t size;
  /// Points
  /// Frontier center point
  geometry_msgs__msg__Point center_point;
  /// vector containing points of all frontier cells
  geometry_msgs__msg__Point__Sequence cells_points;
  /// Cells indexes of map array
  /// cell corresponding to center_point
  uint32_t center_cell;
  /// vector containing all frontier cells
  rosidl_runtime_c__uint32__Sequence cells;
} upc_mrn__msg__Frontier;

// Struct for a sequence of upc_mrn__msg__Frontier.
typedef struct upc_mrn__msg__Frontier__Sequence
{
  upc_mrn__msg__Frontier * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} upc_mrn__msg__Frontier__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UPC_MRN__MSG__DETAIL__FRONTIER__STRUCT_H_

// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from upc_mrn:msg/Frontier.idl
// generated code does not contain a copyright notice
#include "upc_mrn/msg/detail/frontier__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `center_point`
// Member `cells_points`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `cells`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
upc_mrn__msg__Frontier__init(upc_mrn__msg__Frontier * msg)
{
  if (!msg) {
    return false;
  }
  // size
  // center_point
  if (!geometry_msgs__msg__Point__init(&msg->center_point)) {
    upc_mrn__msg__Frontier__fini(msg);
    return false;
  }
  // cells_points
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->cells_points, 0)) {
    upc_mrn__msg__Frontier__fini(msg);
    return false;
  }
  // center_cell
  // cells
  if (!rosidl_runtime_c__uint32__Sequence__init(&msg->cells, 0)) {
    upc_mrn__msg__Frontier__fini(msg);
    return false;
  }
  return true;
}

void
upc_mrn__msg__Frontier__fini(upc_mrn__msg__Frontier * msg)
{
  if (!msg) {
    return;
  }
  // size
  // center_point
  geometry_msgs__msg__Point__fini(&msg->center_point);
  // cells_points
  geometry_msgs__msg__Point__Sequence__fini(&msg->cells_points);
  // center_cell
  // cells
  rosidl_runtime_c__uint32__Sequence__fini(&msg->cells);
}

bool
upc_mrn__msg__Frontier__are_equal(const upc_mrn__msg__Frontier * lhs, const upc_mrn__msg__Frontier * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // size
  if (lhs->size != rhs->size) {
    return false;
  }
  // center_point
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->center_point), &(rhs->center_point)))
  {
    return false;
  }
  // cells_points
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->cells_points), &(rhs->cells_points)))
  {
    return false;
  }
  // center_cell
  if (lhs->center_cell != rhs->center_cell) {
    return false;
  }
  // cells
  if (!rosidl_runtime_c__uint32__Sequence__are_equal(
      &(lhs->cells), &(rhs->cells)))
  {
    return false;
  }
  return true;
}

bool
upc_mrn__msg__Frontier__copy(
  const upc_mrn__msg__Frontier * input,
  upc_mrn__msg__Frontier * output)
{
  if (!input || !output) {
    return false;
  }
  // size
  output->size = input->size;
  // center_point
  if (!geometry_msgs__msg__Point__copy(
      &(input->center_point), &(output->center_point)))
  {
    return false;
  }
  // cells_points
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->cells_points), &(output->cells_points)))
  {
    return false;
  }
  // center_cell
  output->center_cell = input->center_cell;
  // cells
  if (!rosidl_runtime_c__uint32__Sequence__copy(
      &(input->cells), &(output->cells)))
  {
    return false;
  }
  return true;
}

upc_mrn__msg__Frontier *
upc_mrn__msg__Frontier__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  upc_mrn__msg__Frontier * msg = (upc_mrn__msg__Frontier *)allocator.allocate(sizeof(upc_mrn__msg__Frontier), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(upc_mrn__msg__Frontier));
  bool success = upc_mrn__msg__Frontier__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
upc_mrn__msg__Frontier__destroy(upc_mrn__msg__Frontier * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    upc_mrn__msg__Frontier__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
upc_mrn__msg__Frontier__Sequence__init(upc_mrn__msg__Frontier__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  upc_mrn__msg__Frontier * data = NULL;

  if (size) {
    data = (upc_mrn__msg__Frontier *)allocator.zero_allocate(size, sizeof(upc_mrn__msg__Frontier), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = upc_mrn__msg__Frontier__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        upc_mrn__msg__Frontier__fini(&data[i - 1]);
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
upc_mrn__msg__Frontier__Sequence__fini(upc_mrn__msg__Frontier__Sequence * array)
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
      upc_mrn__msg__Frontier__fini(&array->data[i]);
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

upc_mrn__msg__Frontier__Sequence *
upc_mrn__msg__Frontier__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  upc_mrn__msg__Frontier__Sequence * array = (upc_mrn__msg__Frontier__Sequence *)allocator.allocate(sizeof(upc_mrn__msg__Frontier__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = upc_mrn__msg__Frontier__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
upc_mrn__msg__Frontier__Sequence__destroy(upc_mrn__msg__Frontier__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    upc_mrn__msg__Frontier__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
upc_mrn__msg__Frontier__Sequence__are_equal(const upc_mrn__msg__Frontier__Sequence * lhs, const upc_mrn__msg__Frontier__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!upc_mrn__msg__Frontier__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
upc_mrn__msg__Frontier__Sequence__copy(
  const upc_mrn__msg__Frontier__Sequence * input,
  upc_mrn__msg__Frontier__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(upc_mrn__msg__Frontier);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    upc_mrn__msg__Frontier * data =
      (upc_mrn__msg__Frontier *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!upc_mrn__msg__Frontier__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          upc_mrn__msg__Frontier__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!upc_mrn__msg__Frontier__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

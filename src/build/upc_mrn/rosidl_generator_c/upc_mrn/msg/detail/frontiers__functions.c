// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from upc_mrn:msg/Frontiers.idl
// generated code does not contain a copyright notice
#include "upc_mrn/msg/detail/frontiers__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `frontiers`
#include "upc_mrn/msg/detail/frontier__functions.h"

bool
upc_mrn__msg__Frontiers__init(upc_mrn__msg__Frontiers * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    upc_mrn__msg__Frontiers__fini(msg);
    return false;
  }
  // frontiers
  if (!upc_mrn__msg__Frontier__Sequence__init(&msg->frontiers, 0)) {
    upc_mrn__msg__Frontiers__fini(msg);
    return false;
  }
  return true;
}

void
upc_mrn__msg__Frontiers__fini(upc_mrn__msg__Frontiers * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // frontiers
  upc_mrn__msg__Frontier__Sequence__fini(&msg->frontiers);
}

bool
upc_mrn__msg__Frontiers__are_equal(const upc_mrn__msg__Frontiers * lhs, const upc_mrn__msg__Frontiers * rhs)
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
  // frontiers
  if (!upc_mrn__msg__Frontier__Sequence__are_equal(
      &(lhs->frontiers), &(rhs->frontiers)))
  {
    return false;
  }
  return true;
}

bool
upc_mrn__msg__Frontiers__copy(
  const upc_mrn__msg__Frontiers * input,
  upc_mrn__msg__Frontiers * output)
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
  // frontiers
  if (!upc_mrn__msg__Frontier__Sequence__copy(
      &(input->frontiers), &(output->frontiers)))
  {
    return false;
  }
  return true;
}

upc_mrn__msg__Frontiers *
upc_mrn__msg__Frontiers__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  upc_mrn__msg__Frontiers * msg = (upc_mrn__msg__Frontiers *)allocator.allocate(sizeof(upc_mrn__msg__Frontiers), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(upc_mrn__msg__Frontiers));
  bool success = upc_mrn__msg__Frontiers__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
upc_mrn__msg__Frontiers__destroy(upc_mrn__msg__Frontiers * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    upc_mrn__msg__Frontiers__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
upc_mrn__msg__Frontiers__Sequence__init(upc_mrn__msg__Frontiers__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  upc_mrn__msg__Frontiers * data = NULL;

  if (size) {
    data = (upc_mrn__msg__Frontiers *)allocator.zero_allocate(size, sizeof(upc_mrn__msg__Frontiers), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = upc_mrn__msg__Frontiers__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        upc_mrn__msg__Frontiers__fini(&data[i - 1]);
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
upc_mrn__msg__Frontiers__Sequence__fini(upc_mrn__msg__Frontiers__Sequence * array)
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
      upc_mrn__msg__Frontiers__fini(&array->data[i]);
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

upc_mrn__msg__Frontiers__Sequence *
upc_mrn__msg__Frontiers__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  upc_mrn__msg__Frontiers__Sequence * array = (upc_mrn__msg__Frontiers__Sequence *)allocator.allocate(sizeof(upc_mrn__msg__Frontiers__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = upc_mrn__msg__Frontiers__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
upc_mrn__msg__Frontiers__Sequence__destroy(upc_mrn__msg__Frontiers__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    upc_mrn__msg__Frontiers__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
upc_mrn__msg__Frontiers__Sequence__are_equal(const upc_mrn__msg__Frontiers__Sequence * lhs, const upc_mrn__msg__Frontiers__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!upc_mrn__msg__Frontiers__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
upc_mrn__msg__Frontiers__Sequence__copy(
  const upc_mrn__msg__Frontiers__Sequence * input,
  upc_mrn__msg__Frontiers__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(upc_mrn__msg__Frontiers);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    upc_mrn__msg__Frontiers * data =
      (upc_mrn__msg__Frontiers *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!upc_mrn__msg__Frontiers__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          upc_mrn__msg__Frontiers__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!upc_mrn__msg__Frontiers__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

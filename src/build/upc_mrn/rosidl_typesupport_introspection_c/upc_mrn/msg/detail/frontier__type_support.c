// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from upc_mrn:msg/Frontier.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "upc_mrn/msg/detail/frontier__rosidl_typesupport_introspection_c.h"
#include "upc_mrn/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "upc_mrn/msg/detail/frontier__functions.h"
#include "upc_mrn/msg/detail/frontier__struct.h"


// Include directives for member types
// Member `center_point`
// Member `cells_points`
#include "geometry_msgs/msg/point.h"
// Member `center_point`
// Member `cells_points`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `cells`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__Frontier_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  upc_mrn__msg__Frontier__init(message_memory);
}

void upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__Frontier_fini_function(void * message_memory)
{
  upc_mrn__msg__Frontier__fini(message_memory);
}

size_t upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__size_function__Frontier__cells_points(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__get_const_function__Frontier__cells_points(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__get_function__Frontier__cells_points(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__fetch_function__Frontier__cells_points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__get_const_function__Frontier__cells_points(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__assign_function__Frontier__cells_points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__get_function__Frontier__cells_points(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__resize_function__Frontier__cells_points(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__size_function__Frontier__cells(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint32__Sequence * member =
    (const rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return member->size;
}

const void * upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__get_const_function__Frontier__cells(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint32__Sequence * member =
    (const rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__get_function__Frontier__cells(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint32__Sequence * member =
    (rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return &member->data[index];
}

void upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__fetch_function__Frontier__cells(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint32_t * item =
    ((const uint32_t *)
    upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__get_const_function__Frontier__cells(untyped_member, index));
  uint32_t * value =
    (uint32_t *)(untyped_value);
  *value = *item;
}

void upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__assign_function__Frontier__cells(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint32_t * item =
    ((uint32_t *)
    upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__get_function__Frontier__cells(untyped_member, index));
  const uint32_t * value =
    (const uint32_t *)(untyped_value);
  *item = *value;
}

bool upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__resize_function__Frontier__cells(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint32__Sequence * member =
    (rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  rosidl_runtime_c__uint32__Sequence__fini(member);
  return rosidl_runtime_c__uint32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__Frontier_message_member_array[5] = {
  {
    "size",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(upc_mrn__msg__Frontier, size),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "center_point",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(upc_mrn__msg__Frontier, center_point),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cells_points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(upc_mrn__msg__Frontier, cells_points),  // bytes offset in struct
    NULL,  // default value
    upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__size_function__Frontier__cells_points,  // size() function pointer
    upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__get_const_function__Frontier__cells_points,  // get_const(index) function pointer
    upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__get_function__Frontier__cells_points,  // get(index) function pointer
    upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__fetch_function__Frontier__cells_points,  // fetch(index, &value) function pointer
    upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__assign_function__Frontier__cells_points,  // assign(index, value) function pointer
    upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__resize_function__Frontier__cells_points  // resize(index) function pointer
  },
  {
    "center_cell",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(upc_mrn__msg__Frontier, center_cell),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cells",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(upc_mrn__msg__Frontier, cells),  // bytes offset in struct
    NULL,  // default value
    upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__size_function__Frontier__cells,  // size() function pointer
    upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__get_const_function__Frontier__cells,  // get_const(index) function pointer
    upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__get_function__Frontier__cells,  // get(index) function pointer
    upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__fetch_function__Frontier__cells,  // fetch(index, &value) function pointer
    upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__assign_function__Frontier__cells,  // assign(index, value) function pointer
    upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__resize_function__Frontier__cells  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__Frontier_message_members = {
  "upc_mrn__msg",  // message namespace
  "Frontier",  // message name
  5,  // number of fields
  sizeof(upc_mrn__msg__Frontier),
  upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__Frontier_message_member_array,  // message members
  upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__Frontier_init_function,  // function to initialize message memory (memory has to be allocated)
  upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__Frontier_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__Frontier_message_type_support_handle = {
  0,
  &upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__Frontier_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_upc_mrn
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, upc_mrn, msg, Frontier)() {
  upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__Frontier_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__Frontier_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__Frontier_message_type_support_handle.typesupport_identifier) {
    upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__Frontier_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &upc_mrn__msg__Frontier__rosidl_typesupport_introspection_c__Frontier_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

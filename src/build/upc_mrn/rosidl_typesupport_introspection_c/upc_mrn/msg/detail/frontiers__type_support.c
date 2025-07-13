// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from upc_mrn:msg/Frontiers.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "upc_mrn/msg/detail/frontiers__rosidl_typesupport_introspection_c.h"
#include "upc_mrn/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "upc_mrn/msg/detail/frontiers__functions.h"
#include "upc_mrn/msg/detail/frontiers__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `frontiers`
#include "upc_mrn/msg/frontier.h"
// Member `frontiers`
#include "upc_mrn/msg/detail/frontier__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__Frontiers_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  upc_mrn__msg__Frontiers__init(message_memory);
}

void upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__Frontiers_fini_function(void * message_memory)
{
  upc_mrn__msg__Frontiers__fini(message_memory);
}

size_t upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__size_function__Frontiers__frontiers(
  const void * untyped_member)
{
  const upc_mrn__msg__Frontier__Sequence * member =
    (const upc_mrn__msg__Frontier__Sequence *)(untyped_member);
  return member->size;
}

const void * upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__get_const_function__Frontiers__frontiers(
  const void * untyped_member, size_t index)
{
  const upc_mrn__msg__Frontier__Sequence * member =
    (const upc_mrn__msg__Frontier__Sequence *)(untyped_member);
  return &member->data[index];
}

void * upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__get_function__Frontiers__frontiers(
  void * untyped_member, size_t index)
{
  upc_mrn__msg__Frontier__Sequence * member =
    (upc_mrn__msg__Frontier__Sequence *)(untyped_member);
  return &member->data[index];
}

void upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__fetch_function__Frontiers__frontiers(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const upc_mrn__msg__Frontier * item =
    ((const upc_mrn__msg__Frontier *)
    upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__get_const_function__Frontiers__frontiers(untyped_member, index));
  upc_mrn__msg__Frontier * value =
    (upc_mrn__msg__Frontier *)(untyped_value);
  *value = *item;
}

void upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__assign_function__Frontiers__frontiers(
  void * untyped_member, size_t index, const void * untyped_value)
{
  upc_mrn__msg__Frontier * item =
    ((upc_mrn__msg__Frontier *)
    upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__get_function__Frontiers__frontiers(untyped_member, index));
  const upc_mrn__msg__Frontier * value =
    (const upc_mrn__msg__Frontier *)(untyped_value);
  *item = *value;
}

bool upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__resize_function__Frontiers__frontiers(
  void * untyped_member, size_t size)
{
  upc_mrn__msg__Frontier__Sequence * member =
    (upc_mrn__msg__Frontier__Sequence *)(untyped_member);
  upc_mrn__msg__Frontier__Sequence__fini(member);
  return upc_mrn__msg__Frontier__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__Frontiers_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(upc_mrn__msg__Frontiers, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "frontiers",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(upc_mrn__msg__Frontiers, frontiers),  // bytes offset in struct
    NULL,  // default value
    upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__size_function__Frontiers__frontiers,  // size() function pointer
    upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__get_const_function__Frontiers__frontiers,  // get_const(index) function pointer
    upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__get_function__Frontiers__frontiers,  // get(index) function pointer
    upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__fetch_function__Frontiers__frontiers,  // fetch(index, &value) function pointer
    upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__assign_function__Frontiers__frontiers,  // assign(index, value) function pointer
    upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__resize_function__Frontiers__frontiers  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__Frontiers_message_members = {
  "upc_mrn__msg",  // message namespace
  "Frontiers",  // message name
  2,  // number of fields
  sizeof(upc_mrn__msg__Frontiers),
  upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__Frontiers_message_member_array,  // message members
  upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__Frontiers_init_function,  // function to initialize message memory (memory has to be allocated)
  upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__Frontiers_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__Frontiers_message_type_support_handle = {
  0,
  &upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__Frontiers_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_upc_mrn
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, upc_mrn, msg, Frontiers)() {
  upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__Frontiers_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__Frontiers_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, upc_mrn, msg, Frontier)();
  if (!upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__Frontiers_message_type_support_handle.typesupport_identifier) {
    upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__Frontiers_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &upc_mrn__msg__Frontiers__rosidl_typesupport_introspection_c__Frontiers_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from upc_mrn:msg/Frontier.idl
// generated code does not contain a copyright notice

#ifndef UPC_MRN__MSG__DETAIL__FRONTIER__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define UPC_MRN__MSG__DETAIL__FRONTIER__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "upc_mrn/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "upc_mrn/msg/detail/frontier__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace upc_mrn
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_upc_mrn
cdr_serialize(
  const upc_mrn::msg::Frontier & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_upc_mrn
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  upc_mrn::msg::Frontier & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_upc_mrn
get_serialized_size(
  const upc_mrn::msg::Frontier & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_upc_mrn
max_serialized_size_Frontier(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace upc_mrn

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_upc_mrn
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, upc_mrn, msg, Frontier)();

#ifdef __cplusplus
}
#endif

#endif  // UPC_MRN__MSG__DETAIL__FRONTIER__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

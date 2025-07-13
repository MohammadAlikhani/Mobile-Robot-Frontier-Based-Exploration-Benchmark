// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from upc_mrn:msg/Frontiers.idl
// generated code does not contain a copyright notice

#ifndef UPC_MRN__MSG__DETAIL__FRONTIERS__BUILDER_HPP_
#define UPC_MRN__MSG__DETAIL__FRONTIERS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "upc_mrn/msg/detail/frontiers__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace upc_mrn
{

namespace msg
{

namespace builder
{

class Init_Frontiers_frontiers
{
public:
  explicit Init_Frontiers_frontiers(::upc_mrn::msg::Frontiers & msg)
  : msg_(msg)
  {}
  ::upc_mrn::msg::Frontiers frontiers(::upc_mrn::msg::Frontiers::_frontiers_type arg)
  {
    msg_.frontiers = std::move(arg);
    return std::move(msg_);
  }

private:
  ::upc_mrn::msg::Frontiers msg_;
};

class Init_Frontiers_header
{
public:
  Init_Frontiers_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Frontiers_frontiers header(::upc_mrn::msg::Frontiers::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Frontiers_frontiers(msg_);
  }

private:
  ::upc_mrn::msg::Frontiers msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::upc_mrn::msg::Frontiers>()
{
  return upc_mrn::msg::builder::Init_Frontiers_header();
}

}  // namespace upc_mrn

#endif  // UPC_MRN__MSG__DETAIL__FRONTIERS__BUILDER_HPP_

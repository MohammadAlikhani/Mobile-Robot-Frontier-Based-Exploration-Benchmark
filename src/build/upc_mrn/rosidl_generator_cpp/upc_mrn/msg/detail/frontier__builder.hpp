// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from upc_mrn:msg/Frontier.idl
// generated code does not contain a copyright notice

#ifndef UPC_MRN__MSG__DETAIL__FRONTIER__BUILDER_HPP_
#define UPC_MRN__MSG__DETAIL__FRONTIER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "upc_mrn/msg/detail/frontier__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace upc_mrn
{

namespace msg
{

namespace builder
{

class Init_Frontier_cells
{
public:
  explicit Init_Frontier_cells(::upc_mrn::msg::Frontier & msg)
  : msg_(msg)
  {}
  ::upc_mrn::msg::Frontier cells(::upc_mrn::msg::Frontier::_cells_type arg)
  {
    msg_.cells = std::move(arg);
    return std::move(msg_);
  }

private:
  ::upc_mrn::msg::Frontier msg_;
};

class Init_Frontier_center_cell
{
public:
  explicit Init_Frontier_center_cell(::upc_mrn::msg::Frontier & msg)
  : msg_(msg)
  {}
  Init_Frontier_cells center_cell(::upc_mrn::msg::Frontier::_center_cell_type arg)
  {
    msg_.center_cell = std::move(arg);
    return Init_Frontier_cells(msg_);
  }

private:
  ::upc_mrn::msg::Frontier msg_;
};

class Init_Frontier_cells_points
{
public:
  explicit Init_Frontier_cells_points(::upc_mrn::msg::Frontier & msg)
  : msg_(msg)
  {}
  Init_Frontier_center_cell cells_points(::upc_mrn::msg::Frontier::_cells_points_type arg)
  {
    msg_.cells_points = std::move(arg);
    return Init_Frontier_center_cell(msg_);
  }

private:
  ::upc_mrn::msg::Frontier msg_;
};

class Init_Frontier_center_point
{
public:
  explicit Init_Frontier_center_point(::upc_mrn::msg::Frontier & msg)
  : msg_(msg)
  {}
  Init_Frontier_cells_points center_point(::upc_mrn::msg::Frontier::_center_point_type arg)
  {
    msg_.center_point = std::move(arg);
    return Init_Frontier_cells_points(msg_);
  }

private:
  ::upc_mrn::msg::Frontier msg_;
};

class Init_Frontier_size
{
public:
  Init_Frontier_size()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Frontier_center_point size(::upc_mrn::msg::Frontier::_size_type arg)
  {
    msg_.size = std::move(arg);
    return Init_Frontier_center_point(msg_);
  }

private:
  ::upc_mrn::msg::Frontier msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::upc_mrn::msg::Frontier>()
{
  return upc_mrn::msg::builder::Init_Frontier_size();
}

}  // namespace upc_mrn

#endif  // UPC_MRN__MSG__DETAIL__FRONTIER__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from upc_mrn:msg/Frontier.idl
// generated code does not contain a copyright notice

#ifndef UPC_MRN__MSG__DETAIL__FRONTIER__TRAITS_HPP_
#define UPC_MRN__MSG__DETAIL__FRONTIER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "upc_mrn/msg/detail/frontier__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'center_point'
// Member 'cells_points'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace upc_mrn
{

namespace msg
{

inline void to_flow_style_yaml(
  const Frontier & msg,
  std::ostream & out)
{
  out << "{";
  // member: size
  {
    out << "size: ";
    rosidl_generator_traits::value_to_yaml(msg.size, out);
    out << ", ";
  }

  // member: center_point
  {
    out << "center_point: ";
    to_flow_style_yaml(msg.center_point, out);
    out << ", ";
  }

  // member: cells_points
  {
    if (msg.cells_points.size() == 0) {
      out << "cells_points: []";
    } else {
      out << "cells_points: [";
      size_t pending_items = msg.cells_points.size();
      for (auto item : msg.cells_points) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: center_cell
  {
    out << "center_cell: ";
    rosidl_generator_traits::value_to_yaml(msg.center_cell, out);
    out << ", ";
  }

  // member: cells
  {
    if (msg.cells.size() == 0) {
      out << "cells: []";
    } else {
      out << "cells: [";
      size_t pending_items = msg.cells.size();
      for (auto item : msg.cells) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Frontier & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: size
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "size: ";
    rosidl_generator_traits::value_to_yaml(msg.size, out);
    out << "\n";
  }

  // member: center_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_point:\n";
    to_block_style_yaml(msg.center_point, out, indentation + 2);
  }

  // member: cells_points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.cells_points.size() == 0) {
      out << "cells_points: []\n";
    } else {
      out << "cells_points:\n";
      for (auto item : msg.cells_points) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: center_cell
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_cell: ";
    rosidl_generator_traits::value_to_yaml(msg.center_cell, out);
    out << "\n";
  }

  // member: cells
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.cells.size() == 0) {
      out << "cells: []\n";
    } else {
      out << "cells:\n";
      for (auto item : msg.cells) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Frontier & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace upc_mrn

namespace rosidl_generator_traits
{

[[deprecated("use upc_mrn::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const upc_mrn::msg::Frontier & msg,
  std::ostream & out, size_t indentation = 0)
{
  upc_mrn::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use upc_mrn::msg::to_yaml() instead")]]
inline std::string to_yaml(const upc_mrn::msg::Frontier & msg)
{
  return upc_mrn::msg::to_yaml(msg);
}

template<>
inline const char * data_type<upc_mrn::msg::Frontier>()
{
  return "upc_mrn::msg::Frontier";
}

template<>
inline const char * name<upc_mrn::msg::Frontier>()
{
  return "upc_mrn/msg/Frontier";
}

template<>
struct has_fixed_size<upc_mrn::msg::Frontier>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<upc_mrn::msg::Frontier>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<upc_mrn::msg::Frontier>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UPC_MRN__MSG__DETAIL__FRONTIER__TRAITS_HPP_

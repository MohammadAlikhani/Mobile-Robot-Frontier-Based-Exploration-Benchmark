// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from upc_mrn:msg/Frontiers.idl
// generated code does not contain a copyright notice

#ifndef UPC_MRN__MSG__DETAIL__FRONTIERS__TRAITS_HPP_
#define UPC_MRN__MSG__DETAIL__FRONTIERS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "upc_mrn/msg/detail/frontiers__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'frontiers'
#include "upc_mrn/msg/detail/frontier__traits.hpp"

namespace upc_mrn
{

namespace msg
{

inline void to_flow_style_yaml(
  const Frontiers & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: frontiers
  {
    if (msg.frontiers.size() == 0) {
      out << "frontiers: []";
    } else {
      out << "frontiers: [";
      size_t pending_items = msg.frontiers.size();
      for (auto item : msg.frontiers) {
        to_flow_style_yaml(item, out);
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
  const Frontiers & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: frontiers
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.frontiers.size() == 0) {
      out << "frontiers: []\n";
    } else {
      out << "frontiers:\n";
      for (auto item : msg.frontiers) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Frontiers & msg, bool use_flow_style = false)
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
  const upc_mrn::msg::Frontiers & msg,
  std::ostream & out, size_t indentation = 0)
{
  upc_mrn::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use upc_mrn::msg::to_yaml() instead")]]
inline std::string to_yaml(const upc_mrn::msg::Frontiers & msg)
{
  return upc_mrn::msg::to_yaml(msg);
}

template<>
inline const char * data_type<upc_mrn::msg::Frontiers>()
{
  return "upc_mrn::msg::Frontiers";
}

template<>
inline const char * name<upc_mrn::msg::Frontiers>()
{
  return "upc_mrn/msg/Frontiers";
}

template<>
struct has_fixed_size<upc_mrn::msg::Frontiers>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<upc_mrn::msg::Frontiers>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<upc_mrn::msg::Frontiers>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UPC_MRN__MSG__DETAIL__FRONTIERS__TRAITS_HPP_

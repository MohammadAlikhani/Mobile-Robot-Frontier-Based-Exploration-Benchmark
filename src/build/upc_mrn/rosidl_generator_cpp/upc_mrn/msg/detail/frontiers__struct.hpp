// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from upc_mrn:msg/Frontiers.idl
// generated code does not contain a copyright notice

#ifndef UPC_MRN__MSG__DETAIL__FRONTIERS__STRUCT_HPP_
#define UPC_MRN__MSG__DETAIL__FRONTIERS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'frontiers'
#include "upc_mrn/msg/detail/frontier__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__upc_mrn__msg__Frontiers __attribute__((deprecated))
#else
# define DEPRECATED__upc_mrn__msg__Frontiers __declspec(deprecated)
#endif

namespace upc_mrn
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Frontiers_
{
  using Type = Frontiers_<ContainerAllocator>;

  explicit Frontiers_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit Frontiers_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _frontiers_type =
    std::vector<upc_mrn::msg::Frontier_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<upc_mrn::msg::Frontier_<ContainerAllocator>>>;
  _frontiers_type frontiers;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__frontiers(
    const std::vector<upc_mrn::msg::Frontier_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<upc_mrn::msg::Frontier_<ContainerAllocator>>> & _arg)
  {
    this->frontiers = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    upc_mrn::msg::Frontiers_<ContainerAllocator> *;
  using ConstRawPtr =
    const upc_mrn::msg::Frontiers_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<upc_mrn::msg::Frontiers_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<upc_mrn::msg::Frontiers_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      upc_mrn::msg::Frontiers_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<upc_mrn::msg::Frontiers_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      upc_mrn::msg::Frontiers_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<upc_mrn::msg::Frontiers_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<upc_mrn::msg::Frontiers_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<upc_mrn::msg::Frontiers_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__upc_mrn__msg__Frontiers
    std::shared_ptr<upc_mrn::msg::Frontiers_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__upc_mrn__msg__Frontiers
    std::shared_ptr<upc_mrn::msg::Frontiers_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Frontiers_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->frontiers != other.frontiers) {
      return false;
    }
    return true;
  }
  bool operator!=(const Frontiers_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Frontiers_

// alias to use template instance with default allocator
using Frontiers =
  upc_mrn::msg::Frontiers_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace upc_mrn

#endif  // UPC_MRN__MSG__DETAIL__FRONTIERS__STRUCT_HPP_

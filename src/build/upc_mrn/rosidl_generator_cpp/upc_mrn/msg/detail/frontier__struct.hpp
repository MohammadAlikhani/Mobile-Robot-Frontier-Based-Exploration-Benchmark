// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from upc_mrn:msg/Frontier.idl
// generated code does not contain a copyright notice

#ifndef UPC_MRN__MSG__DETAIL__FRONTIER__STRUCT_HPP_
#define UPC_MRN__MSG__DETAIL__FRONTIER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'center_point'
// Member 'cells_points'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__upc_mrn__msg__Frontier __attribute__((deprecated))
#else
# define DEPRECATED__upc_mrn__msg__Frontier __declspec(deprecated)
#endif

namespace upc_mrn
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Frontier_
{
  using Type = Frontier_<ContainerAllocator>;

  explicit Frontier_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : center_point(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->size = 0ul;
      this->center_cell = 0ul;
    }
  }

  explicit Frontier_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : center_point(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->size = 0ul;
      this->center_cell = 0ul;
    }
  }

  // field types and members
  using _size_type =
    uint32_t;
  _size_type size;
  using _center_point_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _center_point_type center_point;
  using _cells_points_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _cells_points_type cells_points;
  using _center_cell_type =
    uint32_t;
  _center_cell_type center_cell;
  using _cells_type =
    std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>>;
  _cells_type cells;

  // setters for named parameter idiom
  Type & set__size(
    const uint32_t & _arg)
  {
    this->size = _arg;
    return *this;
  }
  Type & set__center_point(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->center_point = _arg;
    return *this;
  }
  Type & set__cells_points(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->cells_points = _arg;
    return *this;
  }
  Type & set__center_cell(
    const uint32_t & _arg)
  {
    this->center_cell = _arg;
    return *this;
  }
  Type & set__cells(
    const std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>> & _arg)
  {
    this->cells = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    upc_mrn::msg::Frontier_<ContainerAllocator> *;
  using ConstRawPtr =
    const upc_mrn::msg::Frontier_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<upc_mrn::msg::Frontier_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<upc_mrn::msg::Frontier_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      upc_mrn::msg::Frontier_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<upc_mrn::msg::Frontier_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      upc_mrn::msg::Frontier_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<upc_mrn::msg::Frontier_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<upc_mrn::msg::Frontier_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<upc_mrn::msg::Frontier_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__upc_mrn__msg__Frontier
    std::shared_ptr<upc_mrn::msg::Frontier_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__upc_mrn__msg__Frontier
    std::shared_ptr<upc_mrn::msg::Frontier_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Frontier_ & other) const
  {
    if (this->size != other.size) {
      return false;
    }
    if (this->center_point != other.center_point) {
      return false;
    }
    if (this->cells_points != other.cells_points) {
      return false;
    }
    if (this->center_cell != other.center_cell) {
      return false;
    }
    if (this->cells != other.cells) {
      return false;
    }
    return true;
  }
  bool operator!=(const Frontier_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Frontier_

// alias to use template instance with default allocator
using Frontier =
  upc_mrn::msg::Frontier_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace upc_mrn

#endif  // UPC_MRN__MSG__DETAIL__FRONTIER__STRUCT_HPP_

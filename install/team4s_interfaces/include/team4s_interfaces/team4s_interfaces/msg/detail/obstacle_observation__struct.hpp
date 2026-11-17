// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from team4s_interfaces:msg/ObstacleObservation.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__OBSTACLE_OBSERVATION__STRUCT_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__OBSTACLE_OBSERVATION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'meta'
#include "team4s_interfaces/msg/detail/source_header__struct.hpp"
// Member 'readings'
#include "team4s_interfaces/msg/detail/range_reading__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__team4s_interfaces__msg__ObstacleObservation __attribute__((deprecated))
#else
# define DEPRECATED__team4s_interfaces__msg__ObstacleObservation __declspec(deprecated)
#endif

namespace team4s_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ObstacleObservation_
{
  using Type = ObstacleObservation_<ContainerAllocator>;

  explicit ObstacleObservation_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : meta(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_clear_known = false;
      this->left_clear = false;
      this->right_clear_known = false;
      this->right_clear = false;
    }
  }

  explicit ObstacleObservation_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : meta(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_clear_known = false;
      this->left_clear = false;
      this->right_clear_known = false;
      this->right_clear = false;
    }
  }

  // field types and members
  using _meta_type =
    team4s_interfaces::msg::SourceHeader_<ContainerAllocator>;
  _meta_type meta;
  using _readings_type =
    std::vector<team4s_interfaces::msg::RangeReading_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<team4s_interfaces::msg::RangeReading_<ContainerAllocator>>>;
  _readings_type readings;
  using _left_clear_known_type =
    bool;
  _left_clear_known_type left_clear_known;
  using _left_clear_type =
    bool;
  _left_clear_type left_clear;
  using _right_clear_known_type =
    bool;
  _right_clear_known_type right_clear_known;
  using _right_clear_type =
    bool;
  _right_clear_type right_clear;

  // setters for named parameter idiom
  Type & set__meta(
    const team4s_interfaces::msg::SourceHeader_<ContainerAllocator> & _arg)
  {
    this->meta = _arg;
    return *this;
  }
  Type & set__readings(
    const std::vector<team4s_interfaces::msg::RangeReading_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<team4s_interfaces::msg::RangeReading_<ContainerAllocator>>> & _arg)
  {
    this->readings = _arg;
    return *this;
  }
  Type & set__left_clear_known(
    const bool & _arg)
  {
    this->left_clear_known = _arg;
    return *this;
  }
  Type & set__left_clear(
    const bool & _arg)
  {
    this->left_clear = _arg;
    return *this;
  }
  Type & set__right_clear_known(
    const bool & _arg)
  {
    this->right_clear_known = _arg;
    return *this;
  }
  Type & set__right_clear(
    const bool & _arg)
  {
    this->right_clear = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    team4s_interfaces::msg::ObstacleObservation_<ContainerAllocator> *;
  using ConstRawPtr =
    const team4s_interfaces::msg::ObstacleObservation_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<team4s_interfaces::msg::ObstacleObservation_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<team4s_interfaces::msg::ObstacleObservation_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      team4s_interfaces::msg::ObstacleObservation_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<team4s_interfaces::msg::ObstacleObservation_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      team4s_interfaces::msg::ObstacleObservation_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<team4s_interfaces::msg::ObstacleObservation_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<team4s_interfaces::msg::ObstacleObservation_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<team4s_interfaces::msg::ObstacleObservation_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__team4s_interfaces__msg__ObstacleObservation
    std::shared_ptr<team4s_interfaces::msg::ObstacleObservation_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__team4s_interfaces__msg__ObstacleObservation
    std::shared_ptr<team4s_interfaces::msg::ObstacleObservation_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObstacleObservation_ & other) const
  {
    if (this->meta != other.meta) {
      return false;
    }
    if (this->readings != other.readings) {
      return false;
    }
    if (this->left_clear_known != other.left_clear_known) {
      return false;
    }
    if (this->left_clear != other.left_clear) {
      return false;
    }
    if (this->right_clear_known != other.right_clear_known) {
      return false;
    }
    if (this->right_clear != other.right_clear) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObstacleObservation_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObstacleObservation_

// alias to use template instance with default allocator
using ObstacleObservation =
  team4s_interfaces::msg::ObstacleObservation_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace team4s_interfaces

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__OBSTACLE_OBSERVATION__STRUCT_HPP_

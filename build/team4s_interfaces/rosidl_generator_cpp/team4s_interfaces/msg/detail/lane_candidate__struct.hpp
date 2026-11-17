// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from team4s_interfaces:msg/LaneCandidate.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__LANE_CANDIDATE__STRUCT_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__LANE_CANDIDATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__team4s_interfaces__msg__LaneCandidate __attribute__((deprecated))
#else
# define DEPRECATED__team4s_interfaces__msg__LaneCandidate __declspec(deprecated)
#endif

namespace team4s_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LaneCandidate_
{
  using Type = LaneCandidate_<ContainerAllocator>;

  explicit LaneCandidate_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->candidate_id = "";
      this->route_lane = 0;
      this->is_branch = false;
      this->left_visible = false;
      this->right_visible = false;
      this->center_valid = false;
      this->offset_px = 0.0f;
      this->reference_y_px = 0l;
      this->heading_valid = false;
      this->heading_rad = 0.0f;
    }
  }

  explicit LaneCandidate_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : candidate_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->candidate_id = "";
      this->route_lane = 0;
      this->is_branch = false;
      this->left_visible = false;
      this->right_visible = false;
      this->center_valid = false;
      this->offset_px = 0.0f;
      this->reference_y_px = 0l;
      this->heading_valid = false;
      this->heading_rad = 0.0f;
    }
  }

  // field types and members
  using _candidate_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _candidate_id_type candidate_id;
  using _route_lane_type =
    uint8_t;
  _route_lane_type route_lane;
  using _is_branch_type =
    bool;
  _is_branch_type is_branch;
  using _left_visible_type =
    bool;
  _left_visible_type left_visible;
  using _right_visible_type =
    bool;
  _right_visible_type right_visible;
  using _center_valid_type =
    bool;
  _center_valid_type center_valid;
  using _offset_px_type =
    float;
  _offset_px_type offset_px;
  using _reference_y_px_type =
    int32_t;
  _reference_y_px_type reference_y_px;
  using _heading_valid_type =
    bool;
  _heading_valid_type heading_valid;
  using _heading_rad_type =
    float;
  _heading_rad_type heading_rad;

  // setters for named parameter idiom
  Type & set__candidate_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->candidate_id = _arg;
    return *this;
  }
  Type & set__route_lane(
    const uint8_t & _arg)
  {
    this->route_lane = _arg;
    return *this;
  }
  Type & set__is_branch(
    const bool & _arg)
  {
    this->is_branch = _arg;
    return *this;
  }
  Type & set__left_visible(
    const bool & _arg)
  {
    this->left_visible = _arg;
    return *this;
  }
  Type & set__right_visible(
    const bool & _arg)
  {
    this->right_visible = _arg;
    return *this;
  }
  Type & set__center_valid(
    const bool & _arg)
  {
    this->center_valid = _arg;
    return *this;
  }
  Type & set__offset_px(
    const float & _arg)
  {
    this->offset_px = _arg;
    return *this;
  }
  Type & set__reference_y_px(
    const int32_t & _arg)
  {
    this->reference_y_px = _arg;
    return *this;
  }
  Type & set__heading_valid(
    const bool & _arg)
  {
    this->heading_valid = _arg;
    return *this;
  }
  Type & set__heading_rad(
    const float & _arg)
  {
    this->heading_rad = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t UNKNOWN =
    0u;
  static constexpr uint8_t FIRST =
    1u;
  static constexpr uint8_t SECOND =
    2u;

  // pointer types
  using RawPtr =
    team4s_interfaces::msg::LaneCandidate_<ContainerAllocator> *;
  using ConstRawPtr =
    const team4s_interfaces::msg::LaneCandidate_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<team4s_interfaces::msg::LaneCandidate_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<team4s_interfaces::msg::LaneCandidate_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      team4s_interfaces::msg::LaneCandidate_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<team4s_interfaces::msg::LaneCandidate_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      team4s_interfaces::msg::LaneCandidate_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<team4s_interfaces::msg::LaneCandidate_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<team4s_interfaces::msg::LaneCandidate_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<team4s_interfaces::msg::LaneCandidate_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__team4s_interfaces__msg__LaneCandidate
    std::shared_ptr<team4s_interfaces::msg::LaneCandidate_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__team4s_interfaces__msg__LaneCandidate
    std::shared_ptr<team4s_interfaces::msg::LaneCandidate_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LaneCandidate_ & other) const
  {
    if (this->candidate_id != other.candidate_id) {
      return false;
    }
    if (this->route_lane != other.route_lane) {
      return false;
    }
    if (this->is_branch != other.is_branch) {
      return false;
    }
    if (this->left_visible != other.left_visible) {
      return false;
    }
    if (this->right_visible != other.right_visible) {
      return false;
    }
    if (this->center_valid != other.center_valid) {
      return false;
    }
    if (this->offset_px != other.offset_px) {
      return false;
    }
    if (this->reference_y_px != other.reference_y_px) {
      return false;
    }
    if (this->heading_valid != other.heading_valid) {
      return false;
    }
    if (this->heading_rad != other.heading_rad) {
      return false;
    }
    return true;
  }
  bool operator!=(const LaneCandidate_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LaneCandidate_

// alias to use template instance with default allocator
using LaneCandidate =
  team4s_interfaces::msg::LaneCandidate_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t LaneCandidate_<ContainerAllocator>::UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t LaneCandidate_<ContainerAllocator>::FIRST;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t LaneCandidate_<ContainerAllocator>::SECOND;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace team4s_interfaces

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__LANE_CANDIDATE__STRUCT_HPP_

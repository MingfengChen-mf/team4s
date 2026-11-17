// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from team4s_interfaces:msg/ConeDetection.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__CONE_DETECTION__STRUCT_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__CONE_DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__team4s_interfaces__msg__ConeDetection __attribute__((deprecated))
#else
# define DEPRECATED__team4s_interfaces__msg__ConeDetection __declspec(deprecated)
#endif

namespace team4s_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ConeDetection_
{
  using Type = ConeDetection_<ContainerAllocator>;

  explicit ConeDetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->candidate_id = "";
      this->color = 0;
      this->bbox_known = false;
      std::fill<typename std::array<int32_t, 4>::iterator, int32_t>(this->bbox_xyxy.begin(), this->bbox_xyxy.end(), 0l);
      this->color_pixels = 0ul;
    }
  }

  explicit ConeDetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : candidate_id(_alloc),
    bbox_xyxy(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->candidate_id = "";
      this->color = 0;
      this->bbox_known = false;
      std::fill<typename std::array<int32_t, 4>::iterator, int32_t>(this->bbox_xyxy.begin(), this->bbox_xyxy.end(), 0l);
      this->color_pixels = 0ul;
    }
  }

  // field types and members
  using _candidate_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _candidate_id_type candidate_id;
  using _color_type =
    uint8_t;
  _color_type color;
  using _bbox_known_type =
    bool;
  _bbox_known_type bbox_known;
  using _bbox_xyxy_type =
    std::array<int32_t, 4>;
  _bbox_xyxy_type bbox_xyxy;
  using _color_pixels_type =
    uint32_t;
  _color_pixels_type color_pixels;

  // setters for named parameter idiom
  Type & set__candidate_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->candidate_id = _arg;
    return *this;
  }
  Type & set__color(
    const uint8_t & _arg)
  {
    this->color = _arg;
    return *this;
  }
  Type & set__bbox_known(
    const bool & _arg)
  {
    this->bbox_known = _arg;
    return *this;
  }
  Type & set__bbox_xyxy(
    const std::array<int32_t, 4> & _arg)
  {
    this->bbox_xyxy = _arg;
    return *this;
  }
  Type & set__color_pixels(
    const uint32_t & _arg)
  {
    this->color_pixels = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t COLOR_UNKNOWN =
    0u;
  static constexpr uint8_t COLOR_GREEN =
    1u;
  static constexpr uint8_t COLOR_RED =
    2u;

  // pointer types
  using RawPtr =
    team4s_interfaces::msg::ConeDetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const team4s_interfaces::msg::ConeDetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<team4s_interfaces::msg::ConeDetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<team4s_interfaces::msg::ConeDetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      team4s_interfaces::msg::ConeDetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<team4s_interfaces::msg::ConeDetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      team4s_interfaces::msg::ConeDetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<team4s_interfaces::msg::ConeDetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<team4s_interfaces::msg::ConeDetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<team4s_interfaces::msg::ConeDetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__team4s_interfaces__msg__ConeDetection
    std::shared_ptr<team4s_interfaces::msg::ConeDetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__team4s_interfaces__msg__ConeDetection
    std::shared_ptr<team4s_interfaces::msg::ConeDetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ConeDetection_ & other) const
  {
    if (this->candidate_id != other.candidate_id) {
      return false;
    }
    if (this->color != other.color) {
      return false;
    }
    if (this->bbox_known != other.bbox_known) {
      return false;
    }
    if (this->bbox_xyxy != other.bbox_xyxy) {
      return false;
    }
    if (this->color_pixels != other.color_pixels) {
      return false;
    }
    return true;
  }
  bool operator!=(const ConeDetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ConeDetection_

// alias to use template instance with default allocator
using ConeDetection =
  team4s_interfaces::msg::ConeDetection_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ConeDetection_<ContainerAllocator>::COLOR_UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ConeDetection_<ContainerAllocator>::COLOR_GREEN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ConeDetection_<ContainerAllocator>::COLOR_RED;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace team4s_interfaces

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__CONE_DETECTION__STRUCT_HPP_

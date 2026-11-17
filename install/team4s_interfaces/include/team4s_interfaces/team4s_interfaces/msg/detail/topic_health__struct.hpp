// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from team4s_interfaces:msg/TopicHealth.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__TOPIC_HEALTH__STRUCT_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__TOPIC_HEALTH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__team4s_interfaces__msg__TopicHealth __attribute__((deprecated))
#else
# define DEPRECATED__team4s_interfaces__msg__TopicHealth __declspec(deprecated)
#endif

namespace team4s_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TopicHealth_
{
  using Type = TopicHealth_<ContainerAllocator>;

  explicit TopicHealth_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
      this->reason = "";
      this->age_known = false;
      this->age_s = 0.0f;
      this->max_age_s = 0.0f;
    }
  }

  explicit TopicHealth_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reason(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
      this->reason = "";
      this->age_known = false;
      this->age_s = 0.0f;
      this->max_age_s = 0.0f;
    }
  }

  // field types and members
  using _state_type =
    uint8_t;
  _state_type state;
  using _reason_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _reason_type reason;
  using _age_known_type =
    bool;
  _age_known_type age_known;
  using _age_s_type =
    float;
  _age_s_type age_s;
  using _max_age_s_type =
    float;
  _max_age_s_type max_age_s;

  // setters for named parameter idiom
  Type & set__state(
    const uint8_t & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__reason(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->reason = _arg;
    return *this;
  }
  Type & set__age_known(
    const bool & _arg)
  {
    this->age_known = _arg;
    return *this;
  }
  Type & set__age_s(
    const float & _arg)
  {
    this->age_s = _arg;
    return *this;
  }
  Type & set__max_age_s(
    const float & _arg)
  {
    this->max_age_s = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t MISSING =
    0u;
  static constexpr uint8_t VALID =
    1u;
  static constexpr uint8_t INVALID =
    2u;
  static constexpr uint8_t STALE =
    3u;

  // pointer types
  using RawPtr =
    team4s_interfaces::msg::TopicHealth_<ContainerAllocator> *;
  using ConstRawPtr =
    const team4s_interfaces::msg::TopicHealth_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<team4s_interfaces::msg::TopicHealth_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<team4s_interfaces::msg::TopicHealth_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      team4s_interfaces::msg::TopicHealth_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<team4s_interfaces::msg::TopicHealth_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      team4s_interfaces::msg::TopicHealth_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<team4s_interfaces::msg::TopicHealth_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<team4s_interfaces::msg::TopicHealth_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<team4s_interfaces::msg::TopicHealth_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__team4s_interfaces__msg__TopicHealth
    std::shared_ptr<team4s_interfaces::msg::TopicHealth_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__team4s_interfaces__msg__TopicHealth
    std::shared_ptr<team4s_interfaces::msg::TopicHealth_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TopicHealth_ & other) const
  {
    if (this->state != other.state) {
      return false;
    }
    if (this->reason != other.reason) {
      return false;
    }
    if (this->age_known != other.age_known) {
      return false;
    }
    if (this->age_s != other.age_s) {
      return false;
    }
    if (this->max_age_s != other.max_age_s) {
      return false;
    }
    return true;
  }
  bool operator!=(const TopicHealth_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TopicHealth_

// alias to use template instance with default allocator
using TopicHealth =
  team4s_interfaces::msg::TopicHealth_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TopicHealth_<ContainerAllocator>::MISSING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TopicHealth_<ContainerAllocator>::VALID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TopicHealth_<ContainerAllocator>::INVALID;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TopicHealth_<ContainerAllocator>::STALE;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace team4s_interfaces

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__TOPIC_HEALTH__STRUCT_HPP_

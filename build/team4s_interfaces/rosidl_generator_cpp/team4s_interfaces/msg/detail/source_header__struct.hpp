// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from team4s_interfaces:msg/SourceHeader.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__SOURCE_HEADER__STRUCT_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__SOURCE_HEADER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__team4s_interfaces__msg__SourceHeader __attribute__((deprecated))
#else
# define DEPRECATED__team4s_interfaces__msg__SourceHeader __declspec(deprecated)
#endif

namespace team4s_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SourceHeader_
{
  using Type = SourceHeader_<ContainerAllocator>;

  explicit SourceHeader_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->source_id = "";
      this->source_session_id = "";
      this->run_id = "";
      this->sequence = 0ull;
      this->stamp_source = 0;
      this->valid = false;
      this->reason = "";
    }
  }

  explicit SourceHeader_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    source_id(_alloc),
    source_session_id(_alloc),
    run_id(_alloc),
    reason(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->source_id = "";
      this->source_session_id = "";
      this->run_id = "";
      this->sequence = 0ull;
      this->stamp_source = 0;
      this->valid = false;
      this->reason = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _source_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _source_id_type source_id;
  using _source_session_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _source_session_id_type source_session_id;
  using _run_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _run_id_type run_id;
  using _sequence_type =
    uint64_t;
  _sequence_type sequence;
  using _stamp_source_type =
    uint8_t;
  _stamp_source_type stamp_source;
  using _valid_type =
    bool;
  _valid_type valid;
  using _reason_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _reason_type reason;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__source_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->source_id = _arg;
    return *this;
  }
  Type & set__source_session_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->source_session_id = _arg;
    return *this;
  }
  Type & set__run_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->run_id = _arg;
    return *this;
  }
  Type & set__sequence(
    const uint64_t & _arg)
  {
    this->sequence = _arg;
    return *this;
  }
  Type & set__stamp_source(
    const uint8_t & _arg)
  {
    this->stamp_source = _arg;
    return *this;
  }
  Type & set__valid(
    const bool & _arg)
  {
    this->valid = _arg;
    return *this;
  }
  Type & set__reason(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->reason = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t STAMP_UNKNOWN =
    0u;
  static constexpr uint8_t STAMP_READ_START =
    1u;
  static constexpr uint8_t STAMP_HARDWARE_SYNCED =
    2u;

  // pointer types
  using RawPtr =
    team4s_interfaces::msg::SourceHeader_<ContainerAllocator> *;
  using ConstRawPtr =
    const team4s_interfaces::msg::SourceHeader_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<team4s_interfaces::msg::SourceHeader_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<team4s_interfaces::msg::SourceHeader_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      team4s_interfaces::msg::SourceHeader_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<team4s_interfaces::msg::SourceHeader_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      team4s_interfaces::msg::SourceHeader_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<team4s_interfaces::msg::SourceHeader_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<team4s_interfaces::msg::SourceHeader_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<team4s_interfaces::msg::SourceHeader_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__team4s_interfaces__msg__SourceHeader
    std::shared_ptr<team4s_interfaces::msg::SourceHeader_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__team4s_interfaces__msg__SourceHeader
    std::shared_ptr<team4s_interfaces::msg::SourceHeader_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SourceHeader_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->source_id != other.source_id) {
      return false;
    }
    if (this->source_session_id != other.source_session_id) {
      return false;
    }
    if (this->run_id != other.run_id) {
      return false;
    }
    if (this->sequence != other.sequence) {
      return false;
    }
    if (this->stamp_source != other.stamp_source) {
      return false;
    }
    if (this->valid != other.valid) {
      return false;
    }
    if (this->reason != other.reason) {
      return false;
    }
    return true;
  }
  bool operator!=(const SourceHeader_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SourceHeader_

// alias to use template instance with default allocator
using SourceHeader =
  team4s_interfaces::msg::SourceHeader_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SourceHeader_<ContainerAllocator>::STAMP_UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SourceHeader_<ContainerAllocator>::STAMP_READ_START;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SourceHeader_<ContainerAllocator>::STAMP_HARDWARE_SYNCED;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace team4s_interfaces

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__SOURCE_HEADER__STRUCT_HPP_

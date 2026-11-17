// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from team4s_interfaces:msg/RangeReading.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__RANGE_READING__STRUCT_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__RANGE_READING__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__team4s_interfaces__msg__RangeReading __attribute__((deprecated))
#else
# define DEPRECATED__team4s_interfaces__msg__RangeReading __declspec(deprecated)
#endif

namespace team4s_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RangeReading_
{
  using Type = RangeReading_<ContainerAllocator>;

  explicit RangeReading_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sensor_id = "";
      this->sensor_frame_id = "";
      this->valid = false;
      this->reason = "";
      this->checksum_ok = false;
      this->device_status_raw = 0;
      this->distance_m = 0.0f;
      this->signal_strength = 0ul;
      this->sensor_time_ms = 0ul;
      this->bearing_known = false;
      this->bearing_rad = 0.0f;
    }
  }

  explicit RangeReading_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : sensor_id(_alloc),
    sensor_frame_id(_alloc),
    reason(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sensor_id = "";
      this->sensor_frame_id = "";
      this->valid = false;
      this->reason = "";
      this->checksum_ok = false;
      this->device_status_raw = 0;
      this->distance_m = 0.0f;
      this->signal_strength = 0ul;
      this->sensor_time_ms = 0ul;
      this->bearing_known = false;
      this->bearing_rad = 0.0f;
    }
  }

  // field types and members
  using _sensor_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _sensor_id_type sensor_id;
  using _sensor_frame_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _sensor_frame_id_type sensor_frame_id;
  using _valid_type =
    bool;
  _valid_type valid;
  using _reason_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _reason_type reason;
  using _checksum_ok_type =
    bool;
  _checksum_ok_type checksum_ok;
  using _device_status_raw_type =
    uint8_t;
  _device_status_raw_type device_status_raw;
  using _distance_m_type =
    float;
  _distance_m_type distance_m;
  using _signal_strength_type =
    uint32_t;
  _signal_strength_type signal_strength;
  using _sensor_time_ms_type =
    uint32_t;
  _sensor_time_ms_type sensor_time_ms;
  using _bearing_known_type =
    bool;
  _bearing_known_type bearing_known;
  using _bearing_rad_type =
    float;
  _bearing_rad_type bearing_rad;

  // setters for named parameter idiom
  Type & set__sensor_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->sensor_id = _arg;
    return *this;
  }
  Type & set__sensor_frame_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->sensor_frame_id = _arg;
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
  Type & set__checksum_ok(
    const bool & _arg)
  {
    this->checksum_ok = _arg;
    return *this;
  }
  Type & set__device_status_raw(
    const uint8_t & _arg)
  {
    this->device_status_raw = _arg;
    return *this;
  }
  Type & set__distance_m(
    const float & _arg)
  {
    this->distance_m = _arg;
    return *this;
  }
  Type & set__signal_strength(
    const uint32_t & _arg)
  {
    this->signal_strength = _arg;
    return *this;
  }
  Type & set__sensor_time_ms(
    const uint32_t & _arg)
  {
    this->sensor_time_ms = _arg;
    return *this;
  }
  Type & set__bearing_known(
    const bool & _arg)
  {
    this->bearing_known = _arg;
    return *this;
  }
  Type & set__bearing_rad(
    const float & _arg)
  {
    this->bearing_rad = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    team4s_interfaces::msg::RangeReading_<ContainerAllocator> *;
  using ConstRawPtr =
    const team4s_interfaces::msg::RangeReading_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<team4s_interfaces::msg::RangeReading_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<team4s_interfaces::msg::RangeReading_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      team4s_interfaces::msg::RangeReading_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<team4s_interfaces::msg::RangeReading_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      team4s_interfaces::msg::RangeReading_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<team4s_interfaces::msg::RangeReading_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<team4s_interfaces::msg::RangeReading_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<team4s_interfaces::msg::RangeReading_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__team4s_interfaces__msg__RangeReading
    std::shared_ptr<team4s_interfaces::msg::RangeReading_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__team4s_interfaces__msg__RangeReading
    std::shared_ptr<team4s_interfaces::msg::RangeReading_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RangeReading_ & other) const
  {
    if (this->sensor_id != other.sensor_id) {
      return false;
    }
    if (this->sensor_frame_id != other.sensor_frame_id) {
      return false;
    }
    if (this->valid != other.valid) {
      return false;
    }
    if (this->reason != other.reason) {
      return false;
    }
    if (this->checksum_ok != other.checksum_ok) {
      return false;
    }
    if (this->device_status_raw != other.device_status_raw) {
      return false;
    }
    if (this->distance_m != other.distance_m) {
      return false;
    }
    if (this->signal_strength != other.signal_strength) {
      return false;
    }
    if (this->sensor_time_ms != other.sensor_time_ms) {
      return false;
    }
    if (this->bearing_known != other.bearing_known) {
      return false;
    }
    if (this->bearing_rad != other.bearing_rad) {
      return false;
    }
    return true;
  }
  bool operator!=(const RangeReading_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RangeReading_

// alias to use template instance with default allocator
using RangeReading =
  team4s_interfaces::msg::RangeReading_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace team4s_interfaces

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__RANGE_READING__STRUCT_HPP_

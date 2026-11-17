// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from team4s_interfaces:msg/TaskState.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__TASK_STATE__STRUCT_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__TASK_STATE__STRUCT_HPP_

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
# define DEPRECATED__team4s_interfaces__msg__TaskState __attribute__((deprecated))
#else
# define DEPRECATED__team4s_interfaces__msg__TaskState __declspec(deprecated)
#endif

namespace team4s_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TaskState_
{
  using Type = TaskState_<ContainerAllocator>;

  explicit TaskState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->run_id = "";
      this->controller_session_id = "";
      this->sequence = 0ull;
      this->task_id = 0;
      this->phase = 0;
      this->target_lane = 0;
      this->control_mode = 0;
      this->lap_complete = false;
      this->reason = "";
    }
  }

  explicit TaskState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    run_id(_alloc),
    controller_session_id(_alloc),
    reason(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->run_id = "";
      this->controller_session_id = "";
      this->sequence = 0ull;
      this->task_id = 0;
      this->phase = 0;
      this->target_lane = 0;
      this->control_mode = 0;
      this->lap_complete = false;
      this->reason = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _run_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _run_id_type run_id;
  using _controller_session_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _controller_session_id_type controller_session_id;
  using _sequence_type =
    uint64_t;
  _sequence_type sequence;
  using _task_id_type =
    uint8_t;
  _task_id_type task_id;
  using _phase_type =
    uint8_t;
  _phase_type phase;
  using _target_lane_type =
    uint8_t;
  _target_lane_type target_lane;
  using _control_mode_type =
    uint8_t;
  _control_mode_type control_mode;
  using _lap_complete_type =
    bool;
  _lap_complete_type lap_complete;
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
  Type & set__run_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->run_id = _arg;
    return *this;
  }
  Type & set__controller_session_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->controller_session_id = _arg;
    return *this;
  }
  Type & set__sequence(
    const uint64_t & _arg)
  {
    this->sequence = _arg;
    return *this;
  }
  Type & set__task_id(
    const uint8_t & _arg)
  {
    this->task_id = _arg;
    return *this;
  }
  Type & set__phase(
    const uint8_t & _arg)
  {
    this->phase = _arg;
    return *this;
  }
  Type & set__target_lane(
    const uint8_t & _arg)
  {
    this->target_lane = _arg;
    return *this;
  }
  Type & set__control_mode(
    const uint8_t & _arg)
  {
    this->control_mode = _arg;
    return *this;
  }
  Type & set__lap_complete(
    const bool & _arg)
  {
    this->lap_complete = _arg;
    return *this;
  }
  Type & set__reason(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->reason = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t TASK_NONE =
    0u;
  static constexpr uint8_t TASK_LAP =
    1u;
  static constexpr uint8_t TASK_STRAIGHT =
    2u;
  static constexpr uint8_t LANE_UNKNOWN =
    0u;
  static constexpr uint8_t LANE_FIRST =
    1u;
  static constexpr uint8_t LANE_SECOND =
    2u;
  static constexpr uint8_t MODE_IDLE =
    0u;
  static constexpr uint8_t MODE_AUTO =
    1u;
  static constexpr uint8_t MODE_MANUAL =
    2u;
  static constexpr uint8_t MODE_PAUSED =
    3u;
  static constexpr uint8_t MODE_FINISHED =
    4u;
  static constexpr uint8_t MODE_FAULT =
    5u;
  static constexpr uint8_t PHASE_IDLE =
    0u;
  static constexpr uint8_t PHASE_WAIT_START =
    1u;
  static constexpr uint8_t PHASE_FOLLOW_LAP =
    2u;
  static constexpr uint8_t PHASE_FOLLOW_FIRST =
    3u;
  static constexpr uint8_t PHASE_AVOIDING =
    4u;
  static constexpr uint8_t PHASE_FOLLOW_SECOND =
    5u;
  static constexpr uint8_t PHASE_ZEBRA_SLOW =
    6u;
  static constexpr uint8_t PHASE_FINISH_APPROACH =
    7u;
  static constexpr uint8_t PHASE_STOPPED =
    8u;
  static constexpr uint8_t PHASE_FAULT =
    9u;

  // pointer types
  using RawPtr =
    team4s_interfaces::msg::TaskState_<ContainerAllocator> *;
  using ConstRawPtr =
    const team4s_interfaces::msg::TaskState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<team4s_interfaces::msg::TaskState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<team4s_interfaces::msg::TaskState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      team4s_interfaces::msg::TaskState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<team4s_interfaces::msg::TaskState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      team4s_interfaces::msg::TaskState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<team4s_interfaces::msg::TaskState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<team4s_interfaces::msg::TaskState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<team4s_interfaces::msg::TaskState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__team4s_interfaces__msg__TaskState
    std::shared_ptr<team4s_interfaces::msg::TaskState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__team4s_interfaces__msg__TaskState
    std::shared_ptr<team4s_interfaces::msg::TaskState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->run_id != other.run_id) {
      return false;
    }
    if (this->controller_session_id != other.controller_session_id) {
      return false;
    }
    if (this->sequence != other.sequence) {
      return false;
    }
    if (this->task_id != other.task_id) {
      return false;
    }
    if (this->phase != other.phase) {
      return false;
    }
    if (this->target_lane != other.target_lane) {
      return false;
    }
    if (this->control_mode != other.control_mode) {
      return false;
    }
    if (this->lap_complete != other.lap_complete) {
      return false;
    }
    if (this->reason != other.reason) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskState_

// alias to use template instance with default allocator
using TaskState =
  team4s_interfaces::msg::TaskState_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TaskState_<ContainerAllocator>::TASK_NONE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TaskState_<ContainerAllocator>::TASK_LAP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TaskState_<ContainerAllocator>::TASK_STRAIGHT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TaskState_<ContainerAllocator>::LANE_UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TaskState_<ContainerAllocator>::LANE_FIRST;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TaskState_<ContainerAllocator>::LANE_SECOND;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TaskState_<ContainerAllocator>::MODE_IDLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TaskState_<ContainerAllocator>::MODE_AUTO;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TaskState_<ContainerAllocator>::MODE_MANUAL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TaskState_<ContainerAllocator>::MODE_PAUSED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TaskState_<ContainerAllocator>::MODE_FINISHED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TaskState_<ContainerAllocator>::MODE_FAULT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TaskState_<ContainerAllocator>::PHASE_IDLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TaskState_<ContainerAllocator>::PHASE_WAIT_START;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TaskState_<ContainerAllocator>::PHASE_FOLLOW_LAP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TaskState_<ContainerAllocator>::PHASE_FOLLOW_FIRST;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TaskState_<ContainerAllocator>::PHASE_AVOIDING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TaskState_<ContainerAllocator>::PHASE_FOLLOW_SECOND;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TaskState_<ContainerAllocator>::PHASE_ZEBRA_SLOW;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TaskState_<ContainerAllocator>::PHASE_FINISH_APPROACH;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TaskState_<ContainerAllocator>::PHASE_STOPPED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TaskState_<ContainerAllocator>::PHASE_FAULT;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace team4s_interfaces

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__TASK_STATE__STRUCT_HPP_

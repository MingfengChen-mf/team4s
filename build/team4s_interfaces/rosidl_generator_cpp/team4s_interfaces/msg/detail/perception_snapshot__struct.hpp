// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from team4s_interfaces:msg/PerceptionSnapshot.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__PERCEPTION_SNAPSHOT__STRUCT_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__PERCEPTION_SNAPSHOT__STRUCT_HPP_

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
// Member 'lane'
#include "team4s_interfaces/msg/detail/lane_observation__struct.hpp"
// Member 'lane_health'
// Member 'obstacles_health'
// Member 'scene_health'
#include "team4s_interfaces/msg/detail/topic_health__struct.hpp"
// Member 'obstacles'
#include "team4s_interfaces/msg/detail/obstacle_observation__struct.hpp"
// Member 'scene'
#include "team4s_interfaces/msg/detail/scene_observation__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__team4s_interfaces__msg__PerceptionSnapshot __attribute__((deprecated))
#else
# define DEPRECATED__team4s_interfaces__msg__PerceptionSnapshot __declspec(deprecated)
#endif

namespace team4s_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PerceptionSnapshot_
{
  using Type = PerceptionSnapshot_<ContainerAllocator>;

  explicit PerceptionSnapshot_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    lane(_init),
    lane_health(_init),
    obstacles(_init),
    obstacles_health(_init),
    scene(_init),
    scene_health(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->aggregator_session_id = "";
      this->run_id = "";
      this->sequence = 0ull;
    }
  }

  explicit PerceptionSnapshot_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    aggregator_session_id(_alloc),
    run_id(_alloc),
    lane(_alloc, _init),
    lane_health(_alloc, _init),
    obstacles(_alloc, _init),
    obstacles_health(_alloc, _init),
    scene(_alloc, _init),
    scene_health(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->aggregator_session_id = "";
      this->run_id = "";
      this->sequence = 0ull;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _aggregator_session_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _aggregator_session_id_type aggregator_session_id;
  using _run_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _run_id_type run_id;
  using _sequence_type =
    uint64_t;
  _sequence_type sequence;
  using _lane_type =
    team4s_interfaces::msg::LaneObservation_<ContainerAllocator>;
  _lane_type lane;
  using _lane_health_type =
    team4s_interfaces::msg::TopicHealth_<ContainerAllocator>;
  _lane_health_type lane_health;
  using _obstacles_type =
    team4s_interfaces::msg::ObstacleObservation_<ContainerAllocator>;
  _obstacles_type obstacles;
  using _obstacles_health_type =
    team4s_interfaces::msg::TopicHealth_<ContainerAllocator>;
  _obstacles_health_type obstacles_health;
  using _scene_type =
    team4s_interfaces::msg::SceneObservation_<ContainerAllocator>;
  _scene_type scene;
  using _scene_health_type =
    team4s_interfaces::msg::TopicHealth_<ContainerAllocator>;
  _scene_health_type scene_health;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__aggregator_session_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->aggregator_session_id = _arg;
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
  Type & set__lane(
    const team4s_interfaces::msg::LaneObservation_<ContainerAllocator> & _arg)
  {
    this->lane = _arg;
    return *this;
  }
  Type & set__lane_health(
    const team4s_interfaces::msg::TopicHealth_<ContainerAllocator> & _arg)
  {
    this->lane_health = _arg;
    return *this;
  }
  Type & set__obstacles(
    const team4s_interfaces::msg::ObstacleObservation_<ContainerAllocator> & _arg)
  {
    this->obstacles = _arg;
    return *this;
  }
  Type & set__obstacles_health(
    const team4s_interfaces::msg::TopicHealth_<ContainerAllocator> & _arg)
  {
    this->obstacles_health = _arg;
    return *this;
  }
  Type & set__scene(
    const team4s_interfaces::msg::SceneObservation_<ContainerAllocator> & _arg)
  {
    this->scene = _arg;
    return *this;
  }
  Type & set__scene_health(
    const team4s_interfaces::msg::TopicHealth_<ContainerAllocator> & _arg)
  {
    this->scene_health = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    team4s_interfaces::msg::PerceptionSnapshot_<ContainerAllocator> *;
  using ConstRawPtr =
    const team4s_interfaces::msg::PerceptionSnapshot_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<team4s_interfaces::msg::PerceptionSnapshot_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<team4s_interfaces::msg::PerceptionSnapshot_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      team4s_interfaces::msg::PerceptionSnapshot_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<team4s_interfaces::msg::PerceptionSnapshot_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      team4s_interfaces::msg::PerceptionSnapshot_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<team4s_interfaces::msg::PerceptionSnapshot_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<team4s_interfaces::msg::PerceptionSnapshot_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<team4s_interfaces::msg::PerceptionSnapshot_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__team4s_interfaces__msg__PerceptionSnapshot
    std::shared_ptr<team4s_interfaces::msg::PerceptionSnapshot_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__team4s_interfaces__msg__PerceptionSnapshot
    std::shared_ptr<team4s_interfaces::msg::PerceptionSnapshot_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PerceptionSnapshot_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->aggregator_session_id != other.aggregator_session_id) {
      return false;
    }
    if (this->run_id != other.run_id) {
      return false;
    }
    if (this->sequence != other.sequence) {
      return false;
    }
    if (this->lane != other.lane) {
      return false;
    }
    if (this->lane_health != other.lane_health) {
      return false;
    }
    if (this->obstacles != other.obstacles) {
      return false;
    }
    if (this->obstacles_health != other.obstacles_health) {
      return false;
    }
    if (this->scene != other.scene) {
      return false;
    }
    if (this->scene_health != other.scene_health) {
      return false;
    }
    return true;
  }
  bool operator!=(const PerceptionSnapshot_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PerceptionSnapshot_

// alias to use template instance with default allocator
using PerceptionSnapshot =
  team4s_interfaces::msg::PerceptionSnapshot_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace team4s_interfaces

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__PERCEPTION_SNAPSHOT__STRUCT_HPP_

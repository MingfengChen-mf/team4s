// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from team4s_interfaces:msg/SceneObservation.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__SCENE_OBSERVATION__STRUCT_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__SCENE_OBSERVATION__STRUCT_HPP_

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
// Member 'cone_event_stamp'
// Member 'zebra_event_stamp'
// Member 'red_finish_event_stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"
// Member 'cones'
#include "team4s_interfaces/msg/detail/cone_detection__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__team4s_interfaces__msg__SceneObservation __attribute__((deprecated))
#else
# define DEPRECATED__team4s_interfaces__msg__SceneObservation __declspec(deprecated)
#endif

namespace team4s_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SceneObservation_
{
  using Type = SceneObservation_<ContainerAllocator>;

  explicit SceneObservation_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : meta(_init),
    cone_event_stamp(_init),
    zebra_event_stamp(_init),
    red_finish_event_stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cone_valid = false;
      this->cone_state = 0;
      this->cone_bbox_known = false;
      std::fill<typename std::array<int32_t, 4>::iterator, int32_t>(this->cone_bbox_xyxy.begin(), this->cone_bbox_xyxy.end(), 0l);
      this->zebra_valid = false;
      this->zebra_visible = false;
      this->zebra_bbox_known = false;
      std::fill<typename std::array<int32_t, 4>::iterator, int32_t>(this->zebra_bbox_xyxy.begin(), this->zebra_bbox_xyxy.end(), 0l);
      this->image_width = 0ul;
      this->image_height = 0ul;
      this->cone_event_id = 0ull;
      this->zebra_event_id = 0ull;
      this->zebra_event_confirmed = false;
      this->cones_valid = false;
      this->cones_reason = "";
      this->green_start_visible = false;
      this->red_finish_visible = false;
      this->red_finish_confirmed = false;
      this->red_finish_event_id = 0ull;
    }
  }

  explicit SceneObservation_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : meta(_alloc, _init),
    cone_bbox_xyxy(_alloc),
    zebra_bbox_xyxy(_alloc),
    cone_event_stamp(_alloc, _init),
    zebra_event_stamp(_alloc, _init),
    cones_reason(_alloc),
    red_finish_event_stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cone_valid = false;
      this->cone_state = 0;
      this->cone_bbox_known = false;
      std::fill<typename std::array<int32_t, 4>::iterator, int32_t>(this->cone_bbox_xyxy.begin(), this->cone_bbox_xyxy.end(), 0l);
      this->zebra_valid = false;
      this->zebra_visible = false;
      this->zebra_bbox_known = false;
      std::fill<typename std::array<int32_t, 4>::iterator, int32_t>(this->zebra_bbox_xyxy.begin(), this->zebra_bbox_xyxy.end(), 0l);
      this->image_width = 0ul;
      this->image_height = 0ul;
      this->cone_event_id = 0ull;
      this->zebra_event_id = 0ull;
      this->zebra_event_confirmed = false;
      this->cones_valid = false;
      this->cones_reason = "";
      this->green_start_visible = false;
      this->red_finish_visible = false;
      this->red_finish_confirmed = false;
      this->red_finish_event_id = 0ull;
    }
  }

  // field types and members
  using _meta_type =
    team4s_interfaces::msg::SourceHeader_<ContainerAllocator>;
  _meta_type meta;
  using _cone_valid_type =
    bool;
  _cone_valid_type cone_valid;
  using _cone_state_type =
    uint8_t;
  _cone_state_type cone_state;
  using _cone_bbox_known_type =
    bool;
  _cone_bbox_known_type cone_bbox_known;
  using _cone_bbox_xyxy_type =
    std::array<int32_t, 4>;
  _cone_bbox_xyxy_type cone_bbox_xyxy;
  using _zebra_valid_type =
    bool;
  _zebra_valid_type zebra_valid;
  using _zebra_visible_type =
    bool;
  _zebra_visible_type zebra_visible;
  using _zebra_bbox_known_type =
    bool;
  _zebra_bbox_known_type zebra_bbox_known;
  using _zebra_bbox_xyxy_type =
    std::array<int32_t, 4>;
  _zebra_bbox_xyxy_type zebra_bbox_xyxy;
  using _image_width_type =
    uint32_t;
  _image_width_type image_width;
  using _image_height_type =
    uint32_t;
  _image_height_type image_height;
  using _cone_event_id_type =
    uint64_t;
  _cone_event_id_type cone_event_id;
  using _cone_event_stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _cone_event_stamp_type cone_event_stamp;
  using _zebra_event_id_type =
    uint64_t;
  _zebra_event_id_type zebra_event_id;
  using _zebra_event_stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _zebra_event_stamp_type zebra_event_stamp;
  using _zebra_event_confirmed_type =
    bool;
  _zebra_event_confirmed_type zebra_event_confirmed;
  using _cones_valid_type =
    bool;
  _cones_valid_type cones_valid;
  using _cones_reason_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _cones_reason_type cones_reason;
  using _cones_type =
    std::vector<team4s_interfaces::msg::ConeDetection_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<team4s_interfaces::msg::ConeDetection_<ContainerAllocator>>>;
  _cones_type cones;
  using _green_start_visible_type =
    bool;
  _green_start_visible_type green_start_visible;
  using _red_finish_visible_type =
    bool;
  _red_finish_visible_type red_finish_visible;
  using _red_finish_confirmed_type =
    bool;
  _red_finish_confirmed_type red_finish_confirmed;
  using _red_finish_event_id_type =
    uint64_t;
  _red_finish_event_id_type red_finish_event_id;
  using _red_finish_event_stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _red_finish_event_stamp_type red_finish_event_stamp;

  // setters for named parameter idiom
  Type & set__meta(
    const team4s_interfaces::msg::SourceHeader_<ContainerAllocator> & _arg)
  {
    this->meta = _arg;
    return *this;
  }
  Type & set__cone_valid(
    const bool & _arg)
  {
    this->cone_valid = _arg;
    return *this;
  }
  Type & set__cone_state(
    const uint8_t & _arg)
  {
    this->cone_state = _arg;
    return *this;
  }
  Type & set__cone_bbox_known(
    const bool & _arg)
  {
    this->cone_bbox_known = _arg;
    return *this;
  }
  Type & set__cone_bbox_xyxy(
    const std::array<int32_t, 4> & _arg)
  {
    this->cone_bbox_xyxy = _arg;
    return *this;
  }
  Type & set__zebra_valid(
    const bool & _arg)
  {
    this->zebra_valid = _arg;
    return *this;
  }
  Type & set__zebra_visible(
    const bool & _arg)
  {
    this->zebra_visible = _arg;
    return *this;
  }
  Type & set__zebra_bbox_known(
    const bool & _arg)
  {
    this->zebra_bbox_known = _arg;
    return *this;
  }
  Type & set__zebra_bbox_xyxy(
    const std::array<int32_t, 4> & _arg)
  {
    this->zebra_bbox_xyxy = _arg;
    return *this;
  }
  Type & set__image_width(
    const uint32_t & _arg)
  {
    this->image_width = _arg;
    return *this;
  }
  Type & set__image_height(
    const uint32_t & _arg)
  {
    this->image_height = _arg;
    return *this;
  }
  Type & set__cone_event_id(
    const uint64_t & _arg)
  {
    this->cone_event_id = _arg;
    return *this;
  }
  Type & set__cone_event_stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->cone_event_stamp = _arg;
    return *this;
  }
  Type & set__zebra_event_id(
    const uint64_t & _arg)
  {
    this->zebra_event_id = _arg;
    return *this;
  }
  Type & set__zebra_event_stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->zebra_event_stamp = _arg;
    return *this;
  }
  Type & set__zebra_event_confirmed(
    const bool & _arg)
  {
    this->zebra_event_confirmed = _arg;
    return *this;
  }
  Type & set__cones_valid(
    const bool & _arg)
  {
    this->cones_valid = _arg;
    return *this;
  }
  Type & set__cones_reason(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->cones_reason = _arg;
    return *this;
  }
  Type & set__cones(
    const std::vector<team4s_interfaces::msg::ConeDetection_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<team4s_interfaces::msg::ConeDetection_<ContainerAllocator>>> & _arg)
  {
    this->cones = _arg;
    return *this;
  }
  Type & set__green_start_visible(
    const bool & _arg)
  {
    this->green_start_visible = _arg;
    return *this;
  }
  Type & set__red_finish_visible(
    const bool & _arg)
  {
    this->red_finish_visible = _arg;
    return *this;
  }
  Type & set__red_finish_confirmed(
    const bool & _arg)
  {
    this->red_finish_confirmed = _arg;
    return *this;
  }
  Type & set__red_finish_event_id(
    const uint64_t & _arg)
  {
    this->red_finish_event_id = _arg;
    return *this;
  }
  Type & set__red_finish_event_stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->red_finish_event_stamp = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CONE_UNKNOWN =
    0u;
  static constexpr uint8_t CONE_PRESENT =
    1u;
  static constexpr uint8_t CONE_LEAVING =
    2u;
  static constexpr uint8_t CONE_REMOVED =
    3u;

  // pointer types
  using RawPtr =
    team4s_interfaces::msg::SceneObservation_<ContainerAllocator> *;
  using ConstRawPtr =
    const team4s_interfaces::msg::SceneObservation_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<team4s_interfaces::msg::SceneObservation_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<team4s_interfaces::msg::SceneObservation_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      team4s_interfaces::msg::SceneObservation_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<team4s_interfaces::msg::SceneObservation_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      team4s_interfaces::msg::SceneObservation_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<team4s_interfaces::msg::SceneObservation_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<team4s_interfaces::msg::SceneObservation_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<team4s_interfaces::msg::SceneObservation_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__team4s_interfaces__msg__SceneObservation
    std::shared_ptr<team4s_interfaces::msg::SceneObservation_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__team4s_interfaces__msg__SceneObservation
    std::shared_ptr<team4s_interfaces::msg::SceneObservation_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SceneObservation_ & other) const
  {
    if (this->meta != other.meta) {
      return false;
    }
    if (this->cone_valid != other.cone_valid) {
      return false;
    }
    if (this->cone_state != other.cone_state) {
      return false;
    }
    if (this->cone_bbox_known != other.cone_bbox_known) {
      return false;
    }
    if (this->cone_bbox_xyxy != other.cone_bbox_xyxy) {
      return false;
    }
    if (this->zebra_valid != other.zebra_valid) {
      return false;
    }
    if (this->zebra_visible != other.zebra_visible) {
      return false;
    }
    if (this->zebra_bbox_known != other.zebra_bbox_known) {
      return false;
    }
    if (this->zebra_bbox_xyxy != other.zebra_bbox_xyxy) {
      return false;
    }
    if (this->image_width != other.image_width) {
      return false;
    }
    if (this->image_height != other.image_height) {
      return false;
    }
    if (this->cone_event_id != other.cone_event_id) {
      return false;
    }
    if (this->cone_event_stamp != other.cone_event_stamp) {
      return false;
    }
    if (this->zebra_event_id != other.zebra_event_id) {
      return false;
    }
    if (this->zebra_event_stamp != other.zebra_event_stamp) {
      return false;
    }
    if (this->zebra_event_confirmed != other.zebra_event_confirmed) {
      return false;
    }
    if (this->cones_valid != other.cones_valid) {
      return false;
    }
    if (this->cones_reason != other.cones_reason) {
      return false;
    }
    if (this->cones != other.cones) {
      return false;
    }
    if (this->green_start_visible != other.green_start_visible) {
      return false;
    }
    if (this->red_finish_visible != other.red_finish_visible) {
      return false;
    }
    if (this->red_finish_confirmed != other.red_finish_confirmed) {
      return false;
    }
    if (this->red_finish_event_id != other.red_finish_event_id) {
      return false;
    }
    if (this->red_finish_event_stamp != other.red_finish_event_stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const SceneObservation_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SceneObservation_

// alias to use template instance with default allocator
using SceneObservation =
  team4s_interfaces::msg::SceneObservation_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SceneObservation_<ContainerAllocator>::CONE_UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SceneObservation_<ContainerAllocator>::CONE_PRESENT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SceneObservation_<ContainerAllocator>::CONE_LEAVING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SceneObservation_<ContainerAllocator>::CONE_REMOVED;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace team4s_interfaces

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__SCENE_OBSERVATION__STRUCT_HPP_

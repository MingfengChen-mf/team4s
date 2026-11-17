// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from team4s_interfaces:msg/LaneObservation.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__LANE_OBSERVATION__STRUCT_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__LANE_OBSERVATION__STRUCT_HPP_

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
// Member 'candidates'
#include "team4s_interfaces/msg/detail/lane_candidate__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__team4s_interfaces__msg__LaneObservation __attribute__((deprecated))
#else
# define DEPRECATED__team4s_interfaces__msg__LaneObservation __declspec(deprecated)
#endif

namespace team4s_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LaneObservation_
{
  using Type = LaneObservation_<ContainerAllocator>;

  explicit LaneObservation_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : meta(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->image_width = 0ul;
      this->image_height = 0ul;
      this->selected_candidate_id = "";
      this->offset_m_valid = false;
      this->offset_m = 0.0f;
      this->metric_reason = "";
      this->calibration_id = "";
      this->metric_frame_id = "";
      this->metric_reference_x_m = 0.0f;
      this->metric_reference_y_m = 0.0f;
    }
  }

  explicit LaneObservation_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : meta(_alloc, _init),
    selected_candidate_id(_alloc),
    metric_reason(_alloc),
    calibration_id(_alloc),
    metric_frame_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->image_width = 0ul;
      this->image_height = 0ul;
      this->selected_candidate_id = "";
      this->offset_m_valid = false;
      this->offset_m = 0.0f;
      this->metric_reason = "";
      this->calibration_id = "";
      this->metric_frame_id = "";
      this->metric_reference_x_m = 0.0f;
      this->metric_reference_y_m = 0.0f;
    }
  }

  // field types and members
  using _meta_type =
    team4s_interfaces::msg::SourceHeader_<ContainerAllocator>;
  _meta_type meta;
  using _image_width_type =
    uint32_t;
  _image_width_type image_width;
  using _image_height_type =
    uint32_t;
  _image_height_type image_height;
  using _candidates_type =
    std::vector<team4s_interfaces::msg::LaneCandidate_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<team4s_interfaces::msg::LaneCandidate_<ContainerAllocator>>>;
  _candidates_type candidates;
  using _selected_candidate_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _selected_candidate_id_type selected_candidate_id;
  using _offset_m_valid_type =
    bool;
  _offset_m_valid_type offset_m_valid;
  using _offset_m_type =
    float;
  _offset_m_type offset_m;
  using _metric_reason_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _metric_reason_type metric_reason;
  using _calibration_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _calibration_id_type calibration_id;
  using _metric_frame_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _metric_frame_id_type metric_frame_id;
  using _metric_reference_x_m_type =
    float;
  _metric_reference_x_m_type metric_reference_x_m;
  using _metric_reference_y_m_type =
    float;
  _metric_reference_y_m_type metric_reference_y_m;

  // setters for named parameter idiom
  Type & set__meta(
    const team4s_interfaces::msg::SourceHeader_<ContainerAllocator> & _arg)
  {
    this->meta = _arg;
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
  Type & set__candidates(
    const std::vector<team4s_interfaces::msg::LaneCandidate_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<team4s_interfaces::msg::LaneCandidate_<ContainerAllocator>>> & _arg)
  {
    this->candidates = _arg;
    return *this;
  }
  Type & set__selected_candidate_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->selected_candidate_id = _arg;
    return *this;
  }
  Type & set__offset_m_valid(
    const bool & _arg)
  {
    this->offset_m_valid = _arg;
    return *this;
  }
  Type & set__offset_m(
    const float & _arg)
  {
    this->offset_m = _arg;
    return *this;
  }
  Type & set__metric_reason(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->metric_reason = _arg;
    return *this;
  }
  Type & set__calibration_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->calibration_id = _arg;
    return *this;
  }
  Type & set__metric_frame_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->metric_frame_id = _arg;
    return *this;
  }
  Type & set__metric_reference_x_m(
    const float & _arg)
  {
    this->metric_reference_x_m = _arg;
    return *this;
  }
  Type & set__metric_reference_y_m(
    const float & _arg)
  {
    this->metric_reference_y_m = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    team4s_interfaces::msg::LaneObservation_<ContainerAllocator> *;
  using ConstRawPtr =
    const team4s_interfaces::msg::LaneObservation_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<team4s_interfaces::msg::LaneObservation_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<team4s_interfaces::msg::LaneObservation_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      team4s_interfaces::msg::LaneObservation_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<team4s_interfaces::msg::LaneObservation_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      team4s_interfaces::msg::LaneObservation_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<team4s_interfaces::msg::LaneObservation_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<team4s_interfaces::msg::LaneObservation_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<team4s_interfaces::msg::LaneObservation_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__team4s_interfaces__msg__LaneObservation
    std::shared_ptr<team4s_interfaces::msg::LaneObservation_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__team4s_interfaces__msg__LaneObservation
    std::shared_ptr<team4s_interfaces::msg::LaneObservation_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LaneObservation_ & other) const
  {
    if (this->meta != other.meta) {
      return false;
    }
    if (this->image_width != other.image_width) {
      return false;
    }
    if (this->image_height != other.image_height) {
      return false;
    }
    if (this->candidates != other.candidates) {
      return false;
    }
    if (this->selected_candidate_id != other.selected_candidate_id) {
      return false;
    }
    if (this->offset_m_valid != other.offset_m_valid) {
      return false;
    }
    if (this->offset_m != other.offset_m) {
      return false;
    }
    if (this->metric_reason != other.metric_reason) {
      return false;
    }
    if (this->calibration_id != other.calibration_id) {
      return false;
    }
    if (this->metric_frame_id != other.metric_frame_id) {
      return false;
    }
    if (this->metric_reference_x_m != other.metric_reference_x_m) {
      return false;
    }
    if (this->metric_reference_y_m != other.metric_reference_y_m) {
      return false;
    }
    return true;
  }
  bool operator!=(const LaneObservation_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LaneObservation_

// alias to use template instance with default allocator
using LaneObservation =
  team4s_interfaces::msg::LaneObservation_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace team4s_interfaces

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__LANE_OBSERVATION__STRUCT_HPP_

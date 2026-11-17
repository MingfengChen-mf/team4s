// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from team4s_interfaces:msg/LaneObservation.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__LANE_OBSERVATION__BUILDER_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__LANE_OBSERVATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "team4s_interfaces/msg/detail/lane_observation__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace team4s_interfaces
{

namespace msg
{

namespace builder
{

class Init_LaneObservation_metric_reference_y_m
{
public:
  explicit Init_LaneObservation_metric_reference_y_m(::team4s_interfaces::msg::LaneObservation & msg)
  : msg_(msg)
  {}
  ::team4s_interfaces::msg::LaneObservation metric_reference_y_m(::team4s_interfaces::msg::LaneObservation::_metric_reference_y_m_type arg)
  {
    msg_.metric_reference_y_m = std::move(arg);
    return std::move(msg_);
  }

private:
  ::team4s_interfaces::msg::LaneObservation msg_;
};

class Init_LaneObservation_metric_reference_x_m
{
public:
  explicit Init_LaneObservation_metric_reference_x_m(::team4s_interfaces::msg::LaneObservation & msg)
  : msg_(msg)
  {}
  Init_LaneObservation_metric_reference_y_m metric_reference_x_m(::team4s_interfaces::msg::LaneObservation::_metric_reference_x_m_type arg)
  {
    msg_.metric_reference_x_m = std::move(arg);
    return Init_LaneObservation_metric_reference_y_m(msg_);
  }

private:
  ::team4s_interfaces::msg::LaneObservation msg_;
};

class Init_LaneObservation_metric_frame_id
{
public:
  explicit Init_LaneObservation_metric_frame_id(::team4s_interfaces::msg::LaneObservation & msg)
  : msg_(msg)
  {}
  Init_LaneObservation_metric_reference_x_m metric_frame_id(::team4s_interfaces::msg::LaneObservation::_metric_frame_id_type arg)
  {
    msg_.metric_frame_id = std::move(arg);
    return Init_LaneObservation_metric_reference_x_m(msg_);
  }

private:
  ::team4s_interfaces::msg::LaneObservation msg_;
};

class Init_LaneObservation_calibration_id
{
public:
  explicit Init_LaneObservation_calibration_id(::team4s_interfaces::msg::LaneObservation & msg)
  : msg_(msg)
  {}
  Init_LaneObservation_metric_frame_id calibration_id(::team4s_interfaces::msg::LaneObservation::_calibration_id_type arg)
  {
    msg_.calibration_id = std::move(arg);
    return Init_LaneObservation_metric_frame_id(msg_);
  }

private:
  ::team4s_interfaces::msg::LaneObservation msg_;
};

class Init_LaneObservation_metric_reason
{
public:
  explicit Init_LaneObservation_metric_reason(::team4s_interfaces::msg::LaneObservation & msg)
  : msg_(msg)
  {}
  Init_LaneObservation_calibration_id metric_reason(::team4s_interfaces::msg::LaneObservation::_metric_reason_type arg)
  {
    msg_.metric_reason = std::move(arg);
    return Init_LaneObservation_calibration_id(msg_);
  }

private:
  ::team4s_interfaces::msg::LaneObservation msg_;
};

class Init_LaneObservation_offset_m
{
public:
  explicit Init_LaneObservation_offset_m(::team4s_interfaces::msg::LaneObservation & msg)
  : msg_(msg)
  {}
  Init_LaneObservation_metric_reason offset_m(::team4s_interfaces::msg::LaneObservation::_offset_m_type arg)
  {
    msg_.offset_m = std::move(arg);
    return Init_LaneObservation_metric_reason(msg_);
  }

private:
  ::team4s_interfaces::msg::LaneObservation msg_;
};

class Init_LaneObservation_offset_m_valid
{
public:
  explicit Init_LaneObservation_offset_m_valid(::team4s_interfaces::msg::LaneObservation & msg)
  : msg_(msg)
  {}
  Init_LaneObservation_offset_m offset_m_valid(::team4s_interfaces::msg::LaneObservation::_offset_m_valid_type arg)
  {
    msg_.offset_m_valid = std::move(arg);
    return Init_LaneObservation_offset_m(msg_);
  }

private:
  ::team4s_interfaces::msg::LaneObservation msg_;
};

class Init_LaneObservation_selected_candidate_id
{
public:
  explicit Init_LaneObservation_selected_candidate_id(::team4s_interfaces::msg::LaneObservation & msg)
  : msg_(msg)
  {}
  Init_LaneObservation_offset_m_valid selected_candidate_id(::team4s_interfaces::msg::LaneObservation::_selected_candidate_id_type arg)
  {
    msg_.selected_candidate_id = std::move(arg);
    return Init_LaneObservation_offset_m_valid(msg_);
  }

private:
  ::team4s_interfaces::msg::LaneObservation msg_;
};

class Init_LaneObservation_candidates
{
public:
  explicit Init_LaneObservation_candidates(::team4s_interfaces::msg::LaneObservation & msg)
  : msg_(msg)
  {}
  Init_LaneObservation_selected_candidate_id candidates(::team4s_interfaces::msg::LaneObservation::_candidates_type arg)
  {
    msg_.candidates = std::move(arg);
    return Init_LaneObservation_selected_candidate_id(msg_);
  }

private:
  ::team4s_interfaces::msg::LaneObservation msg_;
};

class Init_LaneObservation_image_height
{
public:
  explicit Init_LaneObservation_image_height(::team4s_interfaces::msg::LaneObservation & msg)
  : msg_(msg)
  {}
  Init_LaneObservation_candidates image_height(::team4s_interfaces::msg::LaneObservation::_image_height_type arg)
  {
    msg_.image_height = std::move(arg);
    return Init_LaneObservation_candidates(msg_);
  }

private:
  ::team4s_interfaces::msg::LaneObservation msg_;
};

class Init_LaneObservation_image_width
{
public:
  explicit Init_LaneObservation_image_width(::team4s_interfaces::msg::LaneObservation & msg)
  : msg_(msg)
  {}
  Init_LaneObservation_image_height image_width(::team4s_interfaces::msg::LaneObservation::_image_width_type arg)
  {
    msg_.image_width = std::move(arg);
    return Init_LaneObservation_image_height(msg_);
  }

private:
  ::team4s_interfaces::msg::LaneObservation msg_;
};

class Init_LaneObservation_meta
{
public:
  Init_LaneObservation_meta()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LaneObservation_image_width meta(::team4s_interfaces::msg::LaneObservation::_meta_type arg)
  {
    msg_.meta = std::move(arg);
    return Init_LaneObservation_image_width(msg_);
  }

private:
  ::team4s_interfaces::msg::LaneObservation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::team4s_interfaces::msg::LaneObservation>()
{
  return team4s_interfaces::msg::builder::Init_LaneObservation_meta();
}

}  // namespace team4s_interfaces

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__LANE_OBSERVATION__BUILDER_HPP_

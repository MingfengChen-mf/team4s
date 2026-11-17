// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from team4s_interfaces:msg/LaneCandidate.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__LANE_CANDIDATE__BUILDER_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__LANE_CANDIDATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "team4s_interfaces/msg/detail/lane_candidate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace team4s_interfaces
{

namespace msg
{

namespace builder
{

class Init_LaneCandidate_heading_rad
{
public:
  explicit Init_LaneCandidate_heading_rad(::team4s_interfaces::msg::LaneCandidate & msg)
  : msg_(msg)
  {}
  ::team4s_interfaces::msg::LaneCandidate heading_rad(::team4s_interfaces::msg::LaneCandidate::_heading_rad_type arg)
  {
    msg_.heading_rad = std::move(arg);
    return std::move(msg_);
  }

private:
  ::team4s_interfaces::msg::LaneCandidate msg_;
};

class Init_LaneCandidate_heading_valid
{
public:
  explicit Init_LaneCandidate_heading_valid(::team4s_interfaces::msg::LaneCandidate & msg)
  : msg_(msg)
  {}
  Init_LaneCandidate_heading_rad heading_valid(::team4s_interfaces::msg::LaneCandidate::_heading_valid_type arg)
  {
    msg_.heading_valid = std::move(arg);
    return Init_LaneCandidate_heading_rad(msg_);
  }

private:
  ::team4s_interfaces::msg::LaneCandidate msg_;
};

class Init_LaneCandidate_reference_y_px
{
public:
  explicit Init_LaneCandidate_reference_y_px(::team4s_interfaces::msg::LaneCandidate & msg)
  : msg_(msg)
  {}
  Init_LaneCandidate_heading_valid reference_y_px(::team4s_interfaces::msg::LaneCandidate::_reference_y_px_type arg)
  {
    msg_.reference_y_px = std::move(arg);
    return Init_LaneCandidate_heading_valid(msg_);
  }

private:
  ::team4s_interfaces::msg::LaneCandidate msg_;
};

class Init_LaneCandidate_offset_px
{
public:
  explicit Init_LaneCandidate_offset_px(::team4s_interfaces::msg::LaneCandidate & msg)
  : msg_(msg)
  {}
  Init_LaneCandidate_reference_y_px offset_px(::team4s_interfaces::msg::LaneCandidate::_offset_px_type arg)
  {
    msg_.offset_px = std::move(arg);
    return Init_LaneCandidate_reference_y_px(msg_);
  }

private:
  ::team4s_interfaces::msg::LaneCandidate msg_;
};

class Init_LaneCandidate_center_valid
{
public:
  explicit Init_LaneCandidate_center_valid(::team4s_interfaces::msg::LaneCandidate & msg)
  : msg_(msg)
  {}
  Init_LaneCandidate_offset_px center_valid(::team4s_interfaces::msg::LaneCandidate::_center_valid_type arg)
  {
    msg_.center_valid = std::move(arg);
    return Init_LaneCandidate_offset_px(msg_);
  }

private:
  ::team4s_interfaces::msg::LaneCandidate msg_;
};

class Init_LaneCandidate_right_visible
{
public:
  explicit Init_LaneCandidate_right_visible(::team4s_interfaces::msg::LaneCandidate & msg)
  : msg_(msg)
  {}
  Init_LaneCandidate_center_valid right_visible(::team4s_interfaces::msg::LaneCandidate::_right_visible_type arg)
  {
    msg_.right_visible = std::move(arg);
    return Init_LaneCandidate_center_valid(msg_);
  }

private:
  ::team4s_interfaces::msg::LaneCandidate msg_;
};

class Init_LaneCandidate_left_visible
{
public:
  explicit Init_LaneCandidate_left_visible(::team4s_interfaces::msg::LaneCandidate & msg)
  : msg_(msg)
  {}
  Init_LaneCandidate_right_visible left_visible(::team4s_interfaces::msg::LaneCandidate::_left_visible_type arg)
  {
    msg_.left_visible = std::move(arg);
    return Init_LaneCandidate_right_visible(msg_);
  }

private:
  ::team4s_interfaces::msg::LaneCandidate msg_;
};

class Init_LaneCandidate_is_branch
{
public:
  explicit Init_LaneCandidate_is_branch(::team4s_interfaces::msg::LaneCandidate & msg)
  : msg_(msg)
  {}
  Init_LaneCandidate_left_visible is_branch(::team4s_interfaces::msg::LaneCandidate::_is_branch_type arg)
  {
    msg_.is_branch = std::move(arg);
    return Init_LaneCandidate_left_visible(msg_);
  }

private:
  ::team4s_interfaces::msg::LaneCandidate msg_;
};

class Init_LaneCandidate_route_lane
{
public:
  explicit Init_LaneCandidate_route_lane(::team4s_interfaces::msg::LaneCandidate & msg)
  : msg_(msg)
  {}
  Init_LaneCandidate_is_branch route_lane(::team4s_interfaces::msg::LaneCandidate::_route_lane_type arg)
  {
    msg_.route_lane = std::move(arg);
    return Init_LaneCandidate_is_branch(msg_);
  }

private:
  ::team4s_interfaces::msg::LaneCandidate msg_;
};

class Init_LaneCandidate_candidate_id
{
public:
  Init_LaneCandidate_candidate_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LaneCandidate_route_lane candidate_id(::team4s_interfaces::msg::LaneCandidate::_candidate_id_type arg)
  {
    msg_.candidate_id = std::move(arg);
    return Init_LaneCandidate_route_lane(msg_);
  }

private:
  ::team4s_interfaces::msg::LaneCandidate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::team4s_interfaces::msg::LaneCandidate>()
{
  return team4s_interfaces::msg::builder::Init_LaneCandidate_candidate_id();
}

}  // namespace team4s_interfaces

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__LANE_CANDIDATE__BUILDER_HPP_

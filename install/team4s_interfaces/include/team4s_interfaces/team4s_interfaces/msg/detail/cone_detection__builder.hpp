// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from team4s_interfaces:msg/ConeDetection.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__CONE_DETECTION__BUILDER_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__CONE_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "team4s_interfaces/msg/detail/cone_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace team4s_interfaces
{

namespace msg
{

namespace builder
{

class Init_ConeDetection_color_pixels
{
public:
  explicit Init_ConeDetection_color_pixels(::team4s_interfaces::msg::ConeDetection & msg)
  : msg_(msg)
  {}
  ::team4s_interfaces::msg::ConeDetection color_pixels(::team4s_interfaces::msg::ConeDetection::_color_pixels_type arg)
  {
    msg_.color_pixels = std::move(arg);
    return std::move(msg_);
  }

private:
  ::team4s_interfaces::msg::ConeDetection msg_;
};

class Init_ConeDetection_bbox_xyxy
{
public:
  explicit Init_ConeDetection_bbox_xyxy(::team4s_interfaces::msg::ConeDetection & msg)
  : msg_(msg)
  {}
  Init_ConeDetection_color_pixels bbox_xyxy(::team4s_interfaces::msg::ConeDetection::_bbox_xyxy_type arg)
  {
    msg_.bbox_xyxy = std::move(arg);
    return Init_ConeDetection_color_pixels(msg_);
  }

private:
  ::team4s_interfaces::msg::ConeDetection msg_;
};

class Init_ConeDetection_bbox_known
{
public:
  explicit Init_ConeDetection_bbox_known(::team4s_interfaces::msg::ConeDetection & msg)
  : msg_(msg)
  {}
  Init_ConeDetection_bbox_xyxy bbox_known(::team4s_interfaces::msg::ConeDetection::_bbox_known_type arg)
  {
    msg_.bbox_known = std::move(arg);
    return Init_ConeDetection_bbox_xyxy(msg_);
  }

private:
  ::team4s_interfaces::msg::ConeDetection msg_;
};

class Init_ConeDetection_color
{
public:
  explicit Init_ConeDetection_color(::team4s_interfaces::msg::ConeDetection & msg)
  : msg_(msg)
  {}
  Init_ConeDetection_bbox_known color(::team4s_interfaces::msg::ConeDetection::_color_type arg)
  {
    msg_.color = std::move(arg);
    return Init_ConeDetection_bbox_known(msg_);
  }

private:
  ::team4s_interfaces::msg::ConeDetection msg_;
};

class Init_ConeDetection_candidate_id
{
public:
  Init_ConeDetection_candidate_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ConeDetection_color candidate_id(::team4s_interfaces::msg::ConeDetection::_candidate_id_type arg)
  {
    msg_.candidate_id = std::move(arg);
    return Init_ConeDetection_color(msg_);
  }

private:
  ::team4s_interfaces::msg::ConeDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::team4s_interfaces::msg::ConeDetection>()
{
  return team4s_interfaces::msg::builder::Init_ConeDetection_candidate_id();
}

}  // namespace team4s_interfaces

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__CONE_DETECTION__BUILDER_HPP_

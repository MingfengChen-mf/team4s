// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from team4s_interfaces:msg/ObstacleObservation.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__OBSTACLE_OBSERVATION__BUILDER_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__OBSTACLE_OBSERVATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "team4s_interfaces/msg/detail/obstacle_observation__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace team4s_interfaces
{

namespace msg
{

namespace builder
{

class Init_ObstacleObservation_right_clear
{
public:
  explicit Init_ObstacleObservation_right_clear(::team4s_interfaces::msg::ObstacleObservation & msg)
  : msg_(msg)
  {}
  ::team4s_interfaces::msg::ObstacleObservation right_clear(::team4s_interfaces::msg::ObstacleObservation::_right_clear_type arg)
  {
    msg_.right_clear = std::move(arg);
    return std::move(msg_);
  }

private:
  ::team4s_interfaces::msg::ObstacleObservation msg_;
};

class Init_ObstacleObservation_right_clear_known
{
public:
  explicit Init_ObstacleObservation_right_clear_known(::team4s_interfaces::msg::ObstacleObservation & msg)
  : msg_(msg)
  {}
  Init_ObstacleObservation_right_clear right_clear_known(::team4s_interfaces::msg::ObstacleObservation::_right_clear_known_type arg)
  {
    msg_.right_clear_known = std::move(arg);
    return Init_ObstacleObservation_right_clear(msg_);
  }

private:
  ::team4s_interfaces::msg::ObstacleObservation msg_;
};

class Init_ObstacleObservation_left_clear
{
public:
  explicit Init_ObstacleObservation_left_clear(::team4s_interfaces::msg::ObstacleObservation & msg)
  : msg_(msg)
  {}
  Init_ObstacleObservation_right_clear_known left_clear(::team4s_interfaces::msg::ObstacleObservation::_left_clear_type arg)
  {
    msg_.left_clear = std::move(arg);
    return Init_ObstacleObservation_right_clear_known(msg_);
  }

private:
  ::team4s_interfaces::msg::ObstacleObservation msg_;
};

class Init_ObstacleObservation_left_clear_known
{
public:
  explicit Init_ObstacleObservation_left_clear_known(::team4s_interfaces::msg::ObstacleObservation & msg)
  : msg_(msg)
  {}
  Init_ObstacleObservation_left_clear left_clear_known(::team4s_interfaces::msg::ObstacleObservation::_left_clear_known_type arg)
  {
    msg_.left_clear_known = std::move(arg);
    return Init_ObstacleObservation_left_clear(msg_);
  }

private:
  ::team4s_interfaces::msg::ObstacleObservation msg_;
};

class Init_ObstacleObservation_readings
{
public:
  explicit Init_ObstacleObservation_readings(::team4s_interfaces::msg::ObstacleObservation & msg)
  : msg_(msg)
  {}
  Init_ObstacleObservation_left_clear_known readings(::team4s_interfaces::msg::ObstacleObservation::_readings_type arg)
  {
    msg_.readings = std::move(arg);
    return Init_ObstacleObservation_left_clear_known(msg_);
  }

private:
  ::team4s_interfaces::msg::ObstacleObservation msg_;
};

class Init_ObstacleObservation_meta
{
public:
  Init_ObstacleObservation_meta()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObstacleObservation_readings meta(::team4s_interfaces::msg::ObstacleObservation::_meta_type arg)
  {
    msg_.meta = std::move(arg);
    return Init_ObstacleObservation_readings(msg_);
  }

private:
  ::team4s_interfaces::msg::ObstacleObservation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::team4s_interfaces::msg::ObstacleObservation>()
{
  return team4s_interfaces::msg::builder::Init_ObstacleObservation_meta();
}

}  // namespace team4s_interfaces

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__OBSTACLE_OBSERVATION__BUILDER_HPP_

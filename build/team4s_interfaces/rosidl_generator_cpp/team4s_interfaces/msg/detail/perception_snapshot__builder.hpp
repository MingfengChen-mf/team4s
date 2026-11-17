// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from team4s_interfaces:msg/PerceptionSnapshot.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__PERCEPTION_SNAPSHOT__BUILDER_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__PERCEPTION_SNAPSHOT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "team4s_interfaces/msg/detail/perception_snapshot__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace team4s_interfaces
{

namespace msg
{

namespace builder
{

class Init_PerceptionSnapshot_scene_health
{
public:
  explicit Init_PerceptionSnapshot_scene_health(::team4s_interfaces::msg::PerceptionSnapshot & msg)
  : msg_(msg)
  {}
  ::team4s_interfaces::msg::PerceptionSnapshot scene_health(::team4s_interfaces::msg::PerceptionSnapshot::_scene_health_type arg)
  {
    msg_.scene_health = std::move(arg);
    return std::move(msg_);
  }

private:
  ::team4s_interfaces::msg::PerceptionSnapshot msg_;
};

class Init_PerceptionSnapshot_scene
{
public:
  explicit Init_PerceptionSnapshot_scene(::team4s_interfaces::msg::PerceptionSnapshot & msg)
  : msg_(msg)
  {}
  Init_PerceptionSnapshot_scene_health scene(::team4s_interfaces::msg::PerceptionSnapshot::_scene_type arg)
  {
    msg_.scene = std::move(arg);
    return Init_PerceptionSnapshot_scene_health(msg_);
  }

private:
  ::team4s_interfaces::msg::PerceptionSnapshot msg_;
};

class Init_PerceptionSnapshot_obstacles_health
{
public:
  explicit Init_PerceptionSnapshot_obstacles_health(::team4s_interfaces::msg::PerceptionSnapshot & msg)
  : msg_(msg)
  {}
  Init_PerceptionSnapshot_scene obstacles_health(::team4s_interfaces::msg::PerceptionSnapshot::_obstacles_health_type arg)
  {
    msg_.obstacles_health = std::move(arg);
    return Init_PerceptionSnapshot_scene(msg_);
  }

private:
  ::team4s_interfaces::msg::PerceptionSnapshot msg_;
};

class Init_PerceptionSnapshot_obstacles
{
public:
  explicit Init_PerceptionSnapshot_obstacles(::team4s_interfaces::msg::PerceptionSnapshot & msg)
  : msg_(msg)
  {}
  Init_PerceptionSnapshot_obstacles_health obstacles(::team4s_interfaces::msg::PerceptionSnapshot::_obstacles_type arg)
  {
    msg_.obstacles = std::move(arg);
    return Init_PerceptionSnapshot_obstacles_health(msg_);
  }

private:
  ::team4s_interfaces::msg::PerceptionSnapshot msg_;
};

class Init_PerceptionSnapshot_lane_health
{
public:
  explicit Init_PerceptionSnapshot_lane_health(::team4s_interfaces::msg::PerceptionSnapshot & msg)
  : msg_(msg)
  {}
  Init_PerceptionSnapshot_obstacles lane_health(::team4s_interfaces::msg::PerceptionSnapshot::_lane_health_type arg)
  {
    msg_.lane_health = std::move(arg);
    return Init_PerceptionSnapshot_obstacles(msg_);
  }

private:
  ::team4s_interfaces::msg::PerceptionSnapshot msg_;
};

class Init_PerceptionSnapshot_lane
{
public:
  explicit Init_PerceptionSnapshot_lane(::team4s_interfaces::msg::PerceptionSnapshot & msg)
  : msg_(msg)
  {}
  Init_PerceptionSnapshot_lane_health lane(::team4s_interfaces::msg::PerceptionSnapshot::_lane_type arg)
  {
    msg_.lane = std::move(arg);
    return Init_PerceptionSnapshot_lane_health(msg_);
  }

private:
  ::team4s_interfaces::msg::PerceptionSnapshot msg_;
};

class Init_PerceptionSnapshot_sequence
{
public:
  explicit Init_PerceptionSnapshot_sequence(::team4s_interfaces::msg::PerceptionSnapshot & msg)
  : msg_(msg)
  {}
  Init_PerceptionSnapshot_lane sequence(::team4s_interfaces::msg::PerceptionSnapshot::_sequence_type arg)
  {
    msg_.sequence = std::move(arg);
    return Init_PerceptionSnapshot_lane(msg_);
  }

private:
  ::team4s_interfaces::msg::PerceptionSnapshot msg_;
};

class Init_PerceptionSnapshot_run_id
{
public:
  explicit Init_PerceptionSnapshot_run_id(::team4s_interfaces::msg::PerceptionSnapshot & msg)
  : msg_(msg)
  {}
  Init_PerceptionSnapshot_sequence run_id(::team4s_interfaces::msg::PerceptionSnapshot::_run_id_type arg)
  {
    msg_.run_id = std::move(arg);
    return Init_PerceptionSnapshot_sequence(msg_);
  }

private:
  ::team4s_interfaces::msg::PerceptionSnapshot msg_;
};

class Init_PerceptionSnapshot_aggregator_session_id
{
public:
  explicit Init_PerceptionSnapshot_aggregator_session_id(::team4s_interfaces::msg::PerceptionSnapshot & msg)
  : msg_(msg)
  {}
  Init_PerceptionSnapshot_run_id aggregator_session_id(::team4s_interfaces::msg::PerceptionSnapshot::_aggregator_session_id_type arg)
  {
    msg_.aggregator_session_id = std::move(arg);
    return Init_PerceptionSnapshot_run_id(msg_);
  }

private:
  ::team4s_interfaces::msg::PerceptionSnapshot msg_;
};

class Init_PerceptionSnapshot_header
{
public:
  Init_PerceptionSnapshot_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PerceptionSnapshot_aggregator_session_id header(::team4s_interfaces::msg::PerceptionSnapshot::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PerceptionSnapshot_aggregator_session_id(msg_);
  }

private:
  ::team4s_interfaces::msg::PerceptionSnapshot msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::team4s_interfaces::msg::PerceptionSnapshot>()
{
  return team4s_interfaces::msg::builder::Init_PerceptionSnapshot_header();
}

}  // namespace team4s_interfaces

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__PERCEPTION_SNAPSHOT__BUILDER_HPP_

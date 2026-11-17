// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from team4s_interfaces:msg/TaskState.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__TASK_STATE__BUILDER_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__TASK_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "team4s_interfaces/msg/detail/task_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace team4s_interfaces
{

namespace msg
{

namespace builder
{

class Init_TaskState_reason
{
public:
  explicit Init_TaskState_reason(::team4s_interfaces::msg::TaskState & msg)
  : msg_(msg)
  {}
  ::team4s_interfaces::msg::TaskState reason(::team4s_interfaces::msg::TaskState::_reason_type arg)
  {
    msg_.reason = std::move(arg);
    return std::move(msg_);
  }

private:
  ::team4s_interfaces::msg::TaskState msg_;
};

class Init_TaskState_lap_complete
{
public:
  explicit Init_TaskState_lap_complete(::team4s_interfaces::msg::TaskState & msg)
  : msg_(msg)
  {}
  Init_TaskState_reason lap_complete(::team4s_interfaces::msg::TaskState::_lap_complete_type arg)
  {
    msg_.lap_complete = std::move(arg);
    return Init_TaskState_reason(msg_);
  }

private:
  ::team4s_interfaces::msg::TaskState msg_;
};

class Init_TaskState_control_mode
{
public:
  explicit Init_TaskState_control_mode(::team4s_interfaces::msg::TaskState & msg)
  : msg_(msg)
  {}
  Init_TaskState_lap_complete control_mode(::team4s_interfaces::msg::TaskState::_control_mode_type arg)
  {
    msg_.control_mode = std::move(arg);
    return Init_TaskState_lap_complete(msg_);
  }

private:
  ::team4s_interfaces::msg::TaskState msg_;
};

class Init_TaskState_target_lane
{
public:
  explicit Init_TaskState_target_lane(::team4s_interfaces::msg::TaskState & msg)
  : msg_(msg)
  {}
  Init_TaskState_control_mode target_lane(::team4s_interfaces::msg::TaskState::_target_lane_type arg)
  {
    msg_.target_lane = std::move(arg);
    return Init_TaskState_control_mode(msg_);
  }

private:
  ::team4s_interfaces::msg::TaskState msg_;
};

class Init_TaskState_phase
{
public:
  explicit Init_TaskState_phase(::team4s_interfaces::msg::TaskState & msg)
  : msg_(msg)
  {}
  Init_TaskState_target_lane phase(::team4s_interfaces::msg::TaskState::_phase_type arg)
  {
    msg_.phase = std::move(arg);
    return Init_TaskState_target_lane(msg_);
  }

private:
  ::team4s_interfaces::msg::TaskState msg_;
};

class Init_TaskState_task_id
{
public:
  explicit Init_TaskState_task_id(::team4s_interfaces::msg::TaskState & msg)
  : msg_(msg)
  {}
  Init_TaskState_phase task_id(::team4s_interfaces::msg::TaskState::_task_id_type arg)
  {
    msg_.task_id = std::move(arg);
    return Init_TaskState_phase(msg_);
  }

private:
  ::team4s_interfaces::msg::TaskState msg_;
};

class Init_TaskState_sequence
{
public:
  explicit Init_TaskState_sequence(::team4s_interfaces::msg::TaskState & msg)
  : msg_(msg)
  {}
  Init_TaskState_task_id sequence(::team4s_interfaces::msg::TaskState::_sequence_type arg)
  {
    msg_.sequence = std::move(arg);
    return Init_TaskState_task_id(msg_);
  }

private:
  ::team4s_interfaces::msg::TaskState msg_;
};

class Init_TaskState_controller_session_id
{
public:
  explicit Init_TaskState_controller_session_id(::team4s_interfaces::msg::TaskState & msg)
  : msg_(msg)
  {}
  Init_TaskState_sequence controller_session_id(::team4s_interfaces::msg::TaskState::_controller_session_id_type arg)
  {
    msg_.controller_session_id = std::move(arg);
    return Init_TaskState_sequence(msg_);
  }

private:
  ::team4s_interfaces::msg::TaskState msg_;
};

class Init_TaskState_run_id
{
public:
  explicit Init_TaskState_run_id(::team4s_interfaces::msg::TaskState & msg)
  : msg_(msg)
  {}
  Init_TaskState_controller_session_id run_id(::team4s_interfaces::msg::TaskState::_run_id_type arg)
  {
    msg_.run_id = std::move(arg);
    return Init_TaskState_controller_session_id(msg_);
  }

private:
  ::team4s_interfaces::msg::TaskState msg_;
};

class Init_TaskState_header
{
public:
  Init_TaskState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskState_run_id header(::team4s_interfaces::msg::TaskState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TaskState_run_id(msg_);
  }

private:
  ::team4s_interfaces::msg::TaskState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::team4s_interfaces::msg::TaskState>()
{
  return team4s_interfaces::msg::builder::Init_TaskState_header();
}

}  // namespace team4s_interfaces

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__TASK_STATE__BUILDER_HPP_

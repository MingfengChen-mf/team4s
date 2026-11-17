// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from team4s_interfaces:msg/TopicHealth.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__TOPIC_HEALTH__BUILDER_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__TOPIC_HEALTH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "team4s_interfaces/msg/detail/topic_health__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace team4s_interfaces
{

namespace msg
{

namespace builder
{

class Init_TopicHealth_max_age_s
{
public:
  explicit Init_TopicHealth_max_age_s(::team4s_interfaces::msg::TopicHealth & msg)
  : msg_(msg)
  {}
  ::team4s_interfaces::msg::TopicHealth max_age_s(::team4s_interfaces::msg::TopicHealth::_max_age_s_type arg)
  {
    msg_.max_age_s = std::move(arg);
    return std::move(msg_);
  }

private:
  ::team4s_interfaces::msg::TopicHealth msg_;
};

class Init_TopicHealth_age_s
{
public:
  explicit Init_TopicHealth_age_s(::team4s_interfaces::msg::TopicHealth & msg)
  : msg_(msg)
  {}
  Init_TopicHealth_max_age_s age_s(::team4s_interfaces::msg::TopicHealth::_age_s_type arg)
  {
    msg_.age_s = std::move(arg);
    return Init_TopicHealth_max_age_s(msg_);
  }

private:
  ::team4s_interfaces::msg::TopicHealth msg_;
};

class Init_TopicHealth_age_known
{
public:
  explicit Init_TopicHealth_age_known(::team4s_interfaces::msg::TopicHealth & msg)
  : msg_(msg)
  {}
  Init_TopicHealth_age_s age_known(::team4s_interfaces::msg::TopicHealth::_age_known_type arg)
  {
    msg_.age_known = std::move(arg);
    return Init_TopicHealth_age_s(msg_);
  }

private:
  ::team4s_interfaces::msg::TopicHealth msg_;
};

class Init_TopicHealth_reason
{
public:
  explicit Init_TopicHealth_reason(::team4s_interfaces::msg::TopicHealth & msg)
  : msg_(msg)
  {}
  Init_TopicHealth_age_known reason(::team4s_interfaces::msg::TopicHealth::_reason_type arg)
  {
    msg_.reason = std::move(arg);
    return Init_TopicHealth_age_known(msg_);
  }

private:
  ::team4s_interfaces::msg::TopicHealth msg_;
};

class Init_TopicHealth_state
{
public:
  Init_TopicHealth_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TopicHealth_reason state(::team4s_interfaces::msg::TopicHealth::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_TopicHealth_reason(msg_);
  }

private:
  ::team4s_interfaces::msg::TopicHealth msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::team4s_interfaces::msg::TopicHealth>()
{
  return team4s_interfaces::msg::builder::Init_TopicHealth_state();
}

}  // namespace team4s_interfaces

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__TOPIC_HEALTH__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from team4s_interfaces:msg/SourceHeader.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__SOURCE_HEADER__BUILDER_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__SOURCE_HEADER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "team4s_interfaces/msg/detail/source_header__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace team4s_interfaces
{

namespace msg
{

namespace builder
{

class Init_SourceHeader_reason
{
public:
  explicit Init_SourceHeader_reason(::team4s_interfaces::msg::SourceHeader & msg)
  : msg_(msg)
  {}
  ::team4s_interfaces::msg::SourceHeader reason(::team4s_interfaces::msg::SourceHeader::_reason_type arg)
  {
    msg_.reason = std::move(arg);
    return std::move(msg_);
  }

private:
  ::team4s_interfaces::msg::SourceHeader msg_;
};

class Init_SourceHeader_valid
{
public:
  explicit Init_SourceHeader_valid(::team4s_interfaces::msg::SourceHeader & msg)
  : msg_(msg)
  {}
  Init_SourceHeader_reason valid(::team4s_interfaces::msg::SourceHeader::_valid_type arg)
  {
    msg_.valid = std::move(arg);
    return Init_SourceHeader_reason(msg_);
  }

private:
  ::team4s_interfaces::msg::SourceHeader msg_;
};

class Init_SourceHeader_stamp_source
{
public:
  explicit Init_SourceHeader_stamp_source(::team4s_interfaces::msg::SourceHeader & msg)
  : msg_(msg)
  {}
  Init_SourceHeader_valid stamp_source(::team4s_interfaces::msg::SourceHeader::_stamp_source_type arg)
  {
    msg_.stamp_source = std::move(arg);
    return Init_SourceHeader_valid(msg_);
  }

private:
  ::team4s_interfaces::msg::SourceHeader msg_;
};

class Init_SourceHeader_sequence
{
public:
  explicit Init_SourceHeader_sequence(::team4s_interfaces::msg::SourceHeader & msg)
  : msg_(msg)
  {}
  Init_SourceHeader_stamp_source sequence(::team4s_interfaces::msg::SourceHeader::_sequence_type arg)
  {
    msg_.sequence = std::move(arg);
    return Init_SourceHeader_stamp_source(msg_);
  }

private:
  ::team4s_interfaces::msg::SourceHeader msg_;
};

class Init_SourceHeader_run_id
{
public:
  explicit Init_SourceHeader_run_id(::team4s_interfaces::msg::SourceHeader & msg)
  : msg_(msg)
  {}
  Init_SourceHeader_sequence run_id(::team4s_interfaces::msg::SourceHeader::_run_id_type arg)
  {
    msg_.run_id = std::move(arg);
    return Init_SourceHeader_sequence(msg_);
  }

private:
  ::team4s_interfaces::msg::SourceHeader msg_;
};

class Init_SourceHeader_source_session_id
{
public:
  explicit Init_SourceHeader_source_session_id(::team4s_interfaces::msg::SourceHeader & msg)
  : msg_(msg)
  {}
  Init_SourceHeader_run_id source_session_id(::team4s_interfaces::msg::SourceHeader::_source_session_id_type arg)
  {
    msg_.source_session_id = std::move(arg);
    return Init_SourceHeader_run_id(msg_);
  }

private:
  ::team4s_interfaces::msg::SourceHeader msg_;
};

class Init_SourceHeader_source_id
{
public:
  explicit Init_SourceHeader_source_id(::team4s_interfaces::msg::SourceHeader & msg)
  : msg_(msg)
  {}
  Init_SourceHeader_source_session_id source_id(::team4s_interfaces::msg::SourceHeader::_source_id_type arg)
  {
    msg_.source_id = std::move(arg);
    return Init_SourceHeader_source_session_id(msg_);
  }

private:
  ::team4s_interfaces::msg::SourceHeader msg_;
};

class Init_SourceHeader_header
{
public:
  Init_SourceHeader_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SourceHeader_source_id header(::team4s_interfaces::msg::SourceHeader::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_SourceHeader_source_id(msg_);
  }

private:
  ::team4s_interfaces::msg::SourceHeader msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::team4s_interfaces::msg::SourceHeader>()
{
  return team4s_interfaces::msg::builder::Init_SourceHeader_header();
}

}  // namespace team4s_interfaces

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__SOURCE_HEADER__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from team4s_interfaces:msg/RangeReading.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__RANGE_READING__BUILDER_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__RANGE_READING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "team4s_interfaces/msg/detail/range_reading__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace team4s_interfaces
{

namespace msg
{

namespace builder
{

class Init_RangeReading_bearing_rad
{
public:
  explicit Init_RangeReading_bearing_rad(::team4s_interfaces::msg::RangeReading & msg)
  : msg_(msg)
  {}
  ::team4s_interfaces::msg::RangeReading bearing_rad(::team4s_interfaces::msg::RangeReading::_bearing_rad_type arg)
  {
    msg_.bearing_rad = std::move(arg);
    return std::move(msg_);
  }

private:
  ::team4s_interfaces::msg::RangeReading msg_;
};

class Init_RangeReading_bearing_known
{
public:
  explicit Init_RangeReading_bearing_known(::team4s_interfaces::msg::RangeReading & msg)
  : msg_(msg)
  {}
  Init_RangeReading_bearing_rad bearing_known(::team4s_interfaces::msg::RangeReading::_bearing_known_type arg)
  {
    msg_.bearing_known = std::move(arg);
    return Init_RangeReading_bearing_rad(msg_);
  }

private:
  ::team4s_interfaces::msg::RangeReading msg_;
};

class Init_RangeReading_sensor_time_ms
{
public:
  explicit Init_RangeReading_sensor_time_ms(::team4s_interfaces::msg::RangeReading & msg)
  : msg_(msg)
  {}
  Init_RangeReading_bearing_known sensor_time_ms(::team4s_interfaces::msg::RangeReading::_sensor_time_ms_type arg)
  {
    msg_.sensor_time_ms = std::move(arg);
    return Init_RangeReading_bearing_known(msg_);
  }

private:
  ::team4s_interfaces::msg::RangeReading msg_;
};

class Init_RangeReading_signal_strength
{
public:
  explicit Init_RangeReading_signal_strength(::team4s_interfaces::msg::RangeReading & msg)
  : msg_(msg)
  {}
  Init_RangeReading_sensor_time_ms signal_strength(::team4s_interfaces::msg::RangeReading::_signal_strength_type arg)
  {
    msg_.signal_strength = std::move(arg);
    return Init_RangeReading_sensor_time_ms(msg_);
  }

private:
  ::team4s_interfaces::msg::RangeReading msg_;
};

class Init_RangeReading_distance_m
{
public:
  explicit Init_RangeReading_distance_m(::team4s_interfaces::msg::RangeReading & msg)
  : msg_(msg)
  {}
  Init_RangeReading_signal_strength distance_m(::team4s_interfaces::msg::RangeReading::_distance_m_type arg)
  {
    msg_.distance_m = std::move(arg);
    return Init_RangeReading_signal_strength(msg_);
  }

private:
  ::team4s_interfaces::msg::RangeReading msg_;
};

class Init_RangeReading_device_status_raw
{
public:
  explicit Init_RangeReading_device_status_raw(::team4s_interfaces::msg::RangeReading & msg)
  : msg_(msg)
  {}
  Init_RangeReading_distance_m device_status_raw(::team4s_interfaces::msg::RangeReading::_device_status_raw_type arg)
  {
    msg_.device_status_raw = std::move(arg);
    return Init_RangeReading_distance_m(msg_);
  }

private:
  ::team4s_interfaces::msg::RangeReading msg_;
};

class Init_RangeReading_checksum_ok
{
public:
  explicit Init_RangeReading_checksum_ok(::team4s_interfaces::msg::RangeReading & msg)
  : msg_(msg)
  {}
  Init_RangeReading_device_status_raw checksum_ok(::team4s_interfaces::msg::RangeReading::_checksum_ok_type arg)
  {
    msg_.checksum_ok = std::move(arg);
    return Init_RangeReading_device_status_raw(msg_);
  }

private:
  ::team4s_interfaces::msg::RangeReading msg_;
};

class Init_RangeReading_reason
{
public:
  explicit Init_RangeReading_reason(::team4s_interfaces::msg::RangeReading & msg)
  : msg_(msg)
  {}
  Init_RangeReading_checksum_ok reason(::team4s_interfaces::msg::RangeReading::_reason_type arg)
  {
    msg_.reason = std::move(arg);
    return Init_RangeReading_checksum_ok(msg_);
  }

private:
  ::team4s_interfaces::msg::RangeReading msg_;
};

class Init_RangeReading_valid
{
public:
  explicit Init_RangeReading_valid(::team4s_interfaces::msg::RangeReading & msg)
  : msg_(msg)
  {}
  Init_RangeReading_reason valid(::team4s_interfaces::msg::RangeReading::_valid_type arg)
  {
    msg_.valid = std::move(arg);
    return Init_RangeReading_reason(msg_);
  }

private:
  ::team4s_interfaces::msg::RangeReading msg_;
};

class Init_RangeReading_sensor_frame_id
{
public:
  explicit Init_RangeReading_sensor_frame_id(::team4s_interfaces::msg::RangeReading & msg)
  : msg_(msg)
  {}
  Init_RangeReading_valid sensor_frame_id(::team4s_interfaces::msg::RangeReading::_sensor_frame_id_type arg)
  {
    msg_.sensor_frame_id = std::move(arg);
    return Init_RangeReading_valid(msg_);
  }

private:
  ::team4s_interfaces::msg::RangeReading msg_;
};

class Init_RangeReading_sensor_id
{
public:
  Init_RangeReading_sensor_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RangeReading_sensor_frame_id sensor_id(::team4s_interfaces::msg::RangeReading::_sensor_id_type arg)
  {
    msg_.sensor_id = std::move(arg);
    return Init_RangeReading_sensor_frame_id(msg_);
  }

private:
  ::team4s_interfaces::msg::RangeReading msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::team4s_interfaces::msg::RangeReading>()
{
  return team4s_interfaces::msg::builder::Init_RangeReading_sensor_id();
}

}  // namespace team4s_interfaces

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__RANGE_READING__BUILDER_HPP_

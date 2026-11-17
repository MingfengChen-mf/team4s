// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from team4s_interfaces:msg/RangeReading.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__RANGE_READING__TRAITS_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__RANGE_READING__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "team4s_interfaces/msg/detail/range_reading__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace team4s_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const RangeReading & msg,
  std::ostream & out)
{
  out << "{";
  // member: sensor_id
  {
    out << "sensor_id: ";
    rosidl_generator_traits::value_to_yaml(msg.sensor_id, out);
    out << ", ";
  }

  // member: sensor_frame_id
  {
    out << "sensor_frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.sensor_frame_id, out);
    out << ", ";
  }

  // member: valid
  {
    out << "valid: ";
    rosidl_generator_traits::value_to_yaml(msg.valid, out);
    out << ", ";
  }

  // member: reason
  {
    out << "reason: ";
    rosidl_generator_traits::value_to_yaml(msg.reason, out);
    out << ", ";
  }

  // member: checksum_ok
  {
    out << "checksum_ok: ";
    rosidl_generator_traits::value_to_yaml(msg.checksum_ok, out);
    out << ", ";
  }

  // member: device_status_raw
  {
    out << "device_status_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.device_status_raw, out);
    out << ", ";
  }

  // member: distance_m
  {
    out << "distance_m: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_m, out);
    out << ", ";
  }

  // member: signal_strength
  {
    out << "signal_strength: ";
    rosidl_generator_traits::value_to_yaml(msg.signal_strength, out);
    out << ", ";
  }

  // member: sensor_time_ms
  {
    out << "sensor_time_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.sensor_time_ms, out);
    out << ", ";
  }

  // member: bearing_known
  {
    out << "bearing_known: ";
    rosidl_generator_traits::value_to_yaml(msg.bearing_known, out);
    out << ", ";
  }

  // member: bearing_rad
  {
    out << "bearing_rad: ";
    rosidl_generator_traits::value_to_yaml(msg.bearing_rad, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RangeReading & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: sensor_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sensor_id: ";
    rosidl_generator_traits::value_to_yaml(msg.sensor_id, out);
    out << "\n";
  }

  // member: sensor_frame_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sensor_frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.sensor_frame_id, out);
    out << "\n";
  }

  // member: valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "valid: ";
    rosidl_generator_traits::value_to_yaml(msg.valid, out);
    out << "\n";
  }

  // member: reason
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reason: ";
    rosidl_generator_traits::value_to_yaml(msg.reason, out);
    out << "\n";
  }

  // member: checksum_ok
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "checksum_ok: ";
    rosidl_generator_traits::value_to_yaml(msg.checksum_ok, out);
    out << "\n";
  }

  // member: device_status_raw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "device_status_raw: ";
    rosidl_generator_traits::value_to_yaml(msg.device_status_raw, out);
    out << "\n";
  }

  // member: distance_m
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance_m: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_m, out);
    out << "\n";
  }

  // member: signal_strength
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "signal_strength: ";
    rosidl_generator_traits::value_to_yaml(msg.signal_strength, out);
    out << "\n";
  }

  // member: sensor_time_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sensor_time_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.sensor_time_ms, out);
    out << "\n";
  }

  // member: bearing_known
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bearing_known: ";
    rosidl_generator_traits::value_to_yaml(msg.bearing_known, out);
    out << "\n";
  }

  // member: bearing_rad
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bearing_rad: ";
    rosidl_generator_traits::value_to_yaml(msg.bearing_rad, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RangeReading & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace team4s_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use team4s_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const team4s_interfaces::msg::RangeReading & msg,
  std::ostream & out, size_t indentation = 0)
{
  team4s_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use team4s_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const team4s_interfaces::msg::RangeReading & msg)
{
  return team4s_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<team4s_interfaces::msg::RangeReading>()
{
  return "team4s_interfaces::msg::RangeReading";
}

template<>
inline const char * name<team4s_interfaces::msg::RangeReading>()
{
  return "team4s_interfaces/msg/RangeReading";
}

template<>
struct has_fixed_size<team4s_interfaces::msg::RangeReading>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<team4s_interfaces::msg::RangeReading>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<team4s_interfaces::msg::RangeReading>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__RANGE_READING__TRAITS_HPP_

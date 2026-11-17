// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from team4s_interfaces:msg/ObstacleObservation.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__OBSTACLE_OBSERVATION__TRAITS_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__OBSTACLE_OBSERVATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "team4s_interfaces/msg/detail/obstacle_observation__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'meta'
#include "team4s_interfaces/msg/detail/source_header__traits.hpp"
// Member 'readings'
#include "team4s_interfaces/msg/detail/range_reading__traits.hpp"

namespace team4s_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ObstacleObservation & msg,
  std::ostream & out)
{
  out << "{";
  // member: meta
  {
    out << "meta: ";
    to_flow_style_yaml(msg.meta, out);
    out << ", ";
  }

  // member: readings
  {
    if (msg.readings.size() == 0) {
      out << "readings: []";
    } else {
      out << "readings: [";
      size_t pending_items = msg.readings.size();
      for (auto item : msg.readings) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: left_clear_known
  {
    out << "left_clear_known: ";
    rosidl_generator_traits::value_to_yaml(msg.left_clear_known, out);
    out << ", ";
  }

  // member: left_clear
  {
    out << "left_clear: ";
    rosidl_generator_traits::value_to_yaml(msg.left_clear, out);
    out << ", ";
  }

  // member: right_clear_known
  {
    out << "right_clear_known: ";
    rosidl_generator_traits::value_to_yaml(msg.right_clear_known, out);
    out << ", ";
  }

  // member: right_clear
  {
    out << "right_clear: ";
    rosidl_generator_traits::value_to_yaml(msg.right_clear, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ObstacleObservation & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: meta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "meta:\n";
    to_block_style_yaml(msg.meta, out, indentation + 2);
  }

  // member: readings
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.readings.size() == 0) {
      out << "readings: []\n";
    } else {
      out << "readings:\n";
      for (auto item : msg.readings) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: left_clear_known
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_clear_known: ";
    rosidl_generator_traits::value_to_yaml(msg.left_clear_known, out);
    out << "\n";
  }

  // member: left_clear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_clear: ";
    rosidl_generator_traits::value_to_yaml(msg.left_clear, out);
    out << "\n";
  }

  // member: right_clear_known
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_clear_known: ";
    rosidl_generator_traits::value_to_yaml(msg.right_clear_known, out);
    out << "\n";
  }

  // member: right_clear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_clear: ";
    rosidl_generator_traits::value_to_yaml(msg.right_clear, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ObstacleObservation & msg, bool use_flow_style = false)
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
  const team4s_interfaces::msg::ObstacleObservation & msg,
  std::ostream & out, size_t indentation = 0)
{
  team4s_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use team4s_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const team4s_interfaces::msg::ObstacleObservation & msg)
{
  return team4s_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<team4s_interfaces::msg::ObstacleObservation>()
{
  return "team4s_interfaces::msg::ObstacleObservation";
}

template<>
inline const char * name<team4s_interfaces::msg::ObstacleObservation>()
{
  return "team4s_interfaces/msg/ObstacleObservation";
}

template<>
struct has_fixed_size<team4s_interfaces::msg::ObstacleObservation>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<team4s_interfaces::msg::ObstacleObservation>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<team4s_interfaces::msg::ObstacleObservation>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__OBSTACLE_OBSERVATION__TRAITS_HPP_

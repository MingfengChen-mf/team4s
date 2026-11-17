// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from team4s_interfaces:msg/TopicHealth.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__TOPIC_HEALTH__TRAITS_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__TOPIC_HEALTH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "team4s_interfaces/msg/detail/topic_health__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace team4s_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TopicHealth & msg,
  std::ostream & out)
{
  out << "{";
  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << ", ";
  }

  // member: reason
  {
    out << "reason: ";
    rosidl_generator_traits::value_to_yaml(msg.reason, out);
    out << ", ";
  }

  // member: age_known
  {
    out << "age_known: ";
    rosidl_generator_traits::value_to_yaml(msg.age_known, out);
    out << ", ";
  }

  // member: age_s
  {
    out << "age_s: ";
    rosidl_generator_traits::value_to_yaml(msg.age_s, out);
    out << ", ";
  }

  // member: max_age_s
  {
    out << "max_age_s: ";
    rosidl_generator_traits::value_to_yaml(msg.max_age_s, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TopicHealth & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
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

  // member: age_known
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "age_known: ";
    rosidl_generator_traits::value_to_yaml(msg.age_known, out);
    out << "\n";
  }

  // member: age_s
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "age_s: ";
    rosidl_generator_traits::value_to_yaml(msg.age_s, out);
    out << "\n";
  }

  // member: max_age_s
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_age_s: ";
    rosidl_generator_traits::value_to_yaml(msg.max_age_s, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TopicHealth & msg, bool use_flow_style = false)
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
  const team4s_interfaces::msg::TopicHealth & msg,
  std::ostream & out, size_t indentation = 0)
{
  team4s_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use team4s_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const team4s_interfaces::msg::TopicHealth & msg)
{
  return team4s_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<team4s_interfaces::msg::TopicHealth>()
{
  return "team4s_interfaces::msg::TopicHealth";
}

template<>
inline const char * name<team4s_interfaces::msg::TopicHealth>()
{
  return "team4s_interfaces/msg/TopicHealth";
}

template<>
struct has_fixed_size<team4s_interfaces::msg::TopicHealth>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<team4s_interfaces::msg::TopicHealth>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<team4s_interfaces::msg::TopicHealth>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__TOPIC_HEALTH__TRAITS_HPP_

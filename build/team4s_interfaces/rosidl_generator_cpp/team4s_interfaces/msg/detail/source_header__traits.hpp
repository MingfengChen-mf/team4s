// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from team4s_interfaces:msg/SourceHeader.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__SOURCE_HEADER__TRAITS_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__SOURCE_HEADER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "team4s_interfaces/msg/detail/source_header__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace team4s_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SourceHeader & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: source_id
  {
    out << "source_id: ";
    rosidl_generator_traits::value_to_yaml(msg.source_id, out);
    out << ", ";
  }

  // member: source_session_id
  {
    out << "source_session_id: ";
    rosidl_generator_traits::value_to_yaml(msg.source_session_id, out);
    out << ", ";
  }

  // member: run_id
  {
    out << "run_id: ";
    rosidl_generator_traits::value_to_yaml(msg.run_id, out);
    out << ", ";
  }

  // member: sequence
  {
    out << "sequence: ";
    rosidl_generator_traits::value_to_yaml(msg.sequence, out);
    out << ", ";
  }

  // member: stamp_source
  {
    out << "stamp_source: ";
    rosidl_generator_traits::value_to_yaml(msg.stamp_source, out);
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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SourceHeader & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: source_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "source_id: ";
    rosidl_generator_traits::value_to_yaml(msg.source_id, out);
    out << "\n";
  }

  // member: source_session_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "source_session_id: ";
    rosidl_generator_traits::value_to_yaml(msg.source_session_id, out);
    out << "\n";
  }

  // member: run_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "run_id: ";
    rosidl_generator_traits::value_to_yaml(msg.run_id, out);
    out << "\n";
  }

  // member: sequence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sequence: ";
    rosidl_generator_traits::value_to_yaml(msg.sequence, out);
    out << "\n";
  }

  // member: stamp_source
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp_source: ";
    rosidl_generator_traits::value_to_yaml(msg.stamp_source, out);
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SourceHeader & msg, bool use_flow_style = false)
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
  const team4s_interfaces::msg::SourceHeader & msg,
  std::ostream & out, size_t indentation = 0)
{
  team4s_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use team4s_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const team4s_interfaces::msg::SourceHeader & msg)
{
  return team4s_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<team4s_interfaces::msg::SourceHeader>()
{
  return "team4s_interfaces::msg::SourceHeader";
}

template<>
inline const char * name<team4s_interfaces::msg::SourceHeader>()
{
  return "team4s_interfaces/msg/SourceHeader";
}

template<>
struct has_fixed_size<team4s_interfaces::msg::SourceHeader>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<team4s_interfaces::msg::SourceHeader>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<team4s_interfaces::msg::SourceHeader>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__SOURCE_HEADER__TRAITS_HPP_

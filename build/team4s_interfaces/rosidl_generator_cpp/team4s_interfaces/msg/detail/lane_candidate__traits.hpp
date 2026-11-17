// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from team4s_interfaces:msg/LaneCandidate.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__LANE_CANDIDATE__TRAITS_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__LANE_CANDIDATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "team4s_interfaces/msg/detail/lane_candidate__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace team4s_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const LaneCandidate & msg,
  std::ostream & out)
{
  out << "{";
  // member: candidate_id
  {
    out << "candidate_id: ";
    rosidl_generator_traits::value_to_yaml(msg.candidate_id, out);
    out << ", ";
  }

  // member: route_lane
  {
    out << "route_lane: ";
    rosidl_generator_traits::value_to_yaml(msg.route_lane, out);
    out << ", ";
  }

  // member: is_branch
  {
    out << "is_branch: ";
    rosidl_generator_traits::value_to_yaml(msg.is_branch, out);
    out << ", ";
  }

  // member: left_visible
  {
    out << "left_visible: ";
    rosidl_generator_traits::value_to_yaml(msg.left_visible, out);
    out << ", ";
  }

  // member: right_visible
  {
    out << "right_visible: ";
    rosidl_generator_traits::value_to_yaml(msg.right_visible, out);
    out << ", ";
  }

  // member: center_valid
  {
    out << "center_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.center_valid, out);
    out << ", ";
  }

  // member: offset_px
  {
    out << "offset_px: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_px, out);
    out << ", ";
  }

  // member: reference_y_px
  {
    out << "reference_y_px: ";
    rosidl_generator_traits::value_to_yaml(msg.reference_y_px, out);
    out << ", ";
  }

  // member: heading_valid
  {
    out << "heading_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_valid, out);
    out << ", ";
  }

  // member: heading_rad
  {
    out << "heading_rad: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_rad, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LaneCandidate & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: candidate_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "candidate_id: ";
    rosidl_generator_traits::value_to_yaml(msg.candidate_id, out);
    out << "\n";
  }

  // member: route_lane
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "route_lane: ";
    rosidl_generator_traits::value_to_yaml(msg.route_lane, out);
    out << "\n";
  }

  // member: is_branch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_branch: ";
    rosidl_generator_traits::value_to_yaml(msg.is_branch, out);
    out << "\n";
  }

  // member: left_visible
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_visible: ";
    rosidl_generator_traits::value_to_yaml(msg.left_visible, out);
    out << "\n";
  }

  // member: right_visible
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_visible: ";
    rosidl_generator_traits::value_to_yaml(msg.right_visible, out);
    out << "\n";
  }

  // member: center_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.center_valid, out);
    out << "\n";
  }

  // member: offset_px
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "offset_px: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_px, out);
    out << "\n";
  }

  // member: reference_y_px
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reference_y_px: ";
    rosidl_generator_traits::value_to_yaml(msg.reference_y_px, out);
    out << "\n";
  }

  // member: heading_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heading_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_valid, out);
    out << "\n";
  }

  // member: heading_rad
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heading_rad: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_rad, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LaneCandidate & msg, bool use_flow_style = false)
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
  const team4s_interfaces::msg::LaneCandidate & msg,
  std::ostream & out, size_t indentation = 0)
{
  team4s_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use team4s_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const team4s_interfaces::msg::LaneCandidate & msg)
{
  return team4s_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<team4s_interfaces::msg::LaneCandidate>()
{
  return "team4s_interfaces::msg::LaneCandidate";
}

template<>
inline const char * name<team4s_interfaces::msg::LaneCandidate>()
{
  return "team4s_interfaces/msg/LaneCandidate";
}

template<>
struct has_fixed_size<team4s_interfaces::msg::LaneCandidate>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<team4s_interfaces::msg::LaneCandidate>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<team4s_interfaces::msg::LaneCandidate>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__LANE_CANDIDATE__TRAITS_HPP_

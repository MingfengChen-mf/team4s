// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from team4s_interfaces:msg/PerceptionSnapshot.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__PERCEPTION_SNAPSHOT__TRAITS_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__PERCEPTION_SNAPSHOT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "team4s_interfaces/msg/detail/perception_snapshot__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'lane'
#include "team4s_interfaces/msg/detail/lane_observation__traits.hpp"
// Member 'lane_health'
// Member 'obstacles_health'
// Member 'scene_health'
#include "team4s_interfaces/msg/detail/topic_health__traits.hpp"
// Member 'obstacles'
#include "team4s_interfaces/msg/detail/obstacle_observation__traits.hpp"
// Member 'scene'
#include "team4s_interfaces/msg/detail/scene_observation__traits.hpp"

namespace team4s_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const PerceptionSnapshot & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: aggregator_session_id
  {
    out << "aggregator_session_id: ";
    rosidl_generator_traits::value_to_yaml(msg.aggregator_session_id, out);
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

  // member: lane
  {
    out << "lane: ";
    to_flow_style_yaml(msg.lane, out);
    out << ", ";
  }

  // member: lane_health
  {
    out << "lane_health: ";
    to_flow_style_yaml(msg.lane_health, out);
    out << ", ";
  }

  // member: obstacles
  {
    out << "obstacles: ";
    to_flow_style_yaml(msg.obstacles, out);
    out << ", ";
  }

  // member: obstacles_health
  {
    out << "obstacles_health: ";
    to_flow_style_yaml(msg.obstacles_health, out);
    out << ", ";
  }

  // member: scene
  {
    out << "scene: ";
    to_flow_style_yaml(msg.scene, out);
    out << ", ";
  }

  // member: scene_health
  {
    out << "scene_health: ";
    to_flow_style_yaml(msg.scene_health, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PerceptionSnapshot & msg,
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

  // member: aggregator_session_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "aggregator_session_id: ";
    rosidl_generator_traits::value_to_yaml(msg.aggregator_session_id, out);
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

  // member: lane
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lane:\n";
    to_block_style_yaml(msg.lane, out, indentation + 2);
  }

  // member: lane_health
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lane_health:\n";
    to_block_style_yaml(msg.lane_health, out, indentation + 2);
  }

  // member: obstacles
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obstacles:\n";
    to_block_style_yaml(msg.obstacles, out, indentation + 2);
  }

  // member: obstacles_health
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obstacles_health:\n";
    to_block_style_yaml(msg.obstacles_health, out, indentation + 2);
  }

  // member: scene
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "scene:\n";
    to_block_style_yaml(msg.scene, out, indentation + 2);
  }

  // member: scene_health
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "scene_health:\n";
    to_block_style_yaml(msg.scene_health, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PerceptionSnapshot & msg, bool use_flow_style = false)
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
  const team4s_interfaces::msg::PerceptionSnapshot & msg,
  std::ostream & out, size_t indentation = 0)
{
  team4s_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use team4s_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const team4s_interfaces::msg::PerceptionSnapshot & msg)
{
  return team4s_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<team4s_interfaces::msg::PerceptionSnapshot>()
{
  return "team4s_interfaces::msg::PerceptionSnapshot";
}

template<>
inline const char * name<team4s_interfaces::msg::PerceptionSnapshot>()
{
  return "team4s_interfaces/msg/PerceptionSnapshot";
}

template<>
struct has_fixed_size<team4s_interfaces::msg::PerceptionSnapshot>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<team4s_interfaces::msg::PerceptionSnapshot>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<team4s_interfaces::msg::PerceptionSnapshot>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__PERCEPTION_SNAPSHOT__TRAITS_HPP_

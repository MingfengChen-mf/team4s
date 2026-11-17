// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from team4s_interfaces:msg/ConeDetection.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__CONE_DETECTION__TRAITS_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__CONE_DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "team4s_interfaces/msg/detail/cone_detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace team4s_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ConeDetection & msg,
  std::ostream & out)
{
  out << "{";
  // member: candidate_id
  {
    out << "candidate_id: ";
    rosidl_generator_traits::value_to_yaml(msg.candidate_id, out);
    out << ", ";
  }

  // member: color
  {
    out << "color: ";
    rosidl_generator_traits::value_to_yaml(msg.color, out);
    out << ", ";
  }

  // member: bbox_known
  {
    out << "bbox_known: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_known, out);
    out << ", ";
  }

  // member: bbox_xyxy
  {
    if (msg.bbox_xyxy.size() == 0) {
      out << "bbox_xyxy: []";
    } else {
      out << "bbox_xyxy: [";
      size_t pending_items = msg.bbox_xyxy.size();
      for (auto item : msg.bbox_xyxy) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: color_pixels
  {
    out << "color_pixels: ";
    rosidl_generator_traits::value_to_yaml(msg.color_pixels, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ConeDetection & msg,
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

  // member: color
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "color: ";
    rosidl_generator_traits::value_to_yaml(msg.color, out);
    out << "\n";
  }

  // member: bbox_known
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bbox_known: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_known, out);
    out << "\n";
  }

  // member: bbox_xyxy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.bbox_xyxy.size() == 0) {
      out << "bbox_xyxy: []\n";
    } else {
      out << "bbox_xyxy:\n";
      for (auto item : msg.bbox_xyxy) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: color_pixels
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "color_pixels: ";
    rosidl_generator_traits::value_to_yaml(msg.color_pixels, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ConeDetection & msg, bool use_flow_style = false)
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
  const team4s_interfaces::msg::ConeDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  team4s_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use team4s_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const team4s_interfaces::msg::ConeDetection & msg)
{
  return team4s_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<team4s_interfaces::msg::ConeDetection>()
{
  return "team4s_interfaces::msg::ConeDetection";
}

template<>
inline const char * name<team4s_interfaces::msg::ConeDetection>()
{
  return "team4s_interfaces/msg/ConeDetection";
}

template<>
struct has_fixed_size<team4s_interfaces::msg::ConeDetection>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<team4s_interfaces::msg::ConeDetection>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<team4s_interfaces::msg::ConeDetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__CONE_DETECTION__TRAITS_HPP_

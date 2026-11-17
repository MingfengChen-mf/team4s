// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from team4s_interfaces:msg/LaneObservation.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__LANE_OBSERVATION__TRAITS_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__LANE_OBSERVATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "team4s_interfaces/msg/detail/lane_observation__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'meta'
#include "team4s_interfaces/msg/detail/source_header__traits.hpp"
// Member 'candidates'
#include "team4s_interfaces/msg/detail/lane_candidate__traits.hpp"

namespace team4s_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const LaneObservation & msg,
  std::ostream & out)
{
  out << "{";
  // member: meta
  {
    out << "meta: ";
    to_flow_style_yaml(msg.meta, out);
    out << ", ";
  }

  // member: image_width
  {
    out << "image_width: ";
    rosidl_generator_traits::value_to_yaml(msg.image_width, out);
    out << ", ";
  }

  // member: image_height
  {
    out << "image_height: ";
    rosidl_generator_traits::value_to_yaml(msg.image_height, out);
    out << ", ";
  }

  // member: candidates
  {
    if (msg.candidates.size() == 0) {
      out << "candidates: []";
    } else {
      out << "candidates: [";
      size_t pending_items = msg.candidates.size();
      for (auto item : msg.candidates) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: selected_candidate_id
  {
    out << "selected_candidate_id: ";
    rosidl_generator_traits::value_to_yaml(msg.selected_candidate_id, out);
    out << ", ";
  }

  // member: offset_m_valid
  {
    out << "offset_m_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_m_valid, out);
    out << ", ";
  }

  // member: offset_m
  {
    out << "offset_m: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_m, out);
    out << ", ";
  }

  // member: metric_reason
  {
    out << "metric_reason: ";
    rosidl_generator_traits::value_to_yaml(msg.metric_reason, out);
    out << ", ";
  }

  // member: calibration_id
  {
    out << "calibration_id: ";
    rosidl_generator_traits::value_to_yaml(msg.calibration_id, out);
    out << ", ";
  }

  // member: metric_frame_id
  {
    out << "metric_frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.metric_frame_id, out);
    out << ", ";
  }

  // member: metric_reference_x_m
  {
    out << "metric_reference_x_m: ";
    rosidl_generator_traits::value_to_yaml(msg.metric_reference_x_m, out);
    out << ", ";
  }

  // member: metric_reference_y_m
  {
    out << "metric_reference_y_m: ";
    rosidl_generator_traits::value_to_yaml(msg.metric_reference_y_m, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LaneObservation & msg,
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

  // member: image_width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "image_width: ";
    rosidl_generator_traits::value_to_yaml(msg.image_width, out);
    out << "\n";
  }

  // member: image_height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "image_height: ";
    rosidl_generator_traits::value_to_yaml(msg.image_height, out);
    out << "\n";
  }

  // member: candidates
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.candidates.size() == 0) {
      out << "candidates: []\n";
    } else {
      out << "candidates:\n";
      for (auto item : msg.candidates) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: selected_candidate_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "selected_candidate_id: ";
    rosidl_generator_traits::value_to_yaml(msg.selected_candidate_id, out);
    out << "\n";
  }

  // member: offset_m_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "offset_m_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_m_valid, out);
    out << "\n";
  }

  // member: offset_m
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "offset_m: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_m, out);
    out << "\n";
  }

  // member: metric_reason
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "metric_reason: ";
    rosidl_generator_traits::value_to_yaml(msg.metric_reason, out);
    out << "\n";
  }

  // member: calibration_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "calibration_id: ";
    rosidl_generator_traits::value_to_yaml(msg.calibration_id, out);
    out << "\n";
  }

  // member: metric_frame_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "metric_frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.metric_frame_id, out);
    out << "\n";
  }

  // member: metric_reference_x_m
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "metric_reference_x_m: ";
    rosidl_generator_traits::value_to_yaml(msg.metric_reference_x_m, out);
    out << "\n";
  }

  // member: metric_reference_y_m
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "metric_reference_y_m: ";
    rosidl_generator_traits::value_to_yaml(msg.metric_reference_y_m, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LaneObservation & msg, bool use_flow_style = false)
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
  const team4s_interfaces::msg::LaneObservation & msg,
  std::ostream & out, size_t indentation = 0)
{
  team4s_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use team4s_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const team4s_interfaces::msg::LaneObservation & msg)
{
  return team4s_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<team4s_interfaces::msg::LaneObservation>()
{
  return "team4s_interfaces::msg::LaneObservation";
}

template<>
inline const char * name<team4s_interfaces::msg::LaneObservation>()
{
  return "team4s_interfaces/msg/LaneObservation";
}

template<>
struct has_fixed_size<team4s_interfaces::msg::LaneObservation>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<team4s_interfaces::msg::LaneObservation>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<team4s_interfaces::msg::LaneObservation>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__LANE_OBSERVATION__TRAITS_HPP_

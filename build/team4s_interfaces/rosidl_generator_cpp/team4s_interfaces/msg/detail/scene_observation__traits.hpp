// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from team4s_interfaces:msg/SceneObservation.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__SCENE_OBSERVATION__TRAITS_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__SCENE_OBSERVATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "team4s_interfaces/msg/detail/scene_observation__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'meta'
#include "team4s_interfaces/msg/detail/source_header__traits.hpp"
// Member 'cone_event_stamp'
// Member 'zebra_event_stamp'
// Member 'red_finish_event_stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"
// Member 'cones'
#include "team4s_interfaces/msg/detail/cone_detection__traits.hpp"

namespace team4s_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SceneObservation & msg,
  std::ostream & out)
{
  out << "{";
  // member: meta
  {
    out << "meta: ";
    to_flow_style_yaml(msg.meta, out);
    out << ", ";
  }

  // member: cone_valid
  {
    out << "cone_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.cone_valid, out);
    out << ", ";
  }

  // member: cone_state
  {
    out << "cone_state: ";
    rosidl_generator_traits::value_to_yaml(msg.cone_state, out);
    out << ", ";
  }

  // member: cone_bbox_known
  {
    out << "cone_bbox_known: ";
    rosidl_generator_traits::value_to_yaml(msg.cone_bbox_known, out);
    out << ", ";
  }

  // member: cone_bbox_xyxy
  {
    if (msg.cone_bbox_xyxy.size() == 0) {
      out << "cone_bbox_xyxy: []";
    } else {
      out << "cone_bbox_xyxy: [";
      size_t pending_items = msg.cone_bbox_xyxy.size();
      for (auto item : msg.cone_bbox_xyxy) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: zebra_valid
  {
    out << "zebra_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.zebra_valid, out);
    out << ", ";
  }

  // member: zebra_visible
  {
    out << "zebra_visible: ";
    rosidl_generator_traits::value_to_yaml(msg.zebra_visible, out);
    out << ", ";
  }

  // member: zebra_bbox_known
  {
    out << "zebra_bbox_known: ";
    rosidl_generator_traits::value_to_yaml(msg.zebra_bbox_known, out);
    out << ", ";
  }

  // member: zebra_bbox_xyxy
  {
    if (msg.zebra_bbox_xyxy.size() == 0) {
      out << "zebra_bbox_xyxy: []";
    } else {
      out << "zebra_bbox_xyxy: [";
      size_t pending_items = msg.zebra_bbox_xyxy.size();
      for (auto item : msg.zebra_bbox_xyxy) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
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

  // member: cone_event_id
  {
    out << "cone_event_id: ";
    rosidl_generator_traits::value_to_yaml(msg.cone_event_id, out);
    out << ", ";
  }

  // member: cone_event_stamp
  {
    out << "cone_event_stamp: ";
    to_flow_style_yaml(msg.cone_event_stamp, out);
    out << ", ";
  }

  // member: zebra_event_id
  {
    out << "zebra_event_id: ";
    rosidl_generator_traits::value_to_yaml(msg.zebra_event_id, out);
    out << ", ";
  }

  // member: zebra_event_stamp
  {
    out << "zebra_event_stamp: ";
    to_flow_style_yaml(msg.zebra_event_stamp, out);
    out << ", ";
  }

  // member: zebra_event_confirmed
  {
    out << "zebra_event_confirmed: ";
    rosidl_generator_traits::value_to_yaml(msg.zebra_event_confirmed, out);
    out << ", ";
  }

  // member: cones_valid
  {
    out << "cones_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.cones_valid, out);
    out << ", ";
  }

  // member: cones_reason
  {
    out << "cones_reason: ";
    rosidl_generator_traits::value_to_yaml(msg.cones_reason, out);
    out << ", ";
  }

  // member: cones
  {
    if (msg.cones.size() == 0) {
      out << "cones: []";
    } else {
      out << "cones: [";
      size_t pending_items = msg.cones.size();
      for (auto item : msg.cones) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: green_start_visible
  {
    out << "green_start_visible: ";
    rosidl_generator_traits::value_to_yaml(msg.green_start_visible, out);
    out << ", ";
  }

  // member: red_finish_visible
  {
    out << "red_finish_visible: ";
    rosidl_generator_traits::value_to_yaml(msg.red_finish_visible, out);
    out << ", ";
  }

  // member: red_finish_confirmed
  {
    out << "red_finish_confirmed: ";
    rosidl_generator_traits::value_to_yaml(msg.red_finish_confirmed, out);
    out << ", ";
  }

  // member: red_finish_event_id
  {
    out << "red_finish_event_id: ";
    rosidl_generator_traits::value_to_yaml(msg.red_finish_event_id, out);
    out << ", ";
  }

  // member: red_finish_event_stamp
  {
    out << "red_finish_event_stamp: ";
    to_flow_style_yaml(msg.red_finish_event_stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SceneObservation & msg,
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

  // member: cone_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cone_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.cone_valid, out);
    out << "\n";
  }

  // member: cone_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cone_state: ";
    rosidl_generator_traits::value_to_yaml(msg.cone_state, out);
    out << "\n";
  }

  // member: cone_bbox_known
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cone_bbox_known: ";
    rosidl_generator_traits::value_to_yaml(msg.cone_bbox_known, out);
    out << "\n";
  }

  // member: cone_bbox_xyxy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.cone_bbox_xyxy.size() == 0) {
      out << "cone_bbox_xyxy: []\n";
    } else {
      out << "cone_bbox_xyxy:\n";
      for (auto item : msg.cone_bbox_xyxy) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: zebra_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zebra_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.zebra_valid, out);
    out << "\n";
  }

  // member: zebra_visible
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zebra_visible: ";
    rosidl_generator_traits::value_to_yaml(msg.zebra_visible, out);
    out << "\n";
  }

  // member: zebra_bbox_known
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zebra_bbox_known: ";
    rosidl_generator_traits::value_to_yaml(msg.zebra_bbox_known, out);
    out << "\n";
  }

  // member: zebra_bbox_xyxy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.zebra_bbox_xyxy.size() == 0) {
      out << "zebra_bbox_xyxy: []\n";
    } else {
      out << "zebra_bbox_xyxy:\n";
      for (auto item : msg.zebra_bbox_xyxy) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
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

  // member: cone_event_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cone_event_id: ";
    rosidl_generator_traits::value_to_yaml(msg.cone_event_id, out);
    out << "\n";
  }

  // member: cone_event_stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cone_event_stamp:\n";
    to_block_style_yaml(msg.cone_event_stamp, out, indentation + 2);
  }

  // member: zebra_event_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zebra_event_id: ";
    rosidl_generator_traits::value_to_yaml(msg.zebra_event_id, out);
    out << "\n";
  }

  // member: zebra_event_stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zebra_event_stamp:\n";
    to_block_style_yaml(msg.zebra_event_stamp, out, indentation + 2);
  }

  // member: zebra_event_confirmed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zebra_event_confirmed: ";
    rosidl_generator_traits::value_to_yaml(msg.zebra_event_confirmed, out);
    out << "\n";
  }

  // member: cones_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cones_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.cones_valid, out);
    out << "\n";
  }

  // member: cones_reason
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cones_reason: ";
    rosidl_generator_traits::value_to_yaml(msg.cones_reason, out);
    out << "\n";
  }

  // member: cones
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.cones.size() == 0) {
      out << "cones: []\n";
    } else {
      out << "cones:\n";
      for (auto item : msg.cones) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: green_start_visible
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "green_start_visible: ";
    rosidl_generator_traits::value_to_yaml(msg.green_start_visible, out);
    out << "\n";
  }

  // member: red_finish_visible
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "red_finish_visible: ";
    rosidl_generator_traits::value_to_yaml(msg.red_finish_visible, out);
    out << "\n";
  }

  // member: red_finish_confirmed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "red_finish_confirmed: ";
    rosidl_generator_traits::value_to_yaml(msg.red_finish_confirmed, out);
    out << "\n";
  }

  // member: red_finish_event_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "red_finish_event_id: ";
    rosidl_generator_traits::value_to_yaml(msg.red_finish_event_id, out);
    out << "\n";
  }

  // member: red_finish_event_stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "red_finish_event_stamp:\n";
    to_block_style_yaml(msg.red_finish_event_stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SceneObservation & msg, bool use_flow_style = false)
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
  const team4s_interfaces::msg::SceneObservation & msg,
  std::ostream & out, size_t indentation = 0)
{
  team4s_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use team4s_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const team4s_interfaces::msg::SceneObservation & msg)
{
  return team4s_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<team4s_interfaces::msg::SceneObservation>()
{
  return "team4s_interfaces::msg::SceneObservation";
}

template<>
inline const char * name<team4s_interfaces::msg::SceneObservation>()
{
  return "team4s_interfaces/msg/SceneObservation";
}

template<>
struct has_fixed_size<team4s_interfaces::msg::SceneObservation>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<team4s_interfaces::msg::SceneObservation>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<team4s_interfaces::msg::SceneObservation>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__SCENE_OBSERVATION__TRAITS_HPP_

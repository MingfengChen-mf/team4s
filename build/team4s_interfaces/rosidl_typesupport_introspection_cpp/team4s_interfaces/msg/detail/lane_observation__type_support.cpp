// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from team4s_interfaces:msg/LaneObservation.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "team4s_interfaces/msg/detail/lane_observation__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace team4s_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void LaneObservation_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) team4s_interfaces::msg::LaneObservation(_init);
}

void LaneObservation_fini_function(void * message_memory)
{
  auto typed_message = static_cast<team4s_interfaces::msg::LaneObservation *>(message_memory);
  typed_message->~LaneObservation();
}

size_t size_function__LaneObservation__candidates(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<team4s_interfaces::msg::LaneCandidate> *>(untyped_member);
  return member->size();
}

const void * get_const_function__LaneObservation__candidates(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<team4s_interfaces::msg::LaneCandidate> *>(untyped_member);
  return &member[index];
}

void * get_function__LaneObservation__candidates(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<team4s_interfaces::msg::LaneCandidate> *>(untyped_member);
  return &member[index];
}

void fetch_function__LaneObservation__candidates(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const team4s_interfaces::msg::LaneCandidate *>(
    get_const_function__LaneObservation__candidates(untyped_member, index));
  auto & value = *reinterpret_cast<team4s_interfaces::msg::LaneCandidate *>(untyped_value);
  value = item;
}

void assign_function__LaneObservation__candidates(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<team4s_interfaces::msg::LaneCandidate *>(
    get_function__LaneObservation__candidates(untyped_member, index));
  const auto & value = *reinterpret_cast<const team4s_interfaces::msg::LaneCandidate *>(untyped_value);
  item = value;
}

void resize_function__LaneObservation__candidates(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<team4s_interfaces::msg::LaneCandidate> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember LaneObservation_message_member_array[12] = {
  {
    "meta",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<team4s_interfaces::msg::SourceHeader>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces::msg::LaneObservation, meta),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "image_width",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces::msg::LaneObservation, image_width),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "image_height",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces::msg::LaneObservation, image_height),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "candidates",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<team4s_interfaces::msg::LaneCandidate>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces::msg::LaneObservation, candidates),  // bytes offset in struct
    nullptr,  // default value
    size_function__LaneObservation__candidates,  // size() function pointer
    get_const_function__LaneObservation__candidates,  // get_const(index) function pointer
    get_function__LaneObservation__candidates,  // get(index) function pointer
    fetch_function__LaneObservation__candidates,  // fetch(index, &value) function pointer
    assign_function__LaneObservation__candidates,  // assign(index, value) function pointer
    resize_function__LaneObservation__candidates  // resize(index) function pointer
  },
  {
    "selected_candidate_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces::msg::LaneObservation, selected_candidate_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "offset_m_valid",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces::msg::LaneObservation, offset_m_valid),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "offset_m",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces::msg::LaneObservation, offset_m),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "metric_reason",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces::msg::LaneObservation, metric_reason),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "calibration_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces::msg::LaneObservation, calibration_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "metric_frame_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces::msg::LaneObservation, metric_frame_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "metric_reference_x_m",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces::msg::LaneObservation, metric_reference_x_m),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "metric_reference_y_m",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces::msg::LaneObservation, metric_reference_y_m),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers LaneObservation_message_members = {
  "team4s_interfaces::msg",  // message namespace
  "LaneObservation",  // message name
  12,  // number of fields
  sizeof(team4s_interfaces::msg::LaneObservation),
  LaneObservation_message_member_array,  // message members
  LaneObservation_init_function,  // function to initialize message memory (memory has to be allocated)
  LaneObservation_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t LaneObservation_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LaneObservation_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace team4s_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<team4s_interfaces::msg::LaneObservation>()
{
  return &::team4s_interfaces::msg::rosidl_typesupport_introspection_cpp::LaneObservation_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, team4s_interfaces, msg, LaneObservation)() {
  return &::team4s_interfaces::msg::rosidl_typesupport_introspection_cpp::LaneObservation_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from team4s_interfaces:msg/ConeDetection.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "team4s_interfaces/msg/detail/cone_detection__struct.hpp"
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

void ConeDetection_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) team4s_interfaces::msg::ConeDetection(_init);
}

void ConeDetection_fini_function(void * message_memory)
{
  auto typed_message = static_cast<team4s_interfaces::msg::ConeDetection *>(message_memory);
  typed_message->~ConeDetection();
}

size_t size_function__ConeDetection__bbox_xyxy(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__ConeDetection__bbox_xyxy(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int32_t, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__ConeDetection__bbox_xyxy(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int32_t, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__ConeDetection__bbox_xyxy(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int32_t *>(
    get_const_function__ConeDetection__bbox_xyxy(untyped_member, index));
  auto & value = *reinterpret_cast<int32_t *>(untyped_value);
  value = item;
}

void assign_function__ConeDetection__bbox_xyxy(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int32_t *>(
    get_function__ConeDetection__bbox_xyxy(untyped_member, index));
  const auto & value = *reinterpret_cast<const int32_t *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ConeDetection_message_member_array[5] = {
  {
    "candidate_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces::msg::ConeDetection, candidate_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "color",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces::msg::ConeDetection, color),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "bbox_known",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces::msg::ConeDetection, bbox_known),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "bbox_xyxy",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces::msg::ConeDetection, bbox_xyxy),  // bytes offset in struct
    nullptr,  // default value
    size_function__ConeDetection__bbox_xyxy,  // size() function pointer
    get_const_function__ConeDetection__bbox_xyxy,  // get_const(index) function pointer
    get_function__ConeDetection__bbox_xyxy,  // get(index) function pointer
    fetch_function__ConeDetection__bbox_xyxy,  // fetch(index, &value) function pointer
    assign_function__ConeDetection__bbox_xyxy,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "color_pixels",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(team4s_interfaces::msg::ConeDetection, color_pixels),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ConeDetection_message_members = {
  "team4s_interfaces::msg",  // message namespace
  "ConeDetection",  // message name
  5,  // number of fields
  sizeof(team4s_interfaces::msg::ConeDetection),
  ConeDetection_message_member_array,  // message members
  ConeDetection_init_function,  // function to initialize message memory (memory has to be allocated)
  ConeDetection_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ConeDetection_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ConeDetection_message_members,
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
get_message_type_support_handle<team4s_interfaces::msg::ConeDetection>()
{
  return &::team4s_interfaces::msg::rosidl_typesupport_introspection_cpp::ConeDetection_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, team4s_interfaces, msg, ConeDetection)() {
  return &::team4s_interfaces::msg::rosidl_typesupport_introspection_cpp::ConeDetection_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

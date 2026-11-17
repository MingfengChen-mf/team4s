// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from team4s_interfaces:msg/SceneObservation.idl
// generated code does not contain a copyright notice

#ifndef TEAM4S_INTERFACES__MSG__DETAIL__SCENE_OBSERVATION__BUILDER_HPP_
#define TEAM4S_INTERFACES__MSG__DETAIL__SCENE_OBSERVATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "team4s_interfaces/msg/detail/scene_observation__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace team4s_interfaces
{

namespace msg
{

namespace builder
{

class Init_SceneObservation_red_finish_event_stamp
{
public:
  explicit Init_SceneObservation_red_finish_event_stamp(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  ::team4s_interfaces::msg::SceneObservation red_finish_event_stamp(::team4s_interfaces::msg::SceneObservation::_red_finish_event_stamp_type arg)
  {
    msg_.red_finish_event_stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_red_finish_event_id
{
public:
  explicit Init_SceneObservation_red_finish_event_id(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  Init_SceneObservation_red_finish_event_stamp red_finish_event_id(::team4s_interfaces::msg::SceneObservation::_red_finish_event_id_type arg)
  {
    msg_.red_finish_event_id = std::move(arg);
    return Init_SceneObservation_red_finish_event_stamp(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_red_finish_confirmed
{
public:
  explicit Init_SceneObservation_red_finish_confirmed(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  Init_SceneObservation_red_finish_event_id red_finish_confirmed(::team4s_interfaces::msg::SceneObservation::_red_finish_confirmed_type arg)
  {
    msg_.red_finish_confirmed = std::move(arg);
    return Init_SceneObservation_red_finish_event_id(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_red_finish_visible
{
public:
  explicit Init_SceneObservation_red_finish_visible(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  Init_SceneObservation_red_finish_confirmed red_finish_visible(::team4s_interfaces::msg::SceneObservation::_red_finish_visible_type arg)
  {
    msg_.red_finish_visible = std::move(arg);
    return Init_SceneObservation_red_finish_confirmed(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_green_start_visible
{
public:
  explicit Init_SceneObservation_green_start_visible(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  Init_SceneObservation_red_finish_visible green_start_visible(::team4s_interfaces::msg::SceneObservation::_green_start_visible_type arg)
  {
    msg_.green_start_visible = std::move(arg);
    return Init_SceneObservation_red_finish_visible(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_cones
{
public:
  explicit Init_SceneObservation_cones(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  Init_SceneObservation_green_start_visible cones(::team4s_interfaces::msg::SceneObservation::_cones_type arg)
  {
    msg_.cones = std::move(arg);
    return Init_SceneObservation_green_start_visible(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_cones_reason
{
public:
  explicit Init_SceneObservation_cones_reason(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  Init_SceneObservation_cones cones_reason(::team4s_interfaces::msg::SceneObservation::_cones_reason_type arg)
  {
    msg_.cones_reason = std::move(arg);
    return Init_SceneObservation_cones(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_cones_valid
{
public:
  explicit Init_SceneObservation_cones_valid(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  Init_SceneObservation_cones_reason cones_valid(::team4s_interfaces::msg::SceneObservation::_cones_valid_type arg)
  {
    msg_.cones_valid = std::move(arg);
    return Init_SceneObservation_cones_reason(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_zebra_event_confirmed
{
public:
  explicit Init_SceneObservation_zebra_event_confirmed(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  Init_SceneObservation_cones_valid zebra_event_confirmed(::team4s_interfaces::msg::SceneObservation::_zebra_event_confirmed_type arg)
  {
    msg_.zebra_event_confirmed = std::move(arg);
    return Init_SceneObservation_cones_valid(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_zebra_event_stamp
{
public:
  explicit Init_SceneObservation_zebra_event_stamp(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  Init_SceneObservation_zebra_event_confirmed zebra_event_stamp(::team4s_interfaces::msg::SceneObservation::_zebra_event_stamp_type arg)
  {
    msg_.zebra_event_stamp = std::move(arg);
    return Init_SceneObservation_zebra_event_confirmed(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_zebra_event_id
{
public:
  explicit Init_SceneObservation_zebra_event_id(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  Init_SceneObservation_zebra_event_stamp zebra_event_id(::team4s_interfaces::msg::SceneObservation::_zebra_event_id_type arg)
  {
    msg_.zebra_event_id = std::move(arg);
    return Init_SceneObservation_zebra_event_stamp(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_cone_event_stamp
{
public:
  explicit Init_SceneObservation_cone_event_stamp(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  Init_SceneObservation_zebra_event_id cone_event_stamp(::team4s_interfaces::msg::SceneObservation::_cone_event_stamp_type arg)
  {
    msg_.cone_event_stamp = std::move(arg);
    return Init_SceneObservation_zebra_event_id(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_cone_event_id
{
public:
  explicit Init_SceneObservation_cone_event_id(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  Init_SceneObservation_cone_event_stamp cone_event_id(::team4s_interfaces::msg::SceneObservation::_cone_event_id_type arg)
  {
    msg_.cone_event_id = std::move(arg);
    return Init_SceneObservation_cone_event_stamp(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_image_height
{
public:
  explicit Init_SceneObservation_image_height(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  Init_SceneObservation_cone_event_id image_height(::team4s_interfaces::msg::SceneObservation::_image_height_type arg)
  {
    msg_.image_height = std::move(arg);
    return Init_SceneObservation_cone_event_id(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_image_width
{
public:
  explicit Init_SceneObservation_image_width(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  Init_SceneObservation_image_height image_width(::team4s_interfaces::msg::SceneObservation::_image_width_type arg)
  {
    msg_.image_width = std::move(arg);
    return Init_SceneObservation_image_height(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_zebra_bbox_xyxy
{
public:
  explicit Init_SceneObservation_zebra_bbox_xyxy(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  Init_SceneObservation_image_width zebra_bbox_xyxy(::team4s_interfaces::msg::SceneObservation::_zebra_bbox_xyxy_type arg)
  {
    msg_.zebra_bbox_xyxy = std::move(arg);
    return Init_SceneObservation_image_width(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_zebra_bbox_known
{
public:
  explicit Init_SceneObservation_zebra_bbox_known(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  Init_SceneObservation_zebra_bbox_xyxy zebra_bbox_known(::team4s_interfaces::msg::SceneObservation::_zebra_bbox_known_type arg)
  {
    msg_.zebra_bbox_known = std::move(arg);
    return Init_SceneObservation_zebra_bbox_xyxy(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_zebra_visible
{
public:
  explicit Init_SceneObservation_zebra_visible(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  Init_SceneObservation_zebra_bbox_known zebra_visible(::team4s_interfaces::msg::SceneObservation::_zebra_visible_type arg)
  {
    msg_.zebra_visible = std::move(arg);
    return Init_SceneObservation_zebra_bbox_known(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_zebra_valid
{
public:
  explicit Init_SceneObservation_zebra_valid(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  Init_SceneObservation_zebra_visible zebra_valid(::team4s_interfaces::msg::SceneObservation::_zebra_valid_type arg)
  {
    msg_.zebra_valid = std::move(arg);
    return Init_SceneObservation_zebra_visible(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_cone_bbox_xyxy
{
public:
  explicit Init_SceneObservation_cone_bbox_xyxy(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  Init_SceneObservation_zebra_valid cone_bbox_xyxy(::team4s_interfaces::msg::SceneObservation::_cone_bbox_xyxy_type arg)
  {
    msg_.cone_bbox_xyxy = std::move(arg);
    return Init_SceneObservation_zebra_valid(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_cone_bbox_known
{
public:
  explicit Init_SceneObservation_cone_bbox_known(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  Init_SceneObservation_cone_bbox_xyxy cone_bbox_known(::team4s_interfaces::msg::SceneObservation::_cone_bbox_known_type arg)
  {
    msg_.cone_bbox_known = std::move(arg);
    return Init_SceneObservation_cone_bbox_xyxy(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_cone_state
{
public:
  explicit Init_SceneObservation_cone_state(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  Init_SceneObservation_cone_bbox_known cone_state(::team4s_interfaces::msg::SceneObservation::_cone_state_type arg)
  {
    msg_.cone_state = std::move(arg);
    return Init_SceneObservation_cone_bbox_known(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_cone_valid
{
public:
  explicit Init_SceneObservation_cone_valid(::team4s_interfaces::msg::SceneObservation & msg)
  : msg_(msg)
  {}
  Init_SceneObservation_cone_state cone_valid(::team4s_interfaces::msg::SceneObservation::_cone_valid_type arg)
  {
    msg_.cone_valid = std::move(arg);
    return Init_SceneObservation_cone_state(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

class Init_SceneObservation_meta
{
public:
  Init_SceneObservation_meta()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SceneObservation_cone_valid meta(::team4s_interfaces::msg::SceneObservation::_meta_type arg)
  {
    msg_.meta = std::move(arg);
    return Init_SceneObservation_cone_valid(msg_);
  }

private:
  ::team4s_interfaces::msg::SceneObservation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::team4s_interfaces::msg::SceneObservation>()
{
  return team4s_interfaces::msg::builder::Init_SceneObservation_meta();
}

}  // namespace team4s_interfaces

#endif  // TEAM4S_INTERFACES__MSG__DETAIL__SCENE_OBSERVATION__BUILDER_HPP_

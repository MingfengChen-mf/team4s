cmake_minimum_required(VERSION 3.5)
project(team4s_interfaces)
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/SourceHeader.msg"
  "msg/LaneCandidate.msg"
  "msg/LaneObservation.msg"
  "msg/RangeReading.msg"
  "msg/ObstacleObservation.msg"
  "msg/ConeDetection.msg"
  "msg/SceneObservation.msg"
  "msg/TopicHealth.msg"
  "msg/PerceptionSnapshot.msg"
  "msg/TaskState.msg"
  DEPENDENCIES std_msgs builtin_interfaces
)
ament_export_dependencies(rosidl_default_runtime)
ament_package()

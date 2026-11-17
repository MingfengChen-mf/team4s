# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target team4s_interfaces::team4s_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${team4s_interfaces_TARGETS}.
if(team4s_interfaces_TARGETS AND NOT TARGET team4s_interfaces::team4s_interfaces)
  add_library(team4s_interfaces::team4s_interfaces INTERFACE IMPORTED)
  set_target_properties(team4s_interfaces::team4s_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${team4s_interfaces_TARGETS}")
endif()

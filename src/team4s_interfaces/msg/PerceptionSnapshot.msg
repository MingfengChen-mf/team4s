# Aggregate time, not the acquisition time of all children.
std_msgs/Header header
string aggregator_session_id
string run_id
uint64 sequence
team4s_interfaces/LaneObservation lane
team4s_interfaces/TopicHealth lane_health
team4s_interfaces/ObstacleObservation obstacles
team4s_interfaces/TopicHealth obstacles_health
team4s_interfaces/SceneObservation scene
team4s_interfaces/TopicHealth scene_health

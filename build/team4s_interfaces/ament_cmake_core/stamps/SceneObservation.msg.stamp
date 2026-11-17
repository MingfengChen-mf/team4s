uint8 CONE_UNKNOWN=0
uint8 CONE_PRESENT=1
uint8 CONE_LEAVING=2
uint8 CONE_REMOVED=3
team4s_interfaces/SourceHeader meta
bool cone_valid
uint8 cone_state
bool cone_bbox_known
int32[4] cone_bbox_xyxy
bool zebra_valid
bool zebra_visible
bool zebra_bbox_known
int32[4] zebra_bbox_xyxy
# Boxes refer to input-image pixels only; half-open right/bottom limits.
uint32 image_width
uint32 image_height
# Tracking IDs, scoped to source_session_id. These do NOT prove lap completion.
uint64 cone_event_id
builtin_interfaces/Time cone_event_stamp
uint64 zebra_event_id
builtin_interfaces/Time zebra_event_stamp
bool zebra_event_confirmed

# v2 cone_* legacy fields above now refer ONLY to the green start cone.
bool cones_valid
string cones_reason
team4s_interfaces/ConeDetection[] cones
bool green_start_visible
bool red_finish_visible
# Observation confirmation only. Control decides whether this is a finish.
bool red_finish_confirmed
uint64 red_finish_event_id
builtin_interfaces/Time red_finish_event_stamp

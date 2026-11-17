# ROS time of acquisition; read-start approximation is explicitly labelled.
uint8 STAMP_UNKNOWN=0
uint8 STAMP_READ_START=1
uint8 STAMP_HARDWARE_SYNCED=2
std_msgs/Header header
string source_id
string source_session_id
string run_id
uint64 sequence
uint8 stamp_source
bool valid
string reason

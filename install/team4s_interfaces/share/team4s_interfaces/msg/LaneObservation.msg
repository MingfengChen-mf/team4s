team4s_interfaces/SourceHeader meta
uint32 image_width
uint32 image_height
team4s_interfaces/LaneCandidate[] candidates

# Metric summary belongs to exactly one candidate selected by task context.
string selected_candidate_id
bool offset_m_valid
# Positive right, at the projected reference point; NOT axle lateral error.
float32 offset_m
string metric_reason
string calibration_id
string metric_frame_id
float32 metric_reference_x_m
float32 metric_reference_y_m

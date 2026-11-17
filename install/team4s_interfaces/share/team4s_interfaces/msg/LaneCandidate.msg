uint8 UNKNOWN=0
uint8 FIRST=1
uint8 SECOND=2
string candidate_id
uint8 route_lane
bool is_branch
bool left_visible
bool right_visible
bool center_valid
# lane center x - image center x, original input image pixels, positive right
float32 offset_px
int32 reference_y_px
# Positive heading means path points right of image-up. Not a steering angle.
bool heading_valid
float32 heading_rad

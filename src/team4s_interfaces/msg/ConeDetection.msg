uint8 COLOR_UNKNOWN=0
uint8 COLOR_GREEN=1
uint8 COLOR_RED=2
# Frame-local candidate ID, not a stable tracking identifier.
string candidate_id
uint8 color
bool bbox_known
int32[4] bbox_xyxy
uint32 color_pixels

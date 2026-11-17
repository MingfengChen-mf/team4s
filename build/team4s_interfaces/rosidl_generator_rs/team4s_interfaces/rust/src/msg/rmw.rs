#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "team4s_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__team4s_interfaces__msg__SourceHeader() -> *const std::ffi::c_void;
}

#[link(name = "team4s_interfaces__rosidl_generator_c")]
extern "C" {
    fn team4s_interfaces__msg__SourceHeader__init(msg: *mut SourceHeader) -> bool;
    fn team4s_interfaces__msg__SourceHeader__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SourceHeader>, size: usize) -> bool;
    fn team4s_interfaces__msg__SourceHeader__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SourceHeader>);
    fn team4s_interfaces__msg__SourceHeader__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SourceHeader>, out_seq: *mut rosidl_runtime_rs::Sequence<SourceHeader>) -> bool;
}

// Corresponds to team4s_interfaces__msg__SourceHeader
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// ROS time of acquisition; read-start approximation is explicitly labelled.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SourceHeader {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub source_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub source_session_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub run_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub sequence: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp_source: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub valid: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reason: rosidl_runtime_rs::String,

}

impl SourceHeader {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const STAMP_UNKNOWN: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const STAMP_READ_START: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const STAMP_HARDWARE_SYNCED: u8 = 2;

}


impl Default for SourceHeader {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !team4s_interfaces__msg__SourceHeader__init(&mut msg as *mut _) {
        panic!("Call to team4s_interfaces__msg__SourceHeader__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SourceHeader {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__SourceHeader__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__SourceHeader__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__SourceHeader__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SourceHeader {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SourceHeader where Self: Sized {
  const TYPE_NAME: &'static str = "team4s_interfaces/msg/SourceHeader";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__team4s_interfaces__msg__SourceHeader() }
  }
}


#[link(name = "team4s_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__team4s_interfaces__msg__LaneCandidate() -> *const std::ffi::c_void;
}

#[link(name = "team4s_interfaces__rosidl_generator_c")]
extern "C" {
    fn team4s_interfaces__msg__LaneCandidate__init(msg: *mut LaneCandidate) -> bool;
    fn team4s_interfaces__msg__LaneCandidate__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<LaneCandidate>, size: usize) -> bool;
    fn team4s_interfaces__msg__LaneCandidate__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<LaneCandidate>);
    fn team4s_interfaces__msg__LaneCandidate__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<LaneCandidate>, out_seq: *mut rosidl_runtime_rs::Sequence<LaneCandidate>) -> bool;
}

// Corresponds to team4s_interfaces__msg__LaneCandidate
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LaneCandidate {

    // This member is not documented.
    #[allow(missing_docs)]
    pub candidate_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub route_lane: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_branch: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub left_visible: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub right_visible: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub center_valid: bool,

    /// lane center x - image center x, original input image pixels, positive right
    pub offset_px: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reference_y_px: i32,

    /// Positive heading means path points right of image-up. Not a steering angle.
    pub heading_valid: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub heading_rad: f32,

}

impl LaneCandidate {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const UNKNOWN: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIRST: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const SECOND: u8 = 2;

}


impl Default for LaneCandidate {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !team4s_interfaces__msg__LaneCandidate__init(&mut msg as *mut _) {
        panic!("Call to team4s_interfaces__msg__LaneCandidate__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for LaneCandidate {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__LaneCandidate__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__LaneCandidate__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__LaneCandidate__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for LaneCandidate {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for LaneCandidate where Self: Sized {
  const TYPE_NAME: &'static str = "team4s_interfaces/msg/LaneCandidate";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__team4s_interfaces__msg__LaneCandidate() }
  }
}


#[link(name = "team4s_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__team4s_interfaces__msg__LaneObservation() -> *const std::ffi::c_void;
}

#[link(name = "team4s_interfaces__rosidl_generator_c")]
extern "C" {
    fn team4s_interfaces__msg__LaneObservation__init(msg: *mut LaneObservation) -> bool;
    fn team4s_interfaces__msg__LaneObservation__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<LaneObservation>, size: usize) -> bool;
    fn team4s_interfaces__msg__LaneObservation__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<LaneObservation>);
    fn team4s_interfaces__msg__LaneObservation__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<LaneObservation>, out_seq: *mut rosidl_runtime_rs::Sequence<LaneObservation>) -> bool;
}

// Corresponds to team4s_interfaces__msg__LaneObservation
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LaneObservation {

    // This member is not documented.
    #[allow(missing_docs)]
    pub meta: super::super::msg::rmw::SourceHeader,


    // This member is not documented.
    #[allow(missing_docs)]
    pub image_width: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub image_height: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub candidates: rosidl_runtime_rs::Sequence<super::super::msg::rmw::LaneCandidate>,

    /// Metric summary belongs to exactly one candidate selected by task context.
    pub selected_candidate_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub offset_m_valid: bool,

    /// Positive right, at the projected reference point; NOT axle lateral error.
    pub offset_m: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub metric_reason: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub calibration_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub metric_frame_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub metric_reference_x_m: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub metric_reference_y_m: f32,

}



impl Default for LaneObservation {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !team4s_interfaces__msg__LaneObservation__init(&mut msg as *mut _) {
        panic!("Call to team4s_interfaces__msg__LaneObservation__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for LaneObservation {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__LaneObservation__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__LaneObservation__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__LaneObservation__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for LaneObservation {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for LaneObservation where Self: Sized {
  const TYPE_NAME: &'static str = "team4s_interfaces/msg/LaneObservation";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__team4s_interfaces__msg__LaneObservation() }
  }
}


#[link(name = "team4s_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__team4s_interfaces__msg__RangeReading() -> *const std::ffi::c_void;
}

#[link(name = "team4s_interfaces__rosidl_generator_c")]
extern "C" {
    fn team4s_interfaces__msg__RangeReading__init(msg: *mut RangeReading) -> bool;
    fn team4s_interfaces__msg__RangeReading__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RangeReading>, size: usize) -> bool;
    fn team4s_interfaces__msg__RangeReading__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RangeReading>);
    fn team4s_interfaces__msg__RangeReading__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RangeReading>, out_seq: *mut rosidl_runtime_rs::Sequence<RangeReading>) -> bool;
}

// Corresponds to team4s_interfaces__msg__RangeReading
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RangeReading {

    // This member is not documented.
    #[allow(missing_docs)]
    pub sensor_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub sensor_frame_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub valid: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reason: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub checksum_ok: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub device_status_raw: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub distance_m: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub signal_strength: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub sensor_time_ms: u32,

    /// Bearing relative to base_link only when transform has been verified.
    pub bearing_known: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bearing_rad: f32,

}



impl Default for RangeReading {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !team4s_interfaces__msg__RangeReading__init(&mut msg as *mut _) {
        panic!("Call to team4s_interfaces__msg__RangeReading__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RangeReading {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__RangeReading__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__RangeReading__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__RangeReading__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RangeReading {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RangeReading where Self: Sized {
  const TYPE_NAME: &'static str = "team4s_interfaces/msg/RangeReading";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__team4s_interfaces__msg__RangeReading() }
  }
}


#[link(name = "team4s_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__team4s_interfaces__msg__ObstacleObservation() -> *const std::ffi::c_void;
}

#[link(name = "team4s_interfaces__rosidl_generator_c")]
extern "C" {
    fn team4s_interfaces__msg__ObstacleObservation__init(msg: *mut ObstacleObservation) -> bool;
    fn team4s_interfaces__msg__ObstacleObservation__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ObstacleObservation>, size: usize) -> bool;
    fn team4s_interfaces__msg__ObstacleObservation__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ObstacleObservation>);
    fn team4s_interfaces__msg__ObstacleObservation__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ObstacleObservation>, out_seq: *mut rosidl_runtime_rs::Sequence<ObstacleObservation>) -> bool;
}

// Corresponds to team4s_interfaces__msg__ObstacleObservation
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ObstacleObservation {

    // This member is not documented.
    #[allow(missing_docs)]
    pub meta: super::super::msg::rmw::SourceHeader,


    // This member is not documented.
    #[allow(missing_docs)]
    pub readings: rosidl_runtime_rs::Sequence<super::super::msg::rmw::RangeReading>,

    /// Unknown space must not be encoded as clear.
    pub left_clear_known: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub left_clear: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub right_clear_known: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub right_clear: bool,

}



impl Default for ObstacleObservation {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !team4s_interfaces__msg__ObstacleObservation__init(&mut msg as *mut _) {
        panic!("Call to team4s_interfaces__msg__ObstacleObservation__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ObstacleObservation {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__ObstacleObservation__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__ObstacleObservation__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__ObstacleObservation__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ObstacleObservation {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ObstacleObservation where Self: Sized {
  const TYPE_NAME: &'static str = "team4s_interfaces/msg/ObstacleObservation";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__team4s_interfaces__msg__ObstacleObservation() }
  }
}


#[link(name = "team4s_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__team4s_interfaces__msg__ConeDetection() -> *const std::ffi::c_void;
}

#[link(name = "team4s_interfaces__rosidl_generator_c")]
extern "C" {
    fn team4s_interfaces__msg__ConeDetection__init(msg: *mut ConeDetection) -> bool;
    fn team4s_interfaces__msg__ConeDetection__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ConeDetection>, size: usize) -> bool;
    fn team4s_interfaces__msg__ConeDetection__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ConeDetection>);
    fn team4s_interfaces__msg__ConeDetection__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ConeDetection>, out_seq: *mut rosidl_runtime_rs::Sequence<ConeDetection>) -> bool;
}

// Corresponds to team4s_interfaces__msg__ConeDetection
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ConeDetection {
    /// Frame-local candidate ID, not a stable tracking identifier.
    pub candidate_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub color: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_known: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_xyxy: [i32; 4],


    // This member is not documented.
    #[allow(missing_docs)]
    pub color_pixels: u32,

}

impl ConeDetection {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const COLOR_UNKNOWN: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const COLOR_GREEN: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const COLOR_RED: u8 = 2;

}


impl Default for ConeDetection {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !team4s_interfaces__msg__ConeDetection__init(&mut msg as *mut _) {
        panic!("Call to team4s_interfaces__msg__ConeDetection__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ConeDetection {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__ConeDetection__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__ConeDetection__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__ConeDetection__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ConeDetection {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ConeDetection where Self: Sized {
  const TYPE_NAME: &'static str = "team4s_interfaces/msg/ConeDetection";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__team4s_interfaces__msg__ConeDetection() }
  }
}


#[link(name = "team4s_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__team4s_interfaces__msg__SceneObservation() -> *const std::ffi::c_void;
}

#[link(name = "team4s_interfaces__rosidl_generator_c")]
extern "C" {
    fn team4s_interfaces__msg__SceneObservation__init(msg: *mut SceneObservation) -> bool;
    fn team4s_interfaces__msg__SceneObservation__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SceneObservation>, size: usize) -> bool;
    fn team4s_interfaces__msg__SceneObservation__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SceneObservation>);
    fn team4s_interfaces__msg__SceneObservation__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SceneObservation>, out_seq: *mut rosidl_runtime_rs::Sequence<SceneObservation>) -> bool;
}

// Corresponds to team4s_interfaces__msg__SceneObservation
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SceneObservation {

    // This member is not documented.
    #[allow(missing_docs)]
    pub meta: super::super::msg::rmw::SourceHeader,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cone_valid: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cone_state: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cone_bbox_known: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cone_bbox_xyxy: [i32; 4],


    // This member is not documented.
    #[allow(missing_docs)]
    pub zebra_valid: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zebra_visible: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zebra_bbox_known: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zebra_bbox_xyxy: [i32; 4],

    /// Boxes refer to input-image pixels only; half-open right/bottom limits.
    pub image_width: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub image_height: u32,

    /// Tracking IDs, scoped to source_session_id. These do NOT prove lap completion.
    pub cone_event_id: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cone_event_stamp: builtin_interfaces::msg::rmw::Time,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zebra_event_id: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zebra_event_stamp: builtin_interfaces::msg::rmw::Time,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zebra_event_confirmed: bool,

    /// v2 cone_* legacy fields above now refer ONLY to the green start cone.
    pub cones_valid: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cones_reason: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cones: rosidl_runtime_rs::Sequence<super::super::msg::rmw::ConeDetection>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub green_start_visible: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub red_finish_visible: bool,

    /// Observation confirmation only. Control decides whether this is a finish.
    pub red_finish_confirmed: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub red_finish_event_id: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub red_finish_event_stamp: builtin_interfaces::msg::rmw::Time,

}

impl SceneObservation {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CONE_UNKNOWN: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CONE_PRESENT: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CONE_LEAVING: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CONE_REMOVED: u8 = 3;

}


impl Default for SceneObservation {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !team4s_interfaces__msg__SceneObservation__init(&mut msg as *mut _) {
        panic!("Call to team4s_interfaces__msg__SceneObservation__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SceneObservation {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__SceneObservation__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__SceneObservation__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__SceneObservation__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SceneObservation {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SceneObservation where Self: Sized {
  const TYPE_NAME: &'static str = "team4s_interfaces/msg/SceneObservation";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__team4s_interfaces__msg__SceneObservation() }
  }
}


#[link(name = "team4s_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__team4s_interfaces__msg__TopicHealth() -> *const std::ffi::c_void;
}

#[link(name = "team4s_interfaces__rosidl_generator_c")]
extern "C" {
    fn team4s_interfaces__msg__TopicHealth__init(msg: *mut TopicHealth) -> bool;
    fn team4s_interfaces__msg__TopicHealth__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TopicHealth>, size: usize) -> bool;
    fn team4s_interfaces__msg__TopicHealth__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TopicHealth>);
    fn team4s_interfaces__msg__TopicHealth__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TopicHealth>, out_seq: *mut rosidl_runtime_rs::Sequence<TopicHealth>) -> bool;
}

// Corresponds to team4s_interfaces__msg__TopicHealth
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TopicHealth {

    // This member is not documented.
    #[allow(missing_docs)]
    pub state: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reason: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub age_known: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub age_s: f32,

    /// Must be configured > 0 before control integration; 0 = unconfigured.
    pub max_age_s: f32,

}

impl TopicHealth {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MISSING: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALID: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const INVALID: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const STALE: u8 = 3;

}


impl Default for TopicHealth {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !team4s_interfaces__msg__TopicHealth__init(&mut msg as *mut _) {
        panic!("Call to team4s_interfaces__msg__TopicHealth__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TopicHealth {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__TopicHealth__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__TopicHealth__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__TopicHealth__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TopicHealth {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TopicHealth where Self: Sized {
  const TYPE_NAME: &'static str = "team4s_interfaces/msg/TopicHealth";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__team4s_interfaces__msg__TopicHealth() }
  }
}


#[link(name = "team4s_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__team4s_interfaces__msg__PerceptionSnapshot() -> *const std::ffi::c_void;
}

#[link(name = "team4s_interfaces__rosidl_generator_c")]
extern "C" {
    fn team4s_interfaces__msg__PerceptionSnapshot__init(msg: *mut PerceptionSnapshot) -> bool;
    fn team4s_interfaces__msg__PerceptionSnapshot__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PerceptionSnapshot>, size: usize) -> bool;
    fn team4s_interfaces__msg__PerceptionSnapshot__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PerceptionSnapshot>);
    fn team4s_interfaces__msg__PerceptionSnapshot__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PerceptionSnapshot>, out_seq: *mut rosidl_runtime_rs::Sequence<PerceptionSnapshot>) -> bool;
}

// Corresponds to team4s_interfaces__msg__PerceptionSnapshot
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Aggregate time, not the acquisition time of all children.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PerceptionSnapshot {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub aggregator_session_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub run_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub sequence: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub lane: super::super::msg::rmw::LaneObservation,


    // This member is not documented.
    #[allow(missing_docs)]
    pub lane_health: super::super::msg::rmw::TopicHealth,


    // This member is not documented.
    #[allow(missing_docs)]
    pub obstacles: super::super::msg::rmw::ObstacleObservation,


    // This member is not documented.
    #[allow(missing_docs)]
    pub obstacles_health: super::super::msg::rmw::TopicHealth,


    // This member is not documented.
    #[allow(missing_docs)]
    pub scene: super::super::msg::rmw::SceneObservation,


    // This member is not documented.
    #[allow(missing_docs)]
    pub scene_health: super::super::msg::rmw::TopicHealth,

}



impl Default for PerceptionSnapshot {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !team4s_interfaces__msg__PerceptionSnapshot__init(&mut msg as *mut _) {
        panic!("Call to team4s_interfaces__msg__PerceptionSnapshot__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PerceptionSnapshot {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__PerceptionSnapshot__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__PerceptionSnapshot__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__PerceptionSnapshot__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PerceptionSnapshot {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PerceptionSnapshot where Self: Sized {
  const TYPE_NAME: &'static str = "team4s_interfaces/msg/PerceptionSnapshot";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__team4s_interfaces__msg__PerceptionSnapshot() }
  }
}


#[link(name = "team4s_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__team4s_interfaces__msg__TaskState() -> *const std::ffi::c_void;
}

#[link(name = "team4s_interfaces__rosidl_generator_c")]
extern "C" {
    fn team4s_interfaces__msg__TaskState__init(msg: *mut TaskState) -> bool;
    fn team4s_interfaces__msg__TaskState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TaskState>, size: usize) -> bool;
    fn team4s_interfaces__msg__TaskState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TaskState>);
    fn team4s_interfaces__msg__TaskState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TaskState>, out_seq: *mut rosidl_runtime_rs::Sequence<TaskState>) -> bool;
}

// Corresponds to team4s_interfaces__msg__TaskState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TaskState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub run_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub controller_session_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub sequence: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub task_id: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub phase: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub target_lane: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub control_mode: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub lap_complete: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reason: rosidl_runtime_rs::String,

}

impl TaskState {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TASK_NONE: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TASK_LAP: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TASK_STRAIGHT: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const LANE_UNKNOWN: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const LANE_FIRST: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const LANE_SECOND: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MODE_IDLE: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MODE_AUTO: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MODE_MANUAL: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MODE_PAUSED: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MODE_FINISHED: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MODE_FAULT: u8 = 5;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PHASE_IDLE: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PHASE_WAIT_START: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PHASE_FOLLOW_LAP: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PHASE_FOLLOW_FIRST: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PHASE_AVOIDING: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PHASE_FOLLOW_SECOND: u8 = 5;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PHASE_ZEBRA_SLOW: u8 = 6;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PHASE_FINISH_APPROACH: u8 = 7;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PHASE_STOPPED: u8 = 8;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PHASE_FAULT: u8 = 9;

}


impl Default for TaskState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !team4s_interfaces__msg__TaskState__init(&mut msg as *mut _) {
        panic!("Call to team4s_interfaces__msg__TaskState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TaskState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__TaskState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__TaskState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { team4s_interfaces__msg__TaskState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TaskState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TaskState where Self: Sized {
  const TYPE_NAME: &'static str = "team4s_interfaces/msg/TaskState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__team4s_interfaces__msg__TaskState() }
  }
}



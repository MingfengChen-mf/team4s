#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to team4s_interfaces__msg__SourceHeader
/// ROS time of acquisition; read-start approximation is explicitly labelled.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SourceHeader {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub source_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub source_session_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub run_id: std::string::String,


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
    pub reason: std::string::String,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::SourceHeader::default())
  }
}

impl rosidl_runtime_rs::Message for SourceHeader {
  type RmwMsg = super::msg::rmw::SourceHeader;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        source_id: msg.source_id.as_str().into(),
        source_session_id: msg.source_session_id.as_str().into(),
        run_id: msg.run_id.as_str().into(),
        sequence: msg.sequence,
        stamp_source: msg.stamp_source,
        valid: msg.valid,
        reason: msg.reason.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        source_id: msg.source_id.as_str().into(),
        source_session_id: msg.source_session_id.as_str().into(),
        run_id: msg.run_id.as_str().into(),
      sequence: msg.sequence,
      stamp_source: msg.stamp_source,
      valid: msg.valid,
        reason: msg.reason.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      source_id: msg.source_id.to_string(),
      source_session_id: msg.source_session_id.to_string(),
      run_id: msg.run_id.to_string(),
      sequence: msg.sequence,
      stamp_source: msg.stamp_source,
      valid: msg.valid,
      reason: msg.reason.to_string(),
    }
  }
}


// Corresponds to team4s_interfaces__msg__LaneCandidate

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LaneCandidate {

    // This member is not documented.
    #[allow(missing_docs)]
    pub candidate_id: std::string::String,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::LaneCandidate::default())
  }
}

impl rosidl_runtime_rs::Message for LaneCandidate {
  type RmwMsg = super::msg::rmw::LaneCandidate;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        candidate_id: msg.candidate_id.as_str().into(),
        route_lane: msg.route_lane,
        is_branch: msg.is_branch,
        left_visible: msg.left_visible,
        right_visible: msg.right_visible,
        center_valid: msg.center_valid,
        offset_px: msg.offset_px,
        reference_y_px: msg.reference_y_px,
        heading_valid: msg.heading_valid,
        heading_rad: msg.heading_rad,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        candidate_id: msg.candidate_id.as_str().into(),
      route_lane: msg.route_lane,
      is_branch: msg.is_branch,
      left_visible: msg.left_visible,
      right_visible: msg.right_visible,
      center_valid: msg.center_valid,
      offset_px: msg.offset_px,
      reference_y_px: msg.reference_y_px,
      heading_valid: msg.heading_valid,
      heading_rad: msg.heading_rad,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      candidate_id: msg.candidate_id.to_string(),
      route_lane: msg.route_lane,
      is_branch: msg.is_branch,
      left_visible: msg.left_visible,
      right_visible: msg.right_visible,
      center_valid: msg.center_valid,
      offset_px: msg.offset_px,
      reference_y_px: msg.reference_y_px,
      heading_valid: msg.heading_valid,
      heading_rad: msg.heading_rad,
    }
  }
}


// Corresponds to team4s_interfaces__msg__LaneObservation

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LaneObservation {

    // This member is not documented.
    #[allow(missing_docs)]
    pub meta: super::msg::SourceHeader,


    // This member is not documented.
    #[allow(missing_docs)]
    pub image_width: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub image_height: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub candidates: Vec<super::msg::LaneCandidate>,

    /// Metric summary belongs to exactly one candidate selected by task context.
    pub selected_candidate_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub offset_m_valid: bool,

    /// Positive right, at the projected reference point; NOT axle lateral error.
    pub offset_m: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub metric_reason: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub calibration_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub metric_frame_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub metric_reference_x_m: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub metric_reference_y_m: f32,

}



impl Default for LaneObservation {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::LaneObservation::default())
  }
}

impl rosidl_runtime_rs::Message for LaneObservation {
  type RmwMsg = super::msg::rmw::LaneObservation;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        meta: super::msg::SourceHeader::into_rmw_message(std::borrow::Cow::Owned(msg.meta)).into_owned(),
        image_width: msg.image_width,
        image_height: msg.image_height,
        candidates: msg.candidates
          .into_iter()
          .map(|elem| super::msg::LaneCandidate::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        selected_candidate_id: msg.selected_candidate_id.as_str().into(),
        offset_m_valid: msg.offset_m_valid,
        offset_m: msg.offset_m,
        metric_reason: msg.metric_reason.as_str().into(),
        calibration_id: msg.calibration_id.as_str().into(),
        metric_frame_id: msg.metric_frame_id.as_str().into(),
        metric_reference_x_m: msg.metric_reference_x_m,
        metric_reference_y_m: msg.metric_reference_y_m,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        meta: super::msg::SourceHeader::into_rmw_message(std::borrow::Cow::Borrowed(&msg.meta)).into_owned(),
      image_width: msg.image_width,
      image_height: msg.image_height,
        candidates: msg.candidates
          .iter()
          .map(|elem| super::msg::LaneCandidate::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        selected_candidate_id: msg.selected_candidate_id.as_str().into(),
      offset_m_valid: msg.offset_m_valid,
      offset_m: msg.offset_m,
        metric_reason: msg.metric_reason.as_str().into(),
        calibration_id: msg.calibration_id.as_str().into(),
        metric_frame_id: msg.metric_frame_id.as_str().into(),
      metric_reference_x_m: msg.metric_reference_x_m,
      metric_reference_y_m: msg.metric_reference_y_m,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      meta: super::msg::SourceHeader::from_rmw_message(msg.meta),
      image_width: msg.image_width,
      image_height: msg.image_height,
      candidates: msg.candidates
          .into_iter()
          .map(super::msg::LaneCandidate::from_rmw_message)
          .collect(),
      selected_candidate_id: msg.selected_candidate_id.to_string(),
      offset_m_valid: msg.offset_m_valid,
      offset_m: msg.offset_m,
      metric_reason: msg.metric_reason.to_string(),
      calibration_id: msg.calibration_id.to_string(),
      metric_frame_id: msg.metric_frame_id.to_string(),
      metric_reference_x_m: msg.metric_reference_x_m,
      metric_reference_y_m: msg.metric_reference_y_m,
    }
  }
}


// Corresponds to team4s_interfaces__msg__RangeReading

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RangeReading {

    // This member is not documented.
    #[allow(missing_docs)]
    pub sensor_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub sensor_frame_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub valid: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reason: std::string::String,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::RangeReading::default())
  }
}

impl rosidl_runtime_rs::Message for RangeReading {
  type RmwMsg = super::msg::rmw::RangeReading;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        sensor_id: msg.sensor_id.as_str().into(),
        sensor_frame_id: msg.sensor_frame_id.as_str().into(),
        valid: msg.valid,
        reason: msg.reason.as_str().into(),
        checksum_ok: msg.checksum_ok,
        device_status_raw: msg.device_status_raw,
        distance_m: msg.distance_m,
        signal_strength: msg.signal_strength,
        sensor_time_ms: msg.sensor_time_ms,
        bearing_known: msg.bearing_known,
        bearing_rad: msg.bearing_rad,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        sensor_id: msg.sensor_id.as_str().into(),
        sensor_frame_id: msg.sensor_frame_id.as_str().into(),
      valid: msg.valid,
        reason: msg.reason.as_str().into(),
      checksum_ok: msg.checksum_ok,
      device_status_raw: msg.device_status_raw,
      distance_m: msg.distance_m,
      signal_strength: msg.signal_strength,
      sensor_time_ms: msg.sensor_time_ms,
      bearing_known: msg.bearing_known,
      bearing_rad: msg.bearing_rad,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      sensor_id: msg.sensor_id.to_string(),
      sensor_frame_id: msg.sensor_frame_id.to_string(),
      valid: msg.valid,
      reason: msg.reason.to_string(),
      checksum_ok: msg.checksum_ok,
      device_status_raw: msg.device_status_raw,
      distance_m: msg.distance_m,
      signal_strength: msg.signal_strength,
      sensor_time_ms: msg.sensor_time_ms,
      bearing_known: msg.bearing_known,
      bearing_rad: msg.bearing_rad,
    }
  }
}


// Corresponds to team4s_interfaces__msg__ObstacleObservation

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ObstacleObservation {

    // This member is not documented.
    #[allow(missing_docs)]
    pub meta: super::msg::SourceHeader,


    // This member is not documented.
    #[allow(missing_docs)]
    pub readings: Vec<super::msg::RangeReading>,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ObstacleObservation::default())
  }
}

impl rosidl_runtime_rs::Message for ObstacleObservation {
  type RmwMsg = super::msg::rmw::ObstacleObservation;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        meta: super::msg::SourceHeader::into_rmw_message(std::borrow::Cow::Owned(msg.meta)).into_owned(),
        readings: msg.readings
          .into_iter()
          .map(|elem| super::msg::RangeReading::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        left_clear_known: msg.left_clear_known,
        left_clear: msg.left_clear,
        right_clear_known: msg.right_clear_known,
        right_clear: msg.right_clear,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        meta: super::msg::SourceHeader::into_rmw_message(std::borrow::Cow::Borrowed(&msg.meta)).into_owned(),
        readings: msg.readings
          .iter()
          .map(|elem| super::msg::RangeReading::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      left_clear_known: msg.left_clear_known,
      left_clear: msg.left_clear,
      right_clear_known: msg.right_clear_known,
      right_clear: msg.right_clear,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      meta: super::msg::SourceHeader::from_rmw_message(msg.meta),
      readings: msg.readings
          .into_iter()
          .map(super::msg::RangeReading::from_rmw_message)
          .collect(),
      left_clear_known: msg.left_clear_known,
      left_clear: msg.left_clear,
      right_clear_known: msg.right_clear_known,
      right_clear: msg.right_clear,
    }
  }
}


// Corresponds to team4s_interfaces__msg__ConeDetection

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ConeDetection {
    /// Frame-local candidate ID, not a stable tracking identifier.
    pub candidate_id: std::string::String,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ConeDetection::default())
  }
}

impl rosidl_runtime_rs::Message for ConeDetection {
  type RmwMsg = super::msg::rmw::ConeDetection;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        candidate_id: msg.candidate_id.as_str().into(),
        color: msg.color,
        bbox_known: msg.bbox_known,
        bbox_xyxy: msg.bbox_xyxy,
        color_pixels: msg.color_pixels,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        candidate_id: msg.candidate_id.as_str().into(),
      color: msg.color,
      bbox_known: msg.bbox_known,
        bbox_xyxy: msg.bbox_xyxy,
      color_pixels: msg.color_pixels,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      candidate_id: msg.candidate_id.to_string(),
      color: msg.color,
      bbox_known: msg.bbox_known,
      bbox_xyxy: msg.bbox_xyxy,
      color_pixels: msg.color_pixels,
    }
  }
}


// Corresponds to team4s_interfaces__msg__SceneObservation

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SceneObservation {

    // This member is not documented.
    #[allow(missing_docs)]
    pub meta: super::msg::SourceHeader,


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
    pub cone_event_stamp: builtin_interfaces::msg::Time,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zebra_event_id: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zebra_event_stamp: builtin_interfaces::msg::Time,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zebra_event_confirmed: bool,

    /// v2 cone_* legacy fields above now refer ONLY to the green start cone.
    pub cones_valid: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cones_reason: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cones: Vec<super::msg::ConeDetection>,


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
    pub red_finish_event_stamp: builtin_interfaces::msg::Time,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::SceneObservation::default())
  }
}

impl rosidl_runtime_rs::Message for SceneObservation {
  type RmwMsg = super::msg::rmw::SceneObservation;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        meta: super::msg::SourceHeader::into_rmw_message(std::borrow::Cow::Owned(msg.meta)).into_owned(),
        cone_valid: msg.cone_valid,
        cone_state: msg.cone_state,
        cone_bbox_known: msg.cone_bbox_known,
        cone_bbox_xyxy: msg.cone_bbox_xyxy,
        zebra_valid: msg.zebra_valid,
        zebra_visible: msg.zebra_visible,
        zebra_bbox_known: msg.zebra_bbox_known,
        zebra_bbox_xyxy: msg.zebra_bbox_xyxy,
        image_width: msg.image_width,
        image_height: msg.image_height,
        cone_event_id: msg.cone_event_id,
        cone_event_stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.cone_event_stamp)).into_owned(),
        zebra_event_id: msg.zebra_event_id,
        zebra_event_stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.zebra_event_stamp)).into_owned(),
        zebra_event_confirmed: msg.zebra_event_confirmed,
        cones_valid: msg.cones_valid,
        cones_reason: msg.cones_reason.as_str().into(),
        cones: msg.cones
          .into_iter()
          .map(|elem| super::msg::ConeDetection::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        green_start_visible: msg.green_start_visible,
        red_finish_visible: msg.red_finish_visible,
        red_finish_confirmed: msg.red_finish_confirmed,
        red_finish_event_id: msg.red_finish_event_id,
        red_finish_event_stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.red_finish_event_stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        meta: super::msg::SourceHeader::into_rmw_message(std::borrow::Cow::Borrowed(&msg.meta)).into_owned(),
      cone_valid: msg.cone_valid,
      cone_state: msg.cone_state,
      cone_bbox_known: msg.cone_bbox_known,
        cone_bbox_xyxy: msg.cone_bbox_xyxy,
      zebra_valid: msg.zebra_valid,
      zebra_visible: msg.zebra_visible,
      zebra_bbox_known: msg.zebra_bbox_known,
        zebra_bbox_xyxy: msg.zebra_bbox_xyxy,
      image_width: msg.image_width,
      image_height: msg.image_height,
      cone_event_id: msg.cone_event_id,
        cone_event_stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.cone_event_stamp)).into_owned(),
      zebra_event_id: msg.zebra_event_id,
        zebra_event_stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.zebra_event_stamp)).into_owned(),
      zebra_event_confirmed: msg.zebra_event_confirmed,
      cones_valid: msg.cones_valid,
        cones_reason: msg.cones_reason.as_str().into(),
        cones: msg.cones
          .iter()
          .map(|elem| super::msg::ConeDetection::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      green_start_visible: msg.green_start_visible,
      red_finish_visible: msg.red_finish_visible,
      red_finish_confirmed: msg.red_finish_confirmed,
      red_finish_event_id: msg.red_finish_event_id,
        red_finish_event_stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.red_finish_event_stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      meta: super::msg::SourceHeader::from_rmw_message(msg.meta),
      cone_valid: msg.cone_valid,
      cone_state: msg.cone_state,
      cone_bbox_known: msg.cone_bbox_known,
      cone_bbox_xyxy: msg.cone_bbox_xyxy,
      zebra_valid: msg.zebra_valid,
      zebra_visible: msg.zebra_visible,
      zebra_bbox_known: msg.zebra_bbox_known,
      zebra_bbox_xyxy: msg.zebra_bbox_xyxy,
      image_width: msg.image_width,
      image_height: msg.image_height,
      cone_event_id: msg.cone_event_id,
      cone_event_stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.cone_event_stamp),
      zebra_event_id: msg.zebra_event_id,
      zebra_event_stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.zebra_event_stamp),
      zebra_event_confirmed: msg.zebra_event_confirmed,
      cones_valid: msg.cones_valid,
      cones_reason: msg.cones_reason.to_string(),
      cones: msg.cones
          .into_iter()
          .map(super::msg::ConeDetection::from_rmw_message)
          .collect(),
      green_start_visible: msg.green_start_visible,
      red_finish_visible: msg.red_finish_visible,
      red_finish_confirmed: msg.red_finish_confirmed,
      red_finish_event_id: msg.red_finish_event_id,
      red_finish_event_stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.red_finish_event_stamp),
    }
  }
}


// Corresponds to team4s_interfaces__msg__TopicHealth

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TopicHealth {

    // This member is not documented.
    #[allow(missing_docs)]
    pub state: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reason: std::string::String,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::TopicHealth::default())
  }
}

impl rosidl_runtime_rs::Message for TopicHealth {
  type RmwMsg = super::msg::rmw::TopicHealth;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        state: msg.state,
        reason: msg.reason.as_str().into(),
        age_known: msg.age_known,
        age_s: msg.age_s,
        max_age_s: msg.max_age_s,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      state: msg.state,
        reason: msg.reason.as_str().into(),
      age_known: msg.age_known,
      age_s: msg.age_s,
      max_age_s: msg.max_age_s,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      state: msg.state,
      reason: msg.reason.to_string(),
      age_known: msg.age_known,
      age_s: msg.age_s,
      max_age_s: msg.max_age_s,
    }
  }
}


// Corresponds to team4s_interfaces__msg__PerceptionSnapshot
/// Aggregate time, not the acquisition time of all children.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PerceptionSnapshot {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub aggregator_session_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub run_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub sequence: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub lane: super::msg::LaneObservation,


    // This member is not documented.
    #[allow(missing_docs)]
    pub lane_health: super::msg::TopicHealth,


    // This member is not documented.
    #[allow(missing_docs)]
    pub obstacles: super::msg::ObstacleObservation,


    // This member is not documented.
    #[allow(missing_docs)]
    pub obstacles_health: super::msg::TopicHealth,


    // This member is not documented.
    #[allow(missing_docs)]
    pub scene: super::msg::SceneObservation,


    // This member is not documented.
    #[allow(missing_docs)]
    pub scene_health: super::msg::TopicHealth,

}



impl Default for PerceptionSnapshot {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::PerceptionSnapshot::default())
  }
}

impl rosidl_runtime_rs::Message for PerceptionSnapshot {
  type RmwMsg = super::msg::rmw::PerceptionSnapshot;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        aggregator_session_id: msg.aggregator_session_id.as_str().into(),
        run_id: msg.run_id.as_str().into(),
        sequence: msg.sequence,
        lane: super::msg::LaneObservation::into_rmw_message(std::borrow::Cow::Owned(msg.lane)).into_owned(),
        lane_health: super::msg::TopicHealth::into_rmw_message(std::borrow::Cow::Owned(msg.lane_health)).into_owned(),
        obstacles: super::msg::ObstacleObservation::into_rmw_message(std::borrow::Cow::Owned(msg.obstacles)).into_owned(),
        obstacles_health: super::msg::TopicHealth::into_rmw_message(std::borrow::Cow::Owned(msg.obstacles_health)).into_owned(),
        scene: super::msg::SceneObservation::into_rmw_message(std::borrow::Cow::Owned(msg.scene)).into_owned(),
        scene_health: super::msg::TopicHealth::into_rmw_message(std::borrow::Cow::Owned(msg.scene_health)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        aggregator_session_id: msg.aggregator_session_id.as_str().into(),
        run_id: msg.run_id.as_str().into(),
      sequence: msg.sequence,
        lane: super::msg::LaneObservation::into_rmw_message(std::borrow::Cow::Borrowed(&msg.lane)).into_owned(),
        lane_health: super::msg::TopicHealth::into_rmw_message(std::borrow::Cow::Borrowed(&msg.lane_health)).into_owned(),
        obstacles: super::msg::ObstacleObservation::into_rmw_message(std::borrow::Cow::Borrowed(&msg.obstacles)).into_owned(),
        obstacles_health: super::msg::TopicHealth::into_rmw_message(std::borrow::Cow::Borrowed(&msg.obstacles_health)).into_owned(),
        scene: super::msg::SceneObservation::into_rmw_message(std::borrow::Cow::Borrowed(&msg.scene)).into_owned(),
        scene_health: super::msg::TopicHealth::into_rmw_message(std::borrow::Cow::Borrowed(&msg.scene_health)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      aggregator_session_id: msg.aggregator_session_id.to_string(),
      run_id: msg.run_id.to_string(),
      sequence: msg.sequence,
      lane: super::msg::LaneObservation::from_rmw_message(msg.lane),
      lane_health: super::msg::TopicHealth::from_rmw_message(msg.lane_health),
      obstacles: super::msg::ObstacleObservation::from_rmw_message(msg.obstacles),
      obstacles_health: super::msg::TopicHealth::from_rmw_message(msg.obstacles_health),
      scene: super::msg::SceneObservation::from_rmw_message(msg.scene),
      scene_health: super::msg::TopicHealth::from_rmw_message(msg.scene_health),
    }
  }
}


// Corresponds to team4s_interfaces__msg__TaskState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TaskState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub run_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub controller_session_id: std::string::String,


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
    pub reason: std::string::String,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::TaskState::default())
  }
}

impl rosidl_runtime_rs::Message for TaskState {
  type RmwMsg = super::msg::rmw::TaskState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        run_id: msg.run_id.as_str().into(),
        controller_session_id: msg.controller_session_id.as_str().into(),
        sequence: msg.sequence,
        task_id: msg.task_id,
        phase: msg.phase,
        target_lane: msg.target_lane,
        control_mode: msg.control_mode,
        lap_complete: msg.lap_complete,
        reason: msg.reason.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        run_id: msg.run_id.as_str().into(),
        controller_session_id: msg.controller_session_id.as_str().into(),
      sequence: msg.sequence,
      task_id: msg.task_id,
      phase: msg.phase,
      target_lane: msg.target_lane,
      control_mode: msg.control_mode,
      lap_complete: msg.lap_complete,
        reason: msg.reason.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      run_id: msg.run_id.to_string(),
      controller_session_id: msg.controller_session_id.to_string(),
      sequence: msg.sequence,
      task_id: msg.task_id,
      phase: msg.phase,
      target_lane: msg.target_lane,
      control_mode: msg.control_mode,
      lap_complete: msg.lap_complete,
      reason: msg.reason.to_string(),
    }
  }
}



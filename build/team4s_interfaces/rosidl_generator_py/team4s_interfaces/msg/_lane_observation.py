# generated from rosidl_generator_py/resource/_idl.py.em
# with input from team4s_interfaces:msg/LaneObservation.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_LaneObservation(type):
    """Metaclass of message 'LaneObservation'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('team4s_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'team4s_interfaces.msg.LaneObservation')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__lane_observation
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__lane_observation
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__lane_observation
            cls._TYPE_SUPPORT = module.type_support_msg__msg__lane_observation
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__lane_observation

            from team4s_interfaces.msg import LaneCandidate
            if LaneCandidate.__class__._TYPE_SUPPORT is None:
                LaneCandidate.__class__.__import_type_support__()

            from team4s_interfaces.msg import SourceHeader
            if SourceHeader.__class__._TYPE_SUPPORT is None:
                SourceHeader.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LaneObservation(metaclass=Metaclass_LaneObservation):
    """Message class 'LaneObservation'."""

    __slots__ = [
        '_meta',
        '_image_width',
        '_image_height',
        '_candidates',
        '_selected_candidate_id',
        '_offset_m_valid',
        '_offset_m',
        '_metric_reason',
        '_calibration_id',
        '_metric_frame_id',
        '_metric_reference_x_m',
        '_metric_reference_y_m',
    ]

    _fields_and_field_types = {
        'meta': 'team4s_interfaces/SourceHeader',
        'image_width': 'uint32',
        'image_height': 'uint32',
        'candidates': 'sequence<team4s_interfaces/LaneCandidate>',
        'selected_candidate_id': 'string',
        'offset_m_valid': 'boolean',
        'offset_m': 'float',
        'metric_reason': 'string',
        'calibration_id': 'string',
        'metric_frame_id': 'string',
        'metric_reference_x_m': 'float',
        'metric_reference_y_m': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['team4s_interfaces', 'msg'], 'SourceHeader'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['team4s_interfaces', 'msg'], 'LaneCandidate')),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from team4s_interfaces.msg import SourceHeader
        self.meta = kwargs.get('meta', SourceHeader())
        self.image_width = kwargs.get('image_width', int())
        self.image_height = kwargs.get('image_height', int())
        self.candidates = kwargs.get('candidates', [])
        self.selected_candidate_id = kwargs.get('selected_candidate_id', str())
        self.offset_m_valid = kwargs.get('offset_m_valid', bool())
        self.offset_m = kwargs.get('offset_m', float())
        self.metric_reason = kwargs.get('metric_reason', str())
        self.calibration_id = kwargs.get('calibration_id', str())
        self.metric_frame_id = kwargs.get('metric_frame_id', str())
        self.metric_reference_x_m = kwargs.get('metric_reference_x_m', float())
        self.metric_reference_y_m = kwargs.get('metric_reference_y_m', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.meta != other.meta:
            return False
        if self.image_width != other.image_width:
            return False
        if self.image_height != other.image_height:
            return False
        if self.candidates != other.candidates:
            return False
        if self.selected_candidate_id != other.selected_candidate_id:
            return False
        if self.offset_m_valid != other.offset_m_valid:
            return False
        if self.offset_m != other.offset_m:
            return False
        if self.metric_reason != other.metric_reason:
            return False
        if self.calibration_id != other.calibration_id:
            return False
        if self.metric_frame_id != other.metric_frame_id:
            return False
        if self.metric_reference_x_m != other.metric_reference_x_m:
            return False
        if self.metric_reference_y_m != other.metric_reference_y_m:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def meta(self):
        """Message field 'meta'."""
        return self._meta

    @meta.setter
    def meta(self, value):
        if __debug__:
            from team4s_interfaces.msg import SourceHeader
            assert \
                isinstance(value, SourceHeader), \
                "The 'meta' field must be a sub message of type 'SourceHeader'"
        self._meta = value

    @builtins.property
    def image_width(self):
        """Message field 'image_width'."""
        return self._image_width

    @image_width.setter
    def image_width(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'image_width' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'image_width' field must be an unsigned integer in [0, 4294967295]"
        self._image_width = value

    @builtins.property
    def image_height(self):
        """Message field 'image_height'."""
        return self._image_height

    @image_height.setter
    def image_height(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'image_height' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'image_height' field must be an unsigned integer in [0, 4294967295]"
        self._image_height = value

    @builtins.property
    def candidates(self):
        """Message field 'candidates'."""
        return self._candidates

    @candidates.setter
    def candidates(self, value):
        if __debug__:
            from team4s_interfaces.msg import LaneCandidate
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, LaneCandidate) for v in value) and
                 True), \
                "The 'candidates' field must be a set or sequence and each value of type 'LaneCandidate'"
        self._candidates = value

    @builtins.property
    def selected_candidate_id(self):
        """Message field 'selected_candidate_id'."""
        return self._selected_candidate_id

    @selected_candidate_id.setter
    def selected_candidate_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'selected_candidate_id' field must be of type 'str'"
        self._selected_candidate_id = value

    @builtins.property
    def offset_m_valid(self):
        """Message field 'offset_m_valid'."""
        return self._offset_m_valid

    @offset_m_valid.setter
    def offset_m_valid(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'offset_m_valid' field must be of type 'bool'"
        self._offset_m_valid = value

    @builtins.property
    def offset_m(self):
        """Message field 'offset_m'."""
        return self._offset_m

    @offset_m.setter
    def offset_m(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'offset_m' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'offset_m' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._offset_m = value

    @builtins.property
    def metric_reason(self):
        """Message field 'metric_reason'."""
        return self._metric_reason

    @metric_reason.setter
    def metric_reason(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'metric_reason' field must be of type 'str'"
        self._metric_reason = value

    @builtins.property
    def calibration_id(self):
        """Message field 'calibration_id'."""
        return self._calibration_id

    @calibration_id.setter
    def calibration_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'calibration_id' field must be of type 'str'"
        self._calibration_id = value

    @builtins.property
    def metric_frame_id(self):
        """Message field 'metric_frame_id'."""
        return self._metric_frame_id

    @metric_frame_id.setter
    def metric_frame_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'metric_frame_id' field must be of type 'str'"
        self._metric_frame_id = value

    @builtins.property
    def metric_reference_x_m(self):
        """Message field 'metric_reference_x_m'."""
        return self._metric_reference_x_m

    @metric_reference_x_m.setter
    def metric_reference_x_m(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'metric_reference_x_m' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'metric_reference_x_m' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._metric_reference_x_m = value

    @builtins.property
    def metric_reference_y_m(self):
        """Message field 'metric_reference_y_m'."""
        return self._metric_reference_y_m

    @metric_reference_y_m.setter
    def metric_reference_y_m(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'metric_reference_y_m' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'metric_reference_y_m' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._metric_reference_y_m = value

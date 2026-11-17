# generated from rosidl_generator_py/resource/_idl.py.em
# with input from team4s_interfaces:msg/LaneCandidate.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_LaneCandidate(type):
    """Metaclass of message 'LaneCandidate'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'UNKNOWN': 0,
        'FIRST': 1,
        'SECOND': 2,
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
                'team4s_interfaces.msg.LaneCandidate')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__lane_candidate
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__lane_candidate
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__lane_candidate
            cls._TYPE_SUPPORT = module.type_support_msg__msg__lane_candidate
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__lane_candidate

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'UNKNOWN': cls.__constants['UNKNOWN'],
            'FIRST': cls.__constants['FIRST'],
            'SECOND': cls.__constants['SECOND'],
        }

    @property
    def UNKNOWN(self):
        """Message constant 'UNKNOWN'."""
        return Metaclass_LaneCandidate.__constants['UNKNOWN']

    @property
    def FIRST(self):
        """Message constant 'FIRST'."""
        return Metaclass_LaneCandidate.__constants['FIRST']

    @property
    def SECOND(self):
        """Message constant 'SECOND'."""
        return Metaclass_LaneCandidate.__constants['SECOND']


class LaneCandidate(metaclass=Metaclass_LaneCandidate):
    """
    Message class 'LaneCandidate'.

    Constants:
      UNKNOWN
      FIRST
      SECOND
    """

    __slots__ = [
        '_candidate_id',
        '_route_lane',
        '_is_branch',
        '_left_visible',
        '_right_visible',
        '_center_valid',
        '_offset_px',
        '_reference_y_px',
        '_heading_valid',
        '_heading_rad',
    ]

    _fields_and_field_types = {
        'candidate_id': 'string',
        'route_lane': 'uint8',
        'is_branch': 'boolean',
        'left_visible': 'boolean',
        'right_visible': 'boolean',
        'center_valid': 'boolean',
        'offset_px': 'float',
        'reference_y_px': 'int32',
        'heading_valid': 'boolean',
        'heading_rad': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.candidate_id = kwargs.get('candidate_id', str())
        self.route_lane = kwargs.get('route_lane', int())
        self.is_branch = kwargs.get('is_branch', bool())
        self.left_visible = kwargs.get('left_visible', bool())
        self.right_visible = kwargs.get('right_visible', bool())
        self.center_valid = kwargs.get('center_valid', bool())
        self.offset_px = kwargs.get('offset_px', float())
        self.reference_y_px = kwargs.get('reference_y_px', int())
        self.heading_valid = kwargs.get('heading_valid', bool())
        self.heading_rad = kwargs.get('heading_rad', float())

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
        if self.candidate_id != other.candidate_id:
            return False
        if self.route_lane != other.route_lane:
            return False
        if self.is_branch != other.is_branch:
            return False
        if self.left_visible != other.left_visible:
            return False
        if self.right_visible != other.right_visible:
            return False
        if self.center_valid != other.center_valid:
            return False
        if self.offset_px != other.offset_px:
            return False
        if self.reference_y_px != other.reference_y_px:
            return False
        if self.heading_valid != other.heading_valid:
            return False
        if self.heading_rad != other.heading_rad:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def candidate_id(self):
        """Message field 'candidate_id'."""
        return self._candidate_id

    @candidate_id.setter
    def candidate_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'candidate_id' field must be of type 'str'"
        self._candidate_id = value

    @builtins.property
    def route_lane(self):
        """Message field 'route_lane'."""
        return self._route_lane

    @route_lane.setter
    def route_lane(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'route_lane' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'route_lane' field must be an unsigned integer in [0, 255]"
        self._route_lane = value

    @builtins.property
    def is_branch(self):
        """Message field 'is_branch'."""
        return self._is_branch

    @is_branch.setter
    def is_branch(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_branch' field must be of type 'bool'"
        self._is_branch = value

    @builtins.property
    def left_visible(self):
        """Message field 'left_visible'."""
        return self._left_visible

    @left_visible.setter
    def left_visible(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'left_visible' field must be of type 'bool'"
        self._left_visible = value

    @builtins.property
    def right_visible(self):
        """Message field 'right_visible'."""
        return self._right_visible

    @right_visible.setter
    def right_visible(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'right_visible' field must be of type 'bool'"
        self._right_visible = value

    @builtins.property
    def center_valid(self):
        """Message field 'center_valid'."""
        return self._center_valid

    @center_valid.setter
    def center_valid(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'center_valid' field must be of type 'bool'"
        self._center_valid = value

    @builtins.property
    def offset_px(self):
        """Message field 'offset_px'."""
        return self._offset_px

    @offset_px.setter
    def offset_px(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'offset_px' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'offset_px' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._offset_px = value

    @builtins.property
    def reference_y_px(self):
        """Message field 'reference_y_px'."""
        return self._reference_y_px

    @reference_y_px.setter
    def reference_y_px(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'reference_y_px' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'reference_y_px' field must be an integer in [-2147483648, 2147483647]"
        self._reference_y_px = value

    @builtins.property
    def heading_valid(self):
        """Message field 'heading_valid'."""
        return self._heading_valid

    @heading_valid.setter
    def heading_valid(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'heading_valid' field must be of type 'bool'"
        self._heading_valid = value

    @builtins.property
    def heading_rad(self):
        """Message field 'heading_rad'."""
        return self._heading_rad

    @heading_rad.setter
    def heading_rad(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'heading_rad' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'heading_rad' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._heading_rad = value

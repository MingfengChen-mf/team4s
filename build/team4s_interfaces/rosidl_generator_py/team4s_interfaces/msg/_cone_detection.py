# generated from rosidl_generator_py/resource/_idl.py.em
# with input from team4s_interfaces:msg/ConeDetection.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'bbox_xyxy'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ConeDetection(type):
    """Metaclass of message 'ConeDetection'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'COLOR_UNKNOWN': 0,
        'COLOR_GREEN': 1,
        'COLOR_RED': 2,
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
                'team4s_interfaces.msg.ConeDetection')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cone_detection
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cone_detection
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cone_detection
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cone_detection
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cone_detection

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'COLOR_UNKNOWN': cls.__constants['COLOR_UNKNOWN'],
            'COLOR_GREEN': cls.__constants['COLOR_GREEN'],
            'COLOR_RED': cls.__constants['COLOR_RED'],
        }

    @property
    def COLOR_UNKNOWN(self):
        """Message constant 'COLOR_UNKNOWN'."""
        return Metaclass_ConeDetection.__constants['COLOR_UNKNOWN']

    @property
    def COLOR_GREEN(self):
        """Message constant 'COLOR_GREEN'."""
        return Metaclass_ConeDetection.__constants['COLOR_GREEN']

    @property
    def COLOR_RED(self):
        """Message constant 'COLOR_RED'."""
        return Metaclass_ConeDetection.__constants['COLOR_RED']


class ConeDetection(metaclass=Metaclass_ConeDetection):
    """
    Message class 'ConeDetection'.

    Constants:
      COLOR_UNKNOWN
      COLOR_GREEN
      COLOR_RED
    """

    __slots__ = [
        '_candidate_id',
        '_color',
        '_bbox_known',
        '_bbox_xyxy',
        '_color_pixels',
    ]

    _fields_and_field_types = {
        'candidate_id': 'string',
        'color': 'uint8',
        'bbox_known': 'boolean',
        'bbox_xyxy': 'int32[4]',
        'color_pixels': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('int32'), 4),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.candidate_id = kwargs.get('candidate_id', str())
        self.color = kwargs.get('color', int())
        self.bbox_known = kwargs.get('bbox_known', bool())
        if 'bbox_xyxy' not in kwargs:
            self.bbox_xyxy = numpy.zeros(4, dtype=numpy.int32)
        else:
            self.bbox_xyxy = kwargs.get('bbox_xyxy')
        self.color_pixels = kwargs.get('color_pixels', int())

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
        if self.color != other.color:
            return False
        if self.bbox_known != other.bbox_known:
            return False
        if any(self.bbox_xyxy != other.bbox_xyxy):
            return False
        if self.color_pixels != other.color_pixels:
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
    def color(self):
        """Message field 'color'."""
        return self._color

    @color.setter
    def color(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'color' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'color' field must be an unsigned integer in [0, 255]"
        self._color = value

    @builtins.property
    def bbox_known(self):
        """Message field 'bbox_known'."""
        return self._bbox_known

    @bbox_known.setter
    def bbox_known(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'bbox_known' field must be of type 'bool'"
        self._bbox_known = value

    @builtins.property
    def bbox_xyxy(self):
        """Message field 'bbox_xyxy'."""
        return self._bbox_xyxy

    @bbox_xyxy.setter
    def bbox_xyxy(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.int32, \
                "The 'bbox_xyxy' numpy.ndarray() must have the dtype of 'numpy.int32'"
            assert value.size == 4, \
                "The 'bbox_xyxy' numpy.ndarray() must have a size of 4"
            self._bbox_xyxy = value
            return
        if __debug__:
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
                 len(value) == 4 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'bbox_xyxy' field must be a set or sequence with length 4 and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._bbox_xyxy = numpy.array(value, dtype=numpy.int32)

    @builtins.property
    def color_pixels(self):
        """Message field 'color_pixels'."""
        return self._color_pixels

    @color_pixels.setter
    def color_pixels(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'color_pixels' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'color_pixels' field must be an unsigned integer in [0, 4294967295]"
        self._color_pixels = value

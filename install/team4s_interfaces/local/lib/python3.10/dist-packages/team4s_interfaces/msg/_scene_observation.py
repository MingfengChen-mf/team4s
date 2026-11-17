# generated from rosidl_generator_py/resource/_idl.py.em
# with input from team4s_interfaces:msg/SceneObservation.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'cone_bbox_xyxy'
# Member 'zebra_bbox_xyxy'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SceneObservation(type):
    """Metaclass of message 'SceneObservation'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CONE_UNKNOWN': 0,
        'CONE_PRESENT': 1,
        'CONE_LEAVING': 2,
        'CONE_REMOVED': 3,
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
                'team4s_interfaces.msg.SceneObservation')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__scene_observation
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__scene_observation
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__scene_observation
            cls._TYPE_SUPPORT = module.type_support_msg__msg__scene_observation
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__scene_observation

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

            from team4s_interfaces.msg import ConeDetection
            if ConeDetection.__class__._TYPE_SUPPORT is None:
                ConeDetection.__class__.__import_type_support__()

            from team4s_interfaces.msg import SourceHeader
            if SourceHeader.__class__._TYPE_SUPPORT is None:
                SourceHeader.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CONE_UNKNOWN': cls.__constants['CONE_UNKNOWN'],
            'CONE_PRESENT': cls.__constants['CONE_PRESENT'],
            'CONE_LEAVING': cls.__constants['CONE_LEAVING'],
            'CONE_REMOVED': cls.__constants['CONE_REMOVED'],
        }

    @property
    def CONE_UNKNOWN(self):
        """Message constant 'CONE_UNKNOWN'."""
        return Metaclass_SceneObservation.__constants['CONE_UNKNOWN']

    @property
    def CONE_PRESENT(self):
        """Message constant 'CONE_PRESENT'."""
        return Metaclass_SceneObservation.__constants['CONE_PRESENT']

    @property
    def CONE_LEAVING(self):
        """Message constant 'CONE_LEAVING'."""
        return Metaclass_SceneObservation.__constants['CONE_LEAVING']

    @property
    def CONE_REMOVED(self):
        """Message constant 'CONE_REMOVED'."""
        return Metaclass_SceneObservation.__constants['CONE_REMOVED']


class SceneObservation(metaclass=Metaclass_SceneObservation):
    """
    Message class 'SceneObservation'.

    Constants:
      CONE_UNKNOWN
      CONE_PRESENT
      CONE_LEAVING
      CONE_REMOVED
    """

    __slots__ = [
        '_meta',
        '_cone_valid',
        '_cone_state',
        '_cone_bbox_known',
        '_cone_bbox_xyxy',
        '_zebra_valid',
        '_zebra_visible',
        '_zebra_bbox_known',
        '_zebra_bbox_xyxy',
        '_image_width',
        '_image_height',
        '_cone_event_id',
        '_cone_event_stamp',
        '_zebra_event_id',
        '_zebra_event_stamp',
        '_zebra_event_confirmed',
        '_cones_valid',
        '_cones_reason',
        '_cones',
        '_green_start_visible',
        '_red_finish_visible',
        '_red_finish_confirmed',
        '_red_finish_event_id',
        '_red_finish_event_stamp',
    ]

    _fields_and_field_types = {
        'meta': 'team4s_interfaces/SourceHeader',
        'cone_valid': 'boolean',
        'cone_state': 'uint8',
        'cone_bbox_known': 'boolean',
        'cone_bbox_xyxy': 'int32[4]',
        'zebra_valid': 'boolean',
        'zebra_visible': 'boolean',
        'zebra_bbox_known': 'boolean',
        'zebra_bbox_xyxy': 'int32[4]',
        'image_width': 'uint32',
        'image_height': 'uint32',
        'cone_event_id': 'uint64',
        'cone_event_stamp': 'builtin_interfaces/Time',
        'zebra_event_id': 'uint64',
        'zebra_event_stamp': 'builtin_interfaces/Time',
        'zebra_event_confirmed': 'boolean',
        'cones_valid': 'boolean',
        'cones_reason': 'string',
        'cones': 'sequence<team4s_interfaces/ConeDetection>',
        'green_start_visible': 'boolean',
        'red_finish_visible': 'boolean',
        'red_finish_confirmed': 'boolean',
        'red_finish_event_id': 'uint64',
        'red_finish_event_stamp': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['team4s_interfaces', 'msg'], 'SourceHeader'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('int32'), 4),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('int32'), 4),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['team4s_interfaces', 'msg'], 'ConeDetection')),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from team4s_interfaces.msg import SourceHeader
        self.meta = kwargs.get('meta', SourceHeader())
        self.cone_valid = kwargs.get('cone_valid', bool())
        self.cone_state = kwargs.get('cone_state', int())
        self.cone_bbox_known = kwargs.get('cone_bbox_known', bool())
        if 'cone_bbox_xyxy' not in kwargs:
            self.cone_bbox_xyxy = numpy.zeros(4, dtype=numpy.int32)
        else:
            self.cone_bbox_xyxy = kwargs.get('cone_bbox_xyxy')
        self.zebra_valid = kwargs.get('zebra_valid', bool())
        self.zebra_visible = kwargs.get('zebra_visible', bool())
        self.zebra_bbox_known = kwargs.get('zebra_bbox_known', bool())
        if 'zebra_bbox_xyxy' not in kwargs:
            self.zebra_bbox_xyxy = numpy.zeros(4, dtype=numpy.int32)
        else:
            self.zebra_bbox_xyxy = kwargs.get('zebra_bbox_xyxy')
        self.image_width = kwargs.get('image_width', int())
        self.image_height = kwargs.get('image_height', int())
        self.cone_event_id = kwargs.get('cone_event_id', int())
        from builtin_interfaces.msg import Time
        self.cone_event_stamp = kwargs.get('cone_event_stamp', Time())
        self.zebra_event_id = kwargs.get('zebra_event_id', int())
        from builtin_interfaces.msg import Time
        self.zebra_event_stamp = kwargs.get('zebra_event_stamp', Time())
        self.zebra_event_confirmed = kwargs.get('zebra_event_confirmed', bool())
        self.cones_valid = kwargs.get('cones_valid', bool())
        self.cones_reason = kwargs.get('cones_reason', str())
        self.cones = kwargs.get('cones', [])
        self.green_start_visible = kwargs.get('green_start_visible', bool())
        self.red_finish_visible = kwargs.get('red_finish_visible', bool())
        self.red_finish_confirmed = kwargs.get('red_finish_confirmed', bool())
        self.red_finish_event_id = kwargs.get('red_finish_event_id', int())
        from builtin_interfaces.msg import Time
        self.red_finish_event_stamp = kwargs.get('red_finish_event_stamp', Time())

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
        if self.cone_valid != other.cone_valid:
            return False
        if self.cone_state != other.cone_state:
            return False
        if self.cone_bbox_known != other.cone_bbox_known:
            return False
        if any(self.cone_bbox_xyxy != other.cone_bbox_xyxy):
            return False
        if self.zebra_valid != other.zebra_valid:
            return False
        if self.zebra_visible != other.zebra_visible:
            return False
        if self.zebra_bbox_known != other.zebra_bbox_known:
            return False
        if any(self.zebra_bbox_xyxy != other.zebra_bbox_xyxy):
            return False
        if self.image_width != other.image_width:
            return False
        if self.image_height != other.image_height:
            return False
        if self.cone_event_id != other.cone_event_id:
            return False
        if self.cone_event_stamp != other.cone_event_stamp:
            return False
        if self.zebra_event_id != other.zebra_event_id:
            return False
        if self.zebra_event_stamp != other.zebra_event_stamp:
            return False
        if self.zebra_event_confirmed != other.zebra_event_confirmed:
            return False
        if self.cones_valid != other.cones_valid:
            return False
        if self.cones_reason != other.cones_reason:
            return False
        if self.cones != other.cones:
            return False
        if self.green_start_visible != other.green_start_visible:
            return False
        if self.red_finish_visible != other.red_finish_visible:
            return False
        if self.red_finish_confirmed != other.red_finish_confirmed:
            return False
        if self.red_finish_event_id != other.red_finish_event_id:
            return False
        if self.red_finish_event_stamp != other.red_finish_event_stamp:
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
    def cone_valid(self):
        """Message field 'cone_valid'."""
        return self._cone_valid

    @cone_valid.setter
    def cone_valid(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'cone_valid' field must be of type 'bool'"
        self._cone_valid = value

    @builtins.property
    def cone_state(self):
        """Message field 'cone_state'."""
        return self._cone_state

    @cone_state.setter
    def cone_state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cone_state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'cone_state' field must be an unsigned integer in [0, 255]"
        self._cone_state = value

    @builtins.property
    def cone_bbox_known(self):
        """Message field 'cone_bbox_known'."""
        return self._cone_bbox_known

    @cone_bbox_known.setter
    def cone_bbox_known(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'cone_bbox_known' field must be of type 'bool'"
        self._cone_bbox_known = value

    @builtins.property
    def cone_bbox_xyxy(self):
        """Message field 'cone_bbox_xyxy'."""
        return self._cone_bbox_xyxy

    @cone_bbox_xyxy.setter
    def cone_bbox_xyxy(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.int32, \
                "The 'cone_bbox_xyxy' numpy.ndarray() must have the dtype of 'numpy.int32'"
            assert value.size == 4, \
                "The 'cone_bbox_xyxy' numpy.ndarray() must have a size of 4"
            self._cone_bbox_xyxy = value
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
                "The 'cone_bbox_xyxy' field must be a set or sequence with length 4 and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._cone_bbox_xyxy = numpy.array(value, dtype=numpy.int32)

    @builtins.property
    def zebra_valid(self):
        """Message field 'zebra_valid'."""
        return self._zebra_valid

    @zebra_valid.setter
    def zebra_valid(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'zebra_valid' field must be of type 'bool'"
        self._zebra_valid = value

    @builtins.property
    def zebra_visible(self):
        """Message field 'zebra_visible'."""
        return self._zebra_visible

    @zebra_visible.setter
    def zebra_visible(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'zebra_visible' field must be of type 'bool'"
        self._zebra_visible = value

    @builtins.property
    def zebra_bbox_known(self):
        """Message field 'zebra_bbox_known'."""
        return self._zebra_bbox_known

    @zebra_bbox_known.setter
    def zebra_bbox_known(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'zebra_bbox_known' field must be of type 'bool'"
        self._zebra_bbox_known = value

    @builtins.property
    def zebra_bbox_xyxy(self):
        """Message field 'zebra_bbox_xyxy'."""
        return self._zebra_bbox_xyxy

    @zebra_bbox_xyxy.setter
    def zebra_bbox_xyxy(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.int32, \
                "The 'zebra_bbox_xyxy' numpy.ndarray() must have the dtype of 'numpy.int32'"
            assert value.size == 4, \
                "The 'zebra_bbox_xyxy' numpy.ndarray() must have a size of 4"
            self._zebra_bbox_xyxy = value
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
                "The 'zebra_bbox_xyxy' field must be a set or sequence with length 4 and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._zebra_bbox_xyxy = numpy.array(value, dtype=numpy.int32)

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
    def cone_event_id(self):
        """Message field 'cone_event_id'."""
        return self._cone_event_id

    @cone_event_id.setter
    def cone_event_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cone_event_id' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'cone_event_id' field must be an unsigned integer in [0, 18446744073709551615]"
        self._cone_event_id = value

    @builtins.property
    def cone_event_stamp(self):
        """Message field 'cone_event_stamp'."""
        return self._cone_event_stamp

    @cone_event_stamp.setter
    def cone_event_stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'cone_event_stamp' field must be a sub message of type 'Time'"
        self._cone_event_stamp = value

    @builtins.property
    def zebra_event_id(self):
        """Message field 'zebra_event_id'."""
        return self._zebra_event_id

    @zebra_event_id.setter
    def zebra_event_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'zebra_event_id' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'zebra_event_id' field must be an unsigned integer in [0, 18446744073709551615]"
        self._zebra_event_id = value

    @builtins.property
    def zebra_event_stamp(self):
        """Message field 'zebra_event_stamp'."""
        return self._zebra_event_stamp

    @zebra_event_stamp.setter
    def zebra_event_stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'zebra_event_stamp' field must be a sub message of type 'Time'"
        self._zebra_event_stamp = value

    @builtins.property
    def zebra_event_confirmed(self):
        """Message field 'zebra_event_confirmed'."""
        return self._zebra_event_confirmed

    @zebra_event_confirmed.setter
    def zebra_event_confirmed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'zebra_event_confirmed' field must be of type 'bool'"
        self._zebra_event_confirmed = value

    @builtins.property
    def cones_valid(self):
        """Message field 'cones_valid'."""
        return self._cones_valid

    @cones_valid.setter
    def cones_valid(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'cones_valid' field must be of type 'bool'"
        self._cones_valid = value

    @builtins.property
    def cones_reason(self):
        """Message field 'cones_reason'."""
        return self._cones_reason

    @cones_reason.setter
    def cones_reason(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'cones_reason' field must be of type 'str'"
        self._cones_reason = value

    @builtins.property
    def cones(self):
        """Message field 'cones'."""
        return self._cones

    @cones.setter
    def cones(self, value):
        if __debug__:
            from team4s_interfaces.msg import ConeDetection
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
                 all(isinstance(v, ConeDetection) for v in value) and
                 True), \
                "The 'cones' field must be a set or sequence and each value of type 'ConeDetection'"
        self._cones = value

    @builtins.property
    def green_start_visible(self):
        """Message field 'green_start_visible'."""
        return self._green_start_visible

    @green_start_visible.setter
    def green_start_visible(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'green_start_visible' field must be of type 'bool'"
        self._green_start_visible = value

    @builtins.property
    def red_finish_visible(self):
        """Message field 'red_finish_visible'."""
        return self._red_finish_visible

    @red_finish_visible.setter
    def red_finish_visible(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'red_finish_visible' field must be of type 'bool'"
        self._red_finish_visible = value

    @builtins.property
    def red_finish_confirmed(self):
        """Message field 'red_finish_confirmed'."""
        return self._red_finish_confirmed

    @red_finish_confirmed.setter
    def red_finish_confirmed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'red_finish_confirmed' field must be of type 'bool'"
        self._red_finish_confirmed = value

    @builtins.property
    def red_finish_event_id(self):
        """Message field 'red_finish_event_id'."""
        return self._red_finish_event_id

    @red_finish_event_id.setter
    def red_finish_event_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'red_finish_event_id' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'red_finish_event_id' field must be an unsigned integer in [0, 18446744073709551615]"
        self._red_finish_event_id = value

    @builtins.property
    def red_finish_event_stamp(self):
        """Message field 'red_finish_event_stamp'."""
        return self._red_finish_event_stamp

    @red_finish_event_stamp.setter
    def red_finish_event_stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'red_finish_event_stamp' field must be a sub message of type 'Time'"
        self._red_finish_event_stamp = value

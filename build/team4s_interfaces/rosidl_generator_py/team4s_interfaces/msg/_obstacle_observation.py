# generated from rosidl_generator_py/resource/_idl.py.em
# with input from team4s_interfaces:msg/ObstacleObservation.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ObstacleObservation(type):
    """Metaclass of message 'ObstacleObservation'."""

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
                'team4s_interfaces.msg.ObstacleObservation')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__obstacle_observation
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__obstacle_observation
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__obstacle_observation
            cls._TYPE_SUPPORT = module.type_support_msg__msg__obstacle_observation
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__obstacle_observation

            from team4s_interfaces.msg import RangeReading
            if RangeReading.__class__._TYPE_SUPPORT is None:
                RangeReading.__class__.__import_type_support__()

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


class ObstacleObservation(metaclass=Metaclass_ObstacleObservation):
    """Message class 'ObstacleObservation'."""

    __slots__ = [
        '_meta',
        '_readings',
        '_left_clear_known',
        '_left_clear',
        '_right_clear_known',
        '_right_clear',
    ]

    _fields_and_field_types = {
        'meta': 'team4s_interfaces/SourceHeader',
        'readings': 'sequence<team4s_interfaces/RangeReading>',
        'left_clear_known': 'boolean',
        'left_clear': 'boolean',
        'right_clear_known': 'boolean',
        'right_clear': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['team4s_interfaces', 'msg'], 'SourceHeader'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['team4s_interfaces', 'msg'], 'RangeReading')),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from team4s_interfaces.msg import SourceHeader
        self.meta = kwargs.get('meta', SourceHeader())
        self.readings = kwargs.get('readings', [])
        self.left_clear_known = kwargs.get('left_clear_known', bool())
        self.left_clear = kwargs.get('left_clear', bool())
        self.right_clear_known = kwargs.get('right_clear_known', bool())
        self.right_clear = kwargs.get('right_clear', bool())

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
        if self.readings != other.readings:
            return False
        if self.left_clear_known != other.left_clear_known:
            return False
        if self.left_clear != other.left_clear:
            return False
        if self.right_clear_known != other.right_clear_known:
            return False
        if self.right_clear != other.right_clear:
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
    def readings(self):
        """Message field 'readings'."""
        return self._readings

    @readings.setter
    def readings(self, value):
        if __debug__:
            from team4s_interfaces.msg import RangeReading
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
                 all(isinstance(v, RangeReading) for v in value) and
                 True), \
                "The 'readings' field must be a set or sequence and each value of type 'RangeReading'"
        self._readings = value

    @builtins.property
    def left_clear_known(self):
        """Message field 'left_clear_known'."""
        return self._left_clear_known

    @left_clear_known.setter
    def left_clear_known(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'left_clear_known' field must be of type 'bool'"
        self._left_clear_known = value

    @builtins.property
    def left_clear(self):
        """Message field 'left_clear'."""
        return self._left_clear

    @left_clear.setter
    def left_clear(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'left_clear' field must be of type 'bool'"
        self._left_clear = value

    @builtins.property
    def right_clear_known(self):
        """Message field 'right_clear_known'."""
        return self._right_clear_known

    @right_clear_known.setter
    def right_clear_known(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'right_clear_known' field must be of type 'bool'"
        self._right_clear_known = value

    @builtins.property
    def right_clear(self):
        """Message field 'right_clear'."""
        return self._right_clear

    @right_clear.setter
    def right_clear(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'right_clear' field must be of type 'bool'"
        self._right_clear = value

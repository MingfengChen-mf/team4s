# generated from rosidl_generator_py/resource/_idl.py.em
# with input from team4s_interfaces:msg/TopicHealth.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TopicHealth(type):
    """Metaclass of message 'TopicHealth'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'MISSING': 0,
        'VALID': 1,
        'INVALID': 2,
        'STALE': 3,
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
                'team4s_interfaces.msg.TopicHealth')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__topic_health
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__topic_health
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__topic_health
            cls._TYPE_SUPPORT = module.type_support_msg__msg__topic_health
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__topic_health

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'MISSING': cls.__constants['MISSING'],
            'VALID': cls.__constants['VALID'],
            'INVALID': cls.__constants['INVALID'],
            'STALE': cls.__constants['STALE'],
        }

    @property
    def MISSING(self):
        """Message constant 'MISSING'."""
        return Metaclass_TopicHealth.__constants['MISSING']

    @property
    def VALID(self):
        """Message constant 'VALID'."""
        return Metaclass_TopicHealth.__constants['VALID']

    @property
    def INVALID(self):
        """Message constant 'INVALID'."""
        return Metaclass_TopicHealth.__constants['INVALID']

    @property
    def STALE(self):
        """Message constant 'STALE'."""
        return Metaclass_TopicHealth.__constants['STALE']


class TopicHealth(metaclass=Metaclass_TopicHealth):
    """
    Message class 'TopicHealth'.

    Constants:
      MISSING
      VALID
      INVALID
      STALE
    """

    __slots__ = [
        '_state',
        '_reason',
        '_age_known',
        '_age_s',
        '_max_age_s',
    ]

    _fields_and_field_types = {
        'state': 'uint8',
        'reason': 'string',
        'age_known': 'boolean',
        'age_s': 'float',
        'max_age_s': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.state = kwargs.get('state', int())
        self.reason = kwargs.get('reason', str())
        self.age_known = kwargs.get('age_known', bool())
        self.age_s = kwargs.get('age_s', float())
        self.max_age_s = kwargs.get('max_age_s', float())

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
        if self.state != other.state:
            return False
        if self.reason != other.reason:
            return False
        if self.age_known != other.age_known:
            return False
        if self.age_s != other.age_s:
            return False
        if self.max_age_s != other.max_age_s:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def state(self):
        """Message field 'state'."""
        return self._state

    @state.setter
    def state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'state' field must be an unsigned integer in [0, 255]"
        self._state = value

    @builtins.property
    def reason(self):
        """Message field 'reason'."""
        return self._reason

    @reason.setter
    def reason(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'reason' field must be of type 'str'"
        self._reason = value

    @builtins.property
    def age_known(self):
        """Message field 'age_known'."""
        return self._age_known

    @age_known.setter
    def age_known(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'age_known' field must be of type 'bool'"
        self._age_known = value

    @builtins.property
    def age_s(self):
        """Message field 'age_s'."""
        return self._age_s

    @age_s.setter
    def age_s(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'age_s' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'age_s' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._age_s = value

    @builtins.property
    def max_age_s(self):
        """Message field 'max_age_s'."""
        return self._max_age_s

    @max_age_s.setter
    def max_age_s(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_age_s' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'max_age_s' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._max_age_s = value

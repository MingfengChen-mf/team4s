# generated from rosidl_generator_py/resource/_idl.py.em
# with input from team4s_interfaces:msg/SourceHeader.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SourceHeader(type):
    """Metaclass of message 'SourceHeader'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'STAMP_UNKNOWN': 0,
        'STAMP_READ_START': 1,
        'STAMP_HARDWARE_SYNCED': 2,
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
                'team4s_interfaces.msg.SourceHeader')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__source_header
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__source_header
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__source_header
            cls._TYPE_SUPPORT = module.type_support_msg__msg__source_header
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__source_header

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'STAMP_UNKNOWN': cls.__constants['STAMP_UNKNOWN'],
            'STAMP_READ_START': cls.__constants['STAMP_READ_START'],
            'STAMP_HARDWARE_SYNCED': cls.__constants['STAMP_HARDWARE_SYNCED'],
        }

    @property
    def STAMP_UNKNOWN(self):
        """Message constant 'STAMP_UNKNOWN'."""
        return Metaclass_SourceHeader.__constants['STAMP_UNKNOWN']

    @property
    def STAMP_READ_START(self):
        """Message constant 'STAMP_READ_START'."""
        return Metaclass_SourceHeader.__constants['STAMP_READ_START']

    @property
    def STAMP_HARDWARE_SYNCED(self):
        """Message constant 'STAMP_HARDWARE_SYNCED'."""
        return Metaclass_SourceHeader.__constants['STAMP_HARDWARE_SYNCED']


class SourceHeader(metaclass=Metaclass_SourceHeader):
    """
    Message class 'SourceHeader'.

    Constants:
      STAMP_UNKNOWN
      STAMP_READ_START
      STAMP_HARDWARE_SYNCED
    """

    __slots__ = [
        '_header',
        '_source_id',
        '_source_session_id',
        '_run_id',
        '_sequence',
        '_stamp_source',
        '_valid',
        '_reason',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'source_id': 'string',
        'source_session_id': 'string',
        'run_id': 'string',
        'sequence': 'uint64',
        'stamp_source': 'uint8',
        'valid': 'boolean',
        'reason': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.source_id = kwargs.get('source_id', str())
        self.source_session_id = kwargs.get('source_session_id', str())
        self.run_id = kwargs.get('run_id', str())
        self.sequence = kwargs.get('sequence', int())
        self.stamp_source = kwargs.get('stamp_source', int())
        self.valid = kwargs.get('valid', bool())
        self.reason = kwargs.get('reason', str())

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
        if self.header != other.header:
            return False
        if self.source_id != other.source_id:
            return False
        if self.source_session_id != other.source_session_id:
            return False
        if self.run_id != other.run_id:
            return False
        if self.sequence != other.sequence:
            return False
        if self.stamp_source != other.stamp_source:
            return False
        if self.valid != other.valid:
            return False
        if self.reason != other.reason:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def source_id(self):
        """Message field 'source_id'."""
        return self._source_id

    @source_id.setter
    def source_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'source_id' field must be of type 'str'"
        self._source_id = value

    @builtins.property
    def source_session_id(self):
        """Message field 'source_session_id'."""
        return self._source_session_id

    @source_session_id.setter
    def source_session_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'source_session_id' field must be of type 'str'"
        self._source_session_id = value

    @builtins.property
    def run_id(self):
        """Message field 'run_id'."""
        return self._run_id

    @run_id.setter
    def run_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'run_id' field must be of type 'str'"
        self._run_id = value

    @builtins.property
    def sequence(self):
        """Message field 'sequence'."""
        return self._sequence

    @sequence.setter
    def sequence(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sequence' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'sequence' field must be an unsigned integer in [0, 18446744073709551615]"
        self._sequence = value

    @builtins.property
    def stamp_source(self):
        """Message field 'stamp_source'."""
        return self._stamp_source

    @stamp_source.setter
    def stamp_source(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'stamp_source' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'stamp_source' field must be an unsigned integer in [0, 255]"
        self._stamp_source = value

    @builtins.property
    def valid(self):
        """Message field 'valid'."""
        return self._valid

    @valid.setter
    def valid(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'valid' field must be of type 'bool'"
        self._valid = value

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

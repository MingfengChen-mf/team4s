# generated from rosidl_generator_py/resource/_idl.py.em
# with input from team4s_interfaces:msg/RangeReading.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RangeReading(type):
    """Metaclass of message 'RangeReading'."""

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
                'team4s_interfaces.msg.RangeReading')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__range_reading
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__range_reading
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__range_reading
            cls._TYPE_SUPPORT = module.type_support_msg__msg__range_reading
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__range_reading

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RangeReading(metaclass=Metaclass_RangeReading):
    """Message class 'RangeReading'."""

    __slots__ = [
        '_sensor_id',
        '_sensor_frame_id',
        '_valid',
        '_reason',
        '_checksum_ok',
        '_device_status_raw',
        '_distance_m',
        '_signal_strength',
        '_sensor_time_ms',
        '_bearing_known',
        '_bearing_rad',
    ]

    _fields_and_field_types = {
        'sensor_id': 'string',
        'sensor_frame_id': 'string',
        'valid': 'boolean',
        'reason': 'string',
        'checksum_ok': 'boolean',
        'device_status_raw': 'uint8',
        'distance_m': 'float',
        'signal_strength': 'uint32',
        'sensor_time_ms': 'uint32',
        'bearing_known': 'boolean',
        'bearing_rad': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.sensor_id = kwargs.get('sensor_id', str())
        self.sensor_frame_id = kwargs.get('sensor_frame_id', str())
        self.valid = kwargs.get('valid', bool())
        self.reason = kwargs.get('reason', str())
        self.checksum_ok = kwargs.get('checksum_ok', bool())
        self.device_status_raw = kwargs.get('device_status_raw', int())
        self.distance_m = kwargs.get('distance_m', float())
        self.signal_strength = kwargs.get('signal_strength', int())
        self.sensor_time_ms = kwargs.get('sensor_time_ms', int())
        self.bearing_known = kwargs.get('bearing_known', bool())
        self.bearing_rad = kwargs.get('bearing_rad', float())

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
        if self.sensor_id != other.sensor_id:
            return False
        if self.sensor_frame_id != other.sensor_frame_id:
            return False
        if self.valid != other.valid:
            return False
        if self.reason != other.reason:
            return False
        if self.checksum_ok != other.checksum_ok:
            return False
        if self.device_status_raw != other.device_status_raw:
            return False
        if self.distance_m != other.distance_m:
            return False
        if self.signal_strength != other.signal_strength:
            return False
        if self.sensor_time_ms != other.sensor_time_ms:
            return False
        if self.bearing_known != other.bearing_known:
            return False
        if self.bearing_rad != other.bearing_rad:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def sensor_id(self):
        """Message field 'sensor_id'."""
        return self._sensor_id

    @sensor_id.setter
    def sensor_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'sensor_id' field must be of type 'str'"
        self._sensor_id = value

    @builtins.property
    def sensor_frame_id(self):
        """Message field 'sensor_frame_id'."""
        return self._sensor_frame_id

    @sensor_frame_id.setter
    def sensor_frame_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'sensor_frame_id' field must be of type 'str'"
        self._sensor_frame_id = value

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

    @builtins.property
    def checksum_ok(self):
        """Message field 'checksum_ok'."""
        return self._checksum_ok

    @checksum_ok.setter
    def checksum_ok(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'checksum_ok' field must be of type 'bool'"
        self._checksum_ok = value

    @builtins.property
    def device_status_raw(self):
        """Message field 'device_status_raw'."""
        return self._device_status_raw

    @device_status_raw.setter
    def device_status_raw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'device_status_raw' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'device_status_raw' field must be an unsigned integer in [0, 255]"
        self._device_status_raw = value

    @builtins.property
    def distance_m(self):
        """Message field 'distance_m'."""
        return self._distance_m

    @distance_m.setter
    def distance_m(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'distance_m' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'distance_m' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._distance_m = value

    @builtins.property
    def signal_strength(self):
        """Message field 'signal_strength'."""
        return self._signal_strength

    @signal_strength.setter
    def signal_strength(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'signal_strength' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'signal_strength' field must be an unsigned integer in [0, 4294967295]"
        self._signal_strength = value

    @builtins.property
    def sensor_time_ms(self):
        """Message field 'sensor_time_ms'."""
        return self._sensor_time_ms

    @sensor_time_ms.setter
    def sensor_time_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sensor_time_ms' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'sensor_time_ms' field must be an unsigned integer in [0, 4294967295]"
        self._sensor_time_ms = value

    @builtins.property
    def bearing_known(self):
        """Message field 'bearing_known'."""
        return self._bearing_known

    @bearing_known.setter
    def bearing_known(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'bearing_known' field must be of type 'bool'"
        self._bearing_known = value

    @builtins.property
    def bearing_rad(self):
        """Message field 'bearing_rad'."""
        return self._bearing_rad

    @bearing_rad.setter
    def bearing_rad(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bearing_rad' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bearing_rad' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bearing_rad = value

# generated from rosidl_generator_py/resource/_idl.py.em
# with input from team4s_interfaces:msg/TaskState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TaskState(type):
    """Metaclass of message 'TaskState'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'TASK_NONE': 0,
        'TASK_LAP': 1,
        'TASK_STRAIGHT': 2,
        'LANE_UNKNOWN': 0,
        'LANE_FIRST': 1,
        'LANE_SECOND': 2,
        'MODE_IDLE': 0,
        'MODE_AUTO': 1,
        'MODE_MANUAL': 2,
        'MODE_PAUSED': 3,
        'MODE_FINISHED': 4,
        'MODE_FAULT': 5,
        'PHASE_IDLE': 0,
        'PHASE_WAIT_START': 1,
        'PHASE_FOLLOW_LAP': 2,
        'PHASE_FOLLOW_FIRST': 3,
        'PHASE_AVOIDING': 4,
        'PHASE_FOLLOW_SECOND': 5,
        'PHASE_ZEBRA_SLOW': 6,
        'PHASE_FINISH_APPROACH': 7,
        'PHASE_STOPPED': 8,
        'PHASE_FAULT': 9,
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
                'team4s_interfaces.msg.TaskState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__task_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__task_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__task_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__task_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__task_state

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'TASK_NONE': cls.__constants['TASK_NONE'],
            'TASK_LAP': cls.__constants['TASK_LAP'],
            'TASK_STRAIGHT': cls.__constants['TASK_STRAIGHT'],
            'LANE_UNKNOWN': cls.__constants['LANE_UNKNOWN'],
            'LANE_FIRST': cls.__constants['LANE_FIRST'],
            'LANE_SECOND': cls.__constants['LANE_SECOND'],
            'MODE_IDLE': cls.__constants['MODE_IDLE'],
            'MODE_AUTO': cls.__constants['MODE_AUTO'],
            'MODE_MANUAL': cls.__constants['MODE_MANUAL'],
            'MODE_PAUSED': cls.__constants['MODE_PAUSED'],
            'MODE_FINISHED': cls.__constants['MODE_FINISHED'],
            'MODE_FAULT': cls.__constants['MODE_FAULT'],
            'PHASE_IDLE': cls.__constants['PHASE_IDLE'],
            'PHASE_WAIT_START': cls.__constants['PHASE_WAIT_START'],
            'PHASE_FOLLOW_LAP': cls.__constants['PHASE_FOLLOW_LAP'],
            'PHASE_FOLLOW_FIRST': cls.__constants['PHASE_FOLLOW_FIRST'],
            'PHASE_AVOIDING': cls.__constants['PHASE_AVOIDING'],
            'PHASE_FOLLOW_SECOND': cls.__constants['PHASE_FOLLOW_SECOND'],
            'PHASE_ZEBRA_SLOW': cls.__constants['PHASE_ZEBRA_SLOW'],
            'PHASE_FINISH_APPROACH': cls.__constants['PHASE_FINISH_APPROACH'],
            'PHASE_STOPPED': cls.__constants['PHASE_STOPPED'],
            'PHASE_FAULT': cls.__constants['PHASE_FAULT'],
        }

    @property
    def TASK_NONE(self):
        """Message constant 'TASK_NONE'."""
        return Metaclass_TaskState.__constants['TASK_NONE']

    @property
    def TASK_LAP(self):
        """Message constant 'TASK_LAP'."""
        return Metaclass_TaskState.__constants['TASK_LAP']

    @property
    def TASK_STRAIGHT(self):
        """Message constant 'TASK_STRAIGHT'."""
        return Metaclass_TaskState.__constants['TASK_STRAIGHT']

    @property
    def LANE_UNKNOWN(self):
        """Message constant 'LANE_UNKNOWN'."""
        return Metaclass_TaskState.__constants['LANE_UNKNOWN']

    @property
    def LANE_FIRST(self):
        """Message constant 'LANE_FIRST'."""
        return Metaclass_TaskState.__constants['LANE_FIRST']

    @property
    def LANE_SECOND(self):
        """Message constant 'LANE_SECOND'."""
        return Metaclass_TaskState.__constants['LANE_SECOND']

    @property
    def MODE_IDLE(self):
        """Message constant 'MODE_IDLE'."""
        return Metaclass_TaskState.__constants['MODE_IDLE']

    @property
    def MODE_AUTO(self):
        """Message constant 'MODE_AUTO'."""
        return Metaclass_TaskState.__constants['MODE_AUTO']

    @property
    def MODE_MANUAL(self):
        """Message constant 'MODE_MANUAL'."""
        return Metaclass_TaskState.__constants['MODE_MANUAL']

    @property
    def MODE_PAUSED(self):
        """Message constant 'MODE_PAUSED'."""
        return Metaclass_TaskState.__constants['MODE_PAUSED']

    @property
    def MODE_FINISHED(self):
        """Message constant 'MODE_FINISHED'."""
        return Metaclass_TaskState.__constants['MODE_FINISHED']

    @property
    def MODE_FAULT(self):
        """Message constant 'MODE_FAULT'."""
        return Metaclass_TaskState.__constants['MODE_FAULT']

    @property
    def PHASE_IDLE(self):
        """Message constant 'PHASE_IDLE'."""
        return Metaclass_TaskState.__constants['PHASE_IDLE']

    @property
    def PHASE_WAIT_START(self):
        """Message constant 'PHASE_WAIT_START'."""
        return Metaclass_TaskState.__constants['PHASE_WAIT_START']

    @property
    def PHASE_FOLLOW_LAP(self):
        """Message constant 'PHASE_FOLLOW_LAP'."""
        return Metaclass_TaskState.__constants['PHASE_FOLLOW_LAP']

    @property
    def PHASE_FOLLOW_FIRST(self):
        """Message constant 'PHASE_FOLLOW_FIRST'."""
        return Metaclass_TaskState.__constants['PHASE_FOLLOW_FIRST']

    @property
    def PHASE_AVOIDING(self):
        """Message constant 'PHASE_AVOIDING'."""
        return Metaclass_TaskState.__constants['PHASE_AVOIDING']

    @property
    def PHASE_FOLLOW_SECOND(self):
        """Message constant 'PHASE_FOLLOW_SECOND'."""
        return Metaclass_TaskState.__constants['PHASE_FOLLOW_SECOND']

    @property
    def PHASE_ZEBRA_SLOW(self):
        """Message constant 'PHASE_ZEBRA_SLOW'."""
        return Metaclass_TaskState.__constants['PHASE_ZEBRA_SLOW']

    @property
    def PHASE_FINISH_APPROACH(self):
        """Message constant 'PHASE_FINISH_APPROACH'."""
        return Metaclass_TaskState.__constants['PHASE_FINISH_APPROACH']

    @property
    def PHASE_STOPPED(self):
        """Message constant 'PHASE_STOPPED'."""
        return Metaclass_TaskState.__constants['PHASE_STOPPED']

    @property
    def PHASE_FAULT(self):
        """Message constant 'PHASE_FAULT'."""
        return Metaclass_TaskState.__constants['PHASE_FAULT']


class TaskState(metaclass=Metaclass_TaskState):
    """
    Message class 'TaskState'.

    Constants:
      TASK_NONE
      TASK_LAP
      TASK_STRAIGHT
      LANE_UNKNOWN
      LANE_FIRST
      LANE_SECOND
      MODE_IDLE
      MODE_AUTO
      MODE_MANUAL
      MODE_PAUSED
      MODE_FINISHED
      MODE_FAULT
      PHASE_IDLE
      PHASE_WAIT_START
      PHASE_FOLLOW_LAP
      PHASE_FOLLOW_FIRST
      PHASE_AVOIDING
      PHASE_FOLLOW_SECOND
      PHASE_ZEBRA_SLOW
      PHASE_FINISH_APPROACH
      PHASE_STOPPED
      PHASE_FAULT
    """

    __slots__ = [
        '_header',
        '_run_id',
        '_controller_session_id',
        '_sequence',
        '_task_id',
        '_phase',
        '_target_lane',
        '_control_mode',
        '_lap_complete',
        '_reason',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'run_id': 'string',
        'controller_session_id': 'string',
        'sequence': 'uint64',
        'task_id': 'uint8',
        'phase': 'uint8',
        'target_lane': 'uint8',
        'control_mode': 'uint8',
        'lap_complete': 'boolean',
        'reason': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
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
        self.run_id = kwargs.get('run_id', str())
        self.controller_session_id = kwargs.get('controller_session_id', str())
        self.sequence = kwargs.get('sequence', int())
        self.task_id = kwargs.get('task_id', int())
        self.phase = kwargs.get('phase', int())
        self.target_lane = kwargs.get('target_lane', int())
        self.control_mode = kwargs.get('control_mode', int())
        self.lap_complete = kwargs.get('lap_complete', bool())
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
        if self.run_id != other.run_id:
            return False
        if self.controller_session_id != other.controller_session_id:
            return False
        if self.sequence != other.sequence:
            return False
        if self.task_id != other.task_id:
            return False
        if self.phase != other.phase:
            return False
        if self.target_lane != other.target_lane:
            return False
        if self.control_mode != other.control_mode:
            return False
        if self.lap_complete != other.lap_complete:
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
    def controller_session_id(self):
        """Message field 'controller_session_id'."""
        return self._controller_session_id

    @controller_session_id.setter
    def controller_session_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'controller_session_id' field must be of type 'str'"
        self._controller_session_id = value

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
    def task_id(self):
        """Message field 'task_id'."""
        return self._task_id

    @task_id.setter
    def task_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'task_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'task_id' field must be an unsigned integer in [0, 255]"
        self._task_id = value

    @builtins.property
    def phase(self):
        """Message field 'phase'."""
        return self._phase

    @phase.setter
    def phase(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'phase' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'phase' field must be an unsigned integer in [0, 255]"
        self._phase = value

    @builtins.property
    def target_lane(self):
        """Message field 'target_lane'."""
        return self._target_lane

    @target_lane.setter
    def target_lane(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'target_lane' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'target_lane' field must be an unsigned integer in [0, 255]"
        self._target_lane = value

    @builtins.property
    def control_mode(self):
        """Message field 'control_mode'."""
        return self._control_mode

    @control_mode.setter
    def control_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'control_mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'control_mode' field must be an unsigned integer in [0, 255]"
        self._control_mode = value

    @builtins.property
    def lap_complete(self):
        """Message field 'lap_complete'."""
        return self._lap_complete

    @lap_complete.setter
    def lap_complete(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'lap_complete' field must be of type 'bool'"
        self._lap_complete = value

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

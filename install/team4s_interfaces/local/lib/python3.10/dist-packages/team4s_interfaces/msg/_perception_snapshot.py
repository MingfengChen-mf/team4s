# generated from rosidl_generator_py/resource/_idl.py.em
# with input from team4s_interfaces:msg/PerceptionSnapshot.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PerceptionSnapshot(type):
    """Metaclass of message 'PerceptionSnapshot'."""

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
                'team4s_interfaces.msg.PerceptionSnapshot')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__perception_snapshot
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__perception_snapshot
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__perception_snapshot
            cls._TYPE_SUPPORT = module.type_support_msg__msg__perception_snapshot
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__perception_snapshot

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

            from team4s_interfaces.msg import LaneObservation
            if LaneObservation.__class__._TYPE_SUPPORT is None:
                LaneObservation.__class__.__import_type_support__()

            from team4s_interfaces.msg import ObstacleObservation
            if ObstacleObservation.__class__._TYPE_SUPPORT is None:
                ObstacleObservation.__class__.__import_type_support__()

            from team4s_interfaces.msg import SceneObservation
            if SceneObservation.__class__._TYPE_SUPPORT is None:
                SceneObservation.__class__.__import_type_support__()

            from team4s_interfaces.msg import TopicHealth
            if TopicHealth.__class__._TYPE_SUPPORT is None:
                TopicHealth.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PerceptionSnapshot(metaclass=Metaclass_PerceptionSnapshot):
    """Message class 'PerceptionSnapshot'."""

    __slots__ = [
        '_header',
        '_aggregator_session_id',
        '_run_id',
        '_sequence',
        '_lane',
        '_lane_health',
        '_obstacles',
        '_obstacles_health',
        '_scene',
        '_scene_health',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'aggregator_session_id': 'string',
        'run_id': 'string',
        'sequence': 'uint64',
        'lane': 'team4s_interfaces/LaneObservation',
        'lane_health': 'team4s_interfaces/TopicHealth',
        'obstacles': 'team4s_interfaces/ObstacleObservation',
        'obstacles_health': 'team4s_interfaces/TopicHealth',
        'scene': 'team4s_interfaces/SceneObservation',
        'scene_health': 'team4s_interfaces/TopicHealth',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['team4s_interfaces', 'msg'], 'LaneObservation'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['team4s_interfaces', 'msg'], 'TopicHealth'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['team4s_interfaces', 'msg'], 'ObstacleObservation'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['team4s_interfaces', 'msg'], 'TopicHealth'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['team4s_interfaces', 'msg'], 'SceneObservation'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['team4s_interfaces', 'msg'], 'TopicHealth'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.aggregator_session_id = kwargs.get('aggregator_session_id', str())
        self.run_id = kwargs.get('run_id', str())
        self.sequence = kwargs.get('sequence', int())
        from team4s_interfaces.msg import LaneObservation
        self.lane = kwargs.get('lane', LaneObservation())
        from team4s_interfaces.msg import TopicHealth
        self.lane_health = kwargs.get('lane_health', TopicHealth())
        from team4s_interfaces.msg import ObstacleObservation
        self.obstacles = kwargs.get('obstacles', ObstacleObservation())
        from team4s_interfaces.msg import TopicHealth
        self.obstacles_health = kwargs.get('obstacles_health', TopicHealth())
        from team4s_interfaces.msg import SceneObservation
        self.scene = kwargs.get('scene', SceneObservation())
        from team4s_interfaces.msg import TopicHealth
        self.scene_health = kwargs.get('scene_health', TopicHealth())

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
        if self.aggregator_session_id != other.aggregator_session_id:
            return False
        if self.run_id != other.run_id:
            return False
        if self.sequence != other.sequence:
            return False
        if self.lane != other.lane:
            return False
        if self.lane_health != other.lane_health:
            return False
        if self.obstacles != other.obstacles:
            return False
        if self.obstacles_health != other.obstacles_health:
            return False
        if self.scene != other.scene:
            return False
        if self.scene_health != other.scene_health:
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
    def aggregator_session_id(self):
        """Message field 'aggregator_session_id'."""
        return self._aggregator_session_id

    @aggregator_session_id.setter
    def aggregator_session_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'aggregator_session_id' field must be of type 'str'"
        self._aggregator_session_id = value

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
    def lane(self):
        """Message field 'lane'."""
        return self._lane

    @lane.setter
    def lane(self, value):
        if __debug__:
            from team4s_interfaces.msg import LaneObservation
            assert \
                isinstance(value, LaneObservation), \
                "The 'lane' field must be a sub message of type 'LaneObservation'"
        self._lane = value

    @builtins.property
    def lane_health(self):
        """Message field 'lane_health'."""
        return self._lane_health

    @lane_health.setter
    def lane_health(self, value):
        if __debug__:
            from team4s_interfaces.msg import TopicHealth
            assert \
                isinstance(value, TopicHealth), \
                "The 'lane_health' field must be a sub message of type 'TopicHealth'"
        self._lane_health = value

    @builtins.property
    def obstacles(self):
        """Message field 'obstacles'."""
        return self._obstacles

    @obstacles.setter
    def obstacles(self, value):
        if __debug__:
            from team4s_interfaces.msg import ObstacleObservation
            assert \
                isinstance(value, ObstacleObservation), \
                "The 'obstacles' field must be a sub message of type 'ObstacleObservation'"
        self._obstacles = value

    @builtins.property
    def obstacles_health(self):
        """Message field 'obstacles_health'."""
        return self._obstacles_health

    @obstacles_health.setter
    def obstacles_health(self, value):
        if __debug__:
            from team4s_interfaces.msg import TopicHealth
            assert \
                isinstance(value, TopicHealth), \
                "The 'obstacles_health' field must be a sub message of type 'TopicHealth'"
        self._obstacles_health = value

    @builtins.property
    def scene(self):
        """Message field 'scene'."""
        return self._scene

    @scene.setter
    def scene(self, value):
        if __debug__:
            from team4s_interfaces.msg import SceneObservation
            assert \
                isinstance(value, SceneObservation), \
                "The 'scene' field must be a sub message of type 'SceneObservation'"
        self._scene = value

    @builtins.property
    def scene_health(self):
        """Message field 'scene_health'."""
        return self._scene_health

    @scene_health.setter
    def scene_health(self, value):
        if __debug__:
            from team4s_interfaces.msg import TopicHealth
            assert \
                isinstance(value, TopicHealth), \
                "The 'scene_health' field must be a sub message of type 'TopicHealth'"
        self._scene_health = value

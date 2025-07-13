# generated from rosidl_generator_py/resource/_idl.py.em
# with input from upc_mrn:msg/Frontier.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'cells'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Frontier(type):
    """Metaclass of message 'Frontier'."""

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
            module = import_type_support('upc_mrn')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'upc_mrn.msg.Frontier')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__frontier
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__frontier
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__frontier
            cls._TYPE_SUPPORT = module.type_support_msg__msg__frontier
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__frontier

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Frontier(metaclass=Metaclass_Frontier):
    """Message class 'Frontier'."""

    __slots__ = [
        '_size',
        '_center_point',
        '_cells_points',
        '_center_cell',
        '_cells',
    ]

    _fields_and_field_types = {
        'size': 'uint32',
        'center_point': 'geometry_msgs/Point',
        'cells_points': 'sequence<geometry_msgs/Point>',
        'center_cell': 'uint32',
        'cells': 'sequence<uint32>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint32')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.size = kwargs.get('size', int())
        from geometry_msgs.msg import Point
        self.center_point = kwargs.get('center_point', Point())
        self.cells_points = kwargs.get('cells_points', [])
        self.center_cell = kwargs.get('center_cell', int())
        self.cells = array.array('I', kwargs.get('cells', []))

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
        if self.size != other.size:
            return False
        if self.center_point != other.center_point:
            return False
        if self.cells_points != other.cells_points:
            return False
        if self.center_cell != other.center_cell:
            return False
        if self.cells != other.cells:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def size(self):
        """Message field 'size'."""
        return self._size

    @size.setter
    def size(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'size' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'size' field must be an unsigned integer in [0, 4294967295]"
        self._size = value

    @builtins.property
    def center_point(self):
        """Message field 'center_point'."""
        return self._center_point

    @center_point.setter
    def center_point(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'center_point' field must be a sub message of type 'Point'"
        self._center_point = value

    @builtins.property
    def cells_points(self):
        """Message field 'cells_points'."""
        return self._cells_points

    @cells_points.setter
    def cells_points(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
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
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'cells_points' field must be a set or sequence and each value of type 'Point'"
        self._cells_points = value

    @builtins.property
    def center_cell(self):
        """Message field 'center_cell'."""
        return self._center_cell

    @center_cell.setter
    def center_cell(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'center_cell' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'center_cell' field must be an unsigned integer in [0, 4294967295]"
        self._center_cell = value

    @builtins.property
    def cells(self):
        """Message field 'cells'."""
        return self._cells

    @cells.setter
    def cells(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'I', \
                "The 'cells' array.array() must have the type code of 'I'"
            self._cells = value
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
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 4294967296 for val in value)), \
                "The 'cells' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 4294967295]"
        self._cells = array.array('I', value)

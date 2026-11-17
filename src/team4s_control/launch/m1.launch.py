"""
m1.launch.py —— 起 m1_control 节点（任务书 (12)）

用法（文件名/目录写全，见任务书 (9)）：
  ros2 launch team4s_control m1.launch.py                          # 车上：domain 默认 111
  ros2 launch team4s_control m1.launch.py domain_id:=113           # WSL 隔离集成测试
  ros2 launch team4s_control m1.launch.py task_id:=2 target_lane:=1

launch API 取 Foxy 可用子集（DeclareLaunchArgument / SetEnvironmentVariable /
launch_ros Node + parameters），不用 Humble 专有语法。
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, SetEnvironmentVariable
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    domain_id = LaunchConfiguration('domain_id')
    task_id = LaunchConfiguration('task_id')
    target_lane = LaunchConfiguration('target_lane')

    return LaunchDescription([
        DeclareLaunchArgument(
            'domain_id', default_value='111',
            description='ROS_DOMAIN_ID：车上 111；WSL 集成测试传 113 隔离'),
        DeclareLaunchArgument(
            'task_id', default_value='1', description='1=单圈，2=直道'),
        DeclareLaunchArgument(
            'target_lane', default_value='1',
            description='1=FIRST 主路左车道，2=SECOND 主路右车道'),
        SetEnvironmentVariable('ROS_DOMAIN_ID', domain_id),
        Node(
            package='team4s_control',
            executable='m1_node',
            name='m1_control',
            output='screen',
            parameters=[{'task_id': task_id, 'target_lane': target_lane}],
        ),
    ])

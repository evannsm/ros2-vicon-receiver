from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    """Launch only the full_state_relay node."""
    
    full_state_relay = Node(
        package='vicon4px4',
        executable='full_state_relay',
        output='screen',
    )

    return LaunchDescription([full_state_relay])
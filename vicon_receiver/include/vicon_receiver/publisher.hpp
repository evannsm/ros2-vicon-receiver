#ifndef PUBLISHER_HPP
#define PUBLISHER_HPP
#include <unistd.h>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include <px4_msgs/msg/vehicle_odometry.hpp>
#include "vicon_receiver/msg/pose_euler.hpp"

// Class that allows segment data to be published in a ROS2 topic.
class Publisher
{
private:
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr position_publisher_;
    rclcpp::Publisher<vicon_receiver::msg::PoseEuler>::SharedPtr rpy_publisher_;
    rclcpp::Publisher<px4_msgs::msg::VehicleOdometry>::SharedPtr px4_odom_publisher_;

public:
    bool is_ready = false;

    Publisher(std::string topic_name, rclcpp::Node* node);

    // Publishes the given position in the ROS2 topic whose name is indicated in
    // the constructor.
    void publish(geometry_msgs::msg::PoseStamped p);
};

#endif
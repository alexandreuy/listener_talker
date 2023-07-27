#include "ros/ros.h"
#include "std_msgs/String.h"


void listenerCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "listener");

  ros::NodeHandle nh;

  // create the subscriber object
  ros::Subscriber chatter_sub = nh.subscribe("talker", 1000, listenerCallback);

  // spin until ROS is shutdown
  ros::spin();

  return 0;
}

#include "ros/ros.h"
#include "std_msgs/String.h"

void talker() {
  ros::NodeHandle nh;
  ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("talker", 1000);

  int count = 0;
  while (ros::ok()) {
    std_msgs::String msg;
    msg.data = "hello ROS " + std::to_string(count);
    ROS_INFO("Publishing: %s", msg.data.c_str());
    chatter_pub.publish(msg);
    ros::spinOnce();
    ++count;
  }
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "talker");

  ros::NodeHandle nh;

  // create the talker object
  talker();

  return 0;
}

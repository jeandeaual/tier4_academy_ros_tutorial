# Tier 4 Academy ROS Tutorial (nodes and topics)

## Requirements

* Ubuntu 18.04+
* [ROS Melodic](http://wiki.ros.org/melodic/Installation/Ubuntu)

## Build Instructions

```
source /opt/ros/melodic/setup.bash
mkdir -p ~/colcon_ws/src
cd ~/colcon_ws/src
git clone REPOSITORY_URL tutorials
cd ~/colcon_ws
colcon build
colcon --packages-select tutorials
source ~/colcon_ws/install/local_setup.bash
```

## Running the Examples

Make sure to launch `roscore` beforehand, then run the examples.

e.g.:

```
rosrun tutorials simple
```

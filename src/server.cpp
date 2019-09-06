#include "ros/ros.h" // ROS で必要なヘッダー
#include "tutorials/AddNums.h"

bool add(tutorials::AddNums::Request &req, tutorials::AddNums::Response &res)
{
    // サービスの内容
    res.sum = req.a + req.b;
    return true;
}

int main(int argc, char **argv)
{
    // ROS の初期化.ノードの名前を特定
    ros::init(argc, argv, "server");
    // プロセスのノードへのハンドラを作成
    ros::NodeHandle n;

    // サービスの提供
    ros::ServiceServer service = n.advertiseService("add_nums", add);
    ros::spin();

    return 0;
}

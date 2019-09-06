#include "ros/ros.h" // ROS で必要なヘッダー
#include "tutorials/AddNums.h"

int main(int argc, char **argv)
{
    // ROS の初期化.ノードの名前を特定
    ros::init(argc, argv, "client");
    // プロセスのノードへのハンドラを作成
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<tutorials::AddNums>("add_nums");
    tutorials::AddNums srv;

    std::cout << "Input 2 nums:";
    // 端末から2つの整数値を入力
    std::cin >> srv.request.a >> srv.request.b;

    // サービスの呼出し
    if (client.call(srv)) {
        // サービス結果を表示
        ROS_INFO("Sum:%ld+%ld=%ld", srv.request.a, srv.request.b, srv.response.sum);
    } else {
        ROS_ERROR("Sum: Failed");
    }

    return 0;
}

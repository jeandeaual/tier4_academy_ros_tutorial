#include "ros/ros.h" // ROSで必要なヘッダー
#include "tutorials/user.h"

void chatterCallback(const tutorials::user::ConstPtr &msg)
{
    // 結果を標準出力
    ROS_INFO("I heard: [%s][%d]", msg->data.c_str(), msg->num);
}

int main(int argc, char **argv)
{
    // ROS の初期化.ノードの名前を特定
    ros::init(argc, argv, "listener2");
    // プロセスのノードへのハンドラを作成
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
    // rosmatserにchatterトピックを購読chatterCallback()を宣言
    // 第1引数:購読するトピック名
    // 第2引数:受信バッファの大きさ
    // 第3引数:トピックデータ受信時に呼び出す関数
    // 待機ループ（メッセージの受信ごとにchatterCallbackを呼び出し）
    ros::spin();

    return 0;
}

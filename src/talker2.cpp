#include "ros/ros.h" // ROS で必要なヘッダー
#include "tutorials/user.h"
#include <sstream>

int main(int argc, char **argv)
{
    // ROS の初期化.ノードの名前を特定
    ros::init(argc, argv, "talker2");
    // プロセスのノードへのハンドラを作成
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<tutorials::user>("chatter", 1000);
    // rosmasterにstd_msgs/String型chatterトピックの配信を宣言
    // 第1引数:配信するトピック名
    // 第2引数:送信バッファの大きさ
    // ループ頻度を設定
    ros::Rate loop_rate(10);
    int count = 0;

    while (ros::ok()) {
        // Ctrl-C(SINGINTシグナル)を押すと ros::ok() が false を返却
        tutorials::user msg;
        std::stringstream ss;

        ss << "Hello, World!";
        msg.data = ss.str();
        msg.num = count;

        count++;

        // メッセージを発信
        chatter_pub.publish(msg);
        // 10Hzの発信が行えるように残り時間をスリープ
        loop_rate.sleep();
    }

    return 0;
}

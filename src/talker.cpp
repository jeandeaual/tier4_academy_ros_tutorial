#include "ros/ros.h" // ROS で必要なヘッダー
#include "std_msgs/String.h" // ROSで利用する型
#include <sstream>

int main(int argc, char **argv)
{
    // ROS の初期化.ノードの名前を特定
    ros::init(argc, argv, "talker");
    // プロセスのノードへのハンドラを作成
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
    // rosmasterにstd_msgs/String型chatterトピックの配信を宣言
    // 第1引数:配信するトピック名
    // 第2引数:送信バッファの大きさ
    // ループ頻度を設定
    ros::Rate loop_rate(10);

    while (ros::ok()) {
        // Ctrl-C(SINGINTシグナル)を押すと ros::ok() が false を返却
        std_msgs::String msg;
        std::stringstream ss;
        ss << "Hello, World!";
        msg.data = ss.str();
        // メッセージを発信
        chatter_pub.publish(msg);
        // 10Hzの発信が行えるように残り時間をスリープ
        loop_rate.sleep();
    }

    return 0;
}

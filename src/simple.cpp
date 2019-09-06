#include "ros/ros.h" // ROS で必要なヘッダー

int main(int argc, char **argv)
{
    // ROS の初期化.ノードの名前を特定
    ros::init(argc, argv, "simple");
    // プロセスのノードへのハンドラを作成
    ros::NodeHandle n;
    // 1Hzで動作させるためのタイマーを作成
    ros::Rate loop_rate(1);
    int count = 0;

    while (ros::ok()) {
        // Ctrl-C(SINGINTシグナル)を押すと ros::ok() が false を返却
        ROS_INFO("Hello world %d", count++); //ログメッセージを出力
        // 1Hzで動作するようスリープ
        loop_rate.sleep();
    }

    return 0;
}

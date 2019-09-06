#include "ros/ros.h" //ROS で必要なヘッダー

int main(int argc, char **argv)
{
    ros::init(argc, argv, "simple"); //ROS の初期化.ノードの名前を特定
    ros::NodeHandle n; //プロセスのノードへのハンドラを作成
    ros::Rate loop_rate(1); //1Hzで動作させるためのタイマーを作成
    int count = 0;
    while (ros::ok()) //Ctrl-C(SINGINTシグナル)を押すと ros::ok() が false を返却
    {
        ROS_INFO("Hello world %d", count++); //ログメッセージを出力
        loop_rate.sleep(); //1Hzで動作するようスリープ
    }
    return 0;
}

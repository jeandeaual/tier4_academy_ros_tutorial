#include "ros/ros.h" // ROS で必要なヘッダー

int main(int argc, char **argv)
{
    // ROS の初期化.ノードの名前を特定
    ros::init(argc, argv, "parameter");
    // プロセスのノードへのハンドラを作成
    ros::NodeHandle n;

    // コマンドライン引数がある場合
    if (argc > 1) {
        // コマンドライン引数をparameter_testにセット
        ros::param::set("parameter_test", argv[1]);
    } else {
        std::string str;
        // parameter_testの値をゲットしstrに格納
        ros::param::get("parameter_test", str);
        // strの値を出力
        ROS_INFO("parameter=%s", str.c_str());
    }

    return 0;
}

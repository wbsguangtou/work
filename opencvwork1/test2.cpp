#include <opencv2/opencv.hpp>
#include <unistd.h>
using namespace cv;
int main()
{
	//读取视频
	VideoCapture capture("MH.mp4");
	//循环显示每一帧
	while(1){
		Mat frame;//定义一个Mat变量，用于存储每一帧的图像
		capture >> frame;//读取当前帧
		if(frame.empty())//播放完毕，退出
			break;
		imshow("读取视频帧",frame);//显示当前帧
		waitKey(30);//掩饰30ms
	}
	pause();
	return 0;
}



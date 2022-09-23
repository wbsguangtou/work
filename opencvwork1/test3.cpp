/*********************************************************************
打开电脑摄像头，空格控制视频录制，ESC退出并保存视频RecordVideo.avi
*********************************************************************/
#include<iostream>
#include <opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;

int main()
{
	//打开电脑摄像头
	VideoCapture cap(0);
	if (!cap.isOpened())
	{
		cout << "error" << endl;
		waitKey(0);
		return 0;
	}

	//获得cap的分辨率
	int w = static_cast<int>(cap.get(CV_CAP_PROP_FRAME_WIDTH));
	int h = static_cast<int>(cap.get(CV_CAP_PROP_FRAME_HEIGHT));
	Size videoSize(w, h);
	VideoWriter writer("RecordVideo.avi", CV_FOURCC('M', 'J', 'P', 'G'), 25, videoSize);
	
	Mat frame;
	int key;//记录键盘按键
	char startOrStop = 1;//0  开始录制视频； 1 结束录制视频
	char flag = 0;//正在录制标志 0-不在录制； 1-正在录制

	while (1)
	{
		cap >> frame;
		key = waitKey(100);
		if (key == 32)//按下空格开始录制、暂停录制   可以来回切换
		{
			startOrStop = 1 - startOrStop;
			if (startOrStop == 0)
			{
				flag = 1;
			}
		}
		if (key == 27)//按下ESC退出整个程序，保存视频文件到磁盘
		{
			break;
		}

		if (startOrStop == 0 && flag==1)
		{
			writer << frame;
			cout << "recording" << endl;
		}
		else if (startOrStop == 1)
		{
			flag = 0;
			cout << "end recording" << endl;
			
		}
		imshow("picture", frame);
	}
	cap.release();
	writer.release();
	destroyAllWindows();
	return 0;
}


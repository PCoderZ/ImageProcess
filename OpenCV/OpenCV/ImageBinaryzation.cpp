/*
//图像二值化

#include<opencv.hpp>

using namespace std;

void on_trackbar(int threshold);

const char* pstrSrcTitle = "原始图像";
const char* pstrBinaryTitle = "二值化图像";
IplImage* pSrcImage = NULL;
IplImage* pBinaryImage = NULL;
IplImage* pGrayImage = NULL;


int main(){
	const char* pstrPathname = "E:\\Photo\\face.jpg";
	const char* pstrTrackbarName = "二值化阈值";
	
	//加载生成灰度图像
	pSrcImage = cvLoadImage(pstrPathname, CV_LOAD_IMAGE_UNCHANGED);
	pGrayImage = cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 1);    //输出：图像像素数据是8位无符号整形
	cvCvtColor(pSrcImage, pGrayImage, CV_RGB2GRAY);                       //输出：8位单倍精度浮点数影像
	
	//此时pGrayImage为像素深度为8位无符号整形的单通道图像，pBinaryImage为空，而cvThreshold源图像和目标图像必须格式一致，即depth和channel要相同
	//所以要对pBinaryImage初始化
	pBinaryImage = cvCreateImage(cvGetSize(pGrayImage), IPL_DEPTH_8U, 1);

	//定义窗口
	cvNamedWindow(pstrSrcTitle, CV_WINDOW_AUTOSIZE);
	cvNamedWindow(pstrBinaryTitle, CV_WINDOW_AUTOSIZE);

	//显示图像
	cvShowImage(pstrSrcTitle, pSrcImage);
	cvShowImage(pstrBinaryTitle, pBinaryImage);

	
	//创建滑动条
	int threshold = 0;
	cvCreateTrackbar(pstrTrackbarName, pstrBinaryTitle ,&threshold, 254, on_trackbar);
	//on_trackbar(1);
	

	cvWaitKey(0);

	cvDestroyAllWindows();
	cvReleaseImage(&pSrcImage);
	cvReleaseImage(&pGrayImage);
	cvReleaseImage(&pBinaryImage);

	return 0;
}

void on_trackbar(int threshold){
	cvThreshold(pGrayImage, pBinaryImage, threshold, 255, CV_THRESH_BINARY);
	cvShowImage(pstrBinaryTitle, pBinaryImage);
}

*/
/*
//图像的canny边缘检测

#include<opencv.hpp>

using namespace std;

//函数声明
void on_trackbar(int threshold);

IplImage *pSrcImage, *pCannyImage;
const char *pstrWindowsCannyTitle = "边缘检测图";


int main(){
	const char *pstrImagePath = "E:\\Photo\\face.jpg"; 
	const char *pstrWindowsSrcTitle = "原图";
	const char *pstrWindowsTrackBarName = "Threshold";

	//从文件中载入图像的灰度图(重点部分)
	pSrcImage = cvLoadImage(pstrImagePath, CV_LOAD_IMAGE_GRAYSCALE);
	pCannyImage = cvCreateImage(cvSize(pSrcImage->width, pSrcImage->height), IPL_DEPTH_8U, 1); 

	//创建窗口
	cvNamedWindow(pstrWindowsSrcTitle, CV_WINDOW_AUTOSIZE);
	cvNamedWindow(pstrWindowsCannyTitle, CV_WINDOW_AUTOSIZE);

	//创建滑动条,从而改变canny边缘检测的阈值
	int nThresholdEdge = 1;
	cvCreateTrackbar(pstrWindowsTrackBarName, pstrWindowsCannyTitle, &nThresholdEdge, 100, on_trackbar );

	//去掉滑动条，固定大小阈值的canny边缘检测
	//int threshold = 50;
	//cvCanny(pSrcImage, pCannyImage, threshold, threshold*3, 3);

	//在指定窗口中显示图像  
    cvShowImage(pstrWindowsSrcTitle, pSrcImage);  
	cvShowImage(pstrWindowsCannyTitle, pCannyImage);

	//等待按键事件
	cvWaitKey();

	return 0;
}

void on_trackbar(int threshold){

	//canny边缘检测
	cvCanny(pSrcImage, pCannyImage, threshold, threshold*3, 3);
	cvShowImage(pstrWindowsCannyTitle, pCannyImage);
}

*/
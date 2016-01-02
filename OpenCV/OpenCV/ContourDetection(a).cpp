///*
//轮廓检测上

#include<opencv.hpp>

using namespace std;

int main(){
	const char* pstrSrcImageTitle = "原图";
	const char* pstrContourImageTitle = "轮廓图";

	const int IMAGE_WIDTH = 400;
	const int IMAGE_HEIGHT = 200;

	//创建图像
	IplImage *pSrcImage = cvLoadImage("E:\\Photo\\face.jpg", CV_LOAD_IMAGE_UNCHANGED);
	IplImage *pSrcImage1 = cvCreateImage(cvSize(IMAGE_WIDTH, IMAGE_HEIGHT), IPL_DEPTH_8U, 3);
	
	/*
	//填充成白色
	cvRectangle(pSrcImage, cvPoint(0,0), cvPoint(IMAGE_WIDTH, IMAGE_HEIGHT), CV_RGB(255,255,255), CV_FILLED);

	//画圆环，两个不同颜色的圆叠加
	CvPoint ptCircleCenter = cvPoint((pSrcImage->width)/4, (pSrcImage->height)/2);  
	int nRadius = 80;
	cvCircle(pSrcImage, ptCircleCenter, nRadius, CV_RGB(255,255,0), CV_FILLED);
	nRadius = 40;
	cvCircle(pSrcImage, ptCircleCenter, nRadius, CV_RGB(255,255,255), CV_FILLED);

	//画矩形环
	CvPoint ptLeftTop = cvPoint(IMAGE_WIDTH / 2 + 20, 20);
	CvPoint ptRightBottom = cvPoint(IMAGE_WIDTH - 20, IMAGE_HEIGHT - 20);
	cvRectangle(pSrcImage, ptLeftTop, ptRightBottom, CV_RGB(0,255,232), CV_FILLED);
	ptLeftTop = cvPoint(IMAGE_WIDTH / 2 +60, 40);
	ptRightBottom = cvPoint(IMAGE_WIDTH - 60, IMAGE_HEIGHT - 40);
	cvRectangle(pSrcImage, ptLeftTop, ptRightBottom, CV_RGB(255,255,255), CV_FILLED);
	*/

	//显示原图
	cvNamedWindow(pstrSrcImageTitle, CV_WINDOW_AUTOSIZE);
	cvShowImage(pstrSrcImageTitle, pSrcImage);

	//转为灰度图
	IplImage *pGrayImage = cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 1);
	cvCvtColor(pSrcImage, pGrayImage, CV_BGR2GRAY);
	//转为二值图，原数组和目标数组应都为单通道，且类型一致
	IplImage *pBinaryIamge = cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 1);
	cvThreshold(pGrayImage, pBinaryIamge, 88, 255, CV_THRESH_BINARY);

	//检测轮廓并返回相应参数
	CvMemStorage *pcvMStorage = cvCreateMemStorage();
	CvSeq *pcvSeq = NULL;
	cvFindContours(pBinaryIamge, pcvMStorage, &pcvSeq, sizeof(CvContour), CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));

	//画轮廓图
	IplImage *pOutLineImage = cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 3);    //RGB图像
	cvRectangle(pOutLineImage, cvPoint(0,0), cvPoint(pOutLineImage->width, pOutLineImage->height), CV_RGB(255,255,255), CV_FILLED);
	int nlevels = 5;
	cvDrawContours(pOutLineImage, pcvSeq, CV_RGB(255,0,0), CV_RGB(121,144,0), nlevels, 2 );

	//显示轮廓图
	cvNamedWindow(pstrContourImageTitle, CV_WINDOW_AUTOSIZE);
	cvShowImage(pstrContourImageTitle, pOutLineImage);

	cvWaitKey(0);

	//销毁窗口，释放图像







	return 0;
}

//*/
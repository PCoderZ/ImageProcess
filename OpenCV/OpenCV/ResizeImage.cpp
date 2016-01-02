/*

#include<opencv.hpp>

using namespace std;

int main(){

	const char* pathname = "E:\\Photo\\car.jpg";


	double fScale = 0.314;    //缩放倍数
	CvSize czSize;            //目标图像尺寸，CvSize为一结构体变量类型

	//从文件中读取图像
	IplImage *pSrcImage = cvLoadImage(pathname,CV_LOAD_IMAGE_UNCHANGED);
	IplImage *pDstImage = NULL; 

	//计算目标图像大小
	czSize.width = (*pSrcImage).width * fScale;    //通过指针调用结构体成员
	czSize.height = pSrcImage->height * fScale;

	//创建图像并缩放
	pDstImage = cvCreateImage(czSize, pSrcImage->depth, pSrcImage->nChannels);
	cvResize(pSrcImage, pDstImage, CV_INTER_AREA);

	//创建窗口
	cvNamedWindow("原始图像", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("缩放图像", CV_WINDOW_AUTOSIZE);

	//在指定窗口中显示图像
	cvShowImage("原始图像", pSrcImage);
	cvShowImage("缩放图像", pDstImage);

	//等待按键事件
	cvWaitKey();

	//保存图片
	//cvSaveImage("E:\\Photo\\OpenCV", pDstImage);

	return 0;
}

*/
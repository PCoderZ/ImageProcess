///*
//���������

#include<opencv.hpp>

using namespace std;

int main(){
	const char* pstrSrcImageTitle = "ԭͼ";
	const char* pstrContourImageTitle = "����ͼ";

	const int IMAGE_WIDTH = 400;
	const int IMAGE_HEIGHT = 200;

	//����ͼ��
	IplImage *pSrcImage = cvLoadImage("E:\\Photo\\face.jpg", CV_LOAD_IMAGE_UNCHANGED);
	IplImage *pSrcImage1 = cvCreateImage(cvSize(IMAGE_WIDTH, IMAGE_HEIGHT), IPL_DEPTH_8U, 3);
	
	/*
	//���ɰ�ɫ
	cvRectangle(pSrcImage, cvPoint(0,0), cvPoint(IMAGE_WIDTH, IMAGE_HEIGHT), CV_RGB(255,255,255), CV_FILLED);

	//��Բ����������ͬ��ɫ��Բ����
	CvPoint ptCircleCenter = cvPoint((pSrcImage->width)/4, (pSrcImage->height)/2);  
	int nRadius = 80;
	cvCircle(pSrcImage, ptCircleCenter, nRadius, CV_RGB(255,255,0), CV_FILLED);
	nRadius = 40;
	cvCircle(pSrcImage, ptCircleCenter, nRadius, CV_RGB(255,255,255), CV_FILLED);

	//�����λ�
	CvPoint ptLeftTop = cvPoint(IMAGE_WIDTH / 2 + 20, 20);
	CvPoint ptRightBottom = cvPoint(IMAGE_WIDTH - 20, IMAGE_HEIGHT - 20);
	cvRectangle(pSrcImage, ptLeftTop, ptRightBottom, CV_RGB(0,255,232), CV_FILLED);
	ptLeftTop = cvPoint(IMAGE_WIDTH / 2 +60, 40);
	ptRightBottom = cvPoint(IMAGE_WIDTH - 60, IMAGE_HEIGHT - 40);
	cvRectangle(pSrcImage, ptLeftTop, ptRightBottom, CV_RGB(255,255,255), CV_FILLED);
	*/

	//��ʾԭͼ
	cvNamedWindow(pstrSrcImageTitle, CV_WINDOW_AUTOSIZE);
	cvShowImage(pstrSrcImageTitle, pSrcImage);

	//תΪ�Ҷ�ͼ
	IplImage *pGrayImage = cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 1);
	cvCvtColor(pSrcImage, pGrayImage, CV_BGR2GRAY);
	//תΪ��ֵͼ��ԭ�����Ŀ������Ӧ��Ϊ��ͨ����������һ��
	IplImage *pBinaryIamge = cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 1);
	cvThreshold(pGrayImage, pBinaryIamge, 88, 255, CV_THRESH_BINARY);

	//���������������Ӧ����
	CvMemStorage *pcvMStorage = cvCreateMemStorage();
	CvSeq *pcvSeq = NULL;
	cvFindContours(pBinaryIamge, pcvMStorage, &pcvSeq, sizeof(CvContour), CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));

	//������ͼ
	IplImage *pOutLineImage = cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 3);    //RGBͼ��
	cvRectangle(pOutLineImage, cvPoint(0,0), cvPoint(pOutLineImage->width, pOutLineImage->height), CV_RGB(255,255,255), CV_FILLED);
	int nlevels = 5;
	cvDrawContours(pOutLineImage, pcvSeq, CV_RGB(255,0,0), CV_RGB(121,144,0), nlevels, 2 );

	//��ʾ����ͼ
	cvNamedWindow(pstrContourImageTitle, CV_WINDOW_AUTOSIZE);
	cvShowImage(pstrContourImageTitle, pOutLineImage);

	cvWaitKey(0);

	//���ٴ��ڣ��ͷ�ͼ��







	return 0;
}

//*/
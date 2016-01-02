/*
//ͼ���ֵ��

#include<opencv.hpp>

using namespace std;

void on_trackbar(int threshold);

const char* pstrSrcTitle = "ԭʼͼ��";
const char* pstrBinaryTitle = "��ֵ��ͼ��";
IplImage* pSrcImage = NULL;
IplImage* pBinaryImage = NULL;
IplImage* pGrayImage = NULL;


int main(){
	const char* pstrPathname = "E:\\Photo\\face.jpg";
	const char* pstrTrackbarName = "��ֵ����ֵ";
	
	//�������ɻҶ�ͼ��
	pSrcImage = cvLoadImage(pstrPathname, CV_LOAD_IMAGE_UNCHANGED);
	pGrayImage = cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 1);    //�����ͼ������������8λ�޷�������
	cvCvtColor(pSrcImage, pGrayImage, CV_RGB2GRAY);                       //�����8λ�������ȸ�����Ӱ��
	
	//��ʱpGrayImageΪ�������Ϊ8λ�޷������εĵ�ͨ��ͼ��pBinaryImageΪ�գ���cvThresholdԴͼ���Ŀ��ͼ������ʽһ�£���depth��channelҪ��ͬ
	//����Ҫ��pBinaryImage��ʼ��
	pBinaryImage = cvCreateImage(cvGetSize(pGrayImage), IPL_DEPTH_8U, 1);

	//���崰��
	cvNamedWindow(pstrSrcTitle, CV_WINDOW_AUTOSIZE);
	cvNamedWindow(pstrBinaryTitle, CV_WINDOW_AUTOSIZE);

	//��ʾͼ��
	cvShowImage(pstrSrcTitle, pSrcImage);
	cvShowImage(pstrBinaryTitle, pBinaryImage);

	
	//����������
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
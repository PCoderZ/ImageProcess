/*
//ͼ���canny��Ե���

#include<opencv.hpp>

using namespace std;

//��������
void on_trackbar(int threshold);

IplImage *pSrcImage, *pCannyImage;
const char *pstrWindowsCannyTitle = "��Ե���ͼ";


int main(){
	const char *pstrImagePath = "E:\\Photo\\face.jpg"; 
	const char *pstrWindowsSrcTitle = "ԭͼ";
	const char *pstrWindowsTrackBarName = "Threshold";

	//���ļ�������ͼ��ĻҶ�ͼ(�ص㲿��)
	pSrcImage = cvLoadImage(pstrImagePath, CV_LOAD_IMAGE_GRAYSCALE);
	pCannyImage = cvCreateImage(cvSize(pSrcImage->width, pSrcImage->height), IPL_DEPTH_8U, 1); 

	//��������
	cvNamedWindow(pstrWindowsSrcTitle, CV_WINDOW_AUTOSIZE);
	cvNamedWindow(pstrWindowsCannyTitle, CV_WINDOW_AUTOSIZE);

	//����������,�Ӷ��ı�canny��Ե������ֵ
	int nThresholdEdge = 1;
	cvCreateTrackbar(pstrWindowsTrackBarName, pstrWindowsCannyTitle, &nThresholdEdge, 100, on_trackbar );

	//ȥ�����������̶���С��ֵ��canny��Ե���
	//int threshold = 50;
	//cvCanny(pSrcImage, pCannyImage, threshold, threshold*3, 3);

	//��ָ����������ʾͼ��  
    cvShowImage(pstrWindowsSrcTitle, pSrcImage);  
	cvShowImage(pstrWindowsCannyTitle, pCannyImage);

	//�ȴ������¼�
	cvWaitKey();

	return 0;
}

void on_trackbar(int threshold){

	//canny��Ե���
	cvCanny(pSrcImage, pCannyImage, threshold, threshold*3, 3);
	cvShowImage(pstrWindowsCannyTitle, pCannyImage);
}

*/
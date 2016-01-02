/*

#include<opencv.hpp>

using namespace std;

int main(){

	const char* pathname = "E:\\Photo\\car.jpg";


	double fScale = 0.314;    //���ű���
	CvSize czSize;            //Ŀ��ͼ��ߴ磬CvSizeΪһ�ṹ���������

	//���ļ��ж�ȡͼ��
	IplImage *pSrcImage = cvLoadImage(pathname,CV_LOAD_IMAGE_UNCHANGED);
	IplImage *pDstImage = NULL; 

	//����Ŀ��ͼ���С
	czSize.width = (*pSrcImage).width * fScale;    //ͨ��ָ����ýṹ���Ա
	czSize.height = pSrcImage->height * fScale;

	//����ͼ������
	pDstImage = cvCreateImage(czSize, pSrcImage->depth, pSrcImage->nChannels);
	cvResize(pSrcImage, pDstImage, CV_INTER_AREA);

	//��������
	cvNamedWindow("ԭʼͼ��", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("����ͼ��", CV_WINDOW_AUTOSIZE);

	//��ָ����������ʾͼ��
	cvShowImage("ԭʼͼ��", pSrcImage);
	cvShowImage("����ͼ��", pDstImage);

	//�ȴ������¼�
	cvWaitKey();

	//����ͼƬ
	//cvSaveImage("E:\\Photo\\OpenCV", pDstImage);

	return 0;
}

*/
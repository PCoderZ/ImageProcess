/*

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cv.h>
#include<highgui.h>


int main(){
	//create a window
	cvNamedWindow("win1", CV_WINDOW_AUTOSIZE);
	cvMoveWindow("win1", 100, 100);

	//load the image
	//By default,CV_LOAD_IMAGE_COLOR>0,the loaded image is forced to be a 3-channel color image
	IplImage* img = 0;
	img = cvLoadImage("E:\\Photo\\car.jpg", CV_LOAD_IMAGE_COLOR);

	//show the image
	cvShowImage("win1", img);

	//resize the window
	cvResizeWindow("win1", 100, 100);

	//wait for a key
	cvWaitKey(0);



	//release the image
	cvReleaseImage(&img);

	//destroy the window
	cvDestroyWindow("win1");

	return 0 ;
}

*/
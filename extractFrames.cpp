// OpenCVStabilization.cpp : Defines the entry point for the console application.
//

#include "cv.h"
#include "highgui.h"

int main()
{
	IplImage *image = 0;			//input 3 channel image
	CvCapture *capture = 0;			//caputring frame from video
	char name[20];
	int counter = 1;

	capture = cvCaptureFromFile("Seq2_N_0001.avi");

	for(;;)
	{
		image = cvQueryFrame(capture);
		if (!image) { break; }

		sprintf(name,"night%05d.bmp",counter);
		cvShowImage("img",image);
		cvSaveImage(name,image);
		counter++;
	}
	cvReleaseCapture(&capture);
	cvReleaseImage(&image);
	return 0;
}
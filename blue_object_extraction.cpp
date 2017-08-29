#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	VideoCapture stream(0);   //0 is the id of the camera
	//you can find the id by type “ll /dev/video*” in a terminal
	if (!stream.isOpened()){
		cout << "cannot open camera";
		return 0;
	}
	//check if video device has been initialized

	char checkForEscKey = 0;
	Scalar blue_low_bound(110,50, 50), blue_high_bound(130,255, 255); 
	Mat cameraFrame_color, cameraFrame_HSV, blue_object; //store the frame data

	while (checkForEscKey != 27 && stream.isOpened()) {
		stream.read(cameraFrame_color);
		cvtColor(cameraFrame_color, cameraFrame_HSV, COLOR_BGR2HSV);
		inRange(cameraFrame_HSV, blue_low_bound, blue_high_bound, blue_object);
		namedWindow("imgOriginal", CV_WINDOW_NORMAL);
		namedWindow("imgBlue", CV_WINDOW_NORMAL);
		imshow("imgOriginal", cameraFrame_color);
		imshow("imgBlue", blue_object);
		checkForEscKey = waitKey(1);
	}
	return 0;
}

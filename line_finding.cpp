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

		vector<Vec4i> lines;
		HoughLinesP(blue_object, lines, 0.7, CV_PI/90, 40, 20, 20);

		for( size_t i = 0; i < lines.size(); i++ ){
    		Vec4i l = lines[i];
			line(cameraFrame_color, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, CV_AA);
  		}

		namedWindow("imgOriginal", CV_WINDOW_NORMAL);
		namedWindow("imgBlue", CV_WINDOW_NORMAL);
		imshow("imgOriginal", cameraFrame_color);
		imshow("imgBlue", blue_object);
		checkForEscKey = waitKey(1);
	}
	return 0;
}

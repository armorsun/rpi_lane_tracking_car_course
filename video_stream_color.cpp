#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
VideoCapture stream(0); //0 is the id of the camera
//you can find the id by type “ll /dev/video*” in a terminal
if (!stream.isOpened()) cout << "cannot open camera”;
//check if video device has been initialized

 stream.set(CV_CAP_PROP_BUFFERSIZE, 3);
 char checkForEscKey = 0;
 Mat cameraFrame; //store the frame data
 while (charCheckForEscKey != 27 && stream.isOpened()) {
 stream.read(cameraFrame);
 namedWindow("imgOriginal", CV_WINDOW_NORMAL);
 imshow("imgOriginal", cameraFrame);
 charCheckForEscKey = waitKey(1);
 }
 return 0;
}

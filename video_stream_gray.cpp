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
Mat cameraFrame_color, cameraFrame_gray; //store the frame data

while (checkForEscKey != 27 && stream.isOpened()) {
stream.read(cameraFrame_color);
cvtColor(cameraFrame_color, cameraFrame_gray, COLOR_BGR2GRAY);
namedWindow("imgOriginal", CV_WINDOW_NORMAL);
imshow("imgOriginal", cameraFrame_gray);
checkForEscKey = waitKey(1);
}
return 0;
}

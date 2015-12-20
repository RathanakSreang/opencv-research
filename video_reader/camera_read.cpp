#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
int main(){
    cv::namedWindow("Camera Reader", cv::WINDOW_AUTOSIZE);
    cv::VideoCapture cap;
    cap.open(0);
    if( !cap.isOpened()){
        std::cerr << "Count not open capture" << std::endl;
        return -1;
    }
    cv::Mat frame;
    while( 1 ) {
    cap >> frame;
    if( !frame.data ) break;
    //convert to gray
    cv::cvtColor( frame, frame, cv::COLOR_BGR2GRAY );
    // Ran out of film
    cv::imshow( "Camera Reader", frame );
    if( cv::waitKey(33) >= 0 ) break;
    }
    return 0;
}

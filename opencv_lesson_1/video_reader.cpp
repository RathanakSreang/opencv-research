#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main(){
cv::namedWindow("Vedio1", cv::WINDOW_AUTOSIZE);
cv::VideoCapture cap;
cap.open("mytestvideo.mp4");
cv::Mat frame;
while(1){
cap >> frame;
if (!frame.data) break;
cv::imshow("Vedio1", frame);
if(cv::waitKey(33) >= 0) break;
}
return 0;
}

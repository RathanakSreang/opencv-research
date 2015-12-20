#include<opencv2/opencv.hpp>
int main(){
cv::Mat img = cv::imread("image3.png");
if(img.empty()) return -1;
cv::namedWindow("Lesson11", cv::WINDOW_AUTOSIZE);
cv::imshow("Lesson11", img);
cv::waitKey(0);
cv::destroyWindow("Lesson11");
return 0;
}

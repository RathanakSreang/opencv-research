#include<opencv2/opencv.hpp>
int main(){
cv::Mat img = cv::imread("image3.png");
if(img.empty()) return -1;
cv::namedWindow("Lesson1", cv::WINDOW_AUTOSIZE);
cv::imshow("Lesson1", img);
cv::waitKey(0);
cv::destroyWindow("Lesson1");
return 0;
}

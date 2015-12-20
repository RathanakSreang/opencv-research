#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <fstream>
using namespace std;
int g_slider_position = 0;
int g_run = -1, g_dont_set = 0;
cv::VideoCapture g_cap;

void onTrackSlideBar(int pos, void *){
g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
    if(!g_dont_set){
        g_run = 1;
        g_dont_set =0;
    }
}
int main(){
cv::namedWindow("Vedio_With_SlideBar", cv::WINDOW_AUTOSIZE);
g_cap.open("mytestvideo.mp4");
int frames = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT);
int tmpw = (int)g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
int tmph = (int)g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);

cout << "Vedio have " << frames << "frame and dimentions(" << tmpw << "x" << tmph << ")" << endl;
cv::createTrackbar("Position", "Vedio_With_SlideBar", &g_slider_position, frames, onTrackSlideBar);
cv::Mat frame;

while(1){
    if (g_run != 0) {

        g_cap >> frame;
        if(!frame.data) break;
        int current_position = (int) g_cap.get(cv::CAP_PROP_POS_FRAMES);
        g_dont_set = 1;
        cv::setTrackbarPos("Position", "Vedio_With_SlideBar", current_position);
        cv::imshow("Vedio_With_SlideBar", frame);
        g_run-=1;
        cout << "g_run = " << g_run << endl;
    }
    char ch = (char) cv::waitKey(10);
    if(ch == 's'){
        g_run = 1;
        cout << "Single step run = " << g_run << endl;
    }
    if(ch == 'r'){
        g_run = -1;
        cout << "Single step run = " << g_run << endl;
    }
    if(ch == 27){
        break;
    }
}
return 0;
}


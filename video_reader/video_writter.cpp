#include<opencv2/opencv.hpp>
#include<iostream>
int main(){
    cv::namedWindow("Video Writer", cv::WINDOW_AUTOSIZE);
    //cv::namedWindow("Log Video Writer", cv::WINDOW_AUTOSIZE);
    cv::VideoCapture capture;
    //capture.open("mytestvideo.mp4");
    capture.open(0);
    if(!capture.isOpened()){
        std::cerr << "Could not open capture" << std::endl;
        return -1;
    }
    double fps = 30;//capture.get(cv::CAP_PROP_FPS);
    std::cout << "FPS = " << fps << std::endl;
    cv::Size size((int)capture.get(cv::CAP_PROP_FRAME_WIDTH), (int)capture.get(cv::CAP_PROP_FRAME_HEIGHT));
    cv::VideoWriter writer;
    writer.open("VedioWrite.avi", CV_FOURCC('M','J','P','G'), fps, size);
    //cv::Mat logpolar_frame(size, CV_8UC2), bgr_frame;
    cv::Mat bgr_frame;
    for(;;){
        capture >> bgr_frame;
        if(bgr_frame.empty()) break;
        cv::imshow("Video Writer", bgr_frame);
        /*cv::logPolar(
        bgr_frame,
        logpolar_frame,
        cv::Point2f(bgr_frame.cols/2, bgr_frame.rows/2),
        40,
        cv::WARP_FILL_OUTLIERS
        );
        cv::imshow("Log Video Writer", logpolar_frame);
        //writer << logpolar_frame;
        */
        writer << bgr_frame;
        char ch = cv::waitKey(10);
        if(ch == 27) break;
    }
    writer.release();
    capture.release();
return 0;
}

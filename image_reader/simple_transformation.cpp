#include <opencv2/opencv.hpp>
/*
void Example_2(cv::Mat &image){
    cv::namedWindow("Example_2_in", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Example_2_out", cv::WINDOW_AUTOSIZE);
    cv::imshow("Example_2_in", image);
    cv::Mat out;
    cv::GaussianBlur(image, out, cv::Size(5,5),3,3);
    cv::GaussianBlur(out, out, cv::Size(5,5),3,3);
    cv::imshow("Example_2_out", out);
    cv::waitKey(0);
}*/
int main(){
    /*cv::Mat img = cv::imread("image3.png"), img2;
    cv::namedWindow("Smoot_Image", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Smoot_Image_2", cv::WINDOW_AUTOSIZE);
    cv::imshow("Smoot_Image", img);
    cv::pyrDown(img, img2);
    cv::imshow("Smoot_Image", img2);
    cv::waitKey(0);*/

    cv::Mat img_rgb = cv::imread( "image3.png" );
    cv::Mat img_gry, img_cny, img_pyr, img_pyr2;
    cv::cvtColor( img_rgb, img_gry, cv::COLOR_BGR2GRAY);
    cv::namedWindow( "Example Gray", cv::WINDOW_AUTOSIZE );
    cv::namedWindow( "Example Canny", cv::WINDOW_AUTOSIZE );
    cv::imshow( "Example Gray", img_gry );
    cv::pyrDown( img_gry, img_pyr );
    cv::pyrDown( img_pyr, img_pyr2 );
    cv::Canny( img_pyr2, img_cny, 10, 100, 3, true );

    cv::Canny( img_gry, img_cny, 10, 100, 3, true );
    cv::imshow( "Example Canny", img_cny );
    int x = 16, y = 32;
    cv::Vec3b intensity = img_rgb.at< cv::Vec3b>(x, y);
    uchar blue = intensity.val[0];
    uchar green = intensity.val[1];
    uchar red = intensity.val[2];
    std::cout << "At (x,y) = (" << x << "," << y << "): (blue green red) = (" << (unsigned int) blue << "," << (unsigned int) green << "," << (unsigned int) red << ")" << std::endl;
    std::cout << "Gray pixel there is: " << (unsigned int)img_gry.at<uchar>(x, y) << std::endl;
    x /= 4; y /= 4;
    std::cout << "Pyramid2 pixel there is: " << (unsigned int)img_pyr2.at<uchar>(x, y) << std::endl;
    img_cny.at<uchar>(x, y) = 128;
    //cv::imshow( "Example Set Get Color", img_rgb );
    cv::waitKey(0);
    return 0;
}

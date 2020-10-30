
#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;


int main()
{
    VideoCapture cap;
        double scale = 0.5;
    // H 0-180
    double i_minH = 0;
    double i_maxH = 20;
    // S 0-255
    double i_minS = 43;
    double i_maxS = 255;
    // V 0-255
    double i_minV = 55;
    double i_maxV = 255;
    int g_nBilateralFilterValue = 15;



    cap.open(0);
    if(!cap.isOpened())
    {
        std::cout<< "No cmera" <<std::endl;
        return -1;
    }

    double fps = cap.get(CAP_PROP_FPS);
    std::cout<< "fps" <<std::endl;

    while(1)
    {
        cv::Mat frame;
        cv::Mat hsvFrame;
        cv::Mat blurFrame;

        bool rSuccess = cap.read(frame);
        frame.copyTo(blurFrame);
        cv::imshow("frame",frame);


        bilateralFilter(frame, blurFrame, g_nBilateralFilterValue, g_nBilateralFilterValue * 2, g_nBilateralFilterValue / 2);
        blur(frame, blurFrame, Size(5,5));
        imshow("blur", blurFrame);

        waitKey(3);
    }
    return 0;
}

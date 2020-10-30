
#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;


int main()
{
    VideoCapture cap;


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
        cv::Mat blurFrame;

        bool rSuccess = cap.read(frame);

        frame.copyTo(blurFrame);
        cv::imshow("frame",frame);
        blur(frame, blurFrame, Size(5,5));
        imshow("blur", blurFrame);

        waitKey(3);
    }
    return 0;
}

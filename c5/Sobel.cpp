
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
        cv::Mat SobelDx, SobelDy, Sobel;

        bool rSuccess = cap.read(frame);

        frame.copyTo(SobelDx);
        frame.copyTo(SobelDy);
        frame.copyTo(Sobel);
        cv::imshow("frame",frame);

        cv::Sobel(frame, SobelDx, CV_8U, 1, 0, 3);
        cv::Sobel(frame, SobelDy, CV_8U, 0, 1, 3);
        cv::Sobel(frame, Sobel, CV_8U, 1, 1, 3);

        imshow("SobelDx", SobelDx);
        imshow("SobelDy", SobelDy);
        imshow("Sobel", Sobel);

        waitKey(3);
    }
    return 0;
}

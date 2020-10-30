
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
        cv::Mat GaussianblurFrame;

        bool rSuccess = cap.read(frame);

        frame.copyTo(GaussianblurFrame);
        cv::imshow("frame",frame);
        GaussianBlur(frame, GaussianblurFrame,Size(5,5),8,0.0);
        imshow("Gaussianblur", GaussianblurFrame);

        waitKey(3);
    }
    return 0;
}

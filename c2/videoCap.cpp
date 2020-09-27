
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
        bool rSuccess = cap.read(frame);
        if(! rSuccess)
        {
            std::cout<< "无法读取视频" <<std::endl;
            break;
        }
        else
            cv::imshow("frame",frame);
        waitKey(30);
    }
    return 0;
}

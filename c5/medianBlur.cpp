
#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;

string window_name = "binaryMat";

void midianblur_Mat(int ksize, void* data)
{
    Mat src = *(Mat*)(data);
    Mat dst;
    medianBlur(src, dst, ksize);
    imshow(window_name, dst);
}

int main()
{
    VideoCapture cap;
    int lowTh = 0;
    int maxTh = 25;

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
        cv::Mat medianblurFrame;

        bool rSuccess = cap.read(frame);

        frame.copyTo(medianblurFrame);
        cv::imshow("frame",frame);
        medianBlur(frame, medianblurFrame, 7);
        imshow("midianblur", medianblurFrame);
        //createTrackbar("threshold",window_name, &lowTh, maxTh, midianblur_Mat, &frame);

        waitKey(3);
    }
    return 0;
}

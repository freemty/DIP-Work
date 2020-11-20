
#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;


int main()
{

    cv::Mat dstMat;
    cv::Mat srcMat = cv::imread("/Users/sum_young/private_code/CV/figure/lena.jpg");

    if(srcMat.empty()) return -1;

    const cv::Point2f src_pt[]{
        cv::Point2f(150,150),
        cv::Point2f(150,300),
        cv::Point2f(350,300),
        cv::Point2f(350,150)
    };

    const cv::Point2f dst_pt[]{
        cv::Point2f(200,150),
        cv::Point2f(200,300),
        cv::Point2f(340,270),
        cv::Point2f(340,180)
    };

    const cv::Mat  perspective_matrix = cv::getPerspectiveTransform(src_pt, dst_pt);

    cv:: warpPerspective(srcMat, dstMat, perspective_matrix, srcMat.size());   
    cv::imshow("Src", srcMat);
    cv::imshow("Dst", dstMat);

    while(true)
    {
        int c;
        c = waitKey(20);
        if (27 == (char) c) 
            break;
    }

    return 0;
}

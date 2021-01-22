
#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;


int main()
{


    cv::Mat srcMat = cv::imread("/Users/sum_young/private_code/CV/figure/18.jpg");
    cv::Mat srcMat_Gray = cv::imread("/Users/sum_young/private_code/CV/figure/18.jpg",0);
    cv::Mat cannyMat;
    std::vector<cv::Vec2f> lines;

    cv::Canny(srcMat_Gray,cannyMat,100,255);
    cv::imshow("canny", cannyMat);
    cv::HoughLines(cannyMat, lines, 1, CV_PI / 180, 80);
    std::vector<cv::Vec2f>::iterator it = lines.begin();

    for(; it != lines.end(); ++it)
    {
        float rho = (*it)[0], theta = (*it)[1];
        cv:: Point pt1, pt2;
        double a = cos(theta);
        double b = sin(theta);
        double x0 = a*rho;
        double y0 = b*rho;
        pt1.x = cv::saturate_cast<int>(x0 + 1000 * (-b));
        pt1.y = cv::saturate_cast<int>(y0 + 1000 * (a));
        pt2.x = cv::saturate_cast<int>(x0 - 1000 * (-b));
        pt2.y = cv::saturate_cast<int>(y0 - 1000 * (a));
        cv::line(srcMat, pt1, pt2, cv::Scalar(0,0,255),1,LINE_AA);
    }

    cv::imshow("Src", srcMat);

    while(true)
    {
        int c;
        c = waitKey(20);
        if (27 == (char) c) 
            break;
    }

    return 0;
}

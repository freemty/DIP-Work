
#include <iostream>
#include "opencv2/opencv.hpp"


using namespace std;
using namespace cv;

int main()
{
    std::cout << "Hello World" << std::endl;
    cv::Mat M1(2, 2, CV_8UC3, Scalar(0,0,255));
    std::cout << "M1 = "<< std::endl;
    std::cout << M1 << std::endl;

    cv::Mat M2(2, 2, CV_8UC3, 1);
    std::cout << "M2 = "<< std::endl;
    std::cout << M2 << std::endl;

    cv::Mat M3(3, 4, CV_8UC1, 1);
    cv::Mat M4(3, 4, CV_8UC3, 1);
    cv::Mat M5(3, 4, CV_8UC3, 1);

    for(int i = 0; i < M3.rows; i++)
    {
        uchar* data = M3.ptr<uchar>(i);
        for(int j = 0;j < M3.cols; j++)
        {
            data[j] = j;
        }
    }

    for(int i = 0; i < M4.rows; i++)
    {
        for(int j = 0;j < M4.cols; j++)
        {
            M4.at<Vec3b>(i,j)[0] = i;
            M4.at<Vec3b>(i,j)[1] = i+1;
            M4.at<Vec3b>(i,j)[2] = i+2;
        }
    }

    std::cout << "M3 = "<< std::endl;
    std::cout << M3 << std::endl;
    std::cout << "M4 = "<< std::endl;
    std::cout << M4 << std::endl;
    std::cout << "M5 = "<< std::endl;
    std::cout << M5 << std::endl;
    
}

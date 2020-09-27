
#include <iostream>
#include "opencv2/opencv.hpp"


using namespace std;
using namespace cv;

int main()
{

    cv::Mat image = imread("figure/test.jpeg");
    cv::Mat image1 = imread("figure/test.jpeg", 0);
    cv::Mat image2;
    image.copyTo(image2);
    //int lenght = image.rows;
    //int weidth = image.cols * image.channels();
    //std::cout << "M3 = "<< std::endl;
    //std::cout << M3 << std::endl;

    for(int i = 0; i < image.rows; i++)
    {
        //uchar* data = image.ptr<uchar>(i);
        for(int j = 0; j < image.cols; j++)
        {
            //uchar average = (image.at<Vec3b>(i,j)[0] + image.at<Vec3b>(i,j)[1] + image.at<Vec3b>(i,j)[2])/3;a
            uchar cr = image.at<Vec3b>(i,j)[0];
            uchar cg = image.at<Vec3b>(i,j)[1];
            uchar cb = image.at<Vec3b>(i,j)[2];
            image.at<Vec3b>(i,j)[0] = cg;
            image.at<Vec3b>(i,j)[1] = cb;
            image.at<Vec3b>(i,j)[2] = cr;
        }
    }

    uchar Threshold = 100;
    for(int i = 0; i < image.rows; i++)
    {
        //uchar* data = image.ptr<uchar>(i);
        for(int j = 0; j < image.cols; j++)
        {
            uchar average = (image2.at<Vec3b>(i,j)[0] + image2.at<Vec3b>(i,j)[1] + image2.at<Vec3b>(i,j)[2])/3 > Threshold ? 255 : 0;
            image2.at<Vec3b>(i,j)[0] = average;
            image2.at<Vec3b>(i,j)[1] = average;
            image2.at<Vec3b>(i,j)[2] = average;
        }
    }

    imshow("im0",image);
    imshow("im1",image1);
    imshow("im2",image2);

    while(true) 
    {
        int c;
        c = waitKey(20);
        if (27 == (char) c) {
            break;
        }
    }

    return 0;
}

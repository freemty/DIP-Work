
#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;


int main()
{
    vector<Mat> images(4);
    Mat dst;

    Mat rawImage = imread("figure/test3.jpg");  
    Mat grayImage = imread("figure/test3.jpg",0);
    Mat binResult1, binResult2;

    threshold(grayImage, binResult1, 100, 255, THRESH_BINARY);
    threshold(grayImage, binResult2, 100, 255, THRESH_BINARY);

    //cv::imshow("rawImage", rawImage);
    //cv::imshow("grayImage", grayImage);
    cv::imshow("BinarizationResult1", binResult1);
    cv::imshow("BinarizationResult2", binResult2);

    // images[0] = rawImage;
    // images[1] = grayImage;
    // images[2] = binResult;
    // images[3] = binResult;
    // mergeImage(dst, images);
    // cv::imshow('dst', dst);


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


#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;


string window_name = "binaryMat";


void threshold_Mat(int th, void* data)
{
    Mat src = *(Mat*)(data);
    Mat dst;
    threshold(src, dst, th, 255, 0);
    imshow(window_name, dst);
}


int main()
{

    Mat srcMat, gryMat;
    int lowTh = 30;
    int maxTh = 255;

    srcMat = imread("/Users/sum_young/private_code/CV/figure/test3.JPG");


    cvtColor(srcMat, gryMat,COLOR_BGR2GRAY);
    cv::imshow(window_name, gryMat);

    createTrackbar("threshold", window_name, &lowTh, maxTh, threshold_Mat, &gryMat);

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

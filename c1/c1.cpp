
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    cv:: Mat srcMat = imread("figure/test.jpeg");
    int height = srcMat.rows;
    int weigth = srcMat.cols;
    
    for(int j = 0;j < height; j++)
    {
        for(int i = 0;i < weigth;i++)
        {
            uchar average = (srcMat.at<Vec3b>(j,i)[0] + srcMat.at<Vec3b>(j,i)[1] + srcMat.at<Vec3b>(j,i)[2])/3;
            srcMat.at<Vec3b>(j,i)[0] = average;
            srcMat.at<Vec3b>(j,i)[1] = average;
            srcMat.at<Vec3b>(j,i)[2] = average;
        }
    }
    imshow("src",srcMat);

    while(true) {
        int c;
        c = waitKey(20);
        if (27 == (char) c) {
            break;
        }
    }
}


#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;


int main()
{
    vector<Mat> images(4);
    Mat dst;

    Mat grayImage = imread("/Users/sum_young/private_code/CV/figure/41.jpg",0);
    Mat binResult;
    Mat Erode, Dilate, Open, Close;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(10,10), Point(-1, -1));

    threshold(grayImage, binResult, 129, 255, THRESH_BINARY);
    morphologyEx(binResult, Erode, 0, kernel);
    morphologyEx(binResult, Dilate, 1, kernel);
    morphologyEx(binResult, Open, 2, kernel);
    morphologyEx(binResult, Close, 3, kernel);


    cv::imshow("BinarizationResult", binResult);
    cv::imshow("Erode", Erode);
    cv::imshow("Dilate", Dilate);
    cv::imshow("Open", Open);
    cv::imshow("Close", Close);



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

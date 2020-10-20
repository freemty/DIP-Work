
#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;


int main()
{

    Mat grayImage = imread("/Users/sum_young/private_code/CV/figure/41.jpg",0);
    Mat binResult;
    Mat Erode, Dilate, Open, Close;
    Mat connectedComponents,bounding_box,centroids;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(10,10), Point(-1, -1));
    int count;

    threshold(grayImage, binResult, 100, 255, THRESH_BINARY);
    // morphologyEx(binResult, Erode, 0, kernel);
    // morphologyEx(binResult, Dilate, 1, kernel);
    // morphologyEx(binResult, Open, 2, kernel);
    // morphologyEx(binResult, Close, 3, kernel);

    count = cv::connectedComponentsWithStats(binResult,connectedComponents,bounding_box,centroids,8,CV_32S);

    std::cout << "There are  "<< std::endl;
    std::cout << count - 1 << std::endl;
    std::cout << "coins in this image "<< std::endl;
    cv::imshow("BinarizationResult", binResult);
    // cv::imshow("Erode", Erode);
    // cv::imshow("Dilate", Dilate);
    // cv::imshow("Open", Open);
    // cv::imshow("Close", Close);
    while(true)
    {
        int c;
        c = waitKey(20);
        if (27 == (char) c)
            break;
    }

    return 0;
}


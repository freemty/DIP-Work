
#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;


int main()
{

    Mat grayImage = imread("/Users/sum_young/private_code/CV/figure/81.jpg",0);
    Mat FinalImage;
    Mat binResult,DilateResult,OpenResult,CloseResult;
    Mat connectedComponents,bounding_box,centroids;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(10,10), Point(-1, -1));
    int count;

    threshold(grayImage, binResult, 100, 255, THRESH_OTSU);

    morphologyEx(binResult, DilateResult, 1, kernel);
    // morphologyEx(binResult, Dilate, 1, kernel);
    //morphologyEx(binResult, OpenResult, 2, kernel);
    morphologyEx(binResult, CloseResult, 2, kernel);
    CloseResult.copyTo(FinalImage);

        for(int i = 0; i < CloseResult.rows; i++)
    {
        //uchar* data = image.ptr<uchar>(i);
        for(int j = 0; j < CloseResult.cols; j++)
        {
            if(CloseResult.at<uchar>(i,j) == 255)
                FinalImage.at<uchar>(i,j) = 0;
            else
                FinalImage.at<uchar>(i,j) = 255;
        }
    }
    count = cv::connectedComponentsWithStats(FinalImage,connectedComponents,bounding_box,centroids,8,CV_32S);




    cv::imshow("BinarizationResult", binResult);
    cv::imshow("CloseResult", CloseResult);
    //cv::imshow("DilateResult", DilateResult);
    std::cout << "There are  "<< std::endl;
    std::cout << count - 1 << std::endl;
    std::cout << "PaperClip in this image "<< std::endl;
    cv::imshow("BinarizationResult", binResult);
    while(true)
    {
        int c;
        c = waitKey(20);
        if (27 == (char) c)
            break;
    }

    return 0;
}
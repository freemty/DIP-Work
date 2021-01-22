
#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;


int main()
{

    Mat grayImage = imread("/Users/sum_young/private_code/CV/figure/81.png",0);
    Mat PureImage = imread("/Users/sum_young/private_code/CV/figure/81.png");
    Mat FinalImage;
    Mat binResult;
    Mat connectedComponents,bounding_box,centroids;
    vector<vector<Point>> conters;
    vector<Vec4i> hierarchy;
    int count;

    threshold(grayImage, binResult, 100, 255, THRESH_OTSU);

    binResult.copyTo(FinalImage);

        for(int i = 0; i < binResult.rows; i++)
    {
        //uchar* data = image.ptr<uchar>(i);
        for(int j = 0; j < binResult.cols; j++)
        {
            if(binResult.at<uchar>(i,j) == 255)
                FinalImage.at<uchar>(i,j) = 0;
            else
                FinalImage.at<uchar>(i,j) = 255;
        }
    }
    //count = cv::connectedComponentsWithStats(FinalImage,connectedComponents,bounding_box,centroids,8,CV_32S);

    cv::findContours(FinalImage, conters,RETR_EXTERNAL,CHAIN_APPROX_NONE);

    cv::RotatedRect rbox = minAreaRect(conters[1]);
    cv::drawContours(FinalImage,conters,1,Scalar(0,255,255),1 ,8);
    cv::Point2f vtx[4];
    rbox.points(vtx);
    for(int i=0;i < 4;++i)
    {
        cv::line(PureImage, vtx[i], vtx[i<3 ? i+1 : 0],cv::Scalar(0,0,255),2,LINE_AA);
    }

    cv::imshow("BinarizationResult", binResult);
    cv::imshow("FinalResult", FinalImage);
    cv::imshow("FinalResult",PureImage);
    while(true)
    {
        int c;
        c = waitKey(20);
        if (27 == (char) c)
            break;
    }

    return 0;
}
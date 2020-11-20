
#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;


int main()
{

    cv::Mat dstMat;
    cv::Mat srcMat = cv::imread("/Users/sum_young/private_code/CV/figure/lena_rotate.jpg");
    cv::Mat srcMat_gray = cv::imread("/Users/sum_young/private_code/CV/figure/lena_rotate.jpg",0);
    cv::Mat binMat;

    if(srcMat.empty()) return -1;

    cv::Size a = srcMat.size();

    Point2f p1,p2,p3,p4;


    //threshold(srcMat, binMat, 100, 255, THRESH_BINARY);

    cv::imshow("Src", srcMat);



    for(int i = 1; i < srcMat_gray.rows; i++)
    {
        if(srcMat_gray.at<uchar>(0,i)  < 100 )
        {
            p1.x = 0;
            p1.y = i;
        }
    }

    for(int i = 1; i < srcMat_gray.rows; i++)
    {
        if(srcMat_gray.at<uchar>(a.height - 1,i)  < 100 )
        {
            p2.x = i;
            p2.y = a.height -1;
        }
    }

    for(int i = 1; i < srcMat_gray.rows; i++)
    {
        if(srcMat_gray.at<uchar>(i,a.width-1) < 100)
        {
            p3.x = a.width - 1;
            p3.y = i;
        }
    }

    for(int i = 1; i < srcMat_gray.rows; i++)
    {
        if(srcMat_gray.at<uchar>(0,i)  < 100 )
        {
            p4.x = 0;
            p4.y = i;
        }
    }

    const cv::Point2f src_pt[]{
        p1,p2,p3,p4
    };

    const cv::Point2f dst_pt[]{
        cv::Point2f(0,0),
        cv::Point2f(0,a.height),
        cv::Point2f(a.width,a.height),
        cv::Point2f(a.width,0)
    };

    const cv::Mat  affine_matrix = cv::getAffineTransform(src_pt, dst_pt);

    cv:: warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());   

    cv::imshow("Dst", dstMat);

    while(true)
    {
        int c;
        c = waitKey(20);
        if (27 == (char) c) 
            break;
    }

    return 0;
}


#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;



int main()
{

    Mat src_image = cv::imread("/Users/sum_young/private_code/CV/figure/lena.jpg");
    vector<Mat> channel, achannel;
    Mat dst_image;

    cv::split(src_image, channel);
    cv::split(src_image, achannel);

    // cv::imshow("B", channel[0]);
    // cv::imshow("G", channel[1]);
    // cv::imshow("R", channel[2]);
    for(int i = 0;i < 3; i++)
        cv::equalizeHist(channel[i], achannel[i]);

    cv::merge(achannel, dst_image);
    cv::imshow("row", src_image);
    cv::imshow("dst", dst_image);

    while(true)
    {
        int c;
        c = waitKey(20);
        if (27 == (char) c)
            break;
    }

    return 0;
}
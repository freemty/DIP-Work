
#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;

int main()
{

    cv::Mat image = imread("figure/test2.png", 0);
    cv::Mat hisGraph =  Mat::zeros(Size(300, 100), CV_8UC3);

    float histgram[256] = {0};

    for(int i = 0; i < image.rows; i++)
    {
        //uchar* data = image.ptr<uchar>(i);
        for(int j = 0; j < image.cols; j++)
        {
            int  gray = image.at<uchar>(i,j);
            //0b 1g 2r
            // rgb2gray: rgb = 
            histgram[gray] += 1;
        }
    }

    for(int i = 0; i < 256; i++)
    {
    cv::Point pt1,pt2;
    pt1.x = i;
    pt1.y = 100;
    pt2.x = i;
    pt2.y = 100 * (1 - histgram[i] / (image.cols * image.rows)) ;
    line(hisGraph,pt1,pt2,CV_RGB(255,0,0),1,8,0);
    }
    
    imshow("image",image);
    imshow("histgram",hisGraph);

    while(true) 
    {
        int c;
        c = waitKey(20);
        if (27 == (char) c)
            break;
    }

    return 0;
}

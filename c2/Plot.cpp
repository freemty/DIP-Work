
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{

   
    cv:: Mat dispMat = Mat::zeros(Size(800, 600), CV_8UC3);

    cv::Point pt;
    pt.x = 100;
    pt.y = 100;
    circle(dispMat,pt,5,CV_RGB(255,0,0),1,8,0);

    cv::Point pt1,pt2;
    pt1.x = 100;
    pt1.y = 300;
    pt2.x = 200;
    pt2.y = 600;

    line(dispMat,pt1,pt2,CV_RGB(255,0,0),1,8,0);

    cv::Rect rect;
    rect.x = 200;
    rect.y = 200;
    rect.width;
    rect.height;
    rectangle(dispMat,rect,CV_RGB(255,0,0),1,8,0);

    cv:: imshow("image",dispMat);

    while(true) {
        int c;
        c = waitKey(20);
        if (27 == (char) c) {
            break;
        }
    }
}

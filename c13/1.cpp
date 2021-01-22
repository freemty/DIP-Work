
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap;
    int cnt = 0;
    Mat refMat, tempMat, resultMat;
    cap.open(0);

    if(!cap.isOpened())
    {
        std::cout<< "No cmera" <<std::endl;
        return -1;
    }

    double fps = cap.get(CAP_PROP_FPS);
    std::cout<< "fps" <<std::endl;

    while(1)
    {
        Mat frame;
        cap.read(frame);

        if (cnt == 0){
            Rect2d r;
            r = selectROI(frame);
            tempMat = frame(r);
            tempMat.copyTo(refMat);
            destroyAllWindows();
        }

        else{
            int match_method = 0;
            matchTemplate(frame, refMat,resultMat, match_method);
            normalize(resultMat, resultMat, 0, 1, NORM_MINMAX, -1, Mat());

            double minVal, maxVal;
            Point minLoc, maxLoc;
            Point matchLoc;

            minMaxLoc(resultMat, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

            //paint a Rect
            matchLoc = minLoc;
            Rect rect;
            rect.x = matchLoc.x;
            rect.y = matchLoc.y;
            rect.width = refMat.cols;
            rect.height = refMat.cols;
            rectangle(frame,rect,CV_RGB(255,0,0),1,8,0);


            imshow("result", frame);
            waitKey(3);

        }
        cnt++;
        //cv::imshow("frame",frame);
    }
    return 0;
}

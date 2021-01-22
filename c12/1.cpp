
#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap;
    int cnt = 0;
    Mat bgMat;
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
        cv::Mat frame, subMat, bny_subMat;
        cap.read(frame);
        cvtColor(frame, frame, COLOR_BGR2GRAY);

        if (cnt == 0){
            frame.copyTo(bgMat);
        }
        else{
            absdiff(frame, bgMat, subMat);
            threshold(subMat, bny_subMat, 50, 255, THRESH_BINARY);

            imshow("b_subMat", bny_subMat);
            imshow("subMat", subMat);
            waitKey(3);

        }
        cnt++;
        //cv::imshow("frame",frame);
    }
    return 0;
}

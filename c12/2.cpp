
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

#define INIT_NUM 20



Mat matseqStd(Mat *bgMats, int length){

    Mat avgMat = Mat::zeros(bgMats->rows, bgMats->cols, CV_16U);
    Mat stdMat = Mat::zeros(bgMats->rows, bgMats->cols, CV_16U);
    Mat t;
    for(int i = 0; i < length; i++){
        bgMats[i].convertTo(t, CV_16U);
        std::cout << t << std::endl;
        avgMat = t + avgMat;
    }

    avgMat = avgMat / length;
    std::cout << avgMat << std::endl;
    for(int i = 0; i < length; i++){
        bgMats[i].convertTo(t, CV_16U);
        stdMat = stdMat + (t - avgMat) * (t - avgMat);
    }

    avgMat = stdMat / length;
    std::cout << stdMat << std::endl;
    return avgMat, stdMat;
}


int main()
{
    VideoCapture cap;
    int cnt = 0;
    Mat bgMat;
    cap.open(0);

    Mat bgMats[INIT_NUM];
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


        if (cnt < INIT_NUM)
            frame.copyTo(bgMats[cnt]);
        else if(cnt == INIT_NUM)
        {
                Mat stdMat, avgMat;
                avgMat, stdMat= matseqStd(bgMats, INIT_NUM);
                imshow("avg", avgMat);
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


#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;




int main()
{

    Mat src_image = cv::imread("/Users/sum_young/private_code/CV/figure/c11_1.jpg",0);
    Mat dst_image;

    src_image.copyTo(dst_image);
    //MyGammaCorrection(src_image, dst_image, 0.5);
    uchar lut[256];
    float fGamma = 0.5;

	for( int i = 0; i < 256; i++ )
	{
		lut[i] = saturate_cast<uchar>(pow((float)(i/255.0), fGamma) * 255.0f);
	}

    for(int i = 0; i < src_image.rows; i++)
    {
        for(int j = 0; j < src_image.cols; j++)
            dst_image.at<uchar>(i,j) = lut[src_image.at<uchar>(i,j)];

    }

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
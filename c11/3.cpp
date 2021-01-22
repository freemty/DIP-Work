#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

string window_name = "GammaCorrection";


void GammaCorrection(Mat& src, Mat& dst, float fGamma)
{
    Mat src_image = src;
    Mat dst_image = dst;
    src_image.copyTo(dst_image);
    uchar lut[256];
    for( int i = 0; i < 256; i++ )
	{
		lut[i] = saturate_cast<uchar>(pow((float)(i/255.0), fGamma) * 255.0f);
	}


	MatIterator_<Vec3b> it, end;
	for( it = dst_image.begin<Vec3b>(), end = dst_image.end<Vec3b>(); it != end; it++)
    {
        (*it)[0] = lut[((*it)[0])];
        (*it)[1] = lut[((*it)[1])];
        (*it)[2] = lut[((*it)[2])];
    }

}


void Gamma_Mat(int fGamma, void* data)
{
    Mat src = *(Mat*)(data);
    Mat dst;
    //cv::imshow("test",src);
    GammaCorrection(src, dst, float(fGamma)/100);
    imshow(window_name, dst);
}



int main()
{

    Mat src_image = cv::imread("/Users/sum_young/private_code/CV/figure/c11_2.jpg");
    Mat dst_image;

    src_image.copyTo(dst_image);
    //MyGammaCorrection(src_image, dst_image, 0.5);

    int fGamma_min = 1;
    int fGamma_max = 100;
    //GammaCorrection(src_image, dst_image, fGamma);

    cv::imshow(window_name, src_image);
    createTrackbar("gamma", window_name, &fGamma_min, fGamma_max, Gamma_Mat, &src_image);
    

    while(true)
    {
        int c;
        c = waitKey(20);
        if (27 == (char) c)
            break;
    }

    return 0;
}
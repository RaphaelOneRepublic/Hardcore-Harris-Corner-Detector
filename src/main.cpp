//
// Created by Mingjie Ma on 27/03/2018.
//
#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main(){
    std::cout << "Hello World" <<std::endl;
    auto img = imread("../sources/office_gray.bmp", IMREAD_COLOR);
    namedWindow("HarrisCornerDetector", 1);
    imshow("HarrisCornerDetector", img);
    waitKey(0);
    return 0;

}

//
// Created by Mingjie Ma on 27/03/2018.
//
#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <utilities.h>

using namespace cv;
using namespace std;

int main(){
    std::cout << "Hello World" <<std::endl;
    auto img = imread("../sources/office_gray.bmp", IMREAD_COLOR);
    img.convertTo(img, CV_32FC1);

    PRINT_MAT(img);
    display_image(img);
    return 0;
}

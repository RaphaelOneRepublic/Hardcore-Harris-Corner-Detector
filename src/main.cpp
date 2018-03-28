//
// Created by Mingjie Ma on 27/03/2018.
//
#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <utilities.h>
#include <harris.h>

using namespace cv;
using namespace std;

int main(){
    std::cout << "Hello World" <<std::endl;
    auto img = imread("../sources/black-white-hat.jpg", IMREAD_COLOR);
    Mat img32;
    cvtColor(img, img32, CV_RGB2GRAY);

    img32.convertTo(img32, CV_32FC1);
    Harris harris(img32);

    auto response = harris.harris_response();
    auto corners = Harris::non_maximum_suppression(response, 100000);


    for (auto i = corners.begin(); i < corners.end(); ++i) {
        circle(img, *i, 3, Scalar(255, 0, 0));
    }
    display_image(img);
    return 0;
}

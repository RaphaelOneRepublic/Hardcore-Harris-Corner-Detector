//
// Created by Mingjie Ma on 27/03/2018.
//
#include <opencv2/opencv.hpp>
#include "utilities.h"

using namespace cv;
using namespace std;

void display_image(Mat &image) {
    namedWindow("Image Preview", 1);
    imshow("Image Preview",image);
    waitKey(0);
}

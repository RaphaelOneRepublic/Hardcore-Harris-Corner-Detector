//
// Created by Mingjie Ma on 27/03/2018.
//

#ifndef HARDCORE_HARRIS_CORNER_DETECTOR_UTILITIES_H
#define HARDCORE_HARRIS_CORNER_DETECTOR_UTILITIES_H

#include <opencv2/opencv.hpp>

#define PRINT_MAT(name) print_matrix_to_console(#name, (name))
#define MAXIMUM_PRINTABLE_ROW 5
#define MAXIMUM_PRINTABLE_COL 5

using namespace std;
using namespace cv;



void display_image(Mat& image);
void print_matrix_to_console(const char *name, Mat& image);


#endif //HARDCORE_HARRIS_CORNER_DETECTOR_UTILITIES_H

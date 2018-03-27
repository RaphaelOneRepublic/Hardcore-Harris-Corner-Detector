//
// Created by Mingjie Ma on 27/03/2018.
//
#include <opencv2/opencv.hpp>
#include "utilities.h"
#include <iostream>

using namespace cv;
using namespace std;

void display_image(Mat &image) {
    namedWindow("Image Preview", 1);
    imshow("Image Preview",image);
    waitKey(0);
}

void print_matrix_to_console(const char *name, Mat &image) {
    auto rows = MIN(image.rows, MAXIMUM_PRINTABLE_ROW), cols = MIN(image.cols, MAXIMUM_PRINTABLE_COL);
    cout << name << " = {" << endl;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << image.at<float>(r,c) << ", ";
        }
        if (cols < image.cols) cout << "...";
        cout <<  endl;
    }
    if (rows < image.rows) cout << "..." << endl;
    cout<< "}" << endl;
}

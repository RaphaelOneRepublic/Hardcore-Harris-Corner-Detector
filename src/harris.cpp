//
// Created by Mingjie Ma on 27/03/2018.
//
#include "harris.h"

Harris::Harris(const Mat &img, float k = DEFAULT_HARRIS_K, int radius = DEFAULT_FILTER_SIZE, float sigma = DEFAULT_SIGMA){
    _mat = img;
    _k = k;
    _radius = radius;
    _sigma = sigma;
}

Mat Harris::harris_response() {
    auto derivative = Derivative(_mat);
    derivative.compute_sobel_derivatives();
    Mat Ix, Iy, Ixy;
    filter2D(derivative.getX(), Ix, CV_32FC1,getGaussianKernel(_radius, _sigma));
    filter2D(derivative.getY(), Iy, CV_32FC1,getGaussianKernel(_radius, _sigma));
    filter2D(derivative.getXY(), Ixy, CV_32FC1,getGaussianKernel(_radius, _sigma));

    Mat    a11 = Ix.mul(Ix),
            a22 = Iy.mul(Iy),
            a12 = Ixy, a21 = Ixy;


    auto det = a11.mul(a22) - a12.mul(a21);
    auto trace = a11 + a22;
    auto response = det - _k * (trace.mul(trace));

    return response;

}

vector<Point> Harris::non_maximum_suppression(Mat _mat) {
    double maxStrength;
    double minStrength;
    std::vector<Point> points;

    cout << _mat << endl;

    minMaxLoc(_mat, &minStrength, &maxStrength);

    Mat dilated;
    Mat local;

    dilate(_mat, dilated, Mat());

    cout << dilated << endl;

    compare(_mat, dilated, local, CMP_EQ);

    cout << local << endl;

    findNonZero(local, points);
    return points;
}



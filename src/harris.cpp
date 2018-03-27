//
// Created by Mingjie Ma on 27/03/2018.
//
#include "harris.h"

Harris::Harris(const Mat &img, float k, int radius, float sigma) {
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
    std::vector<Point> points, result;
    Mat dilated;
    Mat local_maximum;
    dilate(_mat, dilated, Mat());
    compare(_mat, dilated, local_maximum, CMP_EQ);
    findNonZero(local_maximum, points);

    sort(
            points.begin(), points.end(),
            [&_mat](const Point &x, const Point &y) -> bool {
                return _mat.at<float>(x) > _mat.at<float>(y);
            });

    for (int i = 0; i < points.size() * DEFAULT_MAX_PERCENTAGE; ++i) {
        result.push_back(points.at(static_cast<unsigned long>(i)));
    }

    return result;
}


//int main(){
//    Mat m(10,10, CV_8UC1);
//    randu(m, Scalar(-10), Scalar(10));
//    auto r = Harris::non_maximum_suppression(m);
//}
//

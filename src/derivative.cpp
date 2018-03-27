//
// Created by Mingjie Ma on 27/03/2018.
//

#include "derivative.h"

Derivative::Derivative(const Mat& mat){
    _mat = mat;
    _Ix = Mat::zeros(mat.rows - 2, mat.cols - 2, CV_32FC1);
    _Iy = Mat::zeros(mat.rows - 2, mat.cols - 2, CV_32FC1);
    _Ixy = Mat::zeros(mat.rows - 2, mat.cols - 2, CV_32FC1);
}

void Derivative::compute_sobel_derivatives() {
    Mat horizontal_self = _mat(Range(0, _mat.rows), Range(1, _mat.cols - 1));
    Mat left            = _mat(Range(0, _mat.rows), Range(0, _mat.cols - 2));
    Mat right           = _mat(Range(0, _mat.rows), Range(2, _mat.cols));
    Mat vertical_self   = _mat(Range(1, _mat.rows - 1), Range(0, _mat.cols));
    Mat above           = _mat(Range(0, _mat.rows - 2), Range(0, _mat.cols));
    Mat under           = _mat(Range(2, _mat.rows), Range(0, _mat.cols));

    Mat horizontal_sum = horizontal_self * 2 + left + right;
    Mat vertical_sum = vertical_self * 2 + above + under;

    _Iy     = - horizontal_sum(Range(0, _mat.rows - 2), Range(0, horizontal_sum.cols))
              + horizontal_sum(Range(2, _mat.rows), Range(0, horizontal_sum.cols));
    _Ix     = - vertical_sum(Range(0, vertical_sum.rows), Range(0, _mat.cols - 2))
              + vertical_sum(Range(0, vertical_sum.rows), Range(2, _mat.cols));
    _Ixy = _Ix.mul(_Iy);
}

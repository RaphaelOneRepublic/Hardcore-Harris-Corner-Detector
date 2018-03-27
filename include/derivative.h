//
// Created by Mingjie Ma on 27/03/2018.
//

#ifndef HARDCORE_HARRIS_CORNER_DETECTOR_DERIVATIVE_H
#define HARDCORE_HARRIS_CORNER_DETECTOR_DERIVATIVE_H

#include <opencv2/opencv.hpp>

using namespace cv;

class Derivative {
private:
    Mat _mat;
    Mat _Ix;
    Mat _Iy;
    Mat _Ixy;
public:
    explicit Derivative(const Mat mat){
        _mat = mat;
        _Ix = Mat::zeros(mat.rows - 2, mat.cols - 2, CV_32FC1);
        _Iy = Mat::zeros(mat.rows - 2, mat.cols - 2, CV_32FC1);
        _Ixy = Mat::zeros(mat.rows - 2, mat.cols - 2, CV_32FC1);
    }
    
    Mat getX(){
        return _Ix;
    }
    Mat getY(){
        return  _Iy;
    }
    
    Mat getXY(){
        return _Ixy;
    }

    void compute_sobel_derivatives();
};


#endif //HARDCORE_HARRIS_CORNER_DETECTOR_DERIVATIVE_H
